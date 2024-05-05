#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int binarySearch(const vector<pair<int, int>> &indexedSkills, int target, int currentRank) {
    int low = 0, high = indexedSkills.size() - 1;
    int result = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (indexedSkills[mid].first > target) {
            if (indexedSkills[mid].second > currentRank) {
                result = mid;
            }
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return result;
}

vector<int> findTrainers(const vector<int> &skills) {
    int n = skills.size();
    vector<pair<int, int>> indexedSkills;
    for (int i = 0; i < n; ++i) {
        indexedSkills.emplace_back(skills[i], i);

    }

    sort(indexedSkills.begin(), indexedSkills.end(), [](const auto &a, const auto &b) {
        // Sort based on the first element in ascending order
        if (a.first != b.first) {
            return a.first < b.first;
        }
        // In case of a tie, sort based on the second element in descending order
        return a.second > b.second;
    });

    vector<int> trainers(n, -1);  // Initialize trainers with -1

    for (int i = 0; i < n; ++i) {
        int currentRank = indexedSkills[i].second;
        int currentSkill = indexedSkills[i].first;
        trainers[currentRank] = currentRank;
        int closestHigherSkillIndex = binarySearch(indexedSkills, currentSkill, currentRank);

        if (closestHigherSkillIndex != -1) {
            trainers[currentRank] = indexedSkills[closestHigherSkillIndex].second;
        } else {
            trainers[currentRank] = currentRank;
        }
        while (indexedSkills[closestHigherSkillIndex].first <= indexedSkills[trainers[currentRank]].first) {
            closestHigherSkillIndex++;
            if (indexedSkills[trainers[currentRank]].first > indexedSkills[closestHigherSkillIndex].first
                && currentRank < indexedSkills[closestHigherSkillIndex].second) {
                trainers[currentRank] = indexedSkills[closestHigherSkillIndex].second;
            }
        }

    }

    return trainers;
}

int main() {
    int numTestCases;
    cin >> numTestCases;

    for (int i = 0; i < numTestCases; ++i) {
        int numMembers;
        cin >> numMembers;

        vector<int> skills(numMembers);
        for (int &skill: skills) {
            cin >> skill;
        }

        vector<int> trainers = findTrainers(skills);

        for (int j = 0; j < numMembers; ++j) {
            cout << trainers[j] + 1 << " ";
        }
        cout << endl;
    }

    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int binarySearch(const vector<pair<int, int>>& indexedSkills, int target) {
    int low = 0, high = indexedSkills.size() - 1;
    int result = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (indexedSkills[mid].first > target) {
            result = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return result;
}

vector<int> findTrainers(const vector<int>& skills) {
    int n = skills.size();
    vector<pair<int, int>> indexedSkills;

    for (int i = 0; i < n; ++i) {
        indexedSkills.emplace_back(skills[i], i);
    }

    sort(indexedSkills.begin(), indexedSkills.end());

    vector<int> trainers(n, -1);  // Initialize trainers with -1

    for (int i = 0; i < n; ++i) {
        int currentRank = indexedSkills[i].second;
        int currentSkill = indexedSkills[i].first;

        int closestHigherSkillIndex = binarySearch(indexedSkills, currentSkill);

        if (closestHigherSkillIndex != -1 && indexedSkills[closestHigherSkillIndex].second > currentRank) {
            trainers[currentRank] = indexedSkills[closestHigherSkillIndex].second;
        } else {
            trainers[currentRank] = currentRank;
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

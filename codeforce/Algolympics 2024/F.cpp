#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

vector<int> findTrainers(const vector<int> &skills) {
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

        int closestHigherSkillIndex = -1;
        int closestSkillDifference = INT_MAX;

        for (int j = i + 1; j < n; ++j) {
            if (indexedSkills[j].first > currentSkill) {
                int skillDifference = indexedSkills[j].first - currentSkill;

                if (skillDifference < closestSkillDifference && indexedSkills[j].second > currentRank) {
                    closestHigherSkillIndex = indexedSkills[j].second;
                    closestSkillDifference = skillDifference;
                }
            }
        }

        if (closestHigherSkillIndex != -1) {
            trainers[currentRank] = closestHigherSkillIndex;
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

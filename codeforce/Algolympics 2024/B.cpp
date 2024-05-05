#include <bits/stdc++.h>
using namespace std;

void planet_migration_report(int t, vector<pair<int, vector<vector<string>>>>& test_cases) {
    for (int case_idx = 0; case_idx < t; ++case_idx) {
        int n = test_cases[case_idx].first;
        vector<vector<string>>& migrations = test_cases[case_idx].second;

        map<string, int> planet_counts;
        set<string> all_planets = {"Mercury", "Venus", "Earth", "Mars", "Jupiter", "Saturn", "Uranus", "Neptune", "Pluto"};

        for (const vector<string>& person : migrations) {
            for (size_t i = 1; i < person.size(); ++i) {
                planet_counts[person[i]]++;
            }
        }

        // Sort planets based on the number of migrations
        vector<pair<string, int>> sorted_planets(planet_counts.begin(), planet_counts.end());
        sort(sorted_planets.begin(), sorted_planets.end(), [](const auto& a, const auto& b) {
            if (a.second == b.second) {
                return a.first < b.first;
            }
            return a.second > b.second;
        });

        for (const auto& planet_count : sorted_planets) {
            cout << planet_count.first << " " << planet_count.second << "\n";
        }

        // Handle planets with zero visits separately
        for (const string& planet : all_planets) {
            if (planet_counts.find(planet) == planet_counts.end()) {
                cout << planet << " 0\n";
            }
        }
    }
}

int main() {
    int T;
    cin >> T;

    vector<pair<int, vector<vector<string>>>> test_cases;

    for (int i = 0; i < T; ++i) {
        int n;
        cin >> n;

        vector<vector<string>> migrations;
        for (int j = 0; j < n; ++j) {
            int pi;
            cin >> pi;

            vector<string> person(pi);
            for (int k = 0; k < pi; ++k) {
                cin >> person[k];
            }
            migrations.push_back(person);
        }

        test_cases.emplace_back(n, migrations);
    }

    planet_migration_report(T, test_cases);

    return 0;
}

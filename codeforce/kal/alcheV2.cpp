#include <bits/stdc++.h>
using namespace std;
struct scratch {
    string name;
    int srcVal{};
    vector<scratch *> recipe;
    vector<int> amount;
    int cheap = -1;
};

void findRecipe(const string &watToFindXd, unordered_map<string, scratch *> mapScratch, const string &goal) {
    scratch *y = mapScratch[watToFindXd];
    int recipeCount = y->amount.size();
    if (watToFindXd == goal || recipeCount == 0) {
        y->cheap = y->srcVal;
        return;
    } else if (y->cheap != -1) {
        return;
    } else {

        int total = 0;
        for (int i = 0; i < recipeCount; i++) {
            if (y->recipe[i]->cheap == -1) {
                findRecipe(y->recipe[i]->name, mapScratch, watToFindXd);
            }
            int getRecipe = y->recipe[i]->cheap;
            int getAmount = y->amount[i];
            y->cheap = getRecipe * getAmount;
            total = y->cheap + total;
            if (y->srcVal < total) {
                y->cheap = y->srcVal;
                return;
            }
        }

        y->cheap = total;
        return;

    }
}


int main() {
    auto start_time = std::chrono::high_resolution_clock::now();
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int N, Q, R;
    cin >> N >> Q >> R;
    unordered_map<string, scratch *> mapScratch;
    string temp, reciTemp;
    int value;
    for (int i = 0; i < N; i++) {
        cin >> temp >> value;
        auto *bago = new scratch;
        bago->name = temp;
        bago->srcVal = value;
        mapScratch.insert({temp, bago});
    }
    for (int i = 0; i < Q; i++) {
        cin >> temp >> reciTemp >> value;
        mapScratch[temp]->recipe.push_back(mapScratch[reciTemp]);
        mapScratch[temp]->amount.push_back(value);

    }
    for (int i = 0; i < R; i++) {
        cin >> temp;
        if (mapScratch[temp]->cheap == -1) {
            findRecipe(temp, mapScratch, " ");
        }
        cout << mapScratch[temp]->cheap << "\n";
    }
    auto end = std::chrono::high_resolution_clock::now(); // get the current time again
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start_time).count(); // calculate the time difference in ms
    std::cout << "Time taken: " << duration << " ms" << std::endl; // print the time taken

    return 0;
}
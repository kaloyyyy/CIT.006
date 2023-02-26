#include <bits/stdc++.h>
using namespace std;
struct node{
    string star;
    string recipe;
    int amount;
    node* next;
};

node* head=NULL;
node* tail=NULL;
node* curr=NULL;

void insert(string star, string recipe, int amount){
    node* nn = new node;
    if(head==NULL){
        head = nn;
        tail = head;
    }
    else{
        tail->next = nn;
    }
    nn->star = star;
    nn->recipe = recipe;
    nn->amount = amount;
    nn->next = NULL;
    tail = nn;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    map<string, int> m;
    map<string, int> n;
    int N, Q = 10, R;
    cin >> N >> Q >> R;
    string input;
    int k;
    for (int i = 0; i < N; i++) {
        cin >> input;
        cin >> k;
        m.insert({input, k});
    }

    int amt1;
    string first, second, result;

    for (int i = 0; i < Q; i++) {
        cin >> first >> second >> amt1;
        insert(first,second,amt1);
    }
    cin >> result;
    curr = head;
    for (int i = 0; i < Q; i++) {
        if (m.find(curr->star) != m.end()) {
            auto it = m.find(curr->recipe);
            if (n.find(curr->star) != n.end()) {
                auto it1 = n.find(curr->star);
                n.insert({curr->star, it1->second += it->second * curr->amount});
            } else {
                n.insert({curr->star, it->second * curr->amount});
            }
        }
        curr=curr->next;
    }

    for (auto itr = n.begin(); itr != n.end(); ++itr) {
        auto it = m.find(itr->first);
        if (itr->second < it->second) {
            it->second = itr->second;
        }
    }

    curr = head;
    int reqCtr = 0, amt2;
    for(int i = 0; i < Q; i++) {
        if (curr->star==result) {
            auto it = m.find(curr->recipe);
            auto it1 = n.find(curr->star);
            if (reqCtr==0){
                it1->second = it->second * curr->amount;
                reqCtr++;
            }

            else{
                it1->second += it->second * curr->amount;
            }
        }
        curr=curr->next;
    }
    for (auto itr = n.begin(); itr != n.end(); ++itr) {
        auto it = m.find(itr->first);
        if (itr->second < it->second) {
            it->second = itr->second;
        }
    }

    auto it = m.find(result);
    cout << (it->second) * R;

    return 0;
}
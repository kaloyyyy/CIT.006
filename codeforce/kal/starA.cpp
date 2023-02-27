#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 2e5 + 10;
int n,m,T;
vector<int> g[maxn];
int vis[maxn],in[maxn],out[maxn];
int ans[maxn],sz;
set<int> s;

void init(){
    memset(vis,0,sizeof(vis));
    memset(in,0,sizeof(in));
    memset(out,0,sizeof(out));
    sz = 0;
    s.clear();
    for(int i=1;i<=n;i++) g[i].clear();
}

bool toposort(){
    queue<int> q;
    for(int i=1;i<=n;i++)
        if(!in[i]) q.push(i);
    while(q.size()){
        int u = q.front();q.pop();
        vis[u] = 1;
        ans[++sz] = u;
        for(auto v:g[u]){
            if(--in[v] == 0) q.push(v);
            out[u]++;in[v]++;
        }
    }
    return sz == n;
}

void solve(){
    cin >> n >> m;
    init();
    for(int i=1;i<=m;i++){
        int u,v;
        cin >> u >> v;
        g[u].push_back(v);
        in[v]++;
    }
    if(!toposort()){
        cout << "IMPOSSIBLE\n";
        return;
    }
    for(int i=1;i<=n;i++) s.insert(i);
    for(int i=1;i<=n;i++){
        int u = ans[i];
        auto it = s.upper_bound(u);
        while(it != s.end() && out[u] > 0){
            int v = *it;
            if(!vis[v] && g[u].size() > 1){
                int cnt = 0;
                for(auto x:g[u]) if(vis[x]) cnt++;
                if(cnt == g[u].size() - 1) break;
            }
            if(g[u].size() == 1 || !g[u].empty() && vis[g[u][0]] && vis[g[u][1]]){
                ans[++sz] = v;
                vis[v] = 1;
                out[u]--;in[v]++;
            }
            it = s.erase(it);
        }
        if(out[u] > 0){
            cout << "IMPOSSIBLE\n";
            return;
        }
    }
    for(int i=1;i<=n;i++) cout << ans[i] << ' ';
    cout << endl;
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> T;
    while(T--) solve();
    return 0;
}

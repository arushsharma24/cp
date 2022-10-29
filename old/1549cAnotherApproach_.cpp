#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007

void solve(){
    int n, m; cin>>n>>m;
    unordered_map<int, map<int, int, greater<int>>> adj;
    for(int i = 0; i < m; i++){
        int u, v; cin>>u>>v;
        adj[u][v]++;
        adj[v][u]++;
    }
    int q; cin>>q;
    int x, y, z;
    while(q--){
        cin>>x;
        if(x == 1){
            cin>>y>>z;
            adj[y][z]++;
            adj[z][y]++;
        }
        else if(x == 2){
            cin>>y>>z;
            adj[y][z]--;
            adj[z][y]--;
        }
        else{
            // process
            int res = 1;
            bool flag = 0;
            for(int i = 1; i < n; i++){
                // for(auto itr = adj[i].begin(); itr != adj[i].end(); ++itr){
                //     if( !(itr->second) ) continue; // not a friend rn
                //     if(itr->first > i) {
                //         flag = 1;
                //         break;
                //     }
                // }
                auto itr = adj[i].begin();
                while(!(itr->second) && (itr != adj[i].end())) ++itr; // no friends :(
                if( (itr == adj[i].end()) || i > itr->first) res++;   // if i am bigger than my biggest friend
                // if(!flag) res++;
                // flag = 0; 
            }
            cout << res << "\n";
        }
    }
    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);    
    int test_cases = 1;
    // cin>>test_cases;
    while (test_cases--){
        solve();
    }
    return 0;   
}
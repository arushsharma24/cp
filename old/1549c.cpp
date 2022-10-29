#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007

void solve(){
    int n, m; cin>>n>>m;
    vector<vector<int>> adj(n+1);
    for(int i = 0; i < m; i++){
        int u, v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int q; cin>>q;
    int x, y, z;
    while(q--){
        cin>>x;
        if(x == 1){
            cin>>y>>z;
            adj[y].push_back(z);
            adj[z].push_back(y);
        }
        else if(x == 2){
            cin>>y>>z;
            adj[y].erase(find(adj[y].begin(), adj[y].end(), z));
            adj[z].erase(find(adj[z].begin(), adj[z].end(), y));
        }
        else{
            // process
            int res = 1;
            bool flag = 0;
            for(int i = 1; i < n; i++){
                for(int f : adj[i]){
                    if(f > i) {
                        flag = 1;
                        break;
                    }
                }
                if(!flag) res++;
                flag = 0; 
            }
            cout << res << "\n";
        }
    }
    return;
}

void soln(){
    int n, m; cin>>n>>m;
    // vector<vector<int>> adj(n+1);    using adjacency matrix will be not very optimal cuz of time issues.
    int fri[n+1];   // number of stronger friends, basically those who can kill this friend
    memset(fri, 0, sizeof(fri));    // initialize all to 0
    set<int> die;   // set of people who will definitely die
    for(int i = 0; i < m; i++){
        int u, v; cin>>u>>v;
        // adj[u].push_back(v);
        // adj[v].push_back(u);
        if(u > v) swap(u, v);   // take smaller element for simplicity
        die.insert(u);  // add smaller element to the to die list since this bigger guy will be responsibe for the smaller one's death
        fri[u]++;   // ++ number of killer friends. some friends lol
    }
    int q; cin>>q;
    int x, y, z;
    while(q--){
        cin>>x;
        if(x == 1){
            cin>>y>>z;
            // adj[y].push_back(z);
            // adj[z].push_back(y);
            if(y > z) swap(y, z);
            die.insert(y);  // same as initial inserts of 'friends'
            fri[y]++;
        }
        else if(x == 2){
            cin>>y>>z;
            if(y > z) swap(y, z);
            if(fri[y] == 1) die.erase(y); // if the guy only had one friendship, it was this one that is being broken, which means he ain't dying no mo
            fri[y]--;   // -- number of killer friends.
        }
        else{
            // process
            cout << n - die.size() << "\n"; // straightforward
        }
    }
    return;
}

            /*
            int res[n+1];
            memset(res, 0 , sizeof(res));
            for(int i = n; i >= 1; i--){
                // if(res[i] < 0) {
                //    continue; // omae wa mou shindeiru
                // }// Nani!!
                // strongest guy kills all his friends
                for(int f : adj[i]){
                    if(f < i) res[f] = -1; // killing
                }
            }
            int ans = 0;
            for(int i = 1; i <=  n; i++){
                if(res[i] == 0) ans++;
            }
            cout << ans << "\n";
            */

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);    
    int test_cases = 1;
    // cin>>test_cases;
    while (test_cases--){
        soln();
    }
    return 0;   
}
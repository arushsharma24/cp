#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007

void bfs(vector<vector<ll>> adj, int n, vector<ll> dist, vector<ll> &paths){
    vector<bool> visited(n+1, false);
    queue<int> q;
    dist[1] = 0;
    q.push(1);
    paths[1] = 1;
    visited[1] = true;
    while(!q.empty()){
        int now = q.front();
        q.pop();
        for(auto x : adj[now]){
            if(!visited[x]){
                q.push(x);
                visited[x] = true;
            }   // yahan tak toh normal bfs hai
            if(dist[x] > dist[now] + 1){
                dist[x] = dist[now] + 1;
                paths[x] = paths[now];
            }   // if the distance till a path is not the shortest yet
            else if(dist[x] == dist[now] + 1){
                paths[x] += paths[now]; // if the distance till a path is the shortest, then add all it's paths to the old paths
                paths[x] %= M;
            }
            // bc paths paths itne to Isayama ne bhi ni kare they xD
        }
    }
}

void solve(){
    int n, m; cin>>n>>m;
    vector<vector<ll>> adj(n+1);
    for(int i = 0; i < m; i++){
        int a, b; cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<ll> dist(n+1, INT_MAX);
    vector<ll> path(n+1, 0);    // to store the number of shortest paths 
    bfs(adj, n, dist, path);
    cout<<path[n]<<"\n";
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
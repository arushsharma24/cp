#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007

void addEdge(vector<int> edges[], int u, int v){
    edges[u].push_back(v);
    edges[v].push_back(u);
}

void solve(){
    int n, q; cin>>n>>q;
    vector<int> edges[n];
    for(int i = 0; i < n-1; i++){
        int u,v; cin>>u>>v;
        addEdge(edges, --u, --v);
    }
    // i should make the visited wala thingy only once
    vector<bool> done(n, 0);
    vector<int> dist(n, 0);
    queue<int> Q;
    dist[0] = 0;
    done[0] = true;
    Q.push(0);
    while (!Q.empty())
    {
        int town = Q.front();
        Q.pop();
        int nt = edges[town].size();
        for(int i = 0; i < nt; i++){
            if(done[edges[town][i]]) continue;
            done[edges[town][i]] = true;
            dist[edges[town][i]] = dist[town] + 1;
            Q.push(edges[town][i]);
        }
    }
    for(int i = 0; i < q; i++){
        int u, v; cin>>u>>v;
        int d1 = dist[--u];
        int d2 = dist[--v];
        int d = d2 > d1 ? d2 - d1 : d1 - d2;
        if(d%2) cout<<"Road\n";
        else cout<<"Town\n";
    }
    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);    
    int test_cases = 1;
    //cin>>test_cases;
    while (test_cases--){
        solve();
    }
    return 0;   
}
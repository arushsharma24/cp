#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007

void trav(int prev, int curr, vector<bool> &vis, vector<vector<int>> &roads, bool &stop, vector<int> &parent){
    if(stop) return;
    cout << curr << " ";
    if(!vis[curr]) parent[curr] = prev;
    vis[curr] = 1;
    vector<int> temp;
    for(int city : roads[curr]){
        if(vis[city]) continue;
        temp.push_back(city);
    }
    if(temp.size()){
        int smallest = *min_element(temp.begin(), temp.end());
        trav(curr, smallest, vis, roads, stop, parent);
    }
    else{
        if(curr == 1){
            stop = 1;
        }
        else{
            trav(curr, parent[curr], vis, roads, stop, parent);
        }
    }
    return; 
}
// ugh, this one gave tle


// okayy, so it looks somewhat like doing a preorderish traversal of a graph except whenever we step back up we also print that node again.
// i called it preorderGraphTraversal at first, but that seems kinda boring, so I wanna call it noice 
// i hope it actually is nice and passes lol
void noiceGraphTraversal(int curr, vector<bool> &vis, vector<vector<int>> &roads){
    cout << curr << " ";
    vis[curr] = 1;
    vector<int> unv;
    for(int city : roads[curr]){
        if(vis[city]) continue;
        unv.push_back(city);
    }
    sort(unv.begin(), unv.end());
    for(int city : unv){
        noiceGraphTraversal(city, vis, roads);
        cout << curr << " ";    // pring this node again
    }
    return;
}

void solve(){
    int n; cin>>n;
    vector<vector<int>> roads(n+1);
    int a, b;
    for(int i = 1; i < n; i++){
        cin>>a>>b;
        roads[a].push_back(b);
        roads[b].push_back(a);
    }
    bool stop = 0;
    vector<bool> vis(n+1, 0);
    noiceGraphTraversal(1, vis, roads);
    cout << "\n";
    return;
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);    
    int test_cases = 1;
    while (test_cases--){
        solve();
    }
    return 0;   
}
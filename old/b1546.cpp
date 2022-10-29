#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    int n,m; cin>>n>>m;
    vector<string> ini(n);
    vector<string> fin(n);  
    int i, j, k;
    string res;
    for(i = 0; i < n; i++){
        cin>>ini[i];
    }    
    for(i = 0; i < n-1; i++){
        cin>>fin[i];
    }
    for(i = 0; i < m; i++){
        unordered_map<char, int> m;
        for(j = 0; j < n; j++){
            m[ini[j][i]]++;
        }
        for(j = 0; j < n-1; j++){
            m[fin[j][i]]--;
        }
        for(auto it : m){
            if(it.second == 1){
                res.push_back(it.first);
            }
        }
    }
    cout<<res<<endl;

    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);    
    int test_cases = 1;
    cin>>test_cases;
    while (test_cases--){
        solve();
    }
    return 0;   
}
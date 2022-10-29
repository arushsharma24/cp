#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    vector<string> s;
    unordered_map<string, int> m;
    m["H"] = 0;
    m["2B"] = 0;
    m["3B"] = 0;
    m["HR"] = 0;
    for(int i = 0; i < 4; i++){
        string x; cin>>x;
        if(m.find(x) != m.end()){
            m[x]++;
        }
    }
    int found  = 0;
    for(auto it = m.begin(); it != m.end(); ++it){
        if(it->second < 1){
            cout<<"No\n";
            found  = 1;
            break;
        }
    }
    if(!found) cout<<"Yes\n";
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
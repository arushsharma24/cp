#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007

void FAST(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

void OJ(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
}

bool done(unordered_map<int, int> m){
    bool ans = 1;
    for(auto u : m){
        if(!ans) break;
        else{
            if(u.second > 1){
                ans = 0;
                continue;
            }
        }
    }
    return ans;
}

void solve(){
    int n; cin>>n;
    vector<int> v(n);
    unordered_map<int, int> dis;
    for(int i = 0; i < n; i++) {
        cin>>v[i];
        dis[v[i]]++;
    }
    int ct = 0;
    int left = 0, right = 0;
    
    return;
}

int main(){
    FAST();
    OJ();
    int test_cases = 1;
    cin>>test_cases;
    while (test_cases--){
        solve();
    }
    return 0;   
}
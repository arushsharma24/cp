#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    int n, k; cin>>n>>k;
    vector<int> c(n);
    for(int i = 0; i < n; i++) cin>>c[i];
    vector<int> sc(n-k+1);
    unordered_map<int, int> m;
    for(int i = 0; i < k; i++){
        m[c[i]]++;
    }
    sc[0] = m.size();
    for(int i = 1; i < n-k+1; i++){
        sc[i] = sc[i-1];
        m[c[i-1]]--;
        if(m[c[i-1]] == 0){
            sc[i]--;
        }
        if(m.find(c[i+k-1]) == m.end()){
            sc[i]++;
        }
        else if(m[c[i+k-1]] == 0){
            sc[i]++;
        }
        m[c[i+k-1]]++;
    }
    int res = INT_MIN;
    for(auto it : sc){
        //cout<<it<<" ";
        if( it > res ){
            res = it;
        }
    }
    cout<<res<<"\n";
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
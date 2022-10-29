#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    int n; cin>>n;
    string s; cin>>s;
    string sx = s;
    sort(sx.begin(), sx.end());
    int ans = 0;
    for(int i = 0; i < n; i++){
        if(s[i] != sx[i])   ans++;
    }
    cout<<ans<<"\n";
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
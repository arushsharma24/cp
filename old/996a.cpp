#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    int n; cin>>n;
    int ans = 0;
        ans += n/100;    
        n -= 100*(n/100);
        ans += n/20;
        n -= 20*(n/20);
        ans+=n/10;
        n-=10*(n/10);
        ans += n/5;
        n-=5*(n/5);
    ans += n;
    cout<<ans<<"\n";
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
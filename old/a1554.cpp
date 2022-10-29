#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007

void solve(){
    int n; cin>>n;
    ll a[n];
    for(int i = 0; i < n; i++) cin>>a[i];
    ll ans = a[0] * a[1];
    ll tmp;
    for(int i = 1; i < n-1; i++){
        ans = max(ans, a[i] * a[i+1]);
    }
    cout << ans << "\n";
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
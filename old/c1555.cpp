#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007

void solve(){
    ll m; cin>>m;
    ll a[2][m];
    for(ll j = 0; j < 2; j++){
        for(ll i = 0; i < m; i++){
            cin>>a[j][i];
        }
    }
    ll dp[m];
    memset(dp, 0, sizeof(dp));
    dp[0] = a[0][0];
    for(ll i = 0; i < m; i++){
        dp[0] += a[1][i];
    }
    ll vans = dp[0];
    ll ans = 0;
    for(ll idx = 1; idx < m; idx++){
        dp[idx] = dp[idx-1] + a[0][idx] - a[1][idx-1];
        if(dp[idx] > vans){
            ans = idx;
            vans = dp[idx];
        }
    }
    ll one = 0;
    for(ll i = ans + 1; i < m; i++){
        one += a[0][i];
    }
    ll two = 0;
    for(ll i = 0; i < ans; i++){
        two += a[1][i];
    }
    cout << min(one, two) << "\n";
    return;
}

void solve2(){
    ll m; cin>>m;
    ll a[2][m];
    for(ll j = 0; j < 2; j++){
        for(ll i = 0; i < m; i++){
            cin>>a[j][i];
        }
    }
    ll bob[2][m];  // 0 is upar wala road, 1 is neeche wala road, for alice crossing over at ith index
    memset(bob, 0, sizeof(bob));
    for(ll i = 1; i < m; i++){
        bob[0][0] += a[0][i];
    }
    bob[1][0] = 0;
    ll bmax = bob[0][0];
    ll bmin = bmax;
    for(ll i = 1; i < m; i++){
        bob[0][i] = bob[0][i-1] - a[0][i];
        bob[1][i] = bob[1][i-1] + a[1][i-1];
        bmax = max(bob[0][i], bob[1][i]);
        bmin = bmax < bmin ? bmax : bmin ;
    }
    cout << bmin << "\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);    
    int test_cases = 1;
    cin>>test_cases;
    while (test_cases--){
        solve2();
    }
    return 0;   
}
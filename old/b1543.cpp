#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll n; cin>>n;
    vector<ll> a(n);
    ll sum = 0;
    for (ll i = 0; i < n; i++)
    {
        cin>>a[i];
        sum += a[i];
    }
    if(sum%n == 0){
        cout<<"0\n";
        return;
    }
    ll avg = sum/n;
    ll dev = 0;
    for (ll i = 0; i < n; i++)
    {
        dev += a[i] - avg;
    }
    // now, dev should be less than n, nahi toh wo divide ho hi jaata ig
    cout<<dev*(n-dev)<<"\n";
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
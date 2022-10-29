#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll n, k; cin>>n>>k;
    map<ll, ll>m;
    for(ll i = 1; i <= n; i++){
        ll x; cin>>x;
        m[x] = i;
    }
    // output for each citizen
    // now, each citizen has some sweets, and some citizens have one more
    // we just have to find the first k' and give one more to them
    ll k2 = k/n;
    ll base = k2;
    k2 *= n;
    k -= k2;
    // now k is the k'
    int count = 0;
    vector<bool> c(n+1, 0);
    for(auto it = m.begin(); it != m.end(); ++it){
        if(count >= k) break;
        c[it->second] = 1;
        count++;
    }
    for(int i = 1; i <= n; i++){
        if(c[i] == 0)
            cout<<base<<"\n";
        else
            cout<<base+1<<"\n";
    }

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
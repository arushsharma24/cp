#include <bits/stdc++.h>
using namespace std;
#define ll long long

void OJ(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
}

void useMedian(){
    int n; cin>>n;
    vector<ll> p(n);
    for(int i = 0; i < n; i++){
        cin>>p[i];
    }
    sort(p.begin(), p.end());
    ll x = p[n/2];
    ll ans = 0;
    for(int i = 0; i < n; i++){
        ans += abs(p[i] - x);
    }
    cout<<ans<<"\n";
}

void useMean(){
    int n; cin>>n;
    vector<ll> p(n);
    // normalize
    unsigned ll sum = 0;
    for(int i = 0; i < n; i++) {
        cin>>p[i];
        sum += p[i];
    }
    ll mn = *min_element(p.begin(), p.end());
    for(ll i = 0; i < n; i++){
        p[i] -= mn;
    }
    ll mean = sum/n;
    ll ans = 0;
    ll a2 = 0;
    ll a3 = 0;
    ll a4 = 0, a5 = 0;
    for(int i = 0; i < n; i++){
        ans += abs(mean - 2 - p[i]);
        a2 += abs(mean - 1 - p[i]);
        a3 += abs(mean - p[i]);
        a4 += abs(mean + 1 - p[i]);
        a5 += abs(mean + 2 - p[i]);
    }
    ans = min(ans, a2);
    ans = min(ans, a3);
    ans = min(ans, a4);
    ans = min(ans, a5);
    cout << ans + mn << "\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);    
    OJ();
    int test_cases = 1;
    //cin>>test_cases;
    while (test_cases--){
        useMedian();
    }
    return 0;   
}
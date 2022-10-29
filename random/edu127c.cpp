#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
#define yes cout << "YES\n"
#define no cout << "NO\n"

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

void solve(){
    ll n,x; cin>>n>>x;
    vector<ll> a(n);
    for(ll i  = 0; i < n; i++) cin>>a[i];
    sort(a.begin(), a.end());
    ll ans = 0;
    ll today;
    ll tx;
    do{
        today = 0;
        tx = x;
        for(ll i = 0; i < n; i++){
            if(a[i] <= tx){
                tx -= a[i];
                today++;
                a[i]++;
            }
            else break;
        }
        ans += today;
    } while(today > 0);
    cout << ans << "\n";
}

void solve2(){
    ll n,x; cin>>n>>x;
    vector<ll> a(n);
    for(ll i  = 0; i < n; i++) cin>>a[i];
    sort(a.begin(), a.end());
    vector<ll> asum(n);
    asum[0] = 0;
    for(ll i = 1; i  < n; i++) asum[i] = a[i] + asum[i-1];
    ll ans = 0;
}

/*

cheapest item will be bought till it's price == x
so, this will be bought for (x-price+1) days
ith item will be bought till (price[i] - (sum of prices till price[i-1] + (i-1)*days)) == x
(for which we can maintain a prefix sum array)

*/

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


/*


*/
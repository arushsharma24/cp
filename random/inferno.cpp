#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
#define M2 998244353
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

ll powM(ll x, ll y, ll m) {	//returns (a^b)%m ( ^ is exponent )
	ll ans = 1, r = 1;
	x %= m;
	while (r > 0 && r <= y)
	{
		if (r & y)
		{
			ans *= x;
			ans %= m;
		}
		r <<= 1;
		x *= x;
		x %= m;
	}
	return ans;
}

void solve(){
    ll n,x; cin>>n>>x;
    vector<ll> h(n);
    for(int i = 0; i < n ; i++) cin>>h[i];
    sort(h.begin(), h.end());
    ll single = 0;
    ll multi = h[n-1];
    for(int i = 0; i < n; i++){
        if(h[i] <= x){
            single++;
        }
        else{
            single += h[i]/x;
            if(h[i]%x != 0) single++;
        }
    }
    cout << min(single, multi) << "\n";
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


/*


*/
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
    ll n, m, x;
    cin>>n>>m>>x;
    if(x >= m){
        cout << "0\n";
        return;
    }
    else{
        if(n/(x+1) == 0){
            cout << n-1 << "\n";
        }
        else if(n%(x+1) == 0){
            cout << n - (n/(x+1)) << "\n";
        }
        else cout << n - (1 + n/(x+1)) << "\n";
    }
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
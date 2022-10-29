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
    // for diags, add distance from each vertex
    // for horizontal, it is always 2*n - 2
    int n,x,y;
    cin>>n>>x>>y;
    int sum = 2*n - 2;
    // top right
    // distance from top = x - 1
    // distance from left = y - 1
    // distance from right = n - y
    // distanc from bottom = n - x
    sum += min(x - 1, n - y); 
    sum += min(x-1, y-1);
    sum += min(n-x, y-1);
    sum += min(n-x, n-y);
    cout << sum << "\n";
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
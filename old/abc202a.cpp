#include <bits/stdc++.h>
using namespace std;


/********************************************************************/
#define M1 1000000007	//Standard primes used in modulo operations
#define M2 998244353
#define ll long long
#define pll pair<ll,ll>
#define REP(i, a, b) for(ll i=a;i<b;i++)
#define REPR(i, a, b) for(ll i=b-1;i>=a;i--)
#define forr(i, n) for(ll i=0;i<n;i++)
#define ff first
#define ss second
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define MT make_tuple
#define V(a) vector<a>
#define vi vector<ll>
#define endl '\n'
#define ce(ele) cout<<ele<<' '
#define cs(ele) cout<<ele<<'\n'
#define CASE(t) ll t; cin>>t; while(t--)
#define space ' '
#define yes cout<<"Yes"<<endl
#define no cout<<"No"<<endl

void FAST() {	//FAST Input Output, DONT use both scnaf,printf / cin,cout , Use any ONE system
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
ll gcd(ll x, ll y) {	//returns gcd of two long long ints
	if (x == 0) return y;
	return gcd(y % x, x);
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

map<long long, long long> factorize(long long n) {	//returns map containing factor and multiplicity, Eg: 60 = {{2,2},{3,1},{5,1}}
	map<long long, long long> ans;
	for (long long i = 2; i * i <= n; i++) {
		while (n % i == 0) {
			ans[i]++;
			n /= i;
		}
	}
	if (n > 1) {
		ans[n]++;
		n = 1;
	}
	return ans;
}
/* **********END OF TEMPLATE*********** */

int main() {
	int n; cin>>n;
	int a[3][n];
	for(int i = 0; i < 3; i++){
		for(int j = 0; j<n; j++){
			int x; cin>>x;
			a[i][j] = x;
		}
	}		
	int res = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j<n; j++){
			if(a[0][i] == a[1][a[2][j] - 1]){
				res++;
			}
		}
	}
	cout<<res<<endl;

	return 0;
}
	/*
	for(int i = 1; i <= n; i++){
		cout<<"okA";
		for(int j = 1; i <= n; j++){
			cout<<"okB";
			if(a[i] == b[c[j]]){
				res++;
				cout<<res<<"ok";
			}
		}
	}
	*/
	//int a[n+1][, b[n+1], c[n+1]];
	/*
	for(int i = 1; i <= n; i++){
		int x; cin>>x;
		a[i] = x;
		cout<<"a"<<a[i];
	}
	for(int i = 1; i <= n; i++){
		int x; cin>>x;
		b[i] = x;
		cout<<"b"<<b[i];
	}
	for(int i = 1; i <= n; i++){
		int x; cin>>x;
		c[i] = x;
		cout<<"c"<<c[i];
	}
	*/
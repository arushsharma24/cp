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
int N = 100000;
vector<int> dp(N); // number of good formulae for some n
void pre(){
    // number of +'s at any stage = dp[i-1];
    dp[0] = 1;
    dp[1] = 2;
    for(int i = 2; i < N; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
}
int main() {
	FAST();
    pre();
    int n; cin>>n;
    // now i know the number of good formulae for n
    // however, i need the sum of it's elements.
    int pre,suf;
    ll temp;
    unsigned long long sum = 0;
    for(int i = 0; i < n; i++){
        int x; cin>>x;
        if(i == 0){
            sum = x*dp[n-1];
            cout<<sum<<" ";
        }
        else{
            pre = i - 1;
            suf = n - 1 - i;
            // times when this is +ve
            temp = (dp[pre]*dp[suf]);
            // times when this is -ve
            cout<<"after we add "<<(dp[pre]*dp[suf])<<" times and subtract ";
            if(pre>=1&&suf>=1) {
                temp-= (dp[pre-1]*dp[suf-1]);
                cout<<dp[pre-1]*dp[suf-1]<<" ";
            }
            if(pre == 0 && suf != 0) {
                temp-= (dp[suf-1]);
                cout<<dp[suf-1]<<" ";
            }
            if(suf == 0 && pre != 0) {
                temp-= (dp[pre-1]);
                cout<<dp[pre-1]<<" ";
            }
            sum += x*temp;
            cout<<sum<<"\n";
        }
    }
    ll res = powM(sum,1,M1);
    cout<<res<<"\n";
	return 0;
}
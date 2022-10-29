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
	FAST();
	CASE(t) {
        int n,m;
        cin>>n>>m;
        ll res = 0;
        //going casewise
        //case1
        // m < a
        // all satisfy
        // so all [1,n-1] > m
        if(n>m){//basic check
            res += (n-m)*(n-m-1)/2;
        }
        // case 2 
        // a < m < b
        // for this also all satisfy (both sides equal m mod a)
        if(n>m&&m>1){//again, just checking if it is possible at all, or not
            // so a from 2 to m;
            res += (m-2)*(n-m);
        }
        // case 3
        // a < b < m
        if(n>=m){
            for(int i = 1; i < m-1; i++){
                for(int j = i+1; j < m; j++){
                    if(m%i == (m%j)%i){
                        res++;
                        cout<<i<<" "<<j<<"\n";
                    }
                }
            }
        }
        else{
            for(int i = 1; i < n; i++){
                for(int j = i+1; j <= n; j++){
                    if(m%i == (m%j)%i){
                        res++;
                        cout<<i<<" "<<j<<"\n";
                    }
                }
            }            
        }
        // case 4
        // m = a
        // all cases
        if(n>m){
            res += n-m;
        }
        cout<<res<<"\n";
        
        // case 5
        // m = b
        // no pair
    }
	return 0;
}
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
/*
int main() {
	FAST();
	int n,k; cin>>n>>k;
    string s; cin>>s;
    string res(k, 'z');
	// a final result made which is lexicographically greatest
	// now, we'll try to find the lexicographically smallest string
	// using the string in a way as is given to us
	for(int i = 1; i <= n; i++){
		string sub = s.substr(0, i);
		string ash;// the string we will be trying
		while(ash.length() < k){
			ash += sub;
		}
		while(ash.length() > k){
			ash.pop_back();
		}
		// now my ash string has been made using only the given conditions, and now, we have to keep moving like this
		// and find the smallest such lexicographically shortest string
		if(ash<res){
			res = ash;
		}
	} 
	cout<<res<<"\n";
    /*
    int here = n;
    for(int i = n - 1; i > 0; i--){
        string s1 = s.substr(0,i);
        s1 += s;
        s1 = s1.substr(0,n);
        if(s1<s){
            here = i;
        }
    }
    */
/*
	return 0;
}
*/


int main(){
	FAST();
	int n,k; cin>>n>>k;
	string s; cin>>s;
	string min(k,'z');
	for(int i = 1; i <= n; i++){
		string a;
		string sub = s.substr(0,i);
		while(a.length()<k){
			a += sub;
		}
		while(a.length()>k){
			a.pop_back();
		}
		//now this string a is a possible string 
		// i need to find the smallest such string lexicographically
		if(a<min){
			min = a;
		}
	}
	cout<<min<<"\n";
	return 0;
}
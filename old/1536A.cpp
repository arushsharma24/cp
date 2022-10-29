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
vector<int> a;

bool exists(int x){
	for(int i = 0; i < a.size(); i++){
		if(a[i] == x) return 1;
	}
	return 0;
}

void checknice(int index){
	for(int i = 0; i < a.size(); i++){
		if(i != index){
			if(!exists(abs(a[i] - a[index]))){
				a.push_back(abs(a[i]-a[index]));
				checknice(a.size()-1);
			}
		}
	}
}

int main() {
	FAST();
	CASE(t) {
		//cout<<"hello";
		a.clear();
		int n; cin>>n;
		int amin = 100;
		int amax = -100;
		int fuckNo = 0;
		vector<int> diffs(n*(n-1)/2);
		for(int i = 0; i < n; i++){
			int x; cin>>x;
			//cout<<"x: "<<x;
			a.push_back(x);
			if(x>amax) amax = x;
			if(x<amin) amin = x;
		}
		if(abs(amax - amin)<=amax){
			for(int i = 0; i < a.size(); i++){
				if(a.size()<=300){
					checknice(i);
				}
				else{
					fuckNo = 1;
				}
			}
			if(!fuckNo){
				cout<<"YES\n";
				cout<<a.size()<<"\n";
				for(int i = 0; i < a.size(); i++){
					cout<<a[i]<<" ";
				}
				cout<<"\n";
			}
			else{
				cout<<"NO\n";
			}
		}
		else{
			cout<<"NO\n";
		}
		/*
		if(abs(amax-amin)>amax)
			cout<<"NO\n";
		else{
			cout<<"YES\n";
			for(int i = 0; i < n; i++){
				for(int j = i+1; j < n; j++){
					if(!exists(a,abs(a[i]-a[j]))){
						a.push_back(abs(a[i]-a[j]));
					}
				}
			}
		}
		*/
	}

	return 0;
}
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

int removeBiggest11(int num){
    int digs = log10(num) + 1;
    int var11 = (pow(10,digs) - 1)/9;
    int var11low = (pow(10,digs-1) - 1)/9;
    if(num >= var11){
        num -= var11;
        return num;
    }
    else{
        num -= var11low;
        return num;
    }
}

bool checkMultiple(int num){
    int digs = log10(num) + 1;
    for(int i = 2; i <= digs; i++){
        int var11 = (pow(10,i)-1)/9;
        if(num%var11 == 0){
            return 1;
        }
    }
    return 0;
}

int solve(int x){
    if(!checkMultiple(x)){
        if(x < 11){
            return x;
        }
        else{
            return solve(removeBiggest11(x));
        }
    }
    else return 0;
}

int main() {
	FAST();
	CASE(t) {
        //approach #1
        // keep subtracting largest multiple of 111...1 from it till you get a number < 11, and if it is 0; it is okay
        // umm but not sure if this will work since ... getting wrong answer on pretest 2, but umm, kya problem hai isme
        int n; cin>>n;
        if(solve(n) != 0){
            cout<<"NO\n";
        }
        else cout<<"YES\n";
        




       // approach #2
       // slightly more mathematical
       // check all combinations ai = 1 ... 10 and permute each of these with each i from i = 2 ... (log10(num) + 1)
       // a fixed number of tests per number, complexity is log(num) lol idk if this will even work
       //int n; cin>>n;
       //int nineN = n*9;
       //for(int i = 2; i <= log10(nineN) + 1; i++){
       //    for(int i = )
       //}
       // ditched
	}

	return 0;
}
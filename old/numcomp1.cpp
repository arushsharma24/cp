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
vector<bool> prime(10000001, true);
vector<int> numberOfPrimes;

void primeCalc(){
    for(int p = 2; p*p<=10000001; p++){
        if(prime[p] == true){
            for(int i = p*p; i<=10000001; i+=p){
                prime[i] = false;
            }
        }
    }
}

void thisManyPrimes(){
    int count = 0;
    numberOfPrimes.push_back(count);
    numberOfPrimes.push_back(count);
    for(int i = 2; i<=10000001; i++){
        if(prime[i]) count++;
        numberOfPrimes.push_back(count);
    }
}


int main() {
	FAST();
    //cout<<"ok\n";
    primeCalc();
    thisManyPrimes();
    //cout<<"here"<<prime[37]<<prime[49]<<"\n";
	CASE(t) {
        int n; cin>>n;
        if(n>4){
            //bool primes[n+1];
            //memset(primes, true, sizeof(primes));
            //primeCalc(primes, n);//now our primes array has true value for primes
            // now, let the smallest prime p be such that p*2 > n;
            // then the number of sets is equal to the number of primes from p to n, + 1;
            int temp = n/2;
            int num = numberOfPrimes[n] - numberOfPrimes[temp];
            cout<<1+num<<"\n";
            // NOICE, this was super fast, N = 10000000 AC in 0.14; yay
            /*  gave tle on subtask 2
            int smallestP;
            for(int i = 2; i <= n; i++){
                if(prime[i]){
                    if(i*2 > n) {
                        smallestP = i;
                        break;
                    }
                }
            }
            //cout<<smallestP<<"and here\n";
            int biggerPs = 0;
            for(int i = smallestP; i <= n; i++){
                if(prime[i]) biggerPs++;
            }
            cout<<1+biggerPs<<"\n";
            */
        }
        else if(n == 2){
            cout<<1<<"\n";
        }
        else if(n == 3|| n == 4){
            cout<<2<<"\n";
        }
	}

	return 0;
}
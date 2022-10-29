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
#define vi vector<int>
#define vll vector<ll>
#define vvi vector<vector<int>>
#define vvll vector<vector<ll>>
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl

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
// chill bro
int main() {
	FAST();
	int test_cases = 1;
    cin>>test_cases;
    while(test_cases--){
        // solve test cases here
		ll n; cin>>n;
        ll x;
        vector<int> a(2*n+1, -1);
        //vector<int> a(1e5, 0);
        for(int i = 1; i <= n; i++){
            cin>>x;
			a[x] = i;
        }
        ll count = 0;

		// now, the sum can range from 3 to 2*n-1
		// for each value, we need to find if such values exist in the array
		// and firstly we find it's factors

		for(ll sum = 3; sum < 2*n; sum++){
			// for each value, find a divisor y, 
			// and check if sum/y exists 
			for(ll y = 1; y*y <= sum; y++){
				if(sum%y == 0 && y*y != sum && a[y] != -1 && a[sum/y] != -1 && a[y] + a[sum/y] == sum){
					//cout<<a[y]<<" "<<a[sum/y]<<"\n";
					//cout<<y<<" "<<sum/y<<"\n";
					count++;
				}
			}
		}

        cout<<count<<"\n";
	}

	return 0;
}
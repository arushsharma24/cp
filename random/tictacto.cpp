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
// int a[1001][1001] = {0};

int main() {
	FAST();
	int test_cases = 1;
    cin>>test_cases;
    while(test_cases--){
        // solve test cases here
        ll n,m,k; cin>>n>>m>>k;
		int moves[n*m][2];
    	//vector<pair<int,int>> v;
        for(int i = 0; i < n*m; i++){
            int x,y; cin>>x>>y;

			moves[i][0] = x;
			moves[i][1] = y;
			/*
			if(i%2==0){
				a[x][y] = 1;
			}
			else{
				a[x][y] = -1;
			}
			*/
			// check horizontal
			// hmm no idea
            // v.push_back({x,y});
        }
		ll count = 0;
		bool found = 0;

		int low = 0, high = n*m - 1, ans = n*m;
		while(low<=high){
			int mid = low + (high-low)/2;
			int a[n+1][m+1];
			
			for(int i = 0; i <=n; i++){
				for(int j = 0; j <= m; j++)
					a[i][j] = 0;
			}
			
			// now make array uptil these mid number of moves

			for(int i = 0; i < mid; i++){
				if(i%2==0)
					a[moves[i][0]][moves[i][1]] = 1;
				else
					a[moves[i][0]][moves[i][1]] = -1;
			}

			// now, to prefix the sums
			for(int i = 1; i <=n; i++){
				for(int j = 1; j <= m; j++){
					a[i][j] = a[i][j] + a[i-k][j] + a[i][j-k] - a[i-k][j-k];
					if(abs(a[i][j]) == k*k)
						found = 1;
				}
			}

			if (found){
				ans = mid;
				high = mid - 1;
			}
			else
				low = mid + 1;
			
			if(ans == n*m)
				cout<<"Draw\n";
			else if(ans % 2 == 0){
				cout<<"Alice\n";
			}
			else{
				cout<<"Bob\n";
			}
		}
    }

	return 0;
}
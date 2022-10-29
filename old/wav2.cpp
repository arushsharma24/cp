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
    //cin>>test_cases;
    while(test_cases--){
        // solve test cases here
        int n,q; cin>>n>>q;
        vector<int>r;
        for(int i = 0; i < n; i++){
            int x; cin>>x;
            r.push_back(x);
        }
        sort(r.begin(), r.end());
        for(int i = 0; i < q; i++){
            int x; cin>>x;
            if(x>r[n-1]){
                cout<<"POSITIVE\n";
            }
            else if(x<r[0]){
                if(n%2==0){
                    cout<<"POSITIVE\n";
                }
                else{
                    cout<<"NEGATIVE\n";
                }
            }
            else{
                int found = 0;
                /*
                for(int j = 0; j < r.size(); j++){
                    if(x==r[j]){
                        cout<<"0\n";
                        found = 1;
                        break;
                    }
                }
                */
                //now, it is neither a root, nor at end or start
                //int cross = n;
                for(int j = n-1; j >= 0; j--){
                    //if(x<r[j]){
                    //    cross++;
                    //}
                    if(x>r[j]){
                        int cross = n - 1 - j;
                        if(cross%2==0){
                            cout<<"POSITIVE\n"; 
                            found = 1;
                            break;
                        }
                        else{
                            cout<<"NEGATIVE\n";
                            found = 1;
                            break;
                        }
                    }
                    else if(x == r[j]){
                        cout<<"0\n";
                        found = 1;
                        break;
                    }
                }
                //if(found) break;
            }
        }
    }

	return 0;
}
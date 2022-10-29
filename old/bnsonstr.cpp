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
        int n; cin>>n;
        string s; cin>>s;
        string ss = s + s;
        int ones = 0;
        for(int i = 0; i < n; i++){
            if(s[i] == '1')
                ones++;
        }    
        if(ones == 0){
            cout<<1<<"\n";
            continue;
        }
        else{
            int min = n+1;
            vector<int> distances;
            int od = 0, ed = 0;
            for(int i = 0; i < n; i++){
                int start = 0;
                int end = 0;
                int dis;
                if(ss[i] == '1'){
                    start = i;
                    i++;
                    while(s[i] == '0'){
                        i++;
                    }
                    end = i;
                    dis = end - start - 1;
                    if(dis%2==0) ed++;
                    else od++;
                    distances.push_back(dis);
                }
                if(dis<min){
                    min = dis;
                }
                i--;
            }
            // now min i the minimum distance;
            if(min == 0){
                cout<<n-ones<<"\n";
            }
            // the rest we gotta calc somehow
            else{
                sort(distances.begin(), distances.end());
                if(min%2 == 0){

                }
            }
        }
    }

	return 0;
}
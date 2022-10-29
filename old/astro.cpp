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
ll las = 0;

void lased(int M){
    if(M<=1){
        return;
    }
    las++;
    //cout<<las<<"yo "<<M<<" ohk ";
    int m = sqrt(M);
    for(int i = 0; i < m; i++){
        lased(m);
    }
}
//ll res = 1;
//ll mul = 1;
int sqDesc(int m){
    if(m == 1){
        return 0;
    }
    int x = sqrt(m);
    if(x==1){
        return 1;
    }
    return 1+x*sqDesc(x);
}

int main() {
	FAST();
	int t = 1;
    ///cin>>t;
    while(t--){
        int n,k; cin>>n>>k;
        vector<int>a;

        ll res = 0;
        for(int i = 0; i < n; i++){
            int x; cin>>x;
            a.push_back(x);
        }
        sort(a.begin(), a.end());
//        map<ll,ll> mok;
        // for(int i = 0; i < n; i++){
        //     las = 0;
        //     lased(a[i]);
        //     mok[a[i]] = las;
        // }
        if(k<n){
            res += k;
            // now only laser wale remain
            for(int i = 0; i < a.size()-k; i++){
                //las = 0;
                //lased(a[i]);
                //cout<<las<<" ";
                res += sqDesc(a[i]);
            }
            cout<<res%M1<<"\n";
        }
        else{
            cout<<n%M1<<endl;
        }
    }

	return 0;
}
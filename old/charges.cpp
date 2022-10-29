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
int calcDist(string s){
    int res = 0;
    for(int i = 0; i < s.length()-1; i++){
        char c = s[i];
        char cn = s[i+1];
        if(c == cn){
            res += 2;
        }
        else res++;
    }
    return res;
}

int sames(string s){
    int res = 0;
    for(int i = 0; i < s.length()-1; i++){
        if(s[i] == s[i+1]) res++;
    }
    return res;
}

int main() {
	FAST();
	CASE(t) {
        int n,k;cin>>n>>k;
        string s; cin>>s;
        int q[k];
        for(int i = 0; i < k; i++){
            int x; cin>>x;
            q[i] = x;
        }
        int dist = n-1 + sames(s);
        if(n>2){
        for(int i = 0; i<k; i++){
            int pos = q[i] - 1;
            if(s[pos] == '1') s[pos] = '0';
            else s[pos] = '1';

            bool bsame = 0, fsame = 0;
            if(pos == 0){
                if(s[pos] == s[pos+1]){
                    dist++;
                }
                else dist--;
            }
            else if(pos == n-1){
                if(s[pos] == s[pos -1]) dist++;
                else dist--;
            }
            else{
                if(s[pos] == s[pos - 1]) bsame = 1;
                if(s[pos] == s[pos + 1]) fsame = 1;
                if(bsame&&fsame) dist += 2;
                if(!bsame && !fsame) dist -= 2;
            }
            cout<<dist<<"\n";
        }
        }
        else{
            if(n == 1){
                for(int i = 0; i<k; i++){
                    cout<<"0\n";
                }
            }
            if(n == 2){
                for(int i = 0; i < k; i++){
                    int pos = q[i] - 1;
                    if(s[pos] == '1') s[pos] = '0';
                    else s[pos] = '1';     
                    if(s[0] == s[1]) cout<<"2\n";
                    else cout<<"1\n";               
                }
            }
        }
        /*
        for(int i = 0; i < k; i++){
            int pos = q[i]-1;
            if(s[pos] == '1'){
                s[pos] = '0';
            }
            else{
                s[pos] = '1';
            }
            cout<<calcDist(s)<<"\n";
        }
        //gives tle
        */
	}

	return 0;
}
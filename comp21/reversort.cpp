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
//#define CASE(t) ll t; cin>>t; while(t--)
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

int Min(vector<int> vec, int l, int ini){
    int min = ini;
    for(int i = ini + 1; i < l; i++){
        if(vec[i] < vec[min])
            min = i;
    }
    return min;
}

void rev(vector<int> vec, int l, int ini, int fin){
    for (int i = ini; i <= (fin + ini)/2; i++){
        int temp = vec[fin - (i - ini)];
        vec[fin - (i - ini)] = vec[i];
        vec[i] = temp;
    }
}

int main() {
	FAST();
	int N;
    cin>>N;
    for(int n = 1; n <= N; n++){
		int l, I = 0, J = 0;
        cin>>l;
        vector<int> vec;
        for(int i = 0; i < l; i++){
            int x;
            cin>>x;
            vec.push_back(x);
        }
        for(int i = 1; i < l; i++){
            int min = Min(vec, l, i-1);
            //index of minimum valued vector
            rev(vec, l, i-1, min);

            int ini = i-1;
            int fin = min;
            for (int r = ini; r <= (fin + ini)/2; r++){
                int temp = vec[fin - (r - ini)];
                vec[fin - (r - ini)] = vec[r];
                vec[r] = temp;
            }            

            //reverse(vec.begin() + i -1 , vec.at(min));
            //vector reversed from hereon
            I += i;
            //cout<<"i: "<<i<<"  ";
            J += min+1;
            //cout<<"min+1: "<<min+1<<"  ->";
            //for(int xi = 0; xi < vec.size(); xi++){
            //    cout<<vec[xi]<<" ";
            //}
            //cout<<endl;
        }
        cout<<"Case #"<<n<<": "<<J - I + l - 1<<endl;
	}

	return 0;
}
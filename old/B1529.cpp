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

int mindef(int arr[], int n, int fpos){
    //pass it a sorted array and get the minimum difference till index firstpos
    int min;
    if(n>1){
    min = abs(arr[1] - arr[0]);
    for(int i = 0; i < fpos; i++){
        if(abs(arr[i+1] - arr[i]) < min){
            min = abs(arr[i+1] - arr[i]);
        }
    }
    return min;
    }
    else{
        return abs(arr[0]);
    }
}

int firstpos(int arr[], int n){
    //pass it a sorted array to get the first positive number
    if(arr[0]<0){
        for(int i = 0; i < n; i++){
            if( arr[i]>0 ){
                return i;
            }
        }
        return n-1;
    }
    else return 0;
}

int main() {
	FAST();
	CASE(t) {
		//Solve each testcase here
        int n; cin>>n;
        int a[n];
        for(int i = 0; i < n; i++){
            int x; cin>>x;
            a[i] = x; 
        }
        int size = sizeof(a)/sizeof(a[0]);
        
        sort(a, a+ size);
        
        if(a[n-1]<=0){
            cout<<n<<"\n";

        }
        else{
            int fpos = firstpos(a,n);
            int min = mindef(a,n,fpos);

            if(a[fpos] <= min){
                cout<<(fpos + 1)<<"\n";
            }
            else{
                cout<<fpos<<"\n";
            }
        }
    }

	return 0;
}
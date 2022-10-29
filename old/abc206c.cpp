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
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n; cin>>n;
    map<ll,ll> a;
    ll res = 0;
    for(int i = 0; i < n; i++){
        int x; cin>>x;
        ll temp = i - a[x];
        res += temp;
        a[x]++;
    }
    cout<<res<<"\n";
}

/*
int main(){
    FAST();
    int n; cin>>n;
    ll res = n*(n-1)/2;
    vector<int>a;
    for(int i = 0; i < n; i++){
        int x; cin>>x;
        a.push_back(x);
    }
    sort(a.begin(), a.end());
    //vector<int>b;
    ll extra = 0;
    int it = 0;
    while(it<n){
        int x = a[it];
        int start = it;
        while(x == a[it]){
            it++;
        }
        int end = it - 1;
        int temp = end - start + 1;
        extra += temp*(temp-1)/2;
    }
    res -= extra;
    cout<<res<<"\n";
}
*/
/*int arr[300000][2] = {};

int howMany(int x, int index){
    for(int i = index-1; i >= 0 ; i--){
        if(x == arr[i][0]){
            return 1+arr[i][1];
        }
    }
    return 0;
}
int main() {
	FAST();
    int n; cin>>n;
    //int a[n][2];
    int res = 0;
    for(int i = 0; i < n; i++){
        int x; cin>>x;
        arr[i][0] = x;
        int pre = howMany(x,i);
        arr[i][1] = 1 + pre;
        res += i - pre;
    }
    cout<<res<<"\n";
	return 0;
}
*/
/*
int main(){
    FAST();
    int n; cin>>n;
    int res = n*(n-1)/2;
    vector<int> nums(1000000000,0);
    vector<int>a;
    for(int i = 0; i < n; i++){
        int x; cin>>x;
        a.push_back(x);
        //res += i;
        //res -= nums[x-1];
        //nums[x-1]++;
    }
    
    sort(a.begin(), a.end());
    //vector<int>b(n,0);
    int dup = 0;
    for(int i = 0; i < n-1; i++){
        if(a[i]==a[i+1])
            dup++;
    }

    cout<<res-dup<<"\n";
}
*/
/*
int howMany(int x, int arr[], int index){
    int res = 0; 
    for(int i = 0; i < index; i++){
        if(arr[i] == x)
            res++;
    }
    return res;
}
int main(){
    FAST();
    int n; cin>>n;
    int res = n*(n-1)/2;
    vector<int>a;
    for(int i = 0; i < n; i++){
        int x; cin>>x;
        a.push_back(x);
    }
    sort(a.begin(), a.end());
    //vector<int>b;
    int extra = 0;
    int it = 0;
    while(it<n){
        int x = a[it];
        int start = it;
        while(x == a[it]){
            if(it != n-1)
                it++;
            else {
                it++;
                break;
            }
        }
        int end = it - 1;
        int temp = end - start + 1;
        extra += temp*(temp-1)/2;
        //b.push_back(end-start+1);
    }
    res -= extra;
    cout<<res<<"\n";
}
*/
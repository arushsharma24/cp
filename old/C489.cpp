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

unsigned long long dsum(unsigned long long num){
    unsigned long long res = 0;
    while(num != 0){
        res += num%10;
        num /= 10;
    }
    return res;
}

int a2n(int arr[], int n){
    int num;
    for(int i = 0; i < n; i++){
        num += arr[i]*pow(10,i);
    }
    return num;
}

int asum(int arr[], int n){
    int sum;
    for(int i = 0; i<n; i++){
        sum+=arr[i];
    }
    return sum;
}

int main() {
	FAST();

    int m,s; cin>>m>>s;
    int k;
    if(s<1&&m>1||s>m*9){
        cout<<"-1 -1\n";
    }
    else{
        
    }

/*
    int m,s; cin>>m>>s;
    if(s == 0){
        if(m == 1){
            cout<<"0 0\n";
            return 0;
        }
        else {
            cout<<"-1 -1\n";
            return 0;
        }
    }
    int found = 0;
    int min[m] = {};

    //for minimum
    int nines = s/9;
    if(nines > m){
        cout<<"-1 -1\n";
        return 0;
    }
    else if(nines == m){
        if(s%9==0){
            for(int i = 0; i < nines; i++){
                min[i] = 9;
            }
        }
        else{
            cout<<"-1 -1\n";
        }
    }
    else if(nines == m-1){
        for(int i = 0; i < nines; i++){
            min[i] = 9;
        }
        if(s%9 != 0){
            min[m-1] = s - 9*nines;
        }
        else{
            min[m-1] = 1;
            min[m-2]--;
            found++;
        }
    }
    else{
        for(int i = 0; i < nines; i++){
            min[i] = 9;
        }
        if(s%9 == 0){
            min[m-1] = 1;
            min[nines-1]--;
            found++;
        }
        else{
            min[m-1] = 1;
            min[nines] = s - 9*nines - 1;
        }
    }

    //for maximum


    for(int i = 0; i < m; i++){
        cout<<min[m-1-i];
    }

    cout<<" ";

    if(found == 0){
        for(int i = 0; i < m; i++){
            cout<<min[i];
        }
        cout<<"\n";
    }
    else{
        min[m-1]--;
        min[nines-1]++;
        for(int i = 0; i < m; i++){
            cout<<min[i];
        }
        cout<<"\n";
    }
*/
/*
    int m,s; cin>>m>>s;
    if(s==0){
        cout<<"-1 -1"<<"\n";
        return 0;
    }
    int min[m] = {};
    int max[m];

    //for minimum
    // we will increase the min array and fill all digits such that the sum of the number of digits we make 9 in the end is less than the remaining
    int mDigs = s/9;
    int remaining = s - 9*mDigs;
    
    if(m-mDigs<0){
        cout<<"-1 -1"<<"\n";
        return 0;
    }
    else if(remaining == 0){
        for(int i = 0; i<mDigs; i++){
            min[i] = 9;
        }
        if(m-mDigs == 1){

            min[m-1] = s - 9*mDigs;
        }
        else if(m-mDigs > 1){
            min[m-1] = 1;
            min[mDigs] = s - 1 - mDigs*9;
        }
    }
    else if(remaining>0){
        for(int i = 0; i<mDigs; i++){
            min[i] = 9;
        }
        if(m-mDigs == 0){
            cout<<"-1 -1\n";
        }
        else if(m-mDigs == 1){
            min[mDigs] = s - mDigs*9;
        }          
        else{
            min[m-1] = 1;
            min[mDigs] = s-1-mDigs*9;
        }
    }

    for(int i = 0; i < m; i++){
        cout<<min[m-1-i];
    }
    cout<<"\n";

*/

/*
    unsigned long long m,s; cin>>m>>s;
    vector<unsigned long long> numbers;
    unsigned long long min = pow(10, m-1);
    unsigned long long max = pow(10, m)-1;
    
    int found = 0;

    for(int i = min; i <= max; i++){
        if(dsum(i) == s){
            numbers.push_back(i);
            found = 1;
            break;
        }
        else found = 0;
    }
    if(found > 0){
        for(int i = max; i >= min; i--){
            if(dsum(i) == s){
                numbers.push_back(i);
                found = 2;
            }
        }
    }
    
    if(found <= 0){
        cout<<"-1 -1"<<"\n";
    }
    else if(found == 1){
        cout<<"weird"<<"\n";
    }
    else{
        cout<<numbers[0]<<" "<<numbers[1]<<"\n";
    }
*/
	return 0;
}
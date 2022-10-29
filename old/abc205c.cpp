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
unsigned ll arushPower(int n, int p){
    unsigned ll x = 1;
    for(int i = 0; i < p; i++){
        x *= n;
    }
    return x;
}
int main() {
	FAST();
    
    
    int a,b,c;
    cin>>a>>b>>c;
    char res;
    if(a==b){
        res = '=';
    }
    else if(a>b){
        if(abs(a)>abs(b)){
            res = '>';
        }
        else if(abs(a)<abs(b)){
            if(c%2==0){
                res = '<';
            }
            else{
                res = '>';
            }
        }
        else{
            if(c%2==0){
                res = '=';
            }
            else{
                res = '>';
            }
        }
    }
    else{
        if(abs(a)>abs(b)){
            if(c%2==0){
                res = '>';
            }
            else{
                res = '<';
            }
        }
        else if(abs(a)<abs(b)){
            res = '<';
        }
        else{
            if(c%2==0){
                res = '=';
            }
            else{
                res = '<';
            }
        }
    }
    cout<<res<<"\n";
    /*
    unsigned ll xa = arushPower(a,c);
    unsigned ll xb = arushPower(b,c);
    if(xa<xb) cout<<"<\n";
    else if(xa>xb) cout<<">\n";
    else if(xa==xb) cout<<"=\n";
    else cout<<"mangoError\n";
    */
    /*
    char res;
    if(a!=b){
    if(c==1||(a>1&&b>1)){
        if(a==b) res = '=';
        else if(a>b) res = '>';
        else res = '<';
    }
    else if(c%2==0&&(abs(a)>=1&&abs(b)>=1)){
        if(abs(a)==abs(b)) res = '=';
        else if(abs(a)>abs(b)) res = '>';
        else res = '<';
    }
    else if(c%2==1&&(abs(a)>=1&&abs(b)>=1)){
        //if(a==b) res = '=';
        if(a>0&&b>0){
            if(a>b) res = '>';
            else res = '<';
        }
        else if(a<0&&b<0){
            if(a>b) res = '>';
            else res = '<';
        }
        else if(a>0&&b<0){
            res = '>';
        }
        else if(a<0&&b>0){
            res = '<';
        }
    }
    else{
        if(a==0&&b!=0){
            if(b>0){
                res='<';
            }
            else{
                if(c%2){
                    res='>';
                }
                else{
                    res='<';
                }
            }
        }
        else if(b==0&&a!=0){
            if(a>0){
                res='>';
            }
            else{
                if(c%2){
                    res = '<';
                }
                else{
                    res = '>';
                }
            }
        }
    }
    }
    else{
        res = '=';
    }
    cout<<res<<"\n";
    */
    /*
    ll x = pow(a,c);
    ll y = pow(b,c);
    if(x>y) cout<<">\n";
    else if(y>x) cout<<"<\n";
    else cout<<"=\n";
    */
    // c is always >= 1
    /*if(c==1 || ( a>1 && b>1 )){
        //res = a>b ? 0 : 1;
        if(a>b) res = 0;
        if(b>a) res = 1; 
        if(a == b) res = 2;
    }
    else {
        ll x = powM(a,c,M1);
        ll y = powM(b,c,M1) ;
        if(x>y) res = 0;
        if(y>x) res = 1;
        if(x == y) res = 2 ;
    }
    switch (res)
    {
    case 0:
        cout<<">\n";
        break;
    case 1: 
        cout<<"<\n";
    case 2:
        cout<<"=\n";
    default:
        break;
    }
    */
    // c is an integer

}
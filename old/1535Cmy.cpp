
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
    FAST();
    CASE(t){
            
    }
}

/*
bool oneoneorzerozero(string s){
    for(int i = 0; i < s.length()-1; i++){
        char s1 = s[i]; 
        char s2 = s[i+1];
        if(s1 != '?' && s2 != '?'){
            if(s1 == s2)
                return 1;
        }
    }
    return 0;
}

int length2(string s){
    int res = 0;
    for(int i = 0; i < s.length()-1; i++){
        char s1 = s[i]; 
        char s2 = s[i+1];
        if(s1 != s2) res++;
    }
    return 0;
}

bool isUnstable(string s){
    if(s.length() > 2){
        for(int i = 0; i < s.length() - 2; i++){
            char s1 = s[i], s2 = s[i+1], s3 = s[i+2];
            vector<int> ques;
            if (s1 == '?') ques.push_back(1);
            if (s2 == '?') ques.push_back(2);
            if (s3 == '?') ques.push_back(3);
            
            if(ques.size() == 0){
                if((s1=='1'&&s2=='0'&&s3=='1')||(s1=='0'&&s2=='1'&&s3=='0')){
                    return 1;
                }
                else return 0;
            }
            else if(ques.size() == 1){
                if(ques[0] == 1){
                    if(s2 != s3)
                        return 1;
                    else 
                        return 0;
                }
                else if(ques[0] == 2){
                    if(s1 == s3)
                        return 1;
                    else 
                        return 0;
                }
                else {
                    if(s1 != s2) return 1;
                    else return 0;
                }
            }
            else{
                return 1;
            }
        }
    }
    else if(s.length() == 2){
        if(s[0] == '?' || s[1] == '?')
            return 1;
        else if(s[0] == s[1]) return 0;
        else return 1;
    }
    else {
        return 1;
    }
    return 0;
}

int main() {
	FAST();
	CASE(t) {
        int beauts = 0;
        string s; cin>>s;
        // length 1
        //beauts += s.length();
        // length 2
        for(int i = 0; i < s.length(); i++){
            for(int j = i; j < s.length(); j++){
                string ss = s.substr(i,j); 
                if(isUnstable(ss))
                    beauts++; 
            }
        }
        cout<<beauts<<"\n";
	}
	return 0;
}
*/
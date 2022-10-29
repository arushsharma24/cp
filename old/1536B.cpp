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

int main() {
	FAST();
	CASE(t) {
		int n; cin>>n;
		string s; cin>>s;
		string subs;
		string ans;
		bool found = 0;
		
		for(int len = 1; len <= 3; len++){
			string t(len,'a');
			while(!found){
				if(s.find(t) == string::npos){
					cout<<t<<"\n";
					found = 1;
					break;
				}
				int last = len - 1;
				while(last>=0 && t[last]=='z'){
					t[last] = 'a';
					last--;
				}
				if(last < 0) break;
				t[last]++;
			}
		}
	}
	return 0;
}
		/*
		for(int i = 0; i < n; i++){
			subs = (char)('a'+i);
			if(s.find(subs) != string::npos){
				found = 1;
				ans = subs;
				break;
			}
		}
		if(!found){
		for(int i = 0; )
		}
		*/

		//vector<vector<vector<int>>> a(26);

		

		/*
		//Solve each testcase here
		int n; cin>>n;
		string s; cin>>s;
		bool stop = 0;
		// let's try to do this casewise
		//
		// since n < 1000 
		//now i think most (if not all will at max only have upto zz, and i could calculate it but ugh)
		// um but im gonna take a triple vector
		// a is 97;
		// z is 122;
		string ss;
		//vector<vector<vector<bool>>> a;
		for(int i = 0; i < 26; i++){
			if(stop) break;
			for(int j = 0; j < 26; j++){
				if(stop) break;
				for(int k = 0; k<26; k++){
					if(stop) break;
					//ss[] char(k+97);
					//if(s.find(ss) != std::string::npos)
					if(k == 0){
						if(j == 0){
							if(i == 0){
								ss = "a";
							}
							else ss = "aaa";
						}
						else{
							if(i == 0){
								ss = "aa";
							}
							else{
								ss = "aaa";
							}
						}
					}
					if(i == 0 && j == 0){
						ss[0] = char(97 + k);
						if(s.find(ss) != std::string::npos){
							//if found, continue
							continue;
						}
						else{
							cout<<ss<<"\n";
							//return 0;
							stop = 1;
							break;
						}
					}
					else if(i == 0){
						ss[1] = char(97 + k);
						if(s.find(ss) != std::string::npos){
							//if found, continue
							continue;
						}
						else{
							cout<<ss<<"\n";
							//return 0;
							stop = 1;
							break;
						}
					}
					else{
						ss[2] = char(97 + k);
						if(s.find(ss) != std::string::npos){
							//if found, continue
							continue;
						}
						else{
							cout<<ss<<"\n";
							//return 0;
							stop = 1;
							break;
						}
					}
				}
				if(stop) break;
				// once all 26 letters are found, we now go for double letters
				//ss[0] = char(j+96);
				if(j == 0){
					if(i == 0) ss = "aa";
					else {ss = char(i+97);
					ss.append("aa");}
				}
				else{
					ss[0] = char(j+97);
				}
				//if(i == 0) ss[0] = char(j+97);
				//else ss[1] = char(j+97);
			}
			if(stop) break;
			if(i == 0) ss = "aaa";
			else{ss[0] = char(i + 97);}
		}
	}
	*/
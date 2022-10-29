/*
#include <bits/stdc++.h>
using namespace std;


/********************************************************************/
/*
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
*/
/* **********END OF TEMPLATE*********** */
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
// amitesh ka solution
#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
#define rep(i,n) for(i=0; i<n; i++)
#define repa(i,a,n) for(i=a; i<n;i++)
#define repit(x, k) for(auto x:k)
#define vi vector<int>
#define vll vector<ll>
#define vvll vector<vector<ll>>
#define vvi vector<vector<int>>
#define fi first
#define se second
#define pb(t) push_back(t)
#define ins(t) insert(t)
#define mp(a,b) make_pair(a, b)
#define mset(a, val) memset(a, val, sizeof(a))
#define all(v) v.begin(), v.end()
 
#define SPEED ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
 
#define M 1000000007 // 9 zeros + 5
#define epsilon 1e-9
#define PI  3.14159265
#define INF 1e9+5
#define INFF  1000000000000000005ll //18 zeros + 5
 
int main(){
  SPEED;
  ll i,j;
  
  int t;
  cin>>t;
  while(t--){
 
 
    string s;
    cin>>s;
    int n= s.length();
    vi dp(n, 0);
    dp[0]=1;
    repa(i,1, n){
 
      if(s[i]=='?'){
        dp[i]=dp[i-1]+1;
      }
      else{
        int k = i-1;
        while(s[k]=='?' && k>-1) k--;
        if(k==-1){
          dp[i]= dp[i-1]+1;
          continue;
        }
        if((i-k)&1 && s[k]!=s[i]){
          dp[i]=dp[i-1]+1;
          continue;
        }
        else if((i-k)%2==0 && s[k]==s[i]){
          dp[i]=dp[i-1]+1;
          continue;
        }
        else{
          // k++;
          dp[i] = i-k;
          if(dp[i]==0) dp[i]=1;
          continue;
        }
 
      }
 
    }
    ll sum=0;
    repit(it, dp){
      cout<<it<<" ";
    }
    cout<<endl;
    
 
 
  }  
 
 
 
  return 0;
}

/*
//saksham ka solution
// FIRST THINK THEN CODE.
 
#include<iostream>
#include <bits/stdc++.h>
 
using namespace std;
 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
 
#define ll long long
#define ld long double
#define pll pair<ll,ll>
#define cld complex<ld>
#define vl vector<ll>
#define vvl vector<vector<ll>>
#define vld vector<ld>
#define vvld vector<vector<ld>>
#define vpll vector<pll>
#define vcld vector<cld>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define eb emplace_back
#define PI acos(-1)
#define endl "\n"
#define fix(f,n) fixed<<setprecision(n)<<f
#define all(x) x.begin(),x.end()
#define rev(p) reverse(p.begin(),p.end());
#define mset(a,val) memset(a,val,sizeof(a));
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define popcount(x) __builtin_popcountll(x)
#define sz(x) ((ll)x.size())
#define FOR(i,a,b)  for(ll i=a;i<=b;i++)
#define FORR(i,a,b)  for(ll i=a;i>=b;i--)
const ll M = 1000000007;
const ll MM = 998244353;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
#define ordered_set tree<pll, null_type,less<>, rb_tree_tag,tree_order_statistics_node_update>
 
ll begtime = clock();
#define end_routine() cerr << "\n\nTime elapsed: " << (clock() - begtime)*1000/CLOCKS_PER_SEC << " ms\n\n";
 
template<typename T, typename F>
void chmax( T &a, F b) {
  if (b > a)a = b;
}
 
template<typename T, typename F>
void chmin( T &a, F b) {
  if (b < a)a = b;
}
 
const ll N = 2e5 + 5;
 
 
 
 
void OJ() {
 
 
#ifndef ONLINE_JUDGE
 
  freopen("input1.txt", "r", stdin);
  freopen("output1.txt", "w", stdout);
 
#endif
 
}
 
int main() {
 
  IOS;
 
  OJ();
 
 
  ll t; cin >> t;
  while (t--) {
    string s; cin >> s;
    ll n = sz(s);
    s = '!' + s;
 
    ll ans = 0;
    vvl dp(n + 1, vl(2));
//   cout << s << endl;
    for (ll i = 1; i <= n; i++) {
      if (s[i] == '1') {
        dp[i][1] = dp[i - 1][0] + 1;
      } else if (s[i] == '0') {
        dp[i][0] = dp[i - 1][1] + 1;
      } else {
        dp[i][0] = dp[i - 1][1] + 1;
        dp[i][1] = dp[i - 1][0] + 1;
      }
      ans += max(dp[i][0] , dp[i][1]);
      //cout << i << " " << dp[i][0] << " " << dp[i][1] << endl;
    }
    cout << ans << endl;
  }
 
 
 
 
  return 0;
 
 
}
 
*/
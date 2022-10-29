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

void c(){
    int n, x; cin>>n>>x;
    if(n%2 && !x){
        cout<<"-1\n";
        return;
    }
    int ans = 0;
    while(n > 0){
        int p = log2(n);
            
    }
    cout << ans << "\n";
}

void e(){
    string s; cin>>s;
    int n = s.size();
    for(int i = 1; i < n; i++){
        if(s[i] == 'U' && s[i-1] == 'M'){
            cout << "Yes\n";
            return ;
        }
    }
    
    for(int i = 2; i < n; i++){
        if(s[i] == 'U' && s[i-1] == '?' && s[i-2] == 'M'){
            cout << "Yes\n";
            return;
        }
    }

    int idx = n-1;
    bool flag = 0;
    while(idx >= 0){
        if(s[idx] == 'U'){
            idx--;
            flag = 1;
            while(s[idx] == '?'){
                idx--;
            }
            if(s[idx] == 'M'){
                cout << "Yes\n";
                return;
            }
        }
        if(flag){
            idx++;
            flag = 0;
        }
        idx--;
    }

    cout << "No\n";
    return;
}

/* **********END OF TEMPLATE*********** */
// test cases
// // M?????????????????U 	true
// // U????U????M??M		false
// // M????U????M??M		true
// // M					false
// // U					false
// // ?					false
// // ?U					false
// // M?					flase
// // M?U					true // abey iske liye true aaega
// M?????????????????U
// U????U????M??M		
// M????U????M??M		
// M					
// U					
// ?					
// ?U					
// M?					
// M?U			
// Yes
// No
// Yes
// No
// No
// No
// No
// No
// Yes		
int main() {
	FAST();
	int test_cases = 1;
    cin>>test_cases;
    while(test_cases--){
        // solve test cases here
		c();
    }

	return 0;
}
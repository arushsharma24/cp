#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007

void FAST(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

void OJ(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
}

/*

*/

string removeStartingZeroes(string s){
    int idx;
    for(int i = 0; i < s.length(); i++){
        if(s[i] != '0'){
            idx = i;
            break;
        }
    }
    return s.substr(idx, s.length() - idx);
}

string subtractStrings(string s, string r){
    s = "0" + s;
    int borrow = 0;
    string ans = "";
    int n = r.length();
    for(int i = n-1; i >= 0; i--){
        int dr = (int)(r[i] - '0');
        int ds = (int)(s[i] - '0');
        while(borrow > 0 && dr > 0){
            dr--;
            borrow--;
        }
        if(dr < ds){
            // borrow
            borrow++;
            dr += 10;
        }
        ans += to_string(dr - ds);
    }
    reverse(ans.begin(), ans.end());
    return removeStartingZeroes(ans);
}

void solve(){
    ll n; cin>>n;
    string s; cin>>s;
    string ans = "";
    if(s[0] == '9'){
        string r = "";
        for(ll i = 0; i <= n; i++){
            r += "1";
        }
        ans = subtractStrings(s, r);
    }
    else{
        for(ll i = 0; i < n; i++){
            ans += to_string(9 - ((int)(s[i] - '0')));
        }
    }
    cout << ans << "\n";
}

int main(){
    FAST();
    OJ();
    int test_cases = 1;
    cin>>test_cases;
    while (test_cases--){
        solve();
    }
    return 0;   
}
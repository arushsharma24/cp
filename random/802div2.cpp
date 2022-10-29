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

void solve(){
    ll i,j,k,l,m,n;
    cin>>n>>m;
    cout << m*(m-1)/2 + (m*n*(n+1)/2) << "\n";

    return;
}

string removez(string s){
    int idx;
    for(int i = 0; i < s.length(); i++){
        if(s[i] != '0'){
            idx = i;
            break;
        }
    }
    return s.substr(idx, s.length() - idx);
}

bool check(string s){
    bool b = true;
    for(int i = 0; i < s.length(); i++){
        if(s[i] != '1'){
            b = false;
            break;
        }
    }
    return b;
}

void solveb(){
    ll n; cin>>n;
    string s; cin>>s;
    string ans = "";
    int carry = 0;
    int d;
    if(check(s)){
        cout << s << "\n";
        return;
    }
    for(int i = n-1; i >= 0; i--){
        int num = (int)(s[i] - '0');
        num += carry;
        int ld = num % 10;
        if(i == 0){
            int add;
            if(num > 11){
                add = 111 - num;
            }
            else if(num > 1){
                add = 11 - num;
            }
            else{
                add = 1 - num;
            }
            string sa = to_string(add);
            reverse(sa.begin(), sa.end());
            ans += sa;
            continue;
        }
        if(ld > 1){
            ans += to_string(11-ld);
            carry = 1;
        }
        else{
            if(num == 10) carry = 1;
            else carry = 0;
            ans += to_string(1-ld);
        }
    }
    reverse(ans.begin(), ans.end());
    ans = removez(ans);
    cout << ans << "\n";
}

void solvebb(){
    ll n; cin>>n;
    string s; cin>>s;
    string r = "";
    for(ll i = 0; i < n +1; i++){
        r += '1';
    }
    // now i have to perform subtraction on these strings
    s = "0" + s;
    int borrow = 0;
    string ans = "";
    for(int i = n; i >= 0; i--){
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
    ans = removez(ans);
    cout << ans << "\n";
}

string sub(string s, string r){
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
    return removez(ans);
}

void solvebbb(){
    ll n; cin>>n;
    string s; cin>>s;
    string ans = "";
    if(s[0] == '9'){
        string r = "";
        for(ll i = 0; i <= n; i++){
            r += "1";
        }
        ans = sub(s, r);
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
        solvebbb();
    }
    return 0;   
}
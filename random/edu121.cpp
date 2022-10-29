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

void a(){
    int n; cin>> n;
    for(int i = 0; i < n; i++){
        vector<int> m(26, 0);
        string s; cin>>s;
        for(auto c : s){
            m[c - 'a']++;
        }
        string a = "";
        string b = "";
        for(int j = 0; j < 26; j++){
            if(m[j] == 2){
                b += (char)('a' + j);
                b += (char)('a' + j);                
            }
            else{
                for(int ii = 0; ii < m[j]; ii++){
                    a += (char)('a' + j);
                }
            }
        }
        cout << a + b << "\n";
    }
    return;
}

bool isbigger(string a, string b){
    if(a.length() > b.length())
        return true;
    else if(a.length() < b.length())
        return false;
    else{
        int n = a.length();
        int x, y;
        for(int i = 0; i < n; i++){
            x = (int)a[i];
            y = (int)b[i];
            if(i == n-1 && x == y){
                return false;
            }
            if(x > y)
                return true;
            else if (x < y)
                return false;
            else {
                continue;
            }
            return false;
        }
    }
    return false;
}

void solve(){
    string s; cin>>s;
    int n = s.length();
    string a = "";
    string b = "";
    for(int i = 0; i < n - 1; i++){
        string pre = s.substr(0, i);
        string post = s.substr(i+2, n - 2 - i);
        string c = to_string((int)(s[i] - '0' + s[i+1] - '0'));
        b = pre + c + post;
        if(isbigger(b, a)){
            a = b;
        }
    }
    cout << a << "\n";
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
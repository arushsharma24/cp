#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007

void solve(){
    int n, t; cin>>n>>t; 
    string s; cin>>s;
    int idx = n-1;
    char a , b;
    while(t--){
        idx = n-1;
        while(idx > 0){
            a = s[idx];
            b = s[idx - 1];
            if((b == 'G') || (a == 'B' && b == 'B') ) idx--;
            else {
                s[idx] = 'B';
                s[idx-1] = 'G';
                idx -= 2;
            }
        }
    }    
    cout << s << "\n";
    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);    
    int test_cases = 1;
    // cin>>test_cases;
    while (test_cases--){
        solve();
    }
    return 0;   
}
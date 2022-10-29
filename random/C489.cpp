#include <bits/stdc++.h>
using namespace std;
#define ll long long

string myfill(char c, int n){
    string res = "";
    for(int i = 0; i < n; i++) res += c;
    return res;
}

void solve(){
    int m,s; cin>>m>>s;

    if(m == 1 && s > 9) {
        cout << "-1 -1\n";
        return;
    }
    if( m != 1 && (s < 1 || s > 9*m)) {
        cout << "-1 -1\n"; 
        return;
    }

    // if it is possible
    
    int x = (9*m - s + 1)/9;
    string res = "";
    string resr = "";

    if( m == 1){
        res += (s + '0');
        cout << res << " " << res << "\n";
        return;
    }

    if(x == 0){
        char ci = (s - 9*(m-1)) + '0';
        res += ci;
        res += myfill('9', m-1);
        resr = res;
        reverse(resr.begin(), resr.end());
    }
    else if(x == m){
        res = "1";
        res += myfill('0', m-1);
        resr = res;
    }
    /*
    else if(x == m-1){
        string ans;//('1', m-1);
        ans = myfill('1', m-1);
        char ci = (s - m + 1) + '0';
        ans += ci;
        res = ans;
    }*/
    else{
        res += '1';
        res += myfill('0', x-1);
        string temp = res;
        // x number of 1's 
        char ci = (s - 1 - 9*(m-x-1)) + '0';
        // m - x - 1 number of 9's 
        res += ci;
        res += myfill('9', m-x-1);
        resr += myfill('9', m-x-1);
        if(ci != '9') {
            ci++;
            resr += ci;
            resr += myfill('0', x);
        }
        else {
            resr += ci;
            resr += temp;
        }

    }

    cout << res << " " << resr << "\n" ;
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
#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    string s; cin>>s;
    map<char, int> m;
    for(char c : s)
        m[c]++;

    int n = s.size();
    if(n < 2) {
        cout<<"0\n";
        return;
    }
    int nm = m.size();// distinct chars;

    int sng = 0, mul = 0;
    for(auto it = m.begin(); it!= m.end(); ++it){
        if(it->second >1 ){
            mul++;
        }
        else{
            sng++;
        }
    }
    nm += mul;
    cout << (nm/2) <<"\n";
    
    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);    
    int test_cases = 1;
    cin>>test_cases;
    while (test_cases--){
        solve();
    }
    return 0;   
}
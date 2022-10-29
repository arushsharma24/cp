#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool isPalin(string s){
    for(ll i = 0; i < s.size()/2; i++){
        if(s[i] != s[s.size()-1-i]) return false;
    }
    return true;
}

string matchPalin(){
    ll n; cin>>n;
    string s; cin>>s;
    string r = "";
    // find the first index such that the substring before and after that is a palindrome
    for(ll i = 0; i < n; i++){
        // cout << r << "\n";
        if(isPalin(s.substr(0, i+1)) && isPalin(s.substr(i+1, n-i-1))) {
            r = s.substr(0, i+1);
            break;
        }
    }
    return r;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);    
    // cout << "oyy\n";
    int test_cases = 1;
    cin>>test_cases;
    int case_num = 1;
    while (test_cases--){
        cout<<"Case #"<<case_num<<": "<< matchPalin() <<"\n";
        case_num++;
    }
    return 0;   
}
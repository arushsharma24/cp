#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007

int recurse(string &s, int idx, string &chokudai){
    if( chokudai[idx] == 'i'){
        int ans = 0;
        for(char c : s){
            if(c=='i'){
                ans++;
            }
        }
        return ans%M;
    }
    else{
        char x = chokudai[idx];
        int ans = 0;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == x){
                string s2 = s.substr(i+1, s.length() - (i+1));
                ans += recurse(s2, idx+1, chokudai);
                ans %= M;
            }
        }
        return ans%M;
    }
}

void solve(){
    unordered_map<char, int> m;
    string chokudai = "chokudai";
    string s; cin>>s;
    for(char c : s){
        m[c]++;
    }
    for(char c : chokudai){
        if(m[c] < 1){
            cout<<"0\n";
            return;
        }
    }
    long long ans = recurse(s, 0, chokudai);
    ans%= M;
    cout<<ans<<"\n";
    return;
    // getting tle, earlier, but passed strings by reference now, let's see if that works (as written in comment https://codeforces.com/blog/entry/93152?#comment-820379) ok no it was written recursion with memoization, and i am just doing plain recursion; sedlyf
}
/*
int r2(int x, vector<int> v){
    int ans = 0;
    for(int i : v){
        if(i > x){
            ans++;
        }
    }
    return ans;
}

void solve2(){
    unordered_map<char, int> m;
    string chokudai = "chokudai";
    string s; cin>>s;
    for(char c : s){
        m[c]++;
    }
    for(char c : chokudai){
        if(m[c] < 1){
            cout<<"0\n";
            return;
        }
    }
    unordered_map<char, vector<int>> mp;
    for (char c : chokudai){
        for(int i = 0; i < s.length(); i++){
            if(s[i] == c)
                mp[c].push_back(i);
        }
    }

}
*/

void solve3(){
    unordered_map<char, int> m;
    string s; cin>>s;
    for(char c : s){
        if(c == 'c') m['c']++;
        if(c == 'h') m[c] += m['c'], m[c]%=M;
        if(c == 'o') m[c] += m['h'], m[c]%=M;
        if(c == 'k') m[c] += m['o'], m[c]%=M;
        if(c == 'u') m[c] += m['k'], m[c]%=M;
        if(c == 'd') m[c] += m['u'], m[c]%=M;
        if(c == 'a') m[c] += m['d'], m[c]%=M;
        if(c == 'i') m[c] += m['a'], m[c]%=M;

    }
    cout << m['i'] <<"\n";

    // a super sexy solution i saw from a guy on a cf comment
    // https://codeforces.com/blog/entry/93152?#comment-820386
    // apparently according to https://codeforces.com/blog/entry/93152?#comment-820417 this is same as dp, but this seems to be more easy to understand imo
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);    
    int test_cases = 1;
    // cin>>test_cases;
    while (test_cases--){
        solve3();
    }
    return 0;   
}
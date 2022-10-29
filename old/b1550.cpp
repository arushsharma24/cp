#include <bits/stdc++.h>
using namespace std;
#define ll long long

string removeLargestSubstring(string s){
    int index = 0, size = 1, maxsize = 1, findex;
    for(int i = 1; i < s.length(); i++){
        if(s[i] == s[i-1]){
            size++;
            if(size > maxsize){
                findex = index;
                maxsize = size;
            }
        }
        else{
            if(size > maxsize){
                findex = index;
                maxsize = size;
            }
            size = 1;
            index = i;
        }
    }
    string pre = s.substr(0, findex);
    string post = "";
    if(findex + maxsize < s.length()) post = s.substr(findex+maxsize + 1, s.length() - (findex + maxsize));
    string res = pre + post;
    return res;    
}

void solve(){
    int n, a, b; cin>>n>>a>>b;
    string s; cin>>s;
    int score = n*a;    // base score
    //cout<<score<<" ";
    if(b >= 0){
        // do all one by one
        score += n*b;
    }
    else{
        // minimize number of steps taken
        // remove largest substring first
        // and so on
        // to count steps, count number of changes, number of types
        // damn i should have gotten this faster
        int changes = 0;
        for(int i = 1; i < n; i++){
            if(s[i] != s[i-1]){
                changes++;
            }
        }
        int steps;
        if(changes%2) steps = changes/2 + 2;
        else steps = changes/2 + 1;
        score += steps*b;
    }
    cout<<score<<"\n";
    
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
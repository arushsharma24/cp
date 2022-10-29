#include <bits/stdc++.h>
using namespace std;
#define ll long long

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

string solve(){
    string s,p;
    cin>>s>>p;
    // s: correct string
    // p: typed string
    int n = s.length();
    int m = p.length();
    if(s.length() > p.length()){
        return "IMPOSSIBLE";    
    }
    string ans = "";
    // now iterate over the two
    int j = 0;
    for(int i = 0; i < n; i++){
        // iterate over the characters of the first string till you keep finding them in the second string
        while(j < m){
            if(p[j] == s[i]){
                // if letter matches
                ans += s[i];
                j++;
                // cout << ans << " ";
                break;
            }
            else{
                j++;
                // cout << "skip ";
            }
        }
    }    
    if(ans == s){
        return to_string(m-n);
    }
    else return "IMPOSSIBLE";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);    
    OJ();
    int test_cases = 1;
    cin>>test_cases;
    int case_num = 1;
    while (test_cases--){
        cout<<"Case #"<<case_num<<": "<<solve()<<"\n";
        case_num++;
    }
    return 0;   
}
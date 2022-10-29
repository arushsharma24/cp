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

bool comp(string x, string y){
    for(int i = 0; i < x.length(); i++){
        if(x[i] == '?') continue;
        if(x[i] == y[i]) continue;
        else return 0;
    }
    return 1;
}

string solve(){
    int n; cin>>n;
    string s; cin>>s;
    if(n < 5) return "POSSIBLE";
    // make two sets of palindromes, one of length 5 and one of length 6
    // then run across the string and compare, treating a ? as an always match
    vector<string> p = {"00000", "00100", "01010", "10001", "01110", "11011", "11111"};
    vector<string> pp = {"000000", "001100", "010010", "100001", "011110", "110011", "111111"};
    bool flag = 0;
    // first checking substrings of length 5
    for(int i = 0; i < n-4; i++){
        string x = s.substr(i, 5);
        for(string y : p){
            bool tres = comp(x, y);
            if(tres){
                flag = 1;
                break;
            }
        }
        if(flag) break;
    }
    if(flag) return "IMPOSSIBLE";
    // now checking for substrings of length 6
    for(int i = 0; i < n-5; i++){
        string x = s.substr(i, 5);
        for(string y : pp){
            bool tres = comp(x, y);
            if(tres){
                flag = 1;
                break;
            }
        }
        if(flag) break;
    }
    if(flag) return "IMPOSSIBLE";
    return "POSSIBLE";
}

string solve2(){
    int n; cin>>n; string s; cin>>s;

}

/*
00001
00010
01000
10000
000010
000100
001000
010000
000011
000101
001001
001010
100100
101000
010100
** then these with 1 and 0 inverted
0000111

00001111
000101111
0000101111
00001001111
*/
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
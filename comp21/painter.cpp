#include <bits/stdc++.h>
#include <chrono>
using namespace std;
using namespace std::chrono;
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

void printv(vector<int> &a){
    for(int x : a) cout << x << " ";
    cout << "\n";
}

int solve(string s){
    int ans = 0;
    unordered_map<char, int> c;
    c['R'] = 1;
    c['Y'] = 1;
    c['B'] = 1;
    c['O'] = 2;
    c['P'] = 2;
    c['G'] = 2;
    c['A'] = 3;
    string ss;
    for(char cc : s){
        if(ss.back() == cc) continue;
        ss += cc;
    }
    for(int i = 0; i < ss.length(); i++){
        if(c[ss[i]] == 1) ans++;
        else {
            if(i == 0 && i == ss.length() - 1){
                ans+=2;
            }
            else if(i == 0 || i == ss.length() - 1){
                ans++;
            }
            else if(ss[i-1] == ss[i+1]){
                ans++;
                i++;
            }
            else{
                continue;
            }
        }
    }
    return ans;
}


int main(){
    FAST();
    OJ();
    int tcases; cin>>tcases;
    for (int i = 1; i <= tcases; i++)
    {
        int n; cin>>n;
        string s; cin>>s;
        cout << "Case #" << i << ": " << solve(s) << "\n";
    }   
}
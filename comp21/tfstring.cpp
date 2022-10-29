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

int solve(string s, string f){
    int ans = 0;
    vector<bool> a(26, false);
    for(auto c : f) a[c-'a'] = true;
    vector<int> score(26, 0);
    for(int i = 0; i < 26; i++){
        if(a[i]) continue;
        int up = i+1;
        int dn = i-1;
        int tmp = 1;
        if(up == 26) up = 0;
        if(dn == -1) dn = 25;
        while(!a[up] && !a[dn]){
            tmp++;
            up++;
            dn--;
            if(up == 26) up = 0;
            if(dn == -1) dn = 25;
        }
        score[i] = tmp;
    }
    
    for(auto c : s){
        ans += score[c - 'a'];
    }
    return ans;
}

int main(){
    FAST();
    OJ();
    int tcases; cin>>tcases;
    for (int i = 1; i <= tcases; i++)
    {
        string s; cin>>s;
        string f; cin>>f;
        cout << "Case #" << i << ": " << solve(s, f) << "\n";
    }   
}
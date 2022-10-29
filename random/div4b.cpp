#include <bits/stdc++.h>
using namespace std;
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

void solve(){
    int n; cin>>n;
    unordered_map<int, int> m;
    bool flag = 0;
    int v[n];
    for(int i = 0; i < n; i++) cin>>v[i];
    for(int i = 0; i < n ; i++){
        int x = v[i];
        m[x]++;
        if(m[x] >= 3){
            cout << x << "\n";
            flag = 1;
            break;
        } 
    }
    if(flag ) return;
    cout << "-1\n";
    return; 
}

int main(){
    FAST();
    OJ();
    int test_cases = 1;
    cin>>test_cases;
    while (test_cases--){
        solve();
    }
    return 0;   
}
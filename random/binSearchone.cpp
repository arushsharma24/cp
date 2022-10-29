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
    unordered_set<string> temp;
    int n; cin>>n;
    int k; cin>>k;
    for(int i = 0; i < n; i++){
        int x; cin>>x;
        temp.insert(to_string(x));
    }
    for(int i = 0; i < k; i++){
        int x; cin>>x;
        if(temp.find(to_string(x)) != temp.end()) cout << "YES\n";
        else cout << "NO\n";
    }

    return;
}

int main(){
    FAST();
    OJ();
    int test_cases = 1;
    // cin>>test_cases;
    while (test_cases--){
        solve();
    }
    return 0;   
}
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
    int n, r; cin>>n>>r;
    int a[n], b[n];
    for(int i = 0; i < n; i++) cin>>a[i];
    for(int i = 0; i < n; i++) cin>>b[i];
    vector<pair<int, int> > v(n, pair<int, int>());
    for(int i = 0; i < n; i++){
        v[i].first = a[i] - b[i];
        v[i].second = a[i];
    }
    sort(v.begin(), v.end());
    int ct = 0;
    for(int i = 0; i < n; i++){
        while(r >= v[i].second){
            // 
        }
    }

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
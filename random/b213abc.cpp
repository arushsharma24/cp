#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007

void solve(){
    int n; cin>>n;
    vector<pair<int, int>> a(n);
    for(int i = 0;i < n; i++) {
        int x; cin>>x;
        a[i] = {x, i+1};
    }
    sort(a.rbegin(), a.rend());
    cout << a[1].second << "\n";
    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);    
    int test_cases = 1;
    while (test_cases--){
        solve();
    }
    return 0;   
}
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007

void solve(){
    int n; cin>>n;
    int a = 0, b = 0, c = 0;
    int x, y, z;
    while(n--){
        cin>>x>>y>>z;
        a += x, b += y, c += z;
    }
    if(!a && !b && !c){
        cout << "YES\n";
    }
    else cout << "NO\n";
    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);    
    int test_cases = 1;
    // cin>>test_cases;
    while (test_cases--){
        solve();
    }
    return 0;   
}
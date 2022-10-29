#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll a,b; cin>>a>>b;
    ll min = a;
    ll max = 6*a;
    if(b>=min && b <= max)
        cout<<"Yes\n";
    else 
        cout<<"No\n";
    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);    
    int test_cases = 1;
    //cin>>test_cases;
    while (test_cases--){
        solve();
    }
    return 0;   
}
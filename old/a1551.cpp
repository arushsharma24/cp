#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    int n; cin>>n;
    if(n%3 == 1){
        cout<<(1+n/3)<<" "<<n/3<<"\n";
    }
    else if(n%3 == 2){
        cout<<n/3<<" "<<(1+n/3)<<"\n";
    }
    else cout<<n/3<<" "<<n/3<<"\n";
    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);    
    int test_cases = 1;
    cin>>test_cases;
    while (test_cases--){
        solve();
    }
    return 0;   
}
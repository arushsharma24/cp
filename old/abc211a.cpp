#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    dou a, b;
    cin>>a>>b;
    // int c = (a-b)/3 + b;
    float f = (a-b)/3;
    f += b;
    cout<<f<<"\n";
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
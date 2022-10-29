#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    int coin[11];
    coin[1] = 1;
    for(int i = 2; i < 11; i++){
        coin[i] = (i)*coin[i-1];
    }
    int p; cin>>p;
    int r;
    int res = 0;
    for(int i = 10; i >= 1; i--){
        if(p >= coin[i]){
            r = (int)p/coin[i]; // number of coins of this deno
            res += r;
            r *= coin[i];
            p -= r;
        }
    }
    cout<<res<<"\n";
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
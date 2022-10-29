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
    ll n; cin>>n;
    ll ones = 0;
    ll twos = 0;
    for(ll i = 0; i < n; i++){
        ll x;cin>>x;
        if(x == 1) ones++;
        else if(x == 2) twos++;
    }
    ll sum = 0;
    sum += ones*(n-1) - (ones*(ones-1)/2);
    sum += twos*(twos-1)/2;
    cout << sum << "\n";
    
    
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
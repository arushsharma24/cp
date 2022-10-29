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
    ll n, m, l; 
    cin>>n>>m>>l;
    ll ans;
    if(n == 0){
        cout << m << "\n";
        return;
    }
    // first case, m > l + n - 1;
    if(m > l + n - 1){
        m = m%(l + n - 1);
        // now, m < l || >= l
    }
    if(m < l){
        ans = m;
    }
    else ans = 0;
    /*
    for(ll i = n; i > 0; i--){
        m = m%(l + i - 1 );
        if(m == 0) break;
        if(m < l ){
            break;
        }
    }
    */
    cout << ans << "\n";
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
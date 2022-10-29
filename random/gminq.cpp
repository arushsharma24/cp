#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
#define yes cout << "YES\n"
#define no cout << "NO\n"

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
    int x;
    ll p = 0, q = 0;
    for(ll i = 0; i < n ;i++){
        cin>>x;
        if(x== 1) p++;
        else q++;
    }
    if( abs(p-q) <= 1){
        yes;
    }
    else if(abs(p-q) == 2){ 
        if((p%2 == 0) && (q%2 == 0)) yes;
        else no;
    }
    else no;
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


/*


*/
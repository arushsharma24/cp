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
    ll n, m, k;
    cin>>n>>m>>k;
    ll nc2 = n*(n-1)/2;
    if (k < 2){
        cout << "NO\n";
    }
    else if(n == 1){
        if(m == 0){
            cout << "YES\n";
        }
        else cout << "NO\n";
    }
    else if(m >= n-1 && m <= nc2){
        if(m == nc2){
            cout << "YES\n";
        }
        else if(k > 3){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
    }
    else{
        cout << "NO\n";
    }
    return;
    /*
    if(n == 1 && m == 0 && k >= 2){
        cout << "YES\n";
        return;
    }
    if(m >= n-1){
        if( (m == nc2 && k == 3) || (k > 3)){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
    }
    else{
        cout << "NO\n";
    }
    return;
    */
}

int main(){
    FAST();
    OJ();
    ll test_cases = 1;
    cin>>test_cases;
    while (test_cases--){
        solve();
    }
    return 0;   
}
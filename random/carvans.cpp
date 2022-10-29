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
    int n; cin >> n;
    int mx = INT_MAX;
    int ct = 0;
    for(int i = 0; i < n ; i++){
        int x; cin>>x;
        if(x <= mx){
            // max speed of this car is less than the max speed allowed till this level
            ct++;
            mx = x;
        }
    }
    cout << ct << "\n";
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
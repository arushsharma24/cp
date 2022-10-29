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
    int r; cin>>r;
    if(r >= 1900){
        cout << "Division 1\n";
    }
    else if(r < 1900 && r >= 1600){
        cout << "Division 2\n";
    }
    else if(r < 1600 && r >= 1400){
        cout << "Division 3\n";
    }
    else{
        cout << "Division 4\n";
    }
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
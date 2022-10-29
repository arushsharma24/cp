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
    int n; cin>>n;
    int even = 0, odd = 0;
    int x; 
    int no = n/2, ne = n/2;
    if(n&1) no += 1;
    for(int i= 0; i < n; i++) {
        cin>>x;
        if(x&1) odd++;
        else even++;
    }
    odd = min(odd, ne);
    even = min(even, no);
    cout << odd + even << "\n";

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
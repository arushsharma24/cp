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
    // cout << log2(n) << ": " << pow(2, int(log2(n)))<< " ";
    if(n <= 2){
        cout << "1\n";
        return;
    }
    else if(n <= 3){
        cout << "2\n";
        return;
    }
    else{
        int x = 1 + n - pow(2, int(log2(n)));
        int y = pow(2,(int(log2(n))-1));
        cout << max(x,y) << "\n";
        return;
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
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
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin>>v[i];
    bool evenp = v[0]%2;
    bool oddp = v[1]%2;
    for(int i = 0; i < n; i+=2){
        if(v[i]%2 != evenp){
            cout << "NO\n";
            return;
        }
    }
    for(int i = 1; i < n; i+=2){
        if(v[i]%2 != oddp){
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
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


/*


*/
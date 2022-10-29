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
    int n, m; cin>>n>>m;
    vector<int> v(m);
    for(int i = 0; i < m; i++)  cin>>v[i];
    vector<int> a(n, 0);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(abs(v[j] - i) > a[i]) a[i] = abs(v[j] - i);
        }
    }
    for(int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
    cout << "\n";
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
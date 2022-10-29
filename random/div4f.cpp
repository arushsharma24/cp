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
    int a = 0, b = 0;
    int l = 0, r = n-1;
    int ct = 0;
    while(l < r){
        if(a < b){
            a += v[l];
            l++;
        }
        else{
            b += v[r];
            r--;
        }
        ct++;
    }
    if(a == b) cout << ct << "\n";
    else if(a < b ){
        
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


/*


*/
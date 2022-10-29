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
    int n; cin>>n; int k; cin>>k;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin>>a[i];
    int mmin = a[0];
    for(int i = 0; i < n; i++){
        if(mmin > a[i]) mmin = a[i];
    }
    int val = k/n;
    int steps = 0;
    if(mmin <= val ){
        // works, make the rest equal to this
        for(int i = 0; i < n; i++){
            if(a[i] > val) steps++;
        }
    }
    else{
        steps = mmin - val;
        for(int i = 0; i < n; i++){
            if(a[i] > val) steps++;
        }
        steps--;
    }
    cout << steps << "\n";
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
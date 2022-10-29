#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    // each tc is a multiset
    //multiset<int> a;
    int n; cin>>n;
    int odd = 0, even = 0;
    for(int i = 0; i < 2*n; i++){
        int x; cin>>x;
        //a.insert(x);
        if(x%2) odd++;
        else even++;
    }
    if(odd == n && even == n){
        cout<<"yes\n";
    }
    else cout<<"no\n";

    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);    
    int test_cases = 1;
    cin>>test_cases;
    while (test_cases--){
        solve();
    }
    return 0;   
}
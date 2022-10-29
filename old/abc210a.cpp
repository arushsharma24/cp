#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    int n, a, x, y;
    cin>>n>>a>>x>>y;
    if(n <= a){
        cout<<x*n<<"\n";
    }
    else{
        cout<<(a*x + (n - a)*y)<<"\n";
    }
    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);    
    int test_cases = 1;
    //jcin>>test_cases;
    while (test_cases--){
        solve();
    }
    return 0;   
}
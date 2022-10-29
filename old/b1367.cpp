#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    int n; cin>>n;
    int er = 0, orr = 0;
    int x;
    for(int i = 0; i < n; i++){
        cin>>x;
        if(i%2){
            if(x%2 == 0)
                orr++;
        }
        else{
            if(x%2)
                er++;
        }
    }    
    if(er != orr)
        cout<<"-1\n";

    else
        cout<<(er)<<"\n";
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
#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    int n; cin>>n;
    string s; cin>>s;
    int index;
    for(int i = 0; i < n; i++){
        if(s[i] == '1' ){
            index = i;
            break;
        }
    }
    if(index%2){
        cout<<"Aoki\n";
    }
    else{
        cout<<"Takahashi\n";
    }
    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);    
    int test_cases = 1;
    //cin>>test_cases;
    while (test_cases--){
        solve();
    }
    return 0;   
}
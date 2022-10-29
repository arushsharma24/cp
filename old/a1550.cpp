#include <bits/stdc++.h>
using namespace std;
#define ll long long

// stop watch -> 4:13
// end time -> 5:43

void solve(){
    int s; cin>>s;
    int mxodd;
    for(int i = 1; i*i <= s; i++)
        mxodd = i;

    int num = s - (mxodd*mxodd);
    if(num == 0){
        cout<<mxodd<<"\n";
    }
    else{
        cout<<(mxodd+1)<<"\n";
    }
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
#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll n,k; cin>>n>>k;
    int i;
    vector<int> fin(n, INT_MAX);
    vector<int> ac(k);
    for(i = 0; i < k; i++){
        cin>>ac[i];
    }
    vector<int> tac(k);
    for (i = 0; i < k; i++)
    {
        cin>>tac[i];
    }
    // vector<int> mint(k);
    // mint[k-1] = tac[k-1];
    // for (int i = k-2; i >= 0; i--)
    // {
    //     if(tac[i] < mint[i+1]){
    //         mint[i] = tac[i];
    //     }
    //     else{
    //         mint[i] = mint[i+1];
    //     }
    // }
    
    // brute force bina matlab tle hoga
    // 
    // for(i = 0; i < n; i++){
    //     // check the next acs
    //     temp = tac[0] + abs(ac[0] - 1 - i);
    //     for(j = 1; j < k; j++){
    //         t = tac[j] + abs(ac[j] - 1 - i);
    //         temp = t < temp ? t : temp;
    //     }
    //     cout<<temp<<" ";
    // }
    // cout<<"\n";
    int temp, j, t, index;
    for(int i = 0; i < k; i++){
        index = ac[i] - 1;
        for(j = index; j >= 0; j--){
            t = tac[i] + abs(j - index);
            if(t < fin[j]){
                fin[j] = t;
            }    
            else break;
        }
        for(j = index + 1; j < n; j++){
            t = tac[i] + abs(j - index);
            if( t <= fin[j]){
                fin[j] = t;
            }
            else break;
        }
    }
    
    for (int i = 0; i < n; i++)
    {
        cout<<fin[i]<<" ";
    }
    
    cout<<"\n";

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
#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    int n; cin>>n;
    vector<int> w(n);
    for(int i = 0; i < n; i++) cin>>w[i];
    if(n == 1){
        cout<<0<<"\n";
        return;
    }
    if(n == 2 || n == 3){
        cout<<1<<"\n";
        return;
    }
    // 
    sort(w.begin(), w.end());
    map<int, int> x, y;
    for(int i = 0; i  < n; i++){
        x[w[i]]++;
    }
    y = x;
    int max = w[n-1] + w[n-2]; 
    int min = w[0] + w[1];
    vector<int> val(max+1, 0);
    for(int s = min; s <= max; s++){
        x = y;
        for(int i = 0; i < n; i++){
            if( x[w[i]] <= 0 )  continue;
            //cout<<x[w[i]]<<" "<<x[s - w[i]]<<" ";
            if(w[i] < s){
                x[w[i]]--;
                if(x[s - w[i]] > 0){
                    val[s]++;
                    //cout<<w[i]<<"here";
                    x[s-w[i]]--;
                }
                else{
                    x[w[i]]++;
                }
            }
            //cout<<x[w[i]]<<" "<<x[s-w[i]]<<"\n";
        }
        //cout<<val[s]<<"\n";
    }   
    sort(val.rbegin(), val.rend());
    cout<<val[0]<<"\n";
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
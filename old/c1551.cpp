#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    int n; cin>>n;
    vector<string> vs(n);
    for(int i = 0; i < n; i++) cin>>vs[i];
    int mx = 0;

    for(int i= 0; i < 5; i++){
        char c = i + 'a';  
        vector<int> v;
        for(string x : vs){
            int one = 0, two = 0;
            for(char y : x){
                if(y == c){
                    one++;
                }
                else two++;
            }
            v.push_back(one-two);
        }
        sort(v.rbegin(), v.rend());
        int mxx = 0;
        int temp = 0;
        for(int x : v){
            if((temp += x) > 0 ){
                mxx++;
            }
        }
        mx = max(mxx, mx);
    }
    cout<<mx<<"\n";
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
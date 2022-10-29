#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    int n; cin>>n;
    vector< pair<int, int> > m(n, pair<int, int>());
    for(int i = 0; i < n; i++)  cin>>m[i].second>>m[i].first;
    sort(m.begin(), m.end());
    int time = 0;
    int ans = 0;
    for(int i = 0; i < n; i++){
        if(m[i].second >= time){
            // then i can go watch this movie;
            ans++;
            time = m[i].first;
        }
    }
    cout << ans << "\n";
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
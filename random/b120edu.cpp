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
    int n; cin>>n;
    vector<int> p(n);
    for(int i = 0; i < n; i++) cin>>p[i];
    string s; cin>>s;
    vector<pair< int, int> > dis;
    vector<pair< int, int> > lik;
    for(int i = 0; i < n; i++){
        if(s[i] == '0') {
            dis.push_back({p[i], i});
        }
        else{
            lik.push_back({p[i], i});
        }
    }
    sort(dis.begin(), dis.end());
    sort(lik.begin(), lik.end());
    vector<int> q(n);
    for(int i = 0; i < dis.size(); i ++){
        q[dis[i].second] = i+1;
    }
    for(int i = 0; i < lik.size(); i++){
        q[lik[i].second] = n-lik.size() + i + 1;
    }
    for(int i = 0; i < n; i++) cout << q[i] << " ";
    cout << "\n";

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
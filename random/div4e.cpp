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
    ll n; cin>>n;
    ll ct = 0;
    vector<vector<char> > start(11);
    vector<vector<char> > end(11);
    for(ll i = 0; i < n; i++){
        string s; cin>>s;
        char c = s[0];
        start[c - 'a'].push_back(s[1]);
        c = s[1];
        end[c - 'a'].push_back(s[0]);
    }
    for(int i = 0; i < 11; i++){
        multiset<char> set;
        for(char c : start[i]){
            set.insert(c);
        }
        ct += (set.size() * (set.size() - 1))/2;
        set.clear();
        for(char c: end[i]){
            set.insert(c);
        }
        ct += (set.size() * (set.size() - 1))/2;
    }
    cout << ct << "\n";
    /*
    vector<string> v(n);
    for(ll i = 0; i < n; i++) cin>>v[i];
    ll ct = 0;
    for(ll i = 0; i < n; i++){
        string s = v[i];
        for(ll j = i+1; j < n; j++){
            if(s[0] == v[j][0]){
                if(s[1] != v[j][1]) ct++;
            }
            else{
                if(s[1] == v[j][1]) ct++;
            }
        }
    }
    cout << ct << "\n";
    */
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


/*


*/
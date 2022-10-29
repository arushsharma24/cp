#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    int n, k; cin>>n>>k;
    vector<int> colors(k);
    for(int i = 0; i < k; i++){
        colors[i] = i+1;
    }
    vector<int> a(n);
    unordered_map<int, int> mp;
    unordered_map<int, vector<int>> mv;
    for(int i = 0; i < n; i++) {
        cin>>a[i];
        mp[a[i]]++;
        mv[a[i]].push_back(i);
    }
    vector<int> idxs;
    vector<int> res(n, 0);
    int num = 0;
    unordered_map<int, int> rems;
    for(auto it = mp.begin(); it != mp.end(); ++it){
        if(it->second >= k){
            for(int i = 0; i < k; i++){
                res[mv[it->first][i]] = colors[i];
            }
        }
        else{
            rems[it->first] = it->second;
            num += it->second;
            for(int i = 0; i < mv[it->first].size(); i++){
                idxs.push_back(mv[it->first][i]);
            }
        }
    }
    num /= k;
    int c = k*num;
    /*
    for(auto it = rems.begin(); it!= rems.end(); ++it){
        if(c <= 0) break;
        for(int i = 0; i < mv[it->first].size(); i++){
            res[mv[it->first][i]] = colors[c%k];
            c--;
        }
    }
    */
    for(int i = 0; i < c; i++){
        res[idxs[i]] = colors[i%k];
    }

    for(int x : res){
        cout<<x<<" ";
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
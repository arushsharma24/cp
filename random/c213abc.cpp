#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007

void solve(){
    int h, w, n; cin>>h>>w>>n;
    vector<pair<int, int>> x(n);
    vector<pair<int, int>> y(n);
    int a, b;
    for(int i = 0; i < n; i++){
        cin>>a>>b;
        x[i] = {a, i+1};
        y[i] = {b, i+1};
    }
    sort(x.begin(), x.end());
    unordered_map<int, int> mx;
    for(int i = 0; i < n; i++){
        mx[x[i].second] = i + 1;
    }
    sort(y.begin(), y.end());
    unordered_map<int, int> my;
    for(int i = 0; i < n; i++){
        my[y[i].second] = i + 1;
    }
    for(int i = 0; i < n; i++){
        cout << mx[i+1] << " " << my[i+1] << "\n";
    }

    return;
}

void s2(){
    int h,w,n; cin>>h>>w>>n;
    map<int, vector<int>> rows;
    map<int, vector<int>> cols;
    int a, b;
    for(int i = 0; i < n; i++){
        cin>>a>>b;
        rows[a-1].push_back(i);
        cols[b-1].push_back(i);
    }
    vector<pair<int, int>> res(n);
    int ct = 1;
    for(auto it : rows){
        for(int x : it.second){
            res[x].first = ct;
        }
        ct++;
    }
    ct = 1;
    for(auto it : cols){
        for(int x : it.second){
            res[x].second = ct;
        }
        ct++;
    }
    for(int i = 0; i < n; i++){
        cout << res[i].first << " " << res[i].second << "\n";
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);    
    int test_cases = 1;
    while (test_cases--){
        s2();
    }
    return 0;   
}
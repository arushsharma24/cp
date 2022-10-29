#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    int n, m; cin>>n>>m;
    vector<pair<int, int>> r(n);
    vector<int> pos(n);
    for(int i = 0; i < n; i++){
        cin>>r[i].first;
        pos[i] = r[i].first;
    }
    for (int i = 0; i < n; i++)
    {
        char x; cin>>x;
        if(x == 'L')    r[i].second = -1;
        else r[i].second = 1;
    }

    bool run = true;
    int ugh = 100;
    int time = 0;
    vector<int> res(n, -1);
    while(ugh--){
        for (int i = 0; i < n; i++)
        {
            if(r[i].first < 0) continue;
            if(r[i].first == 0 && r[i].second == -1){
                r[i].first = 1;
                r[i].second = 1;
                continue;
            }
            else if(r[i].first == m && r[i].second == 1){
                r[i].first = m-1;
                r[i].second = -1;
                continue;
            }
            r[i].first += r[i].second;
        }
        ++time;
        map<int, vector<int>>m;
        vector<int> er;
        for (int i = 0; i < n; i++)
        {
            m[r[i].first].push_back(i);// push index of the robot
            if(m[r[i].first].size() >= 2)    er.push_back(r[i].first);
        }
        
        for(int i = 0; i < er.size(); i++){
            for(int j = 0; j < m[er[i]].size(); j++){
                int x = m[er[i]][j];
                res[x] = time;
                r[i].first = -1;
            }
        }
    }  
    
    for (int i = 0; i < n; i++)
    {
        cout<<res[i]<<" ";
    }
    cout<<endl;
    
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
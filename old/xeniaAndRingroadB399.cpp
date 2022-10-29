#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    int n, m, i, x; cin>>n>>m;
    vector<int> t;
    for(i = 0; i < m; i++){
        cin>>x;
        t.push_back(x);
    }
    int h = 1;
    ll time = 0;
    for(i = 0; i < m; i++){
        if(h>t[i]){
            time += n - (h - t[i]);
        }
        else{
            time += t[i] - h;
        }
        h = t[i];
    }
    cout<<time<<"\n";
}
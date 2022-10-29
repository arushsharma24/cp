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
long getMaxFun(vector<int> singer, vector<int> length){
    int n = singer.size();
    long fun = 0;
    vector<pair<int,int>> vp;
    for(int i = 0; i < n; i++)
        vp.push_back({length[i], singer[i]});
    sort(vp.begin(), vp.end());
    for(int i = 0; i < n; i++){
        // cout << vp[i].first << ":" << vp[i].second << " ";
    }
    unordered_set<int> s;
    long wait = 0;
    for(int i = 0; i < n; i++){
        if(s.find(vp[i].second) == s.end()){
            // new singer
            s.insert(vp[i].second);
            fun += vp[i].first * s.size();
            // cout << vp[i].first << " " << vp[i].second << " " << fun << "\n";
        }
        else{
            wait += vp[i].first;
            // cout << wait << "\n";
        }
    }
    // cout << wait << "\n";
    fun += wait*s.size();
    return fun;
}


int main(){
    FAST();
    // OJ();
    int n = 3;
    vector<int> singer = {1,2,2};
    vector<int> length = {2,3,2};
    cout << getMaxFun(singer,length) << "\n";
    return 0;   
}
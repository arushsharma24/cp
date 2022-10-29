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

long minCost(int n, vector<int> pid, vector<int> bid){
    unordered_map<int, int> m;
    for(int i = 0; i < pid.size(); i++){
        if(m.find(pid[i]) == m.end()){
            // first time seeing this
            m[pid[i]] = bid[i];
        }
        else{
            // if bid is for a project for which bid exists
            if(bid[i] < m[pid[i]]) m[pid[i]] = bid[i];
        }
    }   
    long sum = 0; 
    bool flag = 0;
    for(int i = 0; i < n; i++){
        if(m.find(i) != m.end()){
            sum += m[i];
        }
        else flag = 1;
    }
    if(flag) return -1;
    return sum;
}


int main(){
    FAST();
    // OJ();
    int n = 2;
    vector<int> pid = {0,1,0,1,1};
    vector<int> bid = {4,74,47,744,7};
    cout << minCost(n,pid,bid) << "\n";
    return 0;   
}
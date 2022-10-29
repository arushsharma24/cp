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

vector<int> findMaximumValue(vector<int> prices, vector<int> pos, vector<long> amount){
    int n = prices.size();
    int q = pos.size();
    vector<int> ans;
    for(int i = 0; i < q; i++){
        // all queries
        int p = pos[i] - 1;
        ll a = amount[i];
        int ct = 0;
        while(a > 0 && p < n){
            if(a >= prices[p]){
                ct++;
                a -= (ll) prices[p];
                p++;
            }
            else break;
        }
        ans.push_back(ct);
    }
    return ans;
}

int main(){
    FAST();
    // OJ();
    int n = 5; 
    vector<int> prices = {3,4,5,5,7};
    vector<int> pos = {2,1,5};
    vector<long> amount = {10,24,5};
    vector<int> res = findMaximumValue(prices, pos, amount);
    for(int i = 0; i < res.size(); i++) cout << res[i] << " ";
    cout << endl;
    return 0;   
}
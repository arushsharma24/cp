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

/*
for an array of n integers the mathematician can perfrom the following move on the array
choose an index and add arr[i] to their scores
discard either the left or the right partition of the array

starting with the initial score of 0, find the maximum score the mathematician can achieve after performing exactly k moves
*/

ll sol(vector<int> &a, int l, int r, int k, map<pair<ll, pair<ll,ll> >, ll> &dp){
    if(k == 0){
        return 0;
    }
    if(l == r && k > 1){
        return -1e17;
    }
    if(dp.find({k,{l,r}}) != dp.end()){
        return dp[{k,{l,r}}];
    }
    ll ans = 0;
    for(int i = l; i <= r; i++){
        ll tmp = a[i] + max(sol(a,l,i-1,k-1,dp), sol(a,i+1,r,k-1,dp));
        ans = max(ans, tmp);
    }
    ans = max(ans, sol(a, l+1, r, k-1, dp) + a[l]);
    ans = max(ans, sol(a, l, r-1, k-1, dp) + a[r]);
    return dp[{k,{l,r}}] = ans;
}

long getMaximumScore(vector<int> arr, int k){
    int n = arr.size();
    map<pair<ll, pair<ll,ll> >, ll> dp;
    return sol(arr, 0, n-1, k, dp);
}

int main(){
    FAST();
    OJ();
    int test_cases = 1;
    cin>>test_cases;
    while (test_cases--){
        cout << getMaximumScore({1, 2, 3, 4, 5}, 3) << endl;
    }
        
    return 0;   
}
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
  int n,k;
  cin >> n;
  cin>>k;
  vector<int> a;
  long long sum = 0;
  for(int i = 0; i < n; i++){
    int x; cin>>x;
    if(x < 0){
      a.push_back(x);
    }
    else sum+=x;
  }
  sort(a.begin(), a.end());
  k = min(k, (int)(a.size()));
  for(int i = 0; i < k; i++){
    sum+=a[i];
  }
  if(sum<0) cout << "-1\n";
  else cout << sum << "\n";
}

long getMaxProfit(vector<int> pnl, int k){
  vector<int> a;
  long long sum = 0;
  for(int x : pnl){
    if(x < 0) a.push_back(x);
    else sum+=x;
  }
  sort(a.begin(), a.end());
  k = min(k, (int)(a.size()));
  for(int i = 0; i < k; i++){
    sum+=a[i];
  }
  if(sum<0) cout << "-1\n";
  else cout << sum << "\n";
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

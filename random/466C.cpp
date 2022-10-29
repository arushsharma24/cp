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
    int n; cin>>n;
    int a[n+1];
    for(int i = 1; i <= n; i++) cin>>a[i];
    int sum[n+1];
    sum[0] = 0;
    for(int i = 1; i <= n; i++){
        sum[i] = a[i] + sum[i-1];
    }
    int ts = sum[n];
    if(ts%3) {
        cout << "0\n"; return;
    }
    int ans = 0;
    for(int i = 2; i < n; i++){
        if(sum[i] == ts/3){
            for(int j = i; j < n; j++){
                if(sum[j] == 2*ts/3){
                    ans++;
                }
            }
        }
    }
    cout << ans << "\n";
    return;
}

void s2(){
    int n; cin>>n;
    int sum = 0;
    int a[n+1];
    for(int i = 1; i <= n; i++) {
        cin>>a[n];
        sum += a[n];
    }
    if(sum%3){
        cout << "0\n";
        return;
    }
    int ans = 0;
    int tmp = a[1];
    for(int i = 2; i < n; i++){
        if(tmp == sum/3){
            int tmp2 = 0;
            for(int j = i; j < n; j++){
                tmp2 += a[j];
                if(tmp2 == sum/3){
                    ans++;
                }
            }
        }
        tmp += a[i];
    }
}

int main(){
    FAST();
    OJ();
    int test_cases = 1;
    // cin>>test_cases;
    while (test_cases--){
        solve();
    }
    return 0;   
}
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
    int x = (n-1)/5;
    int step = x*5 + 1;
    int ans = x*2;
    switch (n-step)
    {
    case 0:
        break;
    case 1:
        ans++;
        break;
    case 2:
        ans++;
        break;
    case 3:
        ans++;
        break;
    case 4:
        ans+=2;
        break;

    default:
        break;
    }
    cout << ans << "\n";
    return;
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
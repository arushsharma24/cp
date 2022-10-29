#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007

void solve(){
    ll n; cin>>n;
    ll k; cin>>k;
    ll z = log2(n);
    vector<ll> a(n+1);
    ll val = INT_MIN, comp;
    // map<int, int> m;  // for lower a,b
    vector<pair<int, int>> vpi(n+1);
    for(int i = 1; i <= n; i++) {
        cin>>a[i];
        // m[a[i]] = i;
        vpi[i] = make_pair(a[i], i);
    }
    sort(vpi.begin(), vpi.end());
    // prioritizing value of i*j
    int flag = 0;
    int sflag = 0;
    for(int i = n; i > 0; i--){
        for(int j = i-1; j > 0; j--){
            comp = i*j - k*(a[i] | a[j]);
            if(comp < val){
                flag++;
                if(flag > z) break;
            }
            else{
                val = max(val, comp);
                // cout << "i" << val << " ";
            }
        }   
        if(flag > z && sflag > z) break;
        sflag++;
    }

    // prioritising value of lower a and b
    // map has our a and b sorted 
    flag = 0, sflag = 0;
    int y = 1;
    for(int x = 2; x <= n; x++){
        ll a = vpi[y].first;
        ll i = vpi[y].second;
        ll b = vpi[x].first;
        ll j = vpi[x].second;
        // cout << "\n" << i << " " << j << " " << a << " " << b << "\n";
        comp = i*j - k*(a|b);
        if(comp < val){
            y++;
            x = y;
            flag++;
            if(flag > z) break;
        }
        else {
            val = max(comp, val);
            // cout << "a " << val << " ";
        }
    }

    cout << val << "\n";

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
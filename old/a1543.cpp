#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll gcd(ll x, ll y) {	//returns gcd of two long long ints
	if (x == 0) return y;
	return gcd(y % x, x);
}

void solve(){
    ll a, b; cin>>a>>b;
    // first num is max excitement
    // second num is steps req
    ll diff = abs(a - b);
    if(diff == 0){
        cout<<"0 0\n";
        return;
    }
    if(diff == 1){
        cout<<"1 0\n";
        return;
    }
    ll low = a < b ? a : b;
    if(low % diff == 0){
        // if divisible already, then 0 steps required, and ans is gcd
        // at each step, also compare with 0 wala case
        cout<<diff<<" 0\n";
        return;
    }
    else{
        if(low < diff){
            if( low < diff - low){
                // then we drive it to 0
                cout<<diff<<" "<<low<<"\n";
            }
            else{
                cout<<diff<<" "<<diff-low<<"\n";
            }
            return;
        }
        else{
            ll l = low/diff;
            l *= diff;
            ll r = l + diff;
            ll steps = abs(low - l) < abs(low - r) ? abs(low - l) : abs(low - r);
            cout<<diff<<" "<<steps<<"\n";
            return;
        }
    }
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
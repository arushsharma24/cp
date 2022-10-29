#include <bits/stdc++.h>
using namespace std;
#define ll long long

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

ll dprod(string s){
    ll ans = 1;
    for(ll i = 0; i < s.length(); i++){
        ans *= (s[i] - '0');
        if(ans == 0) return 0;
    }
    return ans;
}

ll dsum(string s){
    ll ans = 0;
    for(ll i = 0; i < s.length(); i++){
        ans += s[i] - '0';
    }
    return ans;
}

ll solve(){
    ll ans = 0;
    ll a,b; cin>>a>>b;
    for(ll i = a; i <= b; i++){
        ll x = dprod(to_string(i));
        ll y = dsum(to_string(i));
        if( x%y == 0 ) ans++;
    }

    return ans;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);    
    OJ();
    int test_cases = 1;
    cin>>test_cases;
    int case_num = 1;
    while (test_cases--){
        cout<<"Case #"<<case_num<<": "<<solve()<<"\n";
        case_num++;
    }
    return 0;   
}
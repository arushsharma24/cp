#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
#define yes cout<<"YES\n"
#define no cout<<"NO\n"
void FAST(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

long long conv(string s, ll b){
    ll x = 0;
    for(int i = 0; i < s.length(); i++){
        x*=10;
        x += (ll)(s[i] - '0');
        x %= b;
    }
    return x;
}

void OJ(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
}

void solve(){
    ll a,b,n; cin>>a>>b>>n;
    while(n--){
        if(a%b == 0){
            n++;
            string as = to_string(a);
            for(int i = 0; i < n; i++) as += '0';
            cout << as << "\n";
            return;
        }
        else{
            a *= 10;
            bool flag = false;
            for(int i = 0; i < 10; i++){
                if(a%b == 0){
                    flag = true;
                    break;
                }
                a++;
            }
            if(flag){
                continue;
            }
            else {
                cout << "-1\n";
                return;
            }
        }
    }
    cout << a << "\n";
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
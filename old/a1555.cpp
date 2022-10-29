#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007

void solve(ll n){
    if(n%6 == 0){
        cout << 15*n/6 << "\n";
    }
    else if(n%8 == 0){
        cout << 20*n/8 << "\n";
    }
    else if(n%10 ==0){
        cout << 25*n/10 << "\n";
    }
    else{
        // find the one with the minimum x - modulo
        ll a = 6 - n%6;
        ll b = 8 - n%8;
        ll c = 10 - n%10;
        // these are wasted slices
        if(a <= b && a <= c){
            cout << 15*(n/6 + 1) << "\n";
        }
        else if(b <= c && b <= a){
            ll ans = 20*(n/8);
            if(n%8 <= 6) cout << ans + 15 << "\n";
            else cout << ans + 20 << "\n";
        }
        else{
            ll ans = 25*(n/10);
            if(n%10 <= 6){
                cout << ans + 15 << "\n";
            }
            else if(n%10 <= 8){
                cout << ans + 20 << "\n";
            }
            else {
                cout << ans + 25 << "\n";
            }
        }
    }
    return;
}

void s2(){
    ll n; cin>>n;
    ll a = 15*(n/6);
    if(n%6) a+= 15;
    ll b = 20*(n/8);
    if(n%8) {
        if(n%8 <= 6) b+= 15;
        else b+= 20;
    }
    ll c = 25*(n/10);
    if(n%10) {
        if(n%10 <= 6) c+= 15;
        else if(n%10 <= 8) c+= 20;
        else c+= 25;
    }
    a = min(a, b);
    c = min(a,c);
    cout << c << "\n";
}

ll valcal(ll n){
    if(n%6 == 0){
        return n/6;
    }
    else if(n%8 == 0){
        return n/8;
    }
    else if(n%10 ==0){
        return n/10;
    }    
    else{
        ll a = 6 - n%6;
        ll b = 8 - n%8;
        ll c = 10 - n%10;
        // these are wasted slices
        if(a <= b && a <= c){
            cout << 15*(n/6 + 1) << "\n";
        }
        else if(b <= c && b <= a){
            ll ans = 20*(n/8);
            if(n%8 <= 6) cout << ans + 15 << "\n";
            else cout << ans + 20 << "\n";
        }
        else{
            ll ans = 25*(n/10);
            if(n%10 <= 6){
                cout << ans + 15 << "\n";
            }
            else if(n%10 <= 8){
                cout << ans + 20 << "\n";
            }
            else {
                cout << ans + 25 << "\n";
            }
        }        
    }
    return 0;
}

void s3(){
    ll n;
    cin>>n;
    if(n <= 6) cout << "15\n";
    else if(n%2){
        cout << 5 * (n+1) / 2 << "\n";
    }
    else cout << 5*(n/2) << "\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);    
    ll test_cases = 1;
    cin>>test_cases;
    while (test_cases--){
        // ll n; cin>>n;
        s2();
    }
    return 0;   
}
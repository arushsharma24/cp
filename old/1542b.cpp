#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll pwr(ll x, ll y){
    ll res = 1;
    while (y)
    {
        if(y%2 == 1)
            res *= x;
        y >>= 1;
        x *= x;
    }
    return res;
}

void solve(){
    ll n, a, b; cin>>n>>a>>b;
    // get n
    // keep dividing by a till you can
    // when you can't, subtract b
    // check with dividing a again
    // subtract b
    // so on
    // hm slow slow slow
    if(a == 1){
        // only 1 + nb
        n--;
        if(n%b == 0) cout<<"yes\n";
        else cout<<"no\n";
        return;
    }
    ll x = n;
    
    ll mx = 1;
    int max =  0;
    while(mx <= n) {
        mx *= a;
        max++;
    }
    --max;
    

    while(x>1){
        ll ax;
        if(x%a==0){
            for(int i = max; i > 0; i--){
                ax = pow(a,i);
                if(x%ax==0){
                    x /= ax;
                    max -= --i;
                    break;
                }
            }
        }
        if(x != 1)  x -= b;
    }
    if(x == 1)  cout<<"yes\n";
    else cout<<"no\n";
    return;
}

void solve2(){
    ll n,a,b; cin>>n>>a>>b;

    if(a == 1){
        // only 1 + nb
        n--;
        if(n%b == 0) cout<<"yes\n";
        else cout<<"no\n";
        return;
    }        
    else{
        //int max = log(n)/log(a);
        // noted and learnt from this that log(n)/log(a) can not really be relied on
        bool found = 0;
        for(int i = 0; i < 31; i++){
            ll r = pwr(a, i);
            if(r>n) break;
            if((n - r)%b == 0 ){
                cout<<"yes\n";
                found = 1;
                break;
            }
        }
        if(!found) cout<<"no\n";
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);    
    int test_cases = 1;
    cin>>test_cases;
    while (test_cases--){
        solve2();
    }
    return 0;   
}
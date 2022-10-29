#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    int ax, ay, bx, by, fx, fy;
    cin>>ax>>ay>>bx>>by>>fx>>fy;
    int res = abs(by-ay) + abs(bx - ax);
    if(by == ay && by == fy){
        if( (ax - fx)*(bx - fx) < 0){
            // in between
            res += 2;
        }
    }
    else if(ax == bx && ax == fx){
        if((ay-fy)*(by-fy)<0){
            res +=2;
        }
    }
    cout<<res<<"\n";
        
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
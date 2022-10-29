#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007

int helper(int h, int w, int top, int bottom, int left, int right){
    int ans;
    int y = h > top ? h - top : 0;
    int x = w > left ? w - left : 0;
    if(right < x){
        ans = y;
    }
    else{
        if(bottom < y){
            ans = x;
        }
        else{
            ans = min(x, y);
        }
    }
    return ans;
}

void solve(){
    int rw, rh; cin>>rw>>rh;
    int a, b, c, d;
    cin>>a>>b>>c>>d;
    int w,h;
    cin>>w>>h;
    int top = rh - d;
    int bottom = b;
    int left = a;
    int right = rw - c;
    int ww = c-a;
    int hh = d-b;
    if(ww + w <= rw || hh + h <= rh){
        // it is possible to fit it in
        int ans = INT_MAX;
        if(ww + w <= rw && hh + h <= rh){
            if(top > bottom){
                if(left > right){
                    ans = helper(h, w, top, bottom, left, right);
                }
                else{
                    ans = helper(h, w, top, bottom, right, left);
                }
            }
            else{
                if(left > right){
                    ans = helper(h, w, bottom, top, left, right);
                }
                else{
                    ans = helper(h, w, bottom, top, right, left);
                }
            }
        }
        else if(ww + w > rw && hh + h <= rh) {
            if(top > bottom){
                int y = h > top ? h - top : 0;
                ans = y;
            }
            else{
                int y = h > bottom ? h - bottom : 0;
                ans = y;
            }
        }
        else{
            if(left > right){
                int x = w > left ? w - left : 0;
                ans = x;
            }
            else {
                int x = w > right ? w - right : 0;
                ans = x;
            }
        }
        cout << ans << "\n";
    }
    else cout<<"-1\n";
    

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
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007

void solve(){
    int n; cin>>n;
    string a, b; cin>>b>>a;
    int ans = 0;
    for(int i = 0; i < n; i++){
        if(a[i] == '0'){
            if(b[i] == '1'){
                if(i != n-1){
                    if(a[i+1] == '1'){
                        ans++;
                        i++;
                    }
                }
            }
            continue;
        }    
        if(b[i] == '0') ans++;
        else{
            if(i != n-1){
                if(a[i+1] == '1'){
                    ans++;
                    if(b[i+1] == '1') ans++;
                    i++;
                }
            }
        }
    }
    /*
    int res = 0;
    for(int i = n-1; i >= 0; i--){
        if(a[i] == '0') continue;
        if(b[i] == '0') res++;
        else{
            if(i != 0){
                if(a[i-1] == '1'){
                    res++;
                    if(b[i-1] == '1') res++;
                    i--;
                }
            }
        }
    }
    */
    cout << ans << "\n";// " " << res << "\n";
    return;
}

void solve2(){
    int n; cin>>n;
    string a, b; cin>>b>>a;
    int ans = 0;
    for(int i = 0; i < n; i++){
        if((a[i] == '1') && (b[i] == '0')){
            ans++;
            a[i] = '0';
            b[i] = '-';
        }
    }
    // now for the rest, consider squares
    for(int i = 1; i < n; i++){
        if((a[i] == '1') && (a[i-1] == '1') && (b[i] == '1') && (b[i-1] == '1')){
            ans+=2;
            a[i] = '0';
            a[i-1] = '0';
            b[i] = '-';
            b[i-1] = '-';
        }
        else if((b[i] == '1') && (b[i-1] == '1')){
            if((a[i] == '1') && !(a[i-1] == '1')){
                ans++;
                a[i] = '0';
                b[i-1] = '-';
            }
            else if((a[i-1] == '1') && !(a[i] == '1')){
                ans++;
                a[i-1] = '0';
                b[i] = '-';
            }
        }
    }
    cout << ans << "\n";
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
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

int main(){
    FAST();
    OJ();
    int test_cases = 1;
    // cin>>test_cases;
    while (test_cases--){
        int n; cin>>n;
        vector<int> v(n);
        int a = 0, b = 0, c = 0, d = 0;
        for(int i = 0; i < n; i++){
            int x; cin>>x;
            switch (x)
            {
            case 1:
                a++;
                break;
            case 2:
                b++;
                break;
            case 3:
                c++;
                break;
            case 4:
                d++;
            default:
                break;
            }
        }
        int ans = d;
        if(a > c){
            ans += c;
            a -= c;
            c = 0;
            ans += b/2;
            if(b%2){
                if(a <= 2){
                    ans++;
                }
                else{
                    ans++;
                    a -= 2;
                    ans += a/4;
                    if(a%4 > 0) ans++;
                }
            }
            else{
                ans += a/4;
                if(a%4 > 0) ans++;
            }
        }
        else{
            ans += a;
            c -= a;
            a = 0;
            ans += c;
            ans += b/2 + b%2;
        }
        cout << ans << "\n";
    }
    return 0;   
}
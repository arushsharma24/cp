#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve2(){   // my method, didn't work
    int n, k; cin>>n>>k;
    int digs = 1+ log2(n);
    int max = 1<<(digs+1) - 1;
    // for easy version k is always 2;
    // pw is bw 0 and n-1
    int y = max, r = 0;
    while(r != 1){
        cout<<y<<endl;
        cin>>r;
        if(r == 1) break;
        --y;
    }
    return;
}

void solve(){   // shashwat ka method
    int n, k; cin>>n>>k;
    int prev = 0;
    int judgementOfGod; // interactive god
    for(int curr = 0; curr < n; curr++){
        int guess = curr^prev;  // basically aise karne se mere original password always stays, 
        cout<<guess<<endl;  // and at some point toh mera password will be x^(x+1) and at that time my guess will be (x+1)^x, so kabhi na kabhi aaega hi answer; sexy solution
        cin>>judgementOfGod;
        if(judgementOfGod == 0){
            prev = curr;
        }
        else break;
    }
    return;
}
/*
password:   x   x^0    x^1      x^2     x^(x+1)

guess:      0           0^1             1^2             (x+1)^x
*/
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
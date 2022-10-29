#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007

void solve(){
    int n; cin>>n;
    int a = 2;
    int b = 3;
    while(n%b != 1){
        b++;
    }
    cout << a << " " << b << "\n";
    return;
}

void soln(){
    int n; cin>>n;
    // we can fix a = 2;
    // now, since n is def. odd, n%2 == 1
    // we just need to find another number which will give us a modulo of 1 with n
    // and ofcourse, that is n-1
    cout << 2 << " " << n-1 << "\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);    
    int test_cases = 1;
    cin>>test_cases;
    while (test_cases--){
        soln();
    }
    return 0;   
}
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

void a(){
    int n; cin>>n;
    cout << pow(2,n) - 1 << "\n";
    return;
}

void b(){
    
}

int main(){
    FAST();
    OJ();
    int test_cases = 1;
    cin>>test_cases;
    while (test_cases--){
        a();
    }
    return 0;   
}
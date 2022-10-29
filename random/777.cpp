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

/*
1 1
2 2
3 21 
4 121
5 212
6 2121
7 12121
8 21212
9 212121
10 1212121
11 2121212
// so at 3n+1 it starts with 1
*/
void a(){
    int n; cin>>n;
    string ans = "";
    bool flag = 1;
    if((n - 1 )% 3 == 0){
        flag = 0;
    }
    while(n--){
        if(flag){
            ans += '2';
            n --;
        }
        else {
            ans += '1';
        }
        flag = !flag;
    }
    cout << ans << "\n";
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
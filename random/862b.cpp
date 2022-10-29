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

void solve(){
    int n = 0; cin>>n;
    int a = 0, b = 0;
    int bp[n+1] = {0};
    bp[1] = 1;
    for(int i = 0; i < n-1; i++){
        int x,y; cin>>x>>y;
        if(bp[x] == 0){
            if(bp[y] == 1) bp[x] = 2;
            else bp[x] = 1;
        }
        else if (bp[y] == 0){
            // then this will be the one with the new edge being added
            if(bp[x] == 1) bp[y] = 2;
            else bp[y] = 1;
        }
    }
    for(int i = 1; i <= n; i++){
        if(bp[i] == 1) a++;
        else b++;
    }
    cout << a*b - n + 1 << "\n";
}

int main(){
    FAST();
    OJ();
    int test_cases = 1;
    //  cin>>test_cases;
    while (test_cases--){
        solve();
    }
    return 0;   
}


/*


*/
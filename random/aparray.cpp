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
    /*
    1 2 3 4 5
    3 6 9 12 15
    5 10 15 20 25
    7 14 21 28 35
    9 18 27 36 45

    1 2 3 4 5
    4 6 8 10 12
    7 10 13 16 18
    10 14 18 22 26
n = 5
m = 7
1   1 2 3 4 5 6 7
2   7
3   13
4   19
5   25

    5 6
    1 2 3 4 5
    1 7 13 19 25
    2
    3
    4
    5

    5 3
    1 5 9
    2 7 12
    3 9 15
    4 11 18
    5 13 21



    1 3 5 7 9
    2 6 10 14 18
    3 9 15 21 27
    4 12 20 28 36 
    5 15 25 35 45
    */

    int n,m; cin>>n>>m;
    if(n < m){
        int cd = 1;
        int a = 1;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cout << a + j*cd << " ";
            }
            a += n + 1;
            cd ++;
            cout << "\n";
        }
    }
    else{
        int cd  = m+1;
        int a = 1;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cout << a + j*cd << " ";
            }
            a++;
            cd++;
            cout << "\n";
        }
    }

    /*
    int n,m; cin>>n>>m;
    if(n < m){
        int cd = 1;
        int a = 1;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cout << a + j*cd << " ";
            }
            cd+=2;
            a += 2;
            cout << "\n";
        }
    }
    else{
        int cd = 2;
        int a = 1;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cout << a + j*cd << " ";
            }
            cd += 2;
            a++;
            cout << "\n";
        }
    }
    */
    return;
}

int main(){
    FAST();
    OJ();
    int test_cases = 1;
    cin>>test_cases;
    while (test_cases--){
        solve();
    }
    return 0;   
}
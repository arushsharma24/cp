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
    int a,b,c;
    cin>>a>>b>>c;
    vector<int> l;
    l.push_back(a);
    l.push_back(b);
    l.push_back(c);
    sort(l.begin(), l.end());
    a = l[0], b = l[1], c = l[2];
    if(a + b == c) cout << "YES\n";
    else{
        if(a == b && c%2 == 0){
            cout << "YES\n";
        }
        else if(b == c && a%2 == 0){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
    }
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
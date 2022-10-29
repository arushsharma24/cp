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
    unordered_map<int, int> m;
    int pre = 0;
    int pret, post;
    int n, x; cin>>n>>x;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin>>a[i];
    for(int tmp : a){
        int val = ++m[tmp];
        if(val > pre) pre = val, pret = tmp;
    }
    if(x == 0){
        cout << pre << " " << 0 << "\n";
        return;
    }
    unordered_map<int, int> xm;
    int pos = 0;
    for(int tmp : a){
        tmp ^= x;
        int val = ++xm[tmp];
        if(val > pos) pos = val, post = tmp;
    }
    if(pre == 1){
        for(auto itr : xm){
            if(m.find(itr.first) != m.end()){
                cout << "2 1\n";
                return;
            }
        }
    }
    int one = pre + xm[pret];
    int two = pos + m[post];
    int score, cost;
    if(one == two){
        score = one;
        cost = min(xm[pret], pos);
    }
    else if(one > two){
        score = one;
        cost = xm[pret];
    }
    else{
        score = two;
        cost = pos;
    }
    cout << score << " " << cost << "\n";
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
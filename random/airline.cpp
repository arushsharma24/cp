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

int solve(){
    int a,b,c,d,e;
    cin>>a>>b>>c>>d>>e;
    vector<int> arr = {a,b,c};
    int carry = 11;
    for(int w : arr){
        if (w > e) continue;
        if(carry == 11)
            carry = w;
        else carry = max(w, carry);
    }
    if(carry > e) return 0;
    int lugg = a + b + c - carry;
    if(lugg > d) return 0; 
    return 1;
}

int main(){
    FAST();
    OJ();
    int test_cases = 1;
    cin>>test_cases;
    while (test_cases--){
        if(solve()) cout << "yes\n";
        else cout << "no\n";
    }
    return 0;   
}
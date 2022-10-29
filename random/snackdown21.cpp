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

void luckynum(){
    int a, b, c; cin>>a>>b>>c;
    if (a == 7 || b == 7 || c == 7) cout << "YES\n";
    else cout << "NO\n";
    return;
}

void testmatchseries(){
    int score = 0;
    int x;
    for(int i = 0; i < 5; i++){
        cin>>x;
        if(x == 1) score++;
        else if(x == 2) score--;
    }
    if(score > 0){
        cout << "INDIA\n";
    }
    else if(score == 0){
        cout << "DRAW\n";
    }
    else{
        cout << "ENGLAND\n";
    }
    return;
}

void maxdistkt(){
    
}

int main(){
    FAST();
    OJ();
    int test_cases = 1;
    cin>>test_cases;
    while (test_cases--){
        testmatchseries();
    }
    return 0;   
}
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
#define yes cout << "YES\n"
#define no cout << "NO\n"

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
    int n; cin>>n;
    vector<int> v(n); 
    for(int i = 0; i < n; i++) cin>>v[i];
    vector<int> err;
    for(int i = 0; i < n-1; i ++){
        if(v[i+1] < v[i]) {
            err.push_back(i);
        }
        if(err.size() >= 2){
            cout << "NO\n";
            return;
        }
    }
    if(err.size()==0) cout << "YES\n";
    else if(err.size()==1){
        int i = err[0];
        // cout << v[i] << " " << v[i+1] << "\n";
        v[i] = v[i+1] ^ v[i];
        v[i+1] = v[i]^v[i+1];
        v[i] = v[i+1] ^ v[i];
        // cout << v[i] << " " << v[i+1] << "\n";
        // for(int i = 0; i < n; i++) cout << v[i] << " ";
        for(int i = 0; i < n-1; i++){
            if(v[i+1] < v[i]) {
                no;
                return;
            }
        }
        yes;
    }
    else no;
}

void s2(){
    int n; cin>>n;
    int v[n]; 
    for(int i = 0; i < n; i++) cin>>v[i];
    for(int i = 0; i < n-1; i++){
        if(v[i+1] < v[i]){
            swap(v[i+1],v[i]);
            for(int j = 0; j < n-1; j++){
                if(v[j+1] < v[j]) {
                    no;
                    return;
                }
            }
            yes;
            return;
        }
    }
    yes;
}

int main(){
    FAST();
    OJ();
    int test_cases = 1;
    cin>>test_cases;
    while (test_cases--){
        s2();
    }
    return 0;   
}


/*


*/
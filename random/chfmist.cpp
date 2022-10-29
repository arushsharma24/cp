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
    // vector<int> w(n); 
    unordered_map<double, double> w;
    double ws = 0;
    double x;
    for(int i = 0; i < n; i++) {
        cin>>x;
        w[x]++;
        ws+=x;
    }
    double mean = (double)((double)ws/(double)n);
    double ct = 0;
    for(auto it : w){
        if(it.first == mean){
            ct += (double)((double)(it.second * (it.second-1))/(double)2);
        }
        else if(it.first < 2*mean){
            if(w.find(2*mean - it.first) != w.end()){
                // exists
                ct += (double)(((double)(it.second * w[2*mean-it.first]))/(double)2);
            }
        }
    }
    cout << (ll)ct << "\n";
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


/*


*/
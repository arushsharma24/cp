#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
#define yes cout<<"YES\n"
#define no cout<<"NO\n"
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

void solvea(){
    int n,m,x; cin>>n>>m;
    int w = 0;
    bool flag = false;
    for(int i = 0; i < n; i++){
        cin>>x;
        if(flag) {
            w+=x;
            continue;
        }
        if(m < x){
            w += x-m;
            flag = true;
        }
        else m -= x;
    }
    cout << w << "\n";
    return;
}

void solveb(){ // galat
    ll n,q; cin>>n>>q;
    vector<ll> p(n);
    for(ll i = 0; i < n; i++) cin>>p[i];
    sort(p.begin(), p.end(), greater<>());
    vector<ll> sums(n);
    sums[0] = p[0];
    for(ll i = 1; i < n; i++){
        sums[i] = sums[i-1] + p[i];
    }
    while(q--){
        ll num = 0;
        ll x,y; cin>>x>>y;
        // start at x-y
        // end at x
        ll cost = sums[x-1];
        ll adisc = 0;
        if(x > y)  adisc = sums[x-y-1];
        num = cost - adisc;
        cout << num << "\n";
    }
}

void solvec(){
    int n; string s, t; 
    cin>>n>>s>>t;
    bool flag = true;
    if(n == 1){
        if(s == t) yes;
        else no;
        return;
    }
    for(int i = 0; i < n; i++){
        if(!flag) break;
        if(s == t) break;
        if(s[i] == t[i]) continue;
        else{
            if(s[i] == 'a' && t[i] == 'b'){
                int j = i+1;
                while(j < n){
                    if(s[j] == 'a') j++;
                    else if(s[j] == 'b'){
                        swap(s[i], s[j]);
                        break;
                    }
                    else{
                        flag = false;
                        break;
                    }
                }
                if(s[i] != t[i]) flag = false;
            }
            else if(s[i] == 'b' && t[i] == 'c'){
                int j = i+1;
                while(j < n){
                    if(s[j] == 'b') {
                        j++;
                    }
                    else if(s[j] == 'c'){
                        swap(s[i], s[j]);
                        break;
                    }
                    else{
                        flag = false;
                        break;
                    }
                }
                if(s[i] != t[i]) flag = false;
            }
            else{
                flag = false;
            }
        }
    }
    if(s != t) flag = false;
    if(flag) yes;
    else no;
}

int main(){
    FAST();
    OJ();
    int test_cases = 1;
    cin>>test_cases;
    while (test_cases--){
        solvec();
    }
    return 0;   
}
#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll n; cin>>n;
    vector<ll>a(n);
    ll sa = 0;
    vector<ll>b(n);
    ll sb = 0;
    ll i, j, k, ct;
    for(i = 0; i < n; i++){
        cin>>a[i];
        sa += a[i];
    }
    for (i = 0; i < n; i++)
    {
        cin>>b[i];
        sb += b[i];
    }
    vector<ll> diff;
    for (i = 0; i < n; i++)
    {
        diff.push_back(a[i] - b[i]);
        //cout<<diff.back()<<" ";
    }
    //cout<<"\n";
    
    if(sa != sb){
        cout<<"-1\n";
    }
    else{
        // make them equal
        vector<pair<int, int>>v;
        ll index = 0;
        for(i = 0; i < n; i++){
            if(diff[i] <= 0){
                continue;
            }
            // now i am at a +ve diff
            for(j = index; j < n; j++){
                if(diff[j] >= 0){
                    continue;
                }
                // case 1: abs(neg) > abs(pos)
                ct = min(abs(diff[i]), abs(diff[j]));
                for (ll k = 0; k < ct; k++)
                {
                    v.push_back(make_pair(i+1, j+1));
                    diff[i]--;
                    diff[j]++;
                }
                if(diff[i] == 0){
                    break;
                }
                if(diff[j] == 0){
                    continue;
                }
                index = j;
                /*
                if(abs(diff[j]) > abs(diff[i])){
                    // so diff[i] times we do the next thing
                    // ct += diff[i];
                    ct = diff[i];
                    for(k = 0; k < ct; k++){
                        v.push_back(make_pair(i+1,j+1));
                        diff[i]--;
                        diff[j]++;
                    }
                    index = j;
                    break;
                }
                else{
                    ct = abs(diff[j]);
                    for(k = 0; k < ct; k++){
                        v.push_back(make_pair(i+1, j+1));
                        diff[i]--;
                        diff[j]++;
                    }
                    index = j;
                    if(diff[i] == 0)    break;
                }
                */
            }
        }
        // now, v is my answer
        cout<<v.size()<<"\n";
        for(i = 0; i < v.size(); i++){
            cout<<v[i].first<<" "<<v[i].second<<"\n";
        }
    }

    
    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);    
    int test_cases = 1;
    cin>>test_cases;
    while (test_cases--){
        solve();
    }
    return 0;   
}
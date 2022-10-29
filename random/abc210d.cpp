#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll h, w, c;
    cin>>h>>w>>c;
    //cout<<"pity";
    vector<vector<ll>> a(h);
    vector<tuple<ll, ll, ll>> v;
    //vector<ll> nums(h*w);
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            ll x; cin>>x;
            a[i].push_back(x);
            //nums.push_back(x);
            v.push_back(make_tuple(x, i+1, j+1));
        }
    }
    //cout<<"banana\n";
    // for(int i = 0; i < h; i++){
    //     for(int j = 0; j < w; j++){
    //         cout<<a[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }
    
    // vector<ll> cost(h*w);
    sort(v.begin(), v.end());
    vector<ll> sum;
    //cout<<"banbanakdslfjadf";
    int tempi = (h*w) ;
    int tempj = tempi;
    for(int i = 0; i < tempi; i++){
        for(int j = i + 1; j < tempj; j++){
            ll x = get<0>(v[i]) + get<0>(v[j]) + c*(abs(get<1>(v[i]) - get<1>(v[j])) + abs(get<2>(v[i]) - get<2>(v[j])));
            if(i == 0 && j == 1){
                sum.push_back(x);
                continue;
            }
            if(sum.back() < x){
                break;
            }
            sum.push_back(x);
        }
    }

        sort(sum.rbegin(), sum.rend());

    for(int i = 0; i < h-1; i++){
        for(int j = 0; j < w-1; j++){
            ll x = a[i][j];
            ll right = x + a[i][j+1] + c;
            ll below = x + a[i+1][j] + c;
            ll diag = x + a[i+1][j+1] + 2*c;
            ll temp = min(right, below);
            temp = min(temp, diag);
            if(temp < sum.back()){
                sum.push_back(temp);
            }
        }
    }

    for(int j = 1; j < h; j++){
        ll x = a[j-1][w-1];
        ll y = a[j][w-1];
        ll temp = x + y + c;
        if(temp < sum.back()){
            sum.push_back(temp);
        }
    }

    for(int j = 1; j < w; j++){
        ll x = a[h-1][j-1];
        ll y = a[h-1][j];
        ll temp = x + y + c;
        if(temp < sum.back()){
            sum.push_back(temp);
        }
    }
    
    // also try a few side by sides
    sort(sum.begin(), sum.end());
    cout<<sum[0]<<"\n";
    // sort(nums.begin(), nums.end());
    // ll weirdnum = nums[1];
    // for cheapest railway, hmm
    // does it vary linearly? no idts
    
    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);    
    int test_cases = 1;
    // cin>>test_cases;
    while (test_cases--){
        solve();
    }
    return 0;   
}
#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    int n; cin>>n;
    vector<pair<int, int>> a;
    for (int i = 0; i < n; i++)
    {
        int x; cin>>x;
        a.push_back(make_pair(x, 0));
    }
    // i can implement bubble sort and keep track of number of times an element is swapped
    // implement bubble sort 
    bool done = 0;
    while(!done){
        for(int i = 0; i < n - 1; i++){
            if(a[i].first > a[i+1].first){
                swap(a[i], a[i+1]);
                a[i].second++;
                a[i+1].second++;
            }
        }
        // check if it has been sorted by now
        int ct = 0;
        for(int i = 0; i < n - 1; i++){
            if(a[i] <= a[i+1]){
                ct++;
            }
            else{
                break;
            }
        }
        if(ct == n-1)   done = 1;
    }

    // now check if all are right facing
    // that is, all should have value of second as even

    for(int i = 0; i < n; i++){
        if((a[i].second)%2){
            cout<<"NO\n";
            return;
        }
    }
    cout<<"YES\n";
    // ugh, this works but TLEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE
    return;
}

void solve2(){  // pretest passed, tle on main test 18 UGHHHHHH
    // find difference in index from actual position
    // if odd, fuck off and that is the only case, then break NO, if all even, yay
    //
    // for numbers which repeat, check for all repetitions and see which one has even
    int n; cin>>n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    vector<int> b = a;
    sort(b.begin(), b.end());
    int x; 
    // one issue, if one of multiple is taken, ummmm
    vector<bool> taken(n, 0);
    for(int i = 0; i < n; i++){
        x = a[i];
        auto it = lower_bound(b.begin(), b.end(), x);
        int fin = it - b.begin();
        while((fin - i)%2 || (((fin-i)%2 == 0)&&taken[fin])){
            fin++;
            if(fin > n-1){
                cout<<"NO\n";
                return;
            }
            if(b[fin] > x){
                cout<<"NO\n";
                return;
            }
        }
        //cout<<fin<<"k";
        taken[fin] = 1;
    }
    cout<<"YES\n";
    return;
}

void solve3(){
    // fukkkkkkkkkkkkkkkkkkkkk
    // such a sexy solutionnnnnnnnnnnn
    // dammn
    // i love maps
    // instead of so much calc, just see number of odd indexes
    // matches number of even indexes
    int n; cin>>n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    vector<int> b = a;
    sort(b.begin(), b.end());
    unordered_map<int, pair<int, int>> x;
    unordered_map<int, pair<int, int>> y;
    for(int i = 0; i < n; i++){
        if(i%2){ // odd : first; even: second
            x[a[i]].first++;
            y[b[i]].first++;
        }
        else{
            x[a[i]].second++;
            y[b[i]].second++;
        }
    }
    if( x == y ) cout<<"yes\n";
    else cout<<"no\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);    
    int test_cases = 1;
    cin>>test_cases;
    while (test_cases--){
        solve3();
    }
    return 0;   
}
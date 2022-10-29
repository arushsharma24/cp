#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    int k, n, m; cin>>k>>n>>m;
    vector<int> a(n);
    vector<int> b(m);
    int ct = k; // current number of lines
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin>>b[i];
    }
    vector<int> v;
    int ai = 0, bi = 0;
    for(int i = 0; i < n+m; i++){
        if(ai < n){
            if(a[ai] == 0){
                ct++;
                ai++;
                v.push_back(0);
                continue;
            }
            if(a[ai] > ct){
                // cannot be done by a
                // so go to b
                if(bi >= m){
                    cout<<"-1\n";
                    return;
                }
                if(b[bi] == 0){
                    ct++;
                    bi++;
                    v.push_back(0);
                    continue;
                }
                // if not 0, then it must be done by b
                // iske paas option hi nahi hai cuz ho jaega yaar chill kar
                if(b[bi] > ct){
                    cout<<"-1\n";
                    return;
                }
                // agar nahi ho sakta isse, toh kisi se nahi ho sakta
                // anyways, normal case hai agar toh
                v.push_back(b[bi]);
                bi++;
            }
            else{
                v.push_back(a[ai]);
                ai++;
            }
        }
        else{
            if(bi >= m){
                cout<<"-1\n";
                return;
            }
            // agar ai khatam, now just b gotta be okay
            if(b[bi] == 0){
                v.push_back(0);
                ct++;
                bi++;
                continue;
            }
            if(b[bi] > ct){
                cout<<"-1\n";
                return;
            }
            // ab tak yahi ho, toh normal case
            v.push_back(b[bi]);
            bi++;
        }
    }
    if(v.size() !=  n+m){
        cout<<"-1\n";
        return;
    }
    for(int i = 0; i < n+m; i++){
        cout<<v[i]<<" ";
    }
    cout<<"\n";
    return;
}

void solve2(){
    int k, n, m;
    queue<int> a, b;
    int x;
    int ct = k;
    for(int i = 0; i < n; i++){
        cin>>x;
        a.push(x);
    }
    for(int i = 0; i < m; i++){
        cin>>x;
        b.push(x);
    }
    vector<int> res;
    while(!a.empty() && !b.empty()){
        if(a.front() < b.front()){
            x = a.front();
            if( x == 0){
                ct++;
            }
            if(x > ct){
                cout<<"-1\n";
                return;
            }
            res.push_back(x);
            a.pop();
        }
        else{
            x = b.front();
            if( x == 0){
                ct++;
            }
            if ( x > ct){
                cout<<"-1\n";
                return;
            }
            res.push_back(x);
            b.pop();
        }
    }
    while(a.empty() && !b.empty()){
        x = b.front();
        if( x == 0){
            ct++;
        }
        if( x > ct ){
            cout<<"-1\n";
        }
        res.push_back(x);
        b.pop();
    }
    while(!a.empty() && b.empty()){
        x = a.front();
        if( x == 0){
            ct++;
        }
        if( x > ct ){
            cout<<"-1\n";
        }
        res.push_back(x);
        b.pop();
    }
    if(a.empty() && b.empty()){
        if(res.size() == n+m){
            for(int i = 0; i < n+m; i++){
                cout<<res[i]<<" ";
            }
            cout<<"\n";
        }
        else{
            cout<<"-1\n";
        }
    }
    else{
        cout<<"-1\n";
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
#include <bits/stdc++.h>
using namespace std;
#define ll long long


void solve2(){
    int n; cin>>n;
    vector<int> a, b;
    int min = INT_MAX;
    int imin;
    for(int i = 0; i < n; i++){
        int x; cin>>x;
        a.push_back(x);
        b.push_back(x);
        if(x < min) {
            min = x;
            imin = i;
        }
    }
/*
    //cout<<"mango"<<isSorted(a)<<"potato\n";

    sort(b.begin(), b.end());
    bool sorted = 1;
    
    if(isSorted(a)){
        cout<<"0\n";
        return;
    }
    if(a.front() == min) {
        cout<<"1\n";
        return;
    }
    if(a.back() == min){
        if(a.front() == b[1]){
            cout<<"2\n";
            return;
        }
        if(a.front() ==)
        cout<<"3\n";
        return;
    }
    // if all elements after min are sorted
    vector<int> post(a.begin() + imin + 1, a.end());
    //cout<<imin<<"yy "<<a[imin]<<" "<<isSorted(post)<<"\n";
    if(isSorted(post)){
        cout<<"1\n";
        return;
    }

    cout<<"2\n";
    return;
*/
}
bool isSorted(vector<int> a){
    vector<int> b;
    for(int i = 0; i < a.size(); i++){
        b.push_back(a[i]);
    }
    sort(b.begin(), b.end());
    for(int i = 0; i < a.size(); i++){
        if(a[i] != b[i])
            return 0;
    }
    return 1;
}

void solve(){
    int n; cin>>n;
    vector<int> a, b;
    for(int i = 0; i < n; i++){
        int x; cin>>x;
        a.push_back(x);
        b.push_back(x);
    }
    sort(b.begin(), b.end());
    if(isSorted(a)){
        cout<<"0\n";
        return;
    }
    /*
    int count = 0;
    for(int i = 0; i < n; i++){
        if(a[i] == b[n-i-1]) count++;
    }
    if(count == n){
        // then my array is in descending order
        cout<<"3\n";
        return;
    }
    */
    if(a.front() == b.back() && a.back() == b.front()){
        cout<<"3\n";
        return;
    }
    if(a.front() == b.front() || a.back() == b.back()){
        cout<<"1\n";
        return ;
    }
    cout<<"2\n";
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
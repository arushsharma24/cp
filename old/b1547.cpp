#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    string s; cin>>s;
    stack<int>st;
    int n = s.length();
    if(n == 1 && s != "a"){
        cout<<"no\n";
        return;
    }
    if(s == "a"){
        cout<<"yes\n";
        return;
    }
    int m = n;
    // length is between 1 and 26
    while(n > 1){
        char f = s.front();
        char b = s.back();
        int fi = (int) f;
        int bi = (int) b;
        //cout<<f<<" "<<b<<" "<<fi<<" "<<bi<<" ";
        if(fi == bi){
            cout<<"no\n";
            return;
        }
        if(fi > bi){
            s = s.substr(1, s.size()-1);
            st.push(fi);
        }
        else{
            st.push(bi);
            s.pop_back();
        }
        //cout<<st.top()<<"\n";
        n--;
    }
    int f = (int)s.front();
    if( f != 97 ){
        cout<<"no\n";
        return;
    }
    st.push(f);
    int x = st.top();
    st.pop();
    m--;
    while(m--){
        int y = st.top();
        if( y != x + 1){
            cout<<"no\n";
            return;
        }
        x = y;
        st.pop();
    }
    cout<<"yes\n";
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
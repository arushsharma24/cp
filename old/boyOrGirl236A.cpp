#include <bits/stdc++.h>
using namespace std;

int main(){
    string s; cin>>s;
    map<char, int> m;
    for(int i= 0; i < s.length(); i++){
        m[s[i]]++;
    }
    //cout<<m.size()<<" ";
    if(m.size()%2)
        cout<<"IGNORE HIM!\n";
    else
        cout<<"CHAT WITH HER!\n";
}
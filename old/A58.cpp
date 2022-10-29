#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin>>s;
    vector<char> letters;
    vector<char> hello = {'h', 'e', 'l', 'l', 'o'};
    for(int i = 0; i < s.length(); i++){
        letters.push_back(s[i]);
    }
    int n = letters.size();
    for(int i = 0; i < letters.size(); i++){
        if(letters[i] == hello[0]){
            hello.erase(hello.begin());
        }
        if(hello.size() == 0) break;
    }
    if(hello.size() == 0 ) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}
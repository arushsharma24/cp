#include <bits/stdc++.h>
using namespace std;

bool isVowel(char c){
    if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' || c == 'Y' ){
        return 1;
    }
    else return 0;
}

int main(){
    string s; cin>>s;
    string res = "";
    for(int i = 0; i < s.length(); i++){
        int x = (int)s[i];
        if(isVowel(s[i])){
            continue;
        }
        else{
            res += ".";
            if(x >= 65 && x <= 90){
                x += 32;
            }
            res += (char) x;
        }
    }
    cout<<res<<"\n";
}
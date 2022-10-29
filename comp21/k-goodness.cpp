#include <bits/stdc++.h>
using namespace std;

int Kgood(string s){
    int kgood = 0;
    for (int i = 0; i < s.length()/2; i++){
        if(s[i] != s[s.length()-i-1]){
            //cout<<s[i]<<" "<<s[s.length() - i]<<"\n";
            kgood++;
        }
    }
    return kgood;
}

int main(){
    int T;
    cin>>T;
    for(int t = 1; t <=T; t++){
        int N;
        cin>>N;
        int K;
        cin>>K;
        string S;
        cin>>S;
        string s(S);
        //cout<<Kgood(s)<<"\n";
        int kgood = Kgood(s);
        if(K>kgood){
            cout<<"Case #"<<t<<": "<<K-kgood<<"\n";
        }
        else{
            cout<<"Case #"<<t<<": "<<kgood-K<<"\n";
        }
    }
}
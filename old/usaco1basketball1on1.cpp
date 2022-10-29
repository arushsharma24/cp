#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;

    vector <int> A;
    vector <int> B;

    char player = 'A';

    for(int i = 0; i < s.length(); i++){
        if(i%2==0){
            if(s[i] == 'A'){
                player = 'A';
            }
            else{
                player = 'B';
            }
        }
        else{
            if(player == 'A'){
                A.push_back((int)s[i]);
            }
            else{
                B.push_back((int)s[i]);
            }
        }
    }
    int as = accumulate(A.begin(), A.end(), 0);
    int bs = accumulate(B.begin(), B.end(), 0);

    string res = as > bs ? "A" : "B";

    cout<<res<<"\n";    

    return 0;
}
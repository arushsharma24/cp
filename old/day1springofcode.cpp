#include <bits/stdc++.h>
using namespace std;

int main(){
    string a;
    cin>>a;
    int ascii[500] = {0};
    int len = a.length();
    //cout<<len<<endl;
    for (int i = 0; i < len; i++){
        int x = int(a[i]);
        ascii[x]++; 
       // cout<<"x : "<<x<<" ascii[x]: "<<ascii[x]<<endl;       
    }
    int max = 0;
    for (int i = 1; i < 500; i++){
        if(ascii[i] > ascii[max]){
            max = i;
        }
    }
    //cout<<max<<endl<<ascii[max]<<endl;
    //ascii[max] is the number of times the max word appears
    //max is the value ascii value of the corresponding character
    cout<<char(max)<<endl;
}
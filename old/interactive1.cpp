#include <bits/stdc++.h>
using namespace std;

int main(){
    int low = 1;
    int high = 1000000;
    int mid;
    string out;
    while(high>low){
        mid = (low + high + 1)/2;
        cout<<mid<<endl;
        cin>>out;
        if(out == ">="){
            low = mid;
        }
        else{
            high = mid-1;
        }
    }
    cout<<"! "<<low<<endl;
    exit(0);
    return 0;
}
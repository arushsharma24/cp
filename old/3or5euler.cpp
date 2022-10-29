#include <bits/stdc++.h>
using namespace std;

int main(){
    int sum = 0;
    int n = 1000;
    while(--n){
        if(n%3==0&&n%5!=0){
            sum += n;
        }
        if(n%5==0&&n%3!=0){
            sum += n;
        }
        if(n%5==0&&n%3==0){
            sum += n;
            //cout<<n<<" "<<sum<<endl;
        }
    }
    cout<<sum<<endl;
}
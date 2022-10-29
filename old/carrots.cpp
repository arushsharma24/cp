#include <iostream>
using namespace std;

int main(){
    int N;
    cin>>N;
    int p;
    cin>>p;
    string desc[N];
    for(int i = 0; i < N; i++){
        string x;
        cin>>x;
        desc[i] = x;
    }
    cout<<p<<endl;
}
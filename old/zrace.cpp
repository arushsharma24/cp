#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin>>N;
    for (int i=0;  i<N; i++){
        int Red;
        cin>>Red;
        int a;
        cin>>a;
        int b;
        cin>>b;
        int c;
        cin >>c;
        int d;
        cin>>d;
        if(Red>=a&&Red>=b&&Red>=c&&Red>=d){
            cout<<"Champions"<<endl;
        }
        else{
            cout<<-1<<endl;
        }
    }
}
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int g[4] = {0};
    for(int i = 0; i < n; i++){
        int x;
        cin>>x;

        switch (x)
        {
        case 1:
            g[0]++;
            break;
        case 2:
            g[1]++;
            break;            
        case 3:
            g[2]++;
            break;        
        case 4:
            g[3]++;
            break;
        default:
            break;
        }
    }
    //g built
    //cout<<g[0]<<" "<<g[1]<<" "<<g[2]<<" "<<g[3]<<endl;
    
    int add;
    
    /*
    if(g[0] > g[2]){
        add = g[2];
        g[0] -= g[2];
        add = add + g[0]/4 + g[0]%4;
    }
    else{
        add = g[2];
    }
    

    if(g[2]>g[0]){

    }
    */

    int add1=0, add2=0, add3=0, add4=0;
    add4 = g[3];

    if(g[2] <= g[0]){
        add3 = g[2];
        g[0] -= g[2];
    }
    else{
        add3 = g[2];
        g[0] = 0;
    }

    add2 = g[1]/2;
    if(g[1]%2 == 1){
        add2++;
        g[0] -= 2;
    }
    if(g[0] > 0){
        add1 = g[0]/4;
        if(g[0] % 4 != 0){
            add1++;
        }
    }
    /*
    if(g[0] == 0){
        add2 = g[1]/2 + g[1]%2;
    }
    else if(g[0] == 1){
        add2 = g[1]/2;
        if(g[1]%2 == 1){
            add2++;
            g[0]--;
        }
    }
    else {
        add2 = g[1]/2 + 
    }

    if(g[0] != 0){

    }
    */
    //cout<<add4<<" "<<add3<<" "<<add2<<" "<<add1<<endl;
    int res = add4 + add3 + add2 + add1;
    cout<<res<<endl;
}
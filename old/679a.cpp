#include <bits/stdc++.h>
using namespace std;

vector<bool> prime(101, 1);

void sieve(int n){
    for(int p = 2; p*p<=n; p++)
        if(prime[p] == true)
            for(int i = p*p; i <=n ; i+=p)
                prime[i] = false;
}

int main(){
    int count = 0;
    sieve(100);
    vector<int> p;
    for(int i = 2; i <= 100; i++)
        if(prime[i] == true)
            p.push_back(i);

    string x;

    
    
    // this gave wrong answer on tc 8,
    //cout<<"oyooyoyoyo\n";
    int i = 0;
    int num = 1;
    bool f = 0;
    bool l = 0;
    while(count < 2 && !f && !l){
        cout<<p[i]<<endl;
        cin>>x;
        if(x == "no"){
            i++;
            if(p[i] > 50) {
                l = 1;
                break;
            }
        }
        else{
            count++;
            num = p[i];
            i = 0;
            while(count<2 && !f && !l){
                if(p[i]*num > 100) {
                    l = 1;
                    break;
                }
                cout<<p[i]*num<<endl;
                cin>>x;
                if(x == "no"){
                    ++i;
                }
                else{
                    count++;
                    f = 1;
                    break;
                }
            }
        }
    }
    if(f) cout<<"composite"<<endl;
    else if(l) cout<<"prime"<<endl;
    else cout<<"prime"<<endl;
    return 0;
}

// 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 53, ...
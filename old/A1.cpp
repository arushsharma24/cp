#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m,a;
    cin>>n;cin>>m;cin>>a;
    int n1=1, m1=1;
    if(n%a == 0) n1=0;
    if(m%a == 0) m1=0;
    unsigned long long N = n/a + n1;
    unsigned long long M = m/a + m1;
    unsigned long long res = N*M;
    cout<<res<<endl;
}
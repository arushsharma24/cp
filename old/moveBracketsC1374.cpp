#include <bits/stdc++.h>
using namespace std;

int main(){
    int tc; cin>>tc;
    while (tc--){
        int n; cin>>n;
        string s; cin>>s;
        vector<int> v;
        for(int i = 0; i < n; i++){
            if((int)s[i] == 41)
                v.push_back(-1);
            else
                v.push_back(1);
        }
        int sum = 0;
        int count = 0;
        for(int i = 0; i < n; i++){
            sum += v[i];
            if(sum < 0){
                count++;
                sum++;
            }
            //cout<<v[i]<<"     "<<sum<<"     "<<count<<"\n";
        }
        cout<<count<<"\n";
    }
}
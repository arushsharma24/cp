#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007

void FAST(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

void OJ(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
}

// given a binary string that has to be sent across the two servers, find the minimum number of data packets it will be broken into
// data can only be sent in the form of special binary strings that have no two adajacent characters same


int getMinSubsequences(string s){
    int n = s.length();
    int dp[n+1];
    dp[0] = 0;
    dp[1] = 1;
    for(int i=2;i<=n;i++){
        if(s[i-1] == s[i-2]){
            dp[i] = dp[i-1] + 1;
        }
        else{
            dp[i] = dp[i-1];
        }
    }
    return dp[n];
}

int solve(string s){
    string rem = s;
    int n = s.length();
    ll ct = 0;
    while(rem.length() > 0){
        string x = "";
        for(int i=0;i<rem.length();i++){
            if(i == 0){
                continue;
            }
            else{
                if(rem[i] == rem[i-1]){
                    x += rem[i];
                }
            }
        }
        rem = x;
        ct++;
    }
    return ct;
}

int main(){
    FAST();
    // OJ();
    int test_cases = 1;
    // cin>>test_cases;
    while (test_cases--){
        cout << solve("010100") << "yo\n";
    }
        
    return 0;   
}

/*
#define ll long long int 
ll sol(vector<int>&a,int l,int r,int k,map<pair<ll,pair<ll,ll>>,ll>&m){
    if(k==0){
        return 0;
    }
    if(l==r && k>1){
        return -1e17;
    }
    if(m.find(mp(l,mp(r,k)))!=m.end()){
        return m[mp(l,mp(r,k))];
    }


    ll ans=-1e18;
    for(int i=l;i<=r;i++){
        ll tmp=a[i]+max(sol(a,l,i-1,k-1,m),sol(a,i+1,r,k-1,m));
        ans=max(ans,tmp);
    }
    return m[mp(l,mp(r,k))]=ans;
}


void fun(){
    fast_io
    ll tt;
    file();
    //cin>>tt;
    tt=1;
    ll cases=1;
    while(tt--)
    {   
        int n,k;
        cin>>n>>k;
        vector<int>a;
        for(int i = 0; i < n; i++){
            ll num;
            cin>>num;
            a.push_back(num);
        }
        map<pair<ll,pair< ll,ll > >,ll> m;
        int ans=sol(a,0,n-1,k,m);
        cout<<ans<<endl;
    }        
}
*/
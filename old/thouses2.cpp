#include <bits/stdc++.h>
using namespace std;

#define ll long long

void FAST() {	//FAST Input Output, DONT use both scnaf,printf / cin,cout , Use any ONE system
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

ll powM(ll x, ll y, ll m) {	//returns (a^b)%m ( ^ is exponent )
	ll ans = 1, r = 1;
	x %= m;
	while (r > 0 && r <= y)
	{
		if (r & y)
		{
			ans *= x;
			ans %= m;
		}
		r <<= 1;
		x *= x;
		x %= m;
	}
	return ans;
}

ll gcd(ll x, ll y) {	//returns gcd of two long long ints
	if (x == 0) return y;
	return gcd(y % x, x);
}

vector<vector<int>> vec;

void dfs(int val){
    cout<<val<<" ";
    for(const int& node : vec[val]){
        dfs(node);
    }
}

int maxSubtree(int val){
    int maxSize = 0;
    int maxHolder;
    for(const int& node2 : vec[val]){
        if(maxSize == 0){
            maxHolder = node2;
            //cout<<"run once\n";
        }
        if(vec[node2].size()>maxSize){
            maxSize = vec[node2].size();
            maxHolder = node2;
            //cout<<"Max holder changed!\n";
        }
    }
    return maxHolder;
}

// ************************************************** MAIN FUNC //

int main(){
    FAST();
    int t; cin>>t;
    while (t--){
        int n,x; cin>>n>>x;
        vec.resize(n+1);
        vector<int> values(n+1);
        for(int i = 0; i < n-1; i++){
            int u,v; cin>>u>>v;
            vec[u].push_back(v);
        }
        dfs(x);
        //cout<<"this line is run\n";
        cout<<endl<<maxSubtree(x)<<endl;;
    }
    return 0;
}
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

void merge(int a[], int b[], int n, int m) {
    // code here
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(a[i]>b[j]){
                swap(a[i],b[j]);
            }
        }
    }
    sort(b,b+m);
}

void printvv(vector<vector<int> > &a){
    for(auto it : a){
        for(auto itr : it){
            cout << itr << " ";
        }
        cout << "\n";
    }
}
void bs(){
    vector<vector<int > > a = {{1,5}, {3, 4}, {9, 8}, {4,7}};
    sort(a.begin(), a.end());
    printvv(a);
    vector<vector<int> > ans;
    vector<int> temp = a[0];
    for(auto it : a){
        if(it[0] <= temp[1]){
            temp[1] = max(temp[1], it[1]);
        }
        else{
            ans.push_back(temp);
            temp = it;
        }
    }
    ans.push_back(temp);
    cout << "\n";
    printvv(ans);
}

int strstr(string a, string b){
    int n = a.length();
    int m = b.length();
    if(m ==  0) return 0;
    for(int i = 0; i < n; i++){
        if(a[i] == b[0]){
            if(n-i-1 < m-1){
                break;
            }
            else{
                bool found = true;
                for(int j = 1; j < m; j++){
                    if(a[i+j] != b[j]){
                        found = false;
                        break;
                    }
                }
                if(found) return i;
            }
        }
    }
    return -1;
}

int main(){
    FAST();
    OJ();
    int test_cases = 1;
    cin>>test_cases;
    while (test_cases--){
        string a,b;
        cin>>a>>b;
        cout << strstr(a,b) << "\n";
    }
    return 0;   
}
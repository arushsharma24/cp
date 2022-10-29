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

void solve(){
    int n; cin>>n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin>>a[i];
    vector<int> leh(n, 1);// longest inc subsequence ending at that length
    int ans = 0;
    for(int i = 1; i < n; i++){
        int tmp = 0;
        for(int j = 0; j < i; j++){
            if(a[j] < a[i]){
                tmp = max(tmp, leh[j]);
            }
        }
        leh[i] += tmp;
        ans = max(ans, leh[i]);
    }
    cout << ans << "\n";
    return;
}

void solve2(){
    int n; cin>>n; 
    if(n == 0) {
        cout << "0\n"; return;
    }
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin>>a[i];
    int length = 1;
    vector<int> tail(n, 0);// basically sort of like an LIS except smaller newer elements keep getting added so that incase they gonna lead the future then they are there in the start already
    tail[0] = a[0];
    for(int i = 1; i < n; i++){
        auto itr = lower_bound(tail.begin(), tail.begin() + length, a[i]);
        if(itr == tail.begin() + length){
            tail[length++] = a[i];
        }
        else{
            *itr = a[i];
        }
    }
    for(int x : tail){
         cout << x << " ";
    }
    cout << "\n";
    cout << length << "\n";
    
}

int CeilIndex(std::vector<int>& v, int l, int r, int key)
{
    while (r - l > 1) {
        int m = l + (r - l) / 2;
        if (v[m] >= key)
            r = m;
        else
            l = m;
    }
 
    return r;
}
// Binary search (note boundaries in the caller)


int LongestIncreasingSubsequenceLength(std::vector<int>& v)
{
    if (v.size() == 0)
        return 0;
 
    std::vector<int> tail(v.size(), 0);
    int length = 1; // always points empty slot in tail
 
    tail[0] = v[0];
    for (size_t i = 1; i < v.size(); i++) {
 
        // new smallest value
        if (v[i] < tail[0])
            tail[0] = v[i];
 
        // v[i] extends largest subsequence
        else if (v[i] > tail[length - 1])
            tail[length++] = v[i];
 
        // v[i] will become end candidate of an existing
        // subsequence or Throw away larger elements in all
        // LIS, to make room for upcoming greater elements
        // than v[i] (and also, v[i] would have already
        // appeared in one of LIS, identify the location
        // and replace it)
        else
            tail[CeilIndex(tail, -1, length - 1, v[i])] = v[i];
    }
    for (int x : tail){
        cout << x << " ";
    }
    cout << "\n";
    return length;
}
void solve3(){
    int n; cin>>n; 
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin>>a[i];
    cout << LongestIncreasingSubsequenceLength(a) << "\n";
}

int main(){
    FAST();
    OJ();
    int test_cases = 1;
    // cin>>test_cases;
    while (test_cases--){
        solve2();
    }
    return 0;   
}
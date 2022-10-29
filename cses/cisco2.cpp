#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007

int TotalCustomerPenalties(vector<int> a){
    int n = a.size();
    int psum = 0;
    queue<pair<int, int> > q;
    for(int i = 0; i < n; i++){
        q.push({a[i], 0});
    }
    set<int> s;
    while(q.empty() == false) {
        int x = q.front().first;
        if(s.find(x) != s.end()){
            // penalize
            q.push({x+1, q.front().second+1});
        }
        else{
            psum += 10*(pow(2, q.front().second) - 1);
            s.insert(x);
        }
        q.pop();
    }
    return psum;
}

int main()
{
    vector<int> a = {1, 1, 1};
    cout << TotalCustomerPenalties(a) << "\n";
 
    return 0;
}
/*

// Function to print answer
void printAnswer(int N,
                 vector<vector<int> > edges)
{
 
    // Setting parent to itself
    for (int i = 0; i <= N; i++) {
        parent[i] = i;
    }
 
    // Traverse all edges
    for (int i = 0; i < edges.size(); i++) {
        connect(edges[i][0], edges[i][1]);
    }
 
    // Print answer
    connectedComponents(N);
}

void solve(){

    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);    
    int test_cases = 1;
    cin>>test_cases;
    while (test_cases--){
        solve();
    }
    return 0;   
}
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007

// C++ program for the above approach
 
#include <bits/stdc++.h>
using namespace std;
 
int parent[1000000];

int root(int a)
{
    if (a == parent[a]) return a;
    return parent[a] = root(parent[a]);
}
 
void connect(int xx, int yy)
{
    xx = root(xx); yy = root(yy);
    if (xx != yy) parent[yy] = xx;
}

int connectedComponents(int n){
    set<int> s;
    for (int i = 0; i < n; i++) s.insert(root(parent[i]));
    return s.size();
}


int NumberOfMailRooms(int numB, int conns, vector<int> bx, vector<int> by){
    fill(parent, parent+1000000, 0);
    vector<vector<int> > edges;
    for(int i = 0; i < conns; i++)  edges.push_back({bx[i], by[i]});
    for (int i = 0; i <= numB; i++) parent[i] = i;
    for (int i = 0; i < edges.size(); i++) connect(edges[i][0], edges[i][1]);
    return connectedComponents(numB);
}
 
// Driver Code
int main()
{
    // Given N
    int N = 8;
 
    // Given edges
    vector<vector<int> > edges = {
        { 1, 0 }, { 0, 2 }, { 5, 3 }, { 3, 4 }, { 6, 7 }
    };
    vector<int> bx = {1, 0, 5, 3, 6, 1};
    vector<int> by = {0, 2, 3, 4, 7, 0};
    // Function call
    cout << NumberOfMailRooms(N, 6, bx, by) << "\n";
    return 0;
}
#include <bits/stdc++.h>

using namespace std;

vector <int> v[15];
bool vis[15];

void dfs(int s) {
	//cout << s << " ";
	vis[s] = true;
	for (int i = 0; i < v[s].size(); i++) {
		if (vis[v[s][i]] == false) {
			dfs(v[s][i]);
		}
	}
}

int main() {
	int n, e;
	cin >> n >> e;
	for (int i = 0; i <= n; i++) {
		v[i].clear();
	}

	for (int i = 0; i < conns; i++) {
		//cout << x << " " << y << endl;
		v[bx[i]].push_back(by[i]);
		v[by[i]].push_back(bx[i]);
	}
	memset(vis, false, sizeof(vis));
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (vis[i] == false) {
			dfs(i);
			cnt++;
		}
	}
	cout << cnt << endl;
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
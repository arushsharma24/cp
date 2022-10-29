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

void solveb(){
    int n; cin>>n;
    vector<int> a(n);
    vector<int> b(n);
    for(int i = 0; i < n; i++) cin>>a[i];
    for(int i = 0; i < n; i++) cin>>b[i];
    bool f1 = false;
    for(int i = 0; i < n; i++){
        if(b[i] > 0) {
            f1 = true; 
            break;
        }
    }
    if(!f1){
        cout << "YES\n";
        return;
    }
    int mpd = INT_MAX;
    int mpdi = -1;
    for(int i = 0; i < n; i++){
        if(b[i] > 0 && a[i] >= b[i]){
            if(mpd > a[i] - b[i]){
                mpd = a[i] - b[i];
                mpdi = i;
            }
        }
    }
    if(mpdi == -1){
        // no array element eligible
        cout << "NO\n";
        return;
    }
    for(int i = 0; i < n; i++){
        a[i] -= mpd;
        if(a[i] < 0) a[i] = 0;
    }
    bool ans = true;
    for(int i = 0; i < n; i++){
        if(a[i] != b[i]){
            ans = false;
            break;
        }
    }
    if(ans) cout << "YES\n";
    else cout << "NO\n";
    return;
}

void solvea(){
    int n; cin>>n;
    int f, s, t;
    if(n % 3 == 0){
        f = n/3 + 1;
        s = n/3 ;
        t = n/3 - 1;
    }
    else if( n %3 == 1){
        f = n/3 + 2;
        s = n/3;
        t = n/3 - 1;
    }
    else {
        f = n/3 + 2;
        s = n/3 + 1;
        t = n/3 - 1;
    }
    cout << s << " " << f << " " << t << "\n";
    return;
}


void solvec(){
    int n; cin>>n;
    vector<int> st(n);
    vector<int> fin(n);
    for(int i = 0; i < n; i++) cin>>st[i];
    for(int i = 0; i < n; i++) cin>>fin[i];
    int lftime = 0;
    vector<int> dur(n, 0);
    for(int i = 0; i < n; i++){
        if(lftime <= st[i]){
            // then i can start this task
            dur[i] = fin[i] - st[i];
            lftime = fin[i];
        }
        else{
            dur[i] = fin[i] - lftime;
            lftime = fin[i];
        }
    }
    for(int i = 0; i < n; i++) cout << dur[i] << " ";
    cout << "\n";
    return;
}

void solved(){
    int n,k; cin>>n>>k;
    string s; cin>>s;
    int ct = 0;
    for(int i = 0; i < k; i++){
        if(s[i] == 'W') ct++;
    }
    int mb = ct;
    for(int i = k; i < n; i++){
        if(s[i] == 'W') ct++;
        if(s[i-k] == 'W') ct--;
        if(ct < mb) mb = ct;
    }
    cout << mb << "\n";
}

void solvee(){
    int n,k; cin>>n>>k;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin>>a[i];
    map< int, vector<int> > m;
    ll ans = 0;
    for(int i = 0; i < n; i++){
        m[(a[i]%k)].push_back(i);
    }
    cout << "hello";
    int ex0 = 0;    // extra element for mod 0
    // first we can find out the pairs which can be paired up to cut all losses
    for(auto it : m){
        int mdl = it.first;
        if(mdl == 0){
            for(int i = 0; i < m[mdl].size()-1; i+=2){
                ans += (a[m[mdl][i]] + a[m[mdl][i+1]])/k;
                cout << "z";
            }
            if(m[mdl].size()%2) ex0 = m[mdl].back();
            m[mdl].clear();
            continue;
        }
        cout << " a ";
        while(m[mdl].size() != 0 || m[k-mdl].size() != 0){
            ans += (a[m[mdl].back()] + a[m[k-mdl].back()])/k;
            cout << mdl << ";";
            m[mdl].pop_back();
            m[k-mdl].pop_back();
        }
    }
    // then we should minimize our losses by clubbing the higher ones with those lower ones which make it > k
    
    cout << ans << "\n";
}

void solveee(){
    ll n,k; cin>>n>>k;
    vector<ll> a(n);
    ll price = 0;
    for(int i = 0; i < n; i++) {
        cin>>a[i];
        price += a[i]/k;
        a[i] = a[i]%k;
    }
    sort(a.begin(), a.end());
    int i = 0, j = n-1;
    while(i < j){
        if(a[i] + a[j] >= k){
            price++;
            i++;
            j--;
        }
        else{
            i++;
        }
    }
    cout << price << "\n";
}

string f(int input1, string input2){
    string b,c;
    // int n; cin>>n>>input2;
    while(input2.length() != 0 || b.length() != 0){
        if(input2.length() == 0){
            // now just add all the remaining b to c
            for(int i = 0; i < b.length(); i++){
                c += b[b.length() - i - 1];
            }
            break;
        }
        else if(b.length() == 0){
            // this is where we start
            b += input2[0];
            int m = input2.length();
            input2 = input2.substr(1, m-1);
        }
        else{
            // main cases
            // either do move 1 or move 2
            if((int)input2[0] <= (int)b[b.length()-1]){
                // first element of a is less, so pass it on to b
                b += input2[0];
                int m = input2.length();
                input2 = input2.substr(1, m-1);
            }
            else{
                c += b[b.length() - 1];
                b.pop_back();
            }
        }
        // cout << "a: " << a << " b: " << b << " c: " << c << "\n";
    }
    return c;
}

string func(int input1, string input2){
    string b,c;
    int n = input1;
    string a = input2;
    string s = input2;
    int j = 0;
    sort(s.begin(), s.end());
    for(int i = 0; i < n; i++){
        if(s[j] == a[i]){
            c+= s[j];
            j++;
        }
        else{
            b += a[i];
        }
    }
    for(int i = 0; i < b.length(); i++){
        c += b[b.length() -1 - i];
    }
    return c;
}

int main(){
    FAST();
    OJ();
    int test_cases = 1;
    cin>>test_cases;
    while (test_cases--){
        int n; string a; cin>>n>>a;
        string s = func(n,a);
        cout << s << endl;
    }
    return 0;   
}
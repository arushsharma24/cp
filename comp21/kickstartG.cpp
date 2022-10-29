#include <bits/stdc++.h>
using namespace std;
#define ll long long

string dogsandcats(){
    ll n, d, c, m;
    cin>>n>>d>>c>>m;
    string s;
    cin>>s;
    int flag = 0;
    int idx;
    for(int i = 0; i < n; i++){
        // loop through string
        if(s[i] == 'D'){
            if(d){
                // feed dog
                d--;
                c += m;
            }
            else{
                // no dog food
                flag = -1;
                break;
            }
        }
        else{
            // cat
            if(c){
                c--;
            }
            else{
                flag = -2;
                idx = i;
                break;
                // line stopped
            }
        }
    }
    if(flag == 0){
        // all fed
        return "YES";
    }
    else if( flag == -1 ){
        return "NO";
    }
    else if(flag == -2){
        for(int i = idx; i < n; i++){
            if(s[i] == 'D'){
                return "NO";
            }
        }
        return "YES";
    }
    return "YES";
}// passed

vector<pair<pair<int, int>, pair<int, int> > > furn;


int dist(int x, int y){
    int dx = 0, dy = 0;
    int sum = 0;
    for(int i = 0; i < furn.size(); i++){
        // each furniture
        // find min dist from this furniture
        if((x - furn[i].first.first) * (x - furn[i].first.second) <= 0){
            // then it is in line in x, so dx = 0
            dx = 0;
        }
        else{
            dx = min(abs(x -furn[i].first.first), abs(x - furn[i].first.second));
        }
        if((y - furn[i].second.first) * (y - furn[i].second.second) <= 0){
            // then it is in line in x, so dx = 0
            dy = 0;
        }
        else{
            dy = min(abs(y -furn[i].second.first), abs(y - furn[i].second.second));
        }
        sum += dx + dy;
    }
    return sum;
}

string stayHydratedBrute(){
    ll k; cin>>k;
    int d = 100000000;
    int ansx = 0, ansy = 0;
    // basically, check all points on the plane
    int minx = 100001, miny = 100001, maxx = -100001, maxy = -100001;
    int txa, txb, tya, tyb;
    for(int i = 0; i < k; i++){
        cin>>txa>>tya>>txb>>tyb;
        furn.push_back({{txa, txb}, {tya, tyb}});
        if(txa < minx) minx = txa;
        if(txb < minx) minx = txb;
        if(txa > maxx) maxx = txa;
        if(txb > maxx) maxx = txb;
        if(tya < miny) miny = tya;
        if(tyb < miny) miny = tyb;
        if(tya > maxy) maxy = tya;
        if(tyb > maxy) maxy = tyb;       
    }    
    // now, compare each point using dist function
    for(int x = minx; x <= maxx; x++){
        for(int y = miny; y <= maxy; y++){
            // cout << x << "&" << y << "; ";
            int tmp = dist(x,y);
            // cout << tmp << " ";
            if(tmp < d){
                ansx = x;
                ansy = y;
                d = tmp;
                // cout << d << " " << x << " " << y<< "\n";
            }
            else if(tmp == d){
                if(x < ansx){
                    ansx = x;
                    ansy = y;
                }
                else if(x == ansx){
                    if(y < ansy) ansy = y;
                }
            }
        }
    /*
    */
    }
    return to_string(ansx) + " " + to_string(ansy);
}

string stayHydrated(){
    ll k; cin>>k;
    int d = 100000000;
    int xd = d, yd = d;
    int ansx = 0, ansy = 0;
    // approach: 
    // first find minimum for y = 0;
    // then check for all y at that x
    int minx = 100001, miny = 100001, maxx = -100001, maxy = -100001;
    int txa, txb, tya, tyb;
    for(int i = 0; i < k; i++){
        cin>>txa>>tya>>txb>>tyb;
        furn.push_back({{txa, txb}, {tya, tyb}});
        if(txa < minx) minx = txa;
        if(txb < minx) minx = txb;
        if(txa > maxx) maxx = txa;
        if(txb > maxx) maxx = txb;
        if(tya < miny) miny = tya;
        if(tyb < miny) miny = tyb;
        if(tya > maxy) maxy = tya;
        if(tyb > maxy) maxy = tyb;       
    }    
    // now, for fixed y = 0, let us find minimum valued x
    for(int x = minx; x <= maxx; x++){
        int tmp = dist(x, 0);
        if(tmp < xd){
            xd = tmp;
            ansx = x;
        }
        break;
    }
    for(int y = miny; y <= maxy; y++){
        int tmp = dist(0, y);
        if(tmp < yd){
            yd = tmp;
            ansy = y;
        }
        else break;
    }
    return to_string(ansx) + " " + to_string(ansy);
}

ll bb(){
    ll n, k;
    cin>>n>>k;
    vector<ll> b(n);
    ll ans = n+1;
    for(int i = 0; i < n; i++){
        cin>>b[i];
    }
    // first consider one contiguous subsegment of the tree
    ll sum = 0;
    for(int i = 0; i < n; i++){
        sum = b[i];
        if(sum == k) ans = 1;
        for(int j = i; j < n; j++){
            if(i!=j) sum += b[j];
            if(sum == k) ans = j - i + 1 < ans ? j - i + 1: ans;
            if(sum > k) break; 
        }
    }
    //
    // now consider 2 contiguous sections
    ll sum2 = 0;
    for(int i = 0; i < n; i++){
        sum = b[i];
        for(int j = i; j < n; j++){
            if(i!=j) sum += b[j]; // sum of first section
            for(int ii = j + 2; ii < n; ii++){
                sum2 = b[ii];
                for(int jj = ii; jj < n; jj++){
                    if(ii != jj) sum2 += b[jj];
                    if(sum + sum2 == k) ans = jj - ii + 1 + j - i + 1 < ans ? jj - ii + 1 + j - i + 1: ans;
                    if(sum + sum2 > k) break;
                }
            }
        }
    }
    return ans != n + 1 ? ans : -1;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);    
    // cout << "oyy\n";
    int test_cases = 1;
    cin>>test_cases;
    int case_num = 1;
    while (test_cases--){
        cout<<"Case #"<<case_num<<": "<< stayHydrated() <<"\n";
        furn.clear();
        case_num++;
    }
    return 0;   
}
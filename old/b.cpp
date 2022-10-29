#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<vector<int>>rx;

void solve(){   // tle on pretest 2 :(
    int n; cin>>n;
    bool found = 0;
    vector<vector<int>>r(n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 5; j++){
            int x; cin>>x;
            r[i].push_back(x);
        }
    }
    vector<bool> lost(n, false);    // atheletes who have lost atleast once, and therefore can never win ;-;

    if(n == 1){
        cout<<"1\n";
        return;
    }
    int winner = -1;
    for(int i = 0; i < n; i++){
        if(lost[i]) continue;
        // cout<< i << " i ";
        for(int j = 0; j < n; j++){
            if(i == j) continue;
            int si = 0, sj = 0;
            for(int k = 0; k < 5; k++){
                // compare the 5 matches
                if(r[i][k] < r[j][k]){
                    // if i is superior
                    si++;
                }
                else{
                    sj++;
                }
            }
            if(si >= 3){
                lost[j] = true;
                if( i != n-1 && j == n-1){
                    winner = i;
                    found = 1;
                }
                else if( i == n-1 && j == n-2){
                    winner = i;
                    found = 1;
                }
            }
            else if(sj >= 3){
                lost[i] = true;
                break;
            }
            
        }
        if(found) break;
    }
    if( winner == -1) cout<<"-1\n";
    else{
        cout<<winner+1<<"\n";
    }
    return;
}

void solve2(){
    int n; cin>>n;
    vector<vector<int>>r(n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 5; j++){
            int x; cin>>x;
            r[i].push_back(x);
        }
    }    
    if(n == 1){
        cout<<"1\n";
        return;
    }
    // i think i was right initially; i wasn't 
    int winner = -1;
    int ath = 0;    // current winner
    for(int i = 1; i < n; i++){
        int si = 0, sj = 0;
        for(int k = 0; k < 5; k++){
            // compare the 5 matches
            if(r[ath][k] < r[i][k]){
                // if ath is superior
                si++;
            }
            else{
                sj++;
            }
        }
        if(si >= 3){
            // if ath won
            // proceed to next guy
            // unless you already king baby
            if(ath != n-1 && i == n-1){
                winner = ath;
                // break;
            }
            // else proceed
        }
        else{
            ath = i;
            if(i == n-1){
                winner = n-1;
                // break;
            }
        }        
    }
    for(int i = 0; i < n; i++){ // check if winner actually won
        if(i == winner) continue;
        int sw = 0, si = 0;
        for(int k = 0; k < 5; k++){
            // compare the 5 matches
            if(r[winner][k] < r[i][k]){
                // if ath is superior
                sw++;
            }
            else{
                si++;
            }
        }
        if(sw < 3){
            winner = -1;
            break;
        }
    }
    if(winner == -1) cout<<"-1\n";
    else{
        cout<<winner+1<<"\n";
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);    
    int test_cases = 1;
    cin>>test_cases;
    while (test_cases--){
        solve2();
    }
    return 0;   
}
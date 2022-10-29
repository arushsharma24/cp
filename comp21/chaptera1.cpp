#include <bits/stdc++.h>
#include <chrono>
using namespace std;
using namespace std::chrono;
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

void printv(vector<int> &a){
    for(int x : a) cout << x << " ";
    cout << "\n";
}

int solve(string s){
    unordered_map<char, int> vow;
    int nvow = 0;
    unordered_map<char, int> cons;
    int ncons = 0;
    int lvow = 0, lcons = 0;
    for(char c : s){
        if(c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U'){
            vow[c]++;
            nvow++;
            if(vow[c] > lvow) lvow = vow[c];
        }
        else{
            cons[c]++;
            ncons++;
            if(cons[c] > lcons) lcons = cons[c];
        }
    }
    if(vow.size() < 1 || cons.size() < 1){
        if(vow.size() < 1){
            if(cons.size() <= 1) return 0;
            else return ncons;
        }
        else{
            if(vow.size() <=1) return 0;
            else return nvow;
        }
    }
    else if(vow.size() == 1 && cons.size() > 1){
        int num = 0;
        for(auto itr : vow) num += itr.second;
        return s.size() - num;
    }
    else if(cons.size() == 1 && vow.size() > 1){
        int num = 0;
        for(auto itr : cons) num += itr.second;
        return s.size() - num;
    }
    else {//if(vow.size() > 1 && cons.size() > 1){
        if(nvow < ncons){
            // final letter will be a vowel
            return ncons + 2*(nvow - lvow);
        }
        else{
            return nvow + 2*(ncons - lcons);
        }
    }
}

int main(){
    FAST();
    OJ();
    int tcases; cin>>tcases;
    for (int i = 1; i <= tcases; i++)
    {
        string s; cin>>s;
        cout << "Case #" << i << ": " << solve(s) << "\n";
    }
    
}
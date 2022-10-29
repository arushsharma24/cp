#include <bits/stdc++.h>
using namespace std;
#define ll long long

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

string solve(){
    string n; cin>>n;
    string s = n;//to_string(n);
    ll sum = 0;
    for(ll i = 0; i < s.length(); i++){
        sum += s[i] - '0';
        if(sum > 18) sum -= 9;
    }
    ll diff = sum % 9;
    if(diff != 0) diff = 9 - diff;
    // now i should add this number at the first position where diff is smaller
    string pre = "";
    string ans = "";
    bool flag = 0;
    for(ll i = 0; i < s.length(); i++){
        if(diff == 0 && i == 0){
            // then do not consider i == 0
            pre += s[i];
            continue;
        }
        if(diff < (int)(s[i] - '0')){
            // insert at this spot
            ans = pre;
            ans += to_string(diff);
            flag = 1;
            for(ll j = i; j < s.length(); j++){
                ans += s[j];
            }
            break;
        }
        else{
            pre += s[i];
        }
    }
    if(flag) return ans;
    else return s + to_string(diff);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);    
    OJ();
    int test_cases = 1;
    cin>>test_cases;
    int case_num = 1;
    while (test_cases--){
        cout<<"Case #"<<case_num<<": "<<solve()<<"\n";
        case_num++;
    }
    return 0;   
}
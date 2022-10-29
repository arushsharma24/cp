#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
#define rep(i,n) for(i=0; i<n; i++)
#define repa(i,a,n) for(i=a; i<n;i++)
#define repit(x, k) for(auto x:k)
#define vi vector<int>
#define vll vector<ll>
#define vvll vector<vector<ll>>
#define vvi vector<vector<int>>
#define fi first
#define se second
#define pb(t) push_back(t)
#define ins(t) insert(t)
#define mp(a,b) make_pair(a, b)
#define mset(a, val) memset(a, val, sizeof(a))
#define all(v) v.begin(), v.end()
 
#define SPEED ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
 
#define M 1000000007 // 9 zeros + 5
#define epsilon 1e-9
#define PI  3.14159265
#define INF 1e9+5
#define INFF  1000000000000000005ll //18 zeros + 5
 
int main(){
  SPEED;
  ll i,j,k;
  
  
  int t;
  cin>>t;
  while(t--){
    
    int n;
    cin>>n;
    string s;
    cin>>s;
    vi bucket(26, 0);
    bool flag=true;
    string MEX;
 
    string temp="a";
    while(flag){
      int present=0;
      rep(i, n){
        if(s.substr(i,temp.size())==temp){
          present =1;
          break;
        }
      }
 
      if(present!=1){
        MEX=temp;
        flag=false;
        break;
      }
      j= temp.size()-1;
      bool ok=false;
      while(!ok){
        if(temp[j]!='z'){
          int c = (int)(temp[j]);
          c++;
          temp[j] = (char)c;
          ok=true;
        }
        else if(temp[j]=='z' && j!=0){
          temp[j]='a';
          j--;
        }
        else if(temp[j]=='z' && j==0){
          temp[j]='a';
          temp+='a';
          ok=true;
        }
      }
      
    }
 
 
    cout<<MEX<<endl;
 
  }
 
 
  return 0;
}
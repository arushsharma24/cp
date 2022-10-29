#include <bits/stdc++.h>

typedef long long int ll;
typedef long double ld;
using namespace std;
//#define P 1000000007
#define P 998244353
#define rep(i,n) for(i=0;i<n;++i)
#define re(i,a,n) for(i=a;i<=n;++i)
#define repr(i,a,n) for(i=a;i>=n;--i)
#define pb push_back
#define mp make_pair
#define fi first
#define se second

#define ub(v,val) upper_bound(v.begin(),v.end(),val)
#define np(str) next_permutation(str.begin(),str.end())
#define lb(v,val) lower_bound(v.begin(),v.end(),val)
#define sortv(vec) sort(vec.begin(),vec.end())
#define rev(p) reverse(p.begin(),p.end());
#define mset(a,val) memset(a,val,sizeof(a));
#define at(s,pos) *(s.find_by_order(pos))
#define set_ind(s,val) s.order_of_key(val)
#define PI 3.14159265
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

/*#include <ext/pb_ds/assoc_container.hpp> // Common file  
#include <ext/pb_ds/tree_policy.hpp>  
#include <functional> // for less  
#include <iostream>  
// Important header files   
using namespace __gnu_pbds;  
using namespace std;  
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;*/


ll binpowmod(ll a, ll b, ll m) {
    a %= m;
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}


long long modInverse(unsigned long long n, 
                                            int p)
{
    return binpowmod(n, p - 2, p);
}






int main() 
{
  IOS;
 
  ll j,k,i,f,h,l,r,t1,t2,x,ans,y,tc,p,c,t3,m,u,q,a,w,n,t,d;
  cin >> t;
  re(tc,1,t)
  {
    string s;
    cout << "Case #" << tc << ": " ;
    cin >> n ;
    cin >> s ;
    vector<string> v;
    string temp1="";
    v.pb(temp1);
    string s1;
    rep(i,4)
    {
      vector<string> temp;
      for(auto it:v)
      {
        s1=it;
        if(s[i]=='?')
        {
          s1+='0';
          temp.pb(s1);
          s1=it;
          s1+='1';
          temp.pb(s1);
        }
        else 
          {
            s1+=s[i];
            temp.pb(s1);
          }
      }
      v=temp;
    }
    i=4;
    vector<string> temp;
    for(auto it:v)
    {
        s1=it;

        if(s[i]=='?')
        {
          if(s1[1]==s1[3])
          {
            if(s1[0]=='1')
            {
              s1+='0';
              temp.pb(s1);
            }
            else
            {
              s1=it+'1';
              temp.pb(s1);
            }
          }
          else
          {
            s1+='0';
            temp.pb(s1);
            s1=it+'1';
            temp.pb(s1);
          }
          
        }
        else 
          {
            if(s1[1]!=s1[3]||s1[0]!=s[i])
            temp.pb(s1+s[i]);
        }
      }
      v=temp;
      // cout << endl ;
      //   for(auto it:v) cout << it << endl ;
      //   cout << endl << endl ;
    for(i=5;i<n;++i)
    {
      vector<string> temp;
      for(auto it:v)
      {
        
        if(s[i]=='?')
        {
          s1=it+'0';
          f=0;
          rep(j,3)
          {
            if(s1[j]!=s1[5-j]) f=1;
          }
          t1=0;
          rep(j,2)
          {
            if(s1[1+j]!=s1[5-j]) t1=1;
          }
          if(f&&t1) temp.pb(s1.substr(1,5));
          s1=it+'1';
          f=0;
          rep(j,3)
          {
            if(s1[j]!=s1[5-j]) f=1;
          }
          t1=0;
          rep(j,2)
          {
            if(s1[1+j]!=s1[5-j]) t1=1;
          }
          if(f&&t1) temp.pb(s1.substr(1,5));
        }
        else 
        {
          s1=it+s[i];
          f=0;
          rep(j,3)
          {
            if(s1[j]!=s1[5-j]) f=1;
          }
          t1=0;
          rep(j,2)
          {
            if(s1[1+j]!=s1[5-j]) t1=1;
          }
          if(f&&t1) temp.pb(s1.substr(1,5));
        }

      }
      v=temp;
      // for(auto it:v) cout << it << endl ;
      //   cout << endl << endl ;
      
    }
    if(v.size()!=0) cout << "POSSIBLE" << "\n" ;
    else cout << "IMPOSSIBLE" << "\n" ;


  }
  




    

  

  return 0 ;
}
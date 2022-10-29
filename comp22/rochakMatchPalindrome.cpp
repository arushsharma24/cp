#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <bits/stdc++.h>
#include <cmath>
#include <cstdio>

using namespace std;

#define ll long long
#define ld long double
#define lli long long int
#define pll pair<ll, ll>
#define pii pair<int, int>
#define pdd pair<double, double>
#define ordered_set tree<pll, null_type, less<pll>, rb_tree_tag, tree_order_statistics_node_update>

#define pb push_back
#define mp make_pair
#define rep(i, a, b) for (ll i = a; i < b; i++)
#define nrep(i, a, b) for (ll i = a; i >= b; i--)

#define sortv(v) sort(v.begin(), v.end())
#define rev(p) reverse(p.begin(), p.end())

#define v vector
#define pii pair<int, int>

#define fi first
#define se second
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
#define PI 3.14159265358979323846
#define len lenght()

#define ub(v, val) upper_bound(v.begin(), v.end(), val)
#define lb(v, val) lower_bound(v.begin(), v.end(), val)

#define IOS                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

long long int mod = 1000000007;
long long int inf = 9 * 1e18;
const ll maxn = 2e5 + 100;

// Sieve of Eratosthenes
const int MAXN = 1.1e6;
int spf[MAXN];
void sieve()
{
    for (int i = 1; i < MAXN; i++)
        spf[i] = 1;
    for (int i = 2; i * i < MAXN; i++)
    {
        for (int j = i * i; j < MAXN; j += i * i)
            spf[j] = i;
    }
}

// Factorials and Inverse Factorials
ll fact[MAXN], inv[MAXN], invFact[MAXN];
void factGen()
{
    fact[0] = inv[1] = fact[1] = invFact[0] = invFact[1] = 1;
    for (ll i = 2; i < MAXN; i++)
    {
        fact[i] = (fact[i - 1] * i) % mod;
        inv[i] = mod - (inv[mod % i] * (mod / i) % mod);
        invFact[i] = (inv[i] * invFact[i - 1]) % mod;
    }
}

// Function for extended Euclidean Algorithm
int gcdExtended(int a, int b, int *x, int *y)
{
    if (a == 0)
    {
        *x = 0, *y = 1;
        return b;
    }
    int x1, y1;
    int gcd = gcdExtended(b % a, a, &x1, &y1);
    *x = y1 - (b / a) * x1;
    *y = x1;
    return gcd;
}

ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

ll lcm(ll a, ll b)
{
    return (a * b) / gcd(a, b);
}

ll binpow(ll a, ll b, ll m)
{
    a %= m;
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
        {
            res = res * a % m;
        }
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

void solve(int t)
{
    ll n;
    cin >> n;
    string s;
    cin >> s;
    // this answer will exist
    string ans = s;
    v<ll> fac;
    rep(i, 1, n + 1)
    {
        if (n % i == 0)
        {
            fac.pb(i);
        }
    }
    for (auto x : fac)
    {
        string ss = s.substr(0, x);
        ll x2 = n / x;
        string ss2 = "";
        rep(i, 0, x2)
        {
            ss2 += ss;
        }
        if (ss2 == s)
        {
            cout << "Case #" << t << ": " << ss << "\n";
            return;
        }
    }
}

int main()
{
    IOS;
    int t = 1;
    cin >> t;
    rep(i, 1, t + 1)
    {
        solve(i);
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define M1 1000000007

void SieveOfEratosthenes(int n){
    // Create a boolean array
    // "prime[0..n]" and initialize
    // all entries it as true.
    // A value in prime[i] will
    // finally be false if i is
    // Not a prime, else true.
    //bool prime[n + 1];
    //memset(prime, true, sizeof(prime));
    vector<bool> prime(n, true);
    //fill(prime.begin(), prime.begin()+n, true);

    for (ll p = 2; p * p <= n; p++)
    {
        // If prime[p] is not changed,
        // then it is a prime
        if (prime[p] == true){
            // Update all multiples
            // of p greater than or
            // equal to the square of it
            // numbers which are multiple
            // of p and are less than p^2
            // are already been marked.
            for (ll i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
    // now all primes are turu
    ll res = 0;
    // for all odd numbers, the result is 2
    if(n%2 == 0)    res += n;
    else res += n+1;
    // now for all the even numbers
    for(ll i = 2; i <= n; i+=2){
        ll x;
        for(x = 3; x*x <= i; x++){

        }
        res += x;
    }
    res %= M1;
    cout<<res<<"\n";
    // Print all prime numbers
    // for (int p = 2; p <= n; p++)
    //     if (prime[p])
    //         cout << p << " ";
}

// now, a number can have 18 as a factor at max
// so, for each number, check 1 to 18
// should have O(n) complexity

// na na, no sieve needed


void solve2(){
    ll num;
    cin>>num;
    ll res = 0;
    if(num%2==0) res += num;
    else res += num+1;
    // now check all even numbers
    for(ll x = 2; x <= num; x+=2){
        for(ll div = 3; div < 19; div++){
            if(x%div == 0) continue;
            res += div;
            cout<<div<<" ";
            break;
        }
    }
    res %= M1;
    cout<<res<<"\n";
    //SieveOfEratosthenes(num);
    return;
}

ll gcd(ll x, ll y){
    return y ? gcd(y, x%y) : x;
}

ll lcm(ll x, ll y){
    return x/gcd(x,y)*y;
}

void solve(){
    ll n; cin>>n;
    ll l = 1; // lcm till one, and in the loop i will keep lcming
    ll ans = 0;
    for(ll i = 2; i < 100; i++){
        if(l > n) break;
        ll a = n/l;
        l = lcm(l, i);
        ll b = n/l;
        ll num = a-b;
        num *= i;
        //cout<<num<<" ";
        ans += num;
        ans %= M1;
    }
    cout<<ans<<"\n";
    return;
}

void solve3(){
    int n;
    cin >> n;
    int lcm = 1;
    int ans = 0;

    for (int i = 2; ; i++) {
        int bef = n / lcm;
        lcm = lcm * i / __gcd(lcm, i);
        int aft = n / lcm;

        ans += (bef - aft) * i;
        ans %= M1;

        if (lcm > n) break;
    }

    cout << ans << '\n';    
}

void solve4(){
    ll n;
    cin >> n;

    ll jam = (n + 1) / 2;
    //odd numbers
    ll ans = 0;
    ans += 2 * jam % M1;
    ll even = n - jam;


    ll num = 3;
    ll car = 2;
    while (even) {
        ll jam = __gcd(num, car);
        ll num_ = num / jam;
        ll tot = even - even / num_;
        (ans += tot * num % M1) %= M1;
        even = even / num_;
        car *= num_;
        num++;
    }
    cout << ans << '\n';
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

/*

explanation for self understanding:-

now, for a start, we can see that to get the biggest result of f(x) will be LCM 
i earlier thought that factorial would work but actually the repetitions of factorial do not exist for LCM
so if it is a little difficult to think, think factorial first, but since all those repetitions need to be avoided, 
we know of a special type of number called LCM which is exactly what we want

now, let's say that our result is f(x) = k
then, we can be sure that for all int 1 .. k-1, are factors of the number x
so we need to find out, how many such number exist, which would have all these numbers 1 ... k-1 as it's factors
we can simplify 1 ... k-1 acting as factors for a number as lcm(1 ... k-1)
so basically, x has a factor lcm(1 ... k-1) 
now, how many number have this factor?
obviously, n/(lcm(1 ... k-1))               // like there are n/3 factors of 3 in 1 ... n 
(assumming integer trucation)

however, i just want those numbers who do not have k as a factor, but all these

now, numbers who have lcm(1 ... k-1) as a factor will obviously have all the numbers which have lcm(1 ... k) as factors as well
so the smaller ones are a superset
and if i remove the ones which do not have k, but have till k-1, we get our required number of numbers

since we have n going till 10^16, which is close to 18!, i'll go upto 20
*/

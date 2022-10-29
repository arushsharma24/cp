#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
#define M2 998244353
#define yes cout << "YES\n"
#define no cout << "NO\n"

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

ll powM(ll x, ll y, ll m) {	//returns (a^b)%m ( ^ is exponent )
	ll ans = 1, r = 1;
	x %= m;
	while (r > 0 && r <= y)
	{
		if (r & y)
		{
			ans *= x;
			ans %= m;
		}
		r <<= 1;
		x *= x;
		x %= m;
	}
	return ans;
}

void solve(){
    ll n; cin>>n;
    vector<ll> ev;
    vector<ll> od;
    ll eve = 0, odd = 0;
    int tmp;
    for(int i = 0; i < n; i++){
        cin>>tmp;
        if(tmp%2){
            od.push_back(tmp);
            odd+=tmp;
        }
        else {
            ev.push_back(tmp);
            eve+= tmp;
        }
    }
    ll xe = eve/(n/2);
    ll pe = 0, me= 0;
    ll pe2 = 0, me2 = 0;
    if(xe%2){
        // if this is odd
        xe--;
        for(int i = 0; i < n/2; i++){
            if(ev[i] > xe) me += ev[i] - xe;
            else pe += xe - ev[i];
        }
        xe += 2;
        for(int i = 0; i < n/2; i++){
            if(ev[i] > xe) me2 += ev[i] - xe;
            else pe2 += xe - ev[i];
        }
    }
    else{
        // agar even hi aata hai ye bhi
        for(int i = 0; i < n/2; i++){
            if(ev[i] > xe) me += ev[i] - xe;
            else pe += xe - ev[i];
        }
    }
    ll xo = odd/(n/2);
    ll po = 0, mo= 0;
    ll po2 = 0, mo2 = 0;
    if(xo%2 ==0 ){
        // if this is even
        xo--;
        for(int i = 0; i < n/2; i++){
            if(od[i] > xo) mo += od[i] - xo;
            else po += xo - od[i];
        }
        xo += 2;
        for(int i = 0; i < n/2; i++){
            if(od[i] > xo) mo2 += od[i] - xo;
            else po2 += xo - od[i];
        }
    }
    else{
        // agar odd hi aata hai ye bhi
        for(int i = 0; i < n/2; i++){
            if(od[i] > xo) mo += od[i] - xo;
            else po += xo - od[i];
        }
    }

    if((pe2 == me2) && (me2 == 0)){
        // was even only
        if((po2 == mo2) && (mo2 == 0)){
            // was odd only
            if(pe + po == me + mo) yes;
            else no;
        }
        else{
            if((pe + po == me + mo) || (pe + po2 == me + mo2)) yes;
            else no;
        }
    }
    else{
        if((po2 == mo2) && (mo2 == 0)){
            if((pe + po == me + mo) || (pe2 + po == me2 + mo)) yes;
            else no;
        }
        else {
            if( (pe + po == me + mo) || (pe + po2 == me + mo2) || (pe2 + po == me2 + mo) || (pe2 + po2 == me2 + mo2) ) yes;
            else no;
        }
    }

/*
    if( (pe + po == me + mo) || (pe + po2 == me + mo2) || (pe2 + po == me2 + mo) || (pe2 + po2 == me2 + mo2) ){
        cout << "YES\n";
    }
    else cout << "NO\n";
*/
}

int main(){
    FAST();
    OJ();
    int test_cases = 1;
    cin>>test_cases;
    while (test_cases--){
        solve();
    }
    return 0;   
}


/*

START:	LXI H, 2040H	;Load size of array
 	MVI D, 00H	;Clear D register to set up a flag
 	MOV C, M	;Set C register with number of elements in list
 	DCR C		;Decrement C
 	INX H		;Increment memory to access list
CHECK:	MOV A, M	;Retrieve list element in Accumulator
 	INX H		;Increment memory to access next element
 	CMP M		;Compare Accumulator with next element
 	JC NEXTBYTE	;If accumulator is less then jump to NEXTBYTE
 	JZ NEXTBYTE	;If accumulator is equal then jump to NEXTBYTE
 	MOV B, M	;Swap the two elements
 	MOV M, A	 
 	DCX H	 
 	MOV M, B	 
 	INX H	 
 	MVI D, 01H	;If exchange occurs save 01 in D register
NEXTBYTE:	DCR C	;Decrement C for next iteration
 	JNZ CHECK	;Jump to CHECK if C>0
 	MOV A, D	;Transfer contents of D to Accumulator
 	CPI 01H		;Compare accumulator contents with 01H
 	JZ START	;Jump to START if D=01H
 	HLT		;HALT

*/
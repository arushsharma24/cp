#include <bits/stdc++.h>
using namespace std;

int main(){
    int N = 0;
    cin>>N;
    unsigned int cust = N;
    long long budget[N];

    //

    while (N--){
        long long x;
        cin>>x;
        budget[cust-N-1] = x;
    }
    sort(budget, budget + (sizeof(budget)/sizeof(budget[0])));

    //budgets sorted
    //cout<<"lmao"<<endl;
    //moving back from top our maxima will occur at one point or at the extreme values

    long long sum = 0;
    for(unsigned int i = 0; i < cust; i++){
        if(i == 0){
            sum = budget[cust - 1 - i]*(i + 1);
            //cout<<"sum : "<<sum<<endl;
            //cout<<"lol"<<endl;
        }
        else{
            if(sum < budget[cust - 1 - i]*(i + 1)){
                //cout<<budget[cust-1-i]<<endl;
                sum = budget[cust - 1 - i]*(i + 1);
                //cout<<"summm : "<<sum<<endl;
            }
            else if(i != 0){
                //cout<<"lmao"<<endl;
                //break;
            }
        }
    }
    //cout<<"lmao lmao";
    long long iniVal = budget[0]*cust;
    long long finVal = budget[cust - 1];

    if (finVal < iniVal)
        finVal = iniVal;

    if(sum > finVal)
        finVal = sum;

    cout<<sum<<endl;
}



/*
long long revenueCalc(long x, long budget[], unsigned int size){
    unsigned int sum = 0;
    for (unsigned int i = 0; i < size; i++){
        if(x <= budget[i])
            sum++;
    }
    return sum*x;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    unsigned int N = 0;
    cin>>N;
    unsigned int T = N;
    long budget[T] = {0};
    while(N--){
        long x;
        cin>>x;
        budget[T-1-N] = x;
    }
    //budget array made
    long long revenue[T] = {0};   //array with values corresponding to revenue if that budget value is taken as price
    unsigned int i = T;
    while(i--){
    revenue[i] = revenueCalc(budget[i], budget, T);
    }
    //revenue array ready
    long long arrayMax = 0;
    for (unsigned int i = 0; i < T; i++){
        if(revenue[i]>arrayMax)
            arrayMax = revenue[i];
    }
    cout<<arrayMax<<"\n";
}
*/
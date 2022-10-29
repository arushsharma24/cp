#include <bits/stdc++.h>
using namespace std;

bool is_in_array(int array[], int size, int value){
    for (int i=0; i<size; i++){
        if(array[i] == value){
            return 1;
        }
    }
    return 0;
}

int array_sum(int array[], int size){
    int sum = 0;
    for(int i = 0; i<size; i++){
        sum += array[i];
    }
    return sum;
}

int main(){
    int N;//test cases
    cin>>N;
    for(int i=0; i<N; i++){
        int n;//size of array
        cin>>n;
        int pos[n] = {0};
        int neg[n] = {0};
        for(int j=0; j<n; j++){//get array
            int x;
            cin>>x;
            if(x>0){
                if(!is_in_array(pos, n, x)) pos[j] = x;
            }
            else{
                if(!is_in_array(neg, n, x)) neg[j] = x;
            }
        }
        cout<<array_sum(pos, n)<<" "<<array_sum(neg, n)<<"\n";
    }
}
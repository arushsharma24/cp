#include <bits/stdc++.h>
using namespace std;

int second_point(int length){
    if(length%2 == 0){
        return length/2;
    }
    else{
        return length/2 + 1;
    }
}

string check(string input1, string input2){

    int chars1[26] = {0};
    int chars2[26] = {0};
    for (int i = 0; i < input1.length(); i ++){
        int x = input1[i];
        int y = input2[i];
        //cout<<"x: "+x<<" ";
        //cout<<endl;
        //cout<<"y: "+y<<" ";
        //cout<<endl;
        chars1[x-96]++;
        chars2[y-96]++;
    }

        for(int i = 0; i < 26; i++){
            if(chars1[i] != chars2[i]){
                return "NO";
            }
        }
        return "YES";
}

int main(){
    int x;
    cin>>x;
    while(x--){

        string input;
        cin>>input;
        string first(input.substr(0, input.length()/2));
        //cout<<"first: "<<first<<endl;
        string second(input.substr(second_point(input.length()), input.length()/2));
        //cout<<"second: "<<second<<endl;

        cout<<check(first, second)<<endl;

        /*
        int chars1[26] = {0};
        int chars2[26] = {0};
        //setCharArr(chars1, first);
        //setCharArr(chars2, second);

        int temprun = 26;
        while(temprun--){
            cout<<chars1[temprun]<<" ";
        }
        cout<<endl;
        temprun = 26;
        while (temprun--){
            cout<<chars2[temprun]<<" ";
        }
        cout<<endl;

        for(int i = 0; i < 26; i++){
            if(chars1[i] != chars2[i]){
                cout<<"NO"<<endl;
                return 0;
            }
        }
        cout<<"YES"<<endl;
        */
    }
}
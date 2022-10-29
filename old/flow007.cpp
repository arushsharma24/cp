#include <bits/stdc++.h>
using namespace std;

string reverser(string input){
    
    ostringstream output;
    char s[input.length()];
    for(int j = 0; j < input.length(); j++){
       output << input[input.length() - j -1];
    }
    return output.str();
}

string removeInitialZero(string input){
    if(input[0] == '0'){
        string temp = reverser(input);
        temp.pop_back();
        string output = reverser(temp);
        return removeInitialZero(output);
    }
    else {
        return input;
    }
}

int main(){
    int T;
    cin>>T;

    for (int i = 0; i< T; i++){
        string x;
        cin>>x;
        cout<<removeInitialZero(reverser(x))<<endl;
    }
}
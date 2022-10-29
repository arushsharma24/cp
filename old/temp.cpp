#include <iostream>
#include <fstream>

using namespace std;

int main(){
	cout<<"yo"<<endl;
	string s;
	getline(cin, s);
	int i = 0;
	while(!s.empty()){
		cout<<s<<endl;
		getline(cin,s);
		i++;
		cout<<i<<endl;
	}
	return 0;
}

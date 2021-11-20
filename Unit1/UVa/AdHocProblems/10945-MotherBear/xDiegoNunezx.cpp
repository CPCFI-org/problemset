#include <iostream>
#include<string>
#include<algorithm>
using namespace std;

int main() {
	string s;
	while(getline(cin,s)&&s!="DONE"){
		string s1,s2;
		int len=s.length();
		for(int i=0;i<len;i++){
			if(isalpha(s[i])){
				s1+=tolower(s[i]);
			}
		}
		s2=s1;
		reverse(s1.begin(),s1.end());
		if(s1==s2)
			cout<<"You won't be eaten!"<<"\n";
		else{
			cout<<"Uh oh.."<<"\n";
		}

	}
	return 0;
}
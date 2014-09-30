#include<bits/stdc++.h>
using namespace std ;

int main() {
	cout << "Byte Stuffing (esc character is 'E')\n" ;
	cout << "Enter data to send: " ;
	
	string str ;
	cin >> str ;
	char esc = 'E' ;
	string ans;
	ans.push_back(esc) ;
	
	for(int i=0;i<str.size();i++) {
		if(str[i] == esc) 
			ans.push_back(esc) ;
		ans += str[i] ;
	}
	ans.push_back(esc) ;
	cout << "Data recieved: " << ans << endl;
}

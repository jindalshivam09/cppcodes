#include<bits/stdc++.h>
using namespace std;

int main() {
	cout << "Bit Stuffing (flag is 01111110 )\n" ;
	cout << "Enter the data to send: " ;
	string str ;
	cin >> str ;
	string flag = "01111110" ;
	string ans = flag;
	for(int i=0;i<str.size();) {
		if(str[i] == '0') {
			i++;
			ans += '0';
		}
		else {
			int cnt = 0 ;
			while( i < str.size() && cnt < 4 && str[i] == '1' ) {
				ans += '1' ;
				cnt ++ ;
				i++;
			}
			if(cnt == 4 && i<str.size())
				ans += '0' ;
		}
	}
	ans += flag ;
	cout << "Data received : " << ans << endl;

}

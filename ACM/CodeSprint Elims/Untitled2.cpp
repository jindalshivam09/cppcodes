#include<bits/stdc++.h>
using namespace std ;

int main() {
	string str ;
	cin >> str ;
	int sz = 1;
	for(int i=0;i<str.size();) {
		char ch = str[i] ;
		if(str[i] != 'a') {
			i++;
			continue ;
		}
		int cnt = 0;
		while(i<str.size() && str[i] == 'a')
			i++, cnt++;
		sz = max(sz,cnt+1) ;
	}
	for(int i=0;i<sz;i++)
		cout << "a" ;
}

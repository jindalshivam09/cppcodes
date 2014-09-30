#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n ;
	vector<pair<string,string> > input(n+1) ;
	for(int i=1;i<=n;i++)
		cin >> input[i].first >> input[i].second ;
	
	vector<int> permute(n) ;
	for(int i=0;i<n;i++)
		cin >> permute[i] ;

	string pre = min( input[permute[0]].first,input[permute[0]].second);
	
	for(int i=1;i<n;i++) {
		string str1 = input[permute[i]].first ;
		string str2 = input[permute[i]].second ;
		string temp = str1 ;
		str1 = min(str1,str2) ;
		str2 = max(temp,str2) ;
			if(str1 > pre)
				pre = str1 ;
			else if(str2 > pre)
				pre = str2 ;
			else {
				cout << "NO" ;
				return 0;
			}
	}
	cout << "YES" ;
}

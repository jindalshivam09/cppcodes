#include<iostream>
#include<cstring>
using namespace std;
main() {
	int n;
	int hash[26],hash2[26];
	cin >> n;
	while(n--) {
		bool flag=0;
		memset(hash,0,sizeof(hash));
		memset(hash2,0,sizeof(hash2));
		string s;
		cin >> s;
		int l=s.length();
	//	cout << l;
		for(int i=0;i<l/2;i++) {
	//		cout << s[i] << " " << s[l-1-i] << " ";
			hash[s[i]-97]++;
			hash2[s[l-1-i]-97]++;
		}
		for(int i=0;i<26;i++)
		//cout << hash[i] << " " << hash2[i] << endl; 
		if(hash[i]!=hash2[i]) {
			cout << "NO" << endl;
			flag = 1;
			break;	
		}
		if(!flag)
		 cout << "YES" << endl;
	}
}

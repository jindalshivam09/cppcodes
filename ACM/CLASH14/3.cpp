#include<bits/stdc++.h>
using namespace std;

int countr (string str) {
	int cnt = 0;
	for(int i=0;i<str.size();i++)
		if(str[i] == 'r')
			cnt ++ ;
	return cnt ;
}

int main() {
	int n ;
	cin >> n ;
	vector<string> arr(n) ;
	
	for(int i=0;i<n;i++) {
		cin >> arr[i] ;
		transform(arr[i].begin(), arr[i].end(), arr[i].begin(), ::tolower);

	}
	map<string,pair<string,int> > mapped ;	
	
	int k ;
	cin >> k ;
	
	string str1, str2  ;
	for(int i=0;i<k;i++) {
		cin >> str1 >> str2 ;
		transform(str1.begin(), str1.end(), str1.begin(), ::tolower);
		transform(str2.begin(), str2.end(), str2.begin(), ::tolower);
		int r1 = countr(str1) ;
		int r2 = countr(str2) ;
		int len1 = str1.size() ;
		int len2 = str2.size() ;
		
		if(mapped.count(str1) == 0) {
			if(r1 > r2) {
				mapped[str1] = make_pair(str2,r2) ;
			}	
			else if(r1==r2 && len1 > len2)
				mapped[str1] = make_pair(str2,r2) ;
		}
		else {
			string temp = mapped[str1].first ;
			int r3 = mapped[str1].second ;
			int len3 = temp.size() ;
			if(r3 > r2) {
				mapped[str1] = make_pair(str2,r2) ;
			}	
			else if(r3==r2 && len3 > len2)
				mapped[str1] = make_pair(str2,r2) ;
		}
	}

	

	int r = 0, len = 0 ;
	for(int i=0;i<n;i++) {
		if(mapped.count(arr[i])) {
//			cout << mapped[arr[i]].first << " ";
			r += mapped[arr[i]].second ;
			len += mapped[arr[i]].first.size() ;
		}
		else{
//			cout << arr[i] << " ";
			r += countr(arr[i]) ;
			len += arr[i].size();
		}
	}
	cout << r << " " << len << endl;
}

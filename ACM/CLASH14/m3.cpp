#include<bits/stdc++.h>
using namespace std;

map<string,vector<string> > mapped ;
map<string,int> rval ;
map<string,bool> visited ;
map<string,string> optimised;

int countr (const string &str) {
	int cnt = 0;
	for(int i=0;i<str.size();i++)
		if(str[i] == 'r')
			cnt ++ ;
	return cnt ;
}

vector<string> path ;

string dfs (const string &str) {
//	cout << str << endl;
	visited[str] = true ;
	path.push_back(str) ; 
	string good = str ;
	int r = rval[good] ;
	for(int i=0;i<mapped[str].size();i++) {
		string temp = mapped[str][i] ;
		if(visited[temp] == false) {
			temp = dfs(temp) ;
			int len = rval[temp] ;
			if( (len < r) || (len == r && good.size() > temp.size() )) {
				good = temp ;
				r = len ;
			}
		}
	}
	return optimised[str] = good ;
}

int main() {
	int n ;
	cin >> n ;
	vector<string> arr(n) ;
	
	for(int i=0;i<n;i++) {
		cin >> arr[i] ;
		transform(arr[i].begin(), arr[i].end(), arr[i].begin(), ::tolower);
		rval[arr[i]] = countr(arr[i]) ;
	}
	
	int k ;
	cin >> k ;
	
	string str1, str2  ;
	vector<string> input(k);
	for(int i=0;i<k;i++) {
		cin >> str1 >> str2 ;
		input[i] = str1;
		transform(str1.begin(), str1.end(), str1.begin(), ::tolower);
		transform(str2.begin(), str2.end(), str2.begin(), ::tolower);
		int r1 = countr(str1) ;
		int r2 = countr(str2) ;
		mapped[str1].push_back(str2) ;
		rval[str1] = r1 , rval[str2] = r2 ;
	}
	for(int i=0;i<n;i++) {
		if(visited[arr[i]] == false) {
			string best = dfs(arr[i]) ;
		}
	}
	for(int i=0;i<k;i++) {
		if(visited[input[i]] == false) {
			string best = dfs(input[i]) ;
		}	
	}
	
	for(int i=0;i<n;i++) {
	//		cout << arr[i] << "-> " ;
			vector<string> child = mapped[arr[i]] ;
			string good = optimised[arr[i]] ;
			int r = rval[good] ;
			for(int j=0;j<child.size();j++) {
				string temp = optimised[child[j]] ;
	//			cout << temp << " ";
				int len = rval[temp] ;
				if( (len < r) || (len == r && good.size() > temp.size() )) {
					good = temp ;
					r = len ;
				}
			}
			optimised[arr[i]] = good ;
	}
		
	int r = 0, len = 0 ;
	for(int i=0;i<n;i++) {
		if(optimised.count(arr[i])) {
			r += rval[optimised[arr[i]]] ;
			len += optimised[arr[i]].size() ;
//			cout << optimised[arr[i]] << " ";
		}
		else{
//			cout << arr[i] << " " ;
			r += countr(arr[i]) ;
			len += arr[i].size();
		}
	}
	cout << r << " " << len << endl;
}


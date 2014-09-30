#include<bits/stdc++.h>
using namespace std ;

vector<string> arr ;
map<int,vector<int> > adj ;
map<string,int> indexes ;
map<int,int> rval, sz ;
int num = 0;

int countr (const string &str) {
	int cnt = 0 ;
	for(int i=0;i<str.size();i++)
		if(str[i] == 'r')
			cnt ++ ;
	return cnt ;
}

struct cmp {
	bool operator () (int a, int b) {
		return rval[a] == rval[b] ? ( sz[a] == sz[b] ? a < b : sz[a] < sz[b] ) : rval[a] < rval[b] ;
	}
} ;
cmp compare ;
set<int, cmp> order ;

int preprocess ( const string &str ) {
	if(indexes[str])
		return indexes[str] ;
	rval[++num] = countr(str) ;
	sz[num] = str.size() ;
	indexes[str] = num ;
	return num ;
}

int main() {
	int n ;
	cin >> n ;
	arr.resize(n) ;
	for(int i=0;i<n;i++) {
		cin >> arr[i] ;
		transform(arr[i].begin(),arr[i].end(),arr[i].begin(),::tolower) ;
	}
	
	int k;
	cin >> k ;
	string str1, str2 ;
	for(int i=0;i<k;i++) {
		cin >> str1 >> str2 ;
		transform(str1.begin(),str1.end(),str1.begin(),::tolower) ;
		transform(str2.begin(),str2.end(),str2.begin(),::tolower) ;
		adj[ preprocess(str2) ].push_back(preprocess(str1)) ;	
	}
	
	for(int i=1;i<=num;i++) {
		order.insert(i) ;
	}
	
	while( order.size() ) {
		int u = (*order.begin()) ;
		order.erase(u) ;
		vector<int> list = adj[u] ;
		for(int i=0;i<list.size();i++) {
			int v = list[i] ;
			if (compare(u,v)) {
				order.erase(v) ;
				rval[v] = rval[u] ;
				sz[v] = sz[u] ;
				order.insert(v) ;
			}
		}
	}
	
	long long r=0, len=0;
	for(int i=0;i<n;i++) {
		int u = indexes[arr[i]] ;
		if(u)  {
			r += rval[u] ;
			len += sz[u];
		}
		else {
			r += countr(arr[i]) ;
			len += arr[i].size() ;
		}
	}
	cout << r << " " << len << endl;
}

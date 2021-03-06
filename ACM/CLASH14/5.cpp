#include<bits/stdc++.h>
using namespace std ;

int n;
vector<int> arr, ans ;

int func ( int index ) {
	stack<int> stk ;
	map<int,int> sz, result ;
	for(int i=index;i<n;i++) {
		if ( result.count(arr[i]) ) {
			ans.push_back ( result[arr[i]] ) ;
			ans.push_back ( arr[i] ) ;
			ans.push_back ( result[arr[i]] ) ;
			ans.push_back ( arr[i] ) ;
			return i ;
		}
		while( stk.size() && ( sz[arr[i]] > 1 || ( sz[arr[i]] == 1 && stk.top() != arr[i] ) )) {
			result[stk.top()] = arr[i] ;
			sz[stk.top()] -- ;
			stk.pop() ;
		}
		stk.push(arr[i]) ;
		sz[arr[i]] ++ ;
	}
	return -1 ;
}

int main() {
	cin >> n ;
	arr.resize(n) ;
	for(int i=0;i<n;i++)
		cin >> arr[i] ;

	int t = -1;
	while ( (t = func(t+1)) != -1 ) ;
	
	if(ans.size() == 0) {
		cout << 0 << endl;
	}
	else {
		cout << ans.size() << endl;
		for(int i=0;i<ans.size();i++)
			cout << ans[i] << " ";
	}
}

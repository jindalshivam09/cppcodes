#include <bits/stdc++.h>
using namespace std;

typedef long long 		ll;
typedef list<int> 	li;
typedef vector<int> 	vi;
typedef vector<double> 	vd;
typedef vector<long long> 	vll;
typedef vector<bool> 	vb;
typedef pair<int,int> 	pii;
typedef vector<pair<int,int> > vpii;
typedef pair<double,double> 	pdd;
typedef vector<pair<double,double> > vpdd;

#define rep(i,n)    		for(int i=0;i<n;i++)
#define repi(i,k,n) 		for(int i=k;i<n;i++)
#define mp 				make_pair
#define pb			 	push_back
#define all(a) 			a.begin(),a.end()
#define imax  			numeric_limits<int>::max()
#define imin 			numeric_limits<int>::min()
#define dmax            numeric_limits<double>::max()
#define dmin            numeric_limits<double>::min()
#define MAX 8000
vector<vi > arr(MAX,vi(MAX));
string str ;

pii lcs () {
	vb incr(str.size()) ;
	repi(i,1,str.size())
		if ( str[i] == str[0] )		arr[0][i] = 1 ;
		else						arr[0][i] = arr[0][i-1] ;
	repi(i,1,str.size()) {
		bool flag = false;
		int count = 0 ;
		rep(j,str.size()) {
			arr[i][j] = arr[i-1][j] ;
		}
		if(arr[i-1][i] > arr[i-1][i-1])
			flag = true ;
		repi(j,i+1,str.size()) {
			if(str[i] == str[j]) {
				count ++ ;
				if(flag == false)
					arr[i][j] = max ( arr[i][j] , 1+arr[i][j-1] );
				else if (flag && count > 1)
					arr[i][j] = max ( arr[i][j] , 1+arr[i][j-1] );									
			}
			else
				arr[i][j] = max (arr[i][j] , arr[i][j-1]) ;
		}
		rep(j,str.size())
			cout << arr[i][j] << " ";	
		cout << endl;
	}
	
}

int main() {
	int t ;
//	cin >> t;
	t = 1;
	while(t--) {
//		cin >> str ;
		str = "aabcbababc";
		pii ans = lcs();
		cout << ans.first <<  " " << ans.second << endl;
		rep(i,str.size())	rep(j,str.size())
			arr[i][j] = 0 ;
	}
} 




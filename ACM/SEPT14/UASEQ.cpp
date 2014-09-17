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

bool cmp (const pii &a, const pii &b) {
	return a.second == b.second ? a.first < b.first : a.second < b.second ;
}

int main() {
	int n, k;
	cin >> n >> k;
	vi arr(n) ;
	map<int,int > freq ;
	rep(i,n) 
		cin >> arr[i] ;
	if( n < 25 ) {
		int fdiff = arr[1]-arr[0] , fpos = 0 , a = imax;
		int diff,pos ,term ;
		repi(i,1,n) {
			term = 1 ;
			int cnt = 0 ;
			diff = arr[i] - arr[i-1] ;
			pos = i-1 ;
			for(int i=pos-1;i>=0;i--) {
				if(arr[pos]-term*diff != arr[i])
					cnt ++;
				term ++ ;
			}
			term = 1;
			for(int i=pos+1;i<n;i++) {
				if(arr[i] != arr[pos] + term*diff)
					cnt ++ ;
				term++ ;
			}
			if( cnt <= k ) {
				if(a > arr[pos]-pos*diff ) {
					fdiff = diff , a = arr[pos]-pos*diff , fpos = pos ;
				}
				else if ( a == arr[pos]-pos*diff && diff < fdiff) {
					fdiff = diff , a = arr[pos]-pos*diff , fpos = pos ;					
				}
			}
		}
		for(int i=fpos-1;i>=0;i--) {
			arr[i] = arr[i+1] - fdiff ;
		}
		for(int i=fpos+1;i<n;i++)
			arr[i] = arr[i-1] + fdiff ;
		rep(i,n) 
			cout << arr[i] << " ";
		return 0 ;		
	}
	int pos = 0,diff = arr[1]-arr[0] ;
	freq[diff] ++ ;
	repi(i,2,n) {
		int temp = arr[i] - arr[i-1] ;
		freq[temp] ++ ;
		if(freq[temp] > freq[diff]) {
			diff = temp ;
			pos = i-1 ;
		}
		else if(freq[temp] == freq[diff] ) {
			if(diff > temp) {
				diff = temp , pos = i-1;
			}
		}
	}
	for(int i=pos-1;i>=0;i--) {
		arr[i] = arr[i+1] - diff ;
	}
	for(int i=pos+1;i<n;i++)
		arr[i] = arr[i-1] + diff ;
	rep(i,n) 
		cout << arr[i] << " ";
	
}



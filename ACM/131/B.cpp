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

int main() {
	int  n ;
	cin  >> n ;
	vi arr(n) ;
	int zero = 0 ;
	rep(i,n) {
		cin >> arr[i] ;
		if (arr[i] == 0)
			zero++ ;
	}
	sort(all(arr));
	if (zero == 0)
		cout << -1 << endl;
	else if (zero == n)
		cout << 0 << endl;
	else {
		int sum = 0 ;
		rep(i,n)
			sum += arr[i] ;
		if (sum % 3 == 0) {
			for(int i=n-1;i>=0;i--)
				cout << arr[i] ;
		}
		else {
			int one = 0 , two = 0 ;
			rep(i,n) {
				if (arr[i] % 3  == 1)	one ++ ;
				if ( arr[i] % 3 == 2)	two ++ ;
			}
			bool print = false;
			if (sum % 3 == 1) {
				if (one) 	one -- ;
				else two -= 2 ;
			}			
			else {
				if (two )	two --;
				else	one -= 2;
			}
			for(int i=n-1;i>=0;i--) {
				if (arr[i]%3==0){
					if (print == false && arr[i] == 0) {
						cout << 0 << endl;
						return 0;
					}
					cout << arr[i] ;
					print = true; 
				}
				else if (arr[i]%3==2 && two > 0) {
					cout << arr[i] ; 
					two -- ;
					print = true; 
				}
				else if (arr[i]%3==1 && one > 0) {
					cout << arr[i] ;
					one -- ;
					print = true; 
				}
			}
			if (print == false)
				cout << -1 ;
		}
	}
}



#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <algorithm>
#include <set>
#include <limits>
#include <utility>
#include <iomanip>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cstring>

using namespace std;

typedef long long 		ll;
typedef vector<int> 	vi;
typedef pair<int,int> 	pii;
typedef vector<pair<int, int> > vpii;
typedef vector<double> 	vd;
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

	int t;
	cin >> t;
	int test = 1;
//	fropen("out.txt","r").stdout;	
	while(t--) {
		
		int n;
		cin >> n;
		
		vector<vector<char> > input(n,vector<char>(n));
		
		for(int i=0;i<n;i++) {
			
			for(int j=0;j<n;j++) {
				
				cin >> input[i][j];
			}
		}
		
		int l,m;
		bool flag = false;
		for(int i=0;i<n;i++) {
			
			for(int j=0;j<n;j++) {
				
				if(input[i][j] == '#') {
					
					l = i;
					m = j;
					flag = true;
					break;
				}
 			}
 			if(flag)
 				break;
		}
		int side = 0;
		for(int i=l,j=m;j<n;j++) {
			
			if(input[i][j] == '#') {
				
				side++;
	//			input[i][j] = '.';
			}
			else
				break;
		}
//		cout << side << endl;
//		cout << l << " " << m << endl;
		flag = false;
		int i=l;
		for(;i<l+side&&i<n;i++) {
			
			for(int j=m;j<m+side;j++) {
				
//				cout << i << " "<< j << endl;
				if(input[i][j] != '#') {
					
					flag = true;
					break;
				}
				else
					input[i][j] = '.';
			}
			if(flag)
			break;
		}
//		cout << flag << endl;
		if(!flag && (i == l+side)) {
			
			bool flag2 = false;
			for(int i=0;i<n;i++) {
				
				for(int j=0;j<n;j++) {
					
//					cout << i << " " << j << endl;
					if(input[i][j] =='#'){
						
						flag2 = true;
						break;
					}
				}
				if(flag2)
					break;
			}
			
			if(flag2)		cout << "Case #" << test << ": NO" << endl;
			else			cout << "Case #" << test << ": YES" << endl;
		}
		else
			cout <<"Case #" << test << ": NO" << endl;
			test++;
	}
}



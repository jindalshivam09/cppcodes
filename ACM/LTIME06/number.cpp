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
#define llmax  			numeric_limits<long long>::max()

#define dmax            numeric_limits<double>::max()
#define dmin            numeric_limits<double>::min()

bool cmp (const pair<string,int> &a,const pair<string,int> &b) {
	
	return a.second < b.second;
}

int main() {

	int t;
	cin >> t;
	while(t--) {
		
		int n;
		cin >> n;
		
		vector<pair<string,long long> > num(n);
		
		string str;
		int q;
		for(int i=0;i<n;i++) {
			
			cin >> str >> q;
			num[i] = mp(str,q);
		} 
		sort(num.begin(),num.end(),cmp);
		
		int index = -1;
		for(int i=0;i<n;i++) {
			
//			cout << num[i].first << " " << num[i].second << endl;
			if( i > 0 && i < n-1 && num[i].second != num[i-1].second && num[i].second != num[i+1].second) {
				
				index = i;
				break;	
			}		
			else if (!i && num[i].second != num[i+1].second) {
				
				index = i;
				break;		
			}
			else if ( i==n-1 && num[i].second != num[i-1].second) {
			
				index = i;
				break;			
			}
		}
//		cout << index << endl;
		
		if(index > -1 ) 
			cout << num[index].first << endl;
		else
			cout << "Nobody wins." << endl;
	}
}



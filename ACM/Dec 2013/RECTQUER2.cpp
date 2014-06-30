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
#define MAX 302
vector<vector<int> > arr(MAX,vector<int>(MAX));
int n;

struct n {
	vpii present;
} number[11];

void preprocess() {
	
	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++) {
			int temp = arr[i][j];
			number[temp].present.pb(mp(i,j));
		}
	}
}

int main() {

	cin >> n;
	for(int i=0 ; i<n ; i++) {
		for(int j=0 ; j<n ; j++) {
			cin >> arr[i][j];
		}
	}
	preprocess();
	int q;
	cin >> q;
	while(q--) {
		int x1,x2,y1,y2;
		cin >> x1 >> y1 >> x2 >> y2;
		x1--;
		y1--;
		x2--;
		y2--;
		int count = 0;
		for(int i=1;i<=10;i++) {
			bool flag = false;			
			for(int j=x1;j<=x2;j++) {
				vpii::iterator itr = lower_bound(all(number[i].present),mp(j,y1));
				if(itr != number[i].present.end()) {	
					if(itr->first <= x2 && itr->second <= y2 && itr->first >= j && itr->second >= y1) {
//						cout << i << " ";
						flag = true;
						break;
					}
				}
			}
			if(flag)
				count ++;
		}
		cout << count << endl;
	}
}



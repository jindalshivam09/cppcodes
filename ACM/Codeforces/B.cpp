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
#define MAX 109
struct c {
	bool number[MAX];
	int count ;
} card[109];

int main() {

	int n;
	cin >> n;
	for(int i=0;i<n;i++) {
		
		cin >> card[i].count;
		for(int j=0;j<card[i].count;j++) {
			int a;
			cin >>a ;
			card[i].number[a] = true;
		}
	}
	 
	for(int i=0;i<n;i++) {
		bool flag = true;
		for(int j=0;j<n;j++) {
			if( i != j ){
				int c1 = 0 ,c2 = 0;
				for(int k=1;k<101;k++) {
					if(card[i].number[k] == card[j].number[k] && card[i].number[k]) {
						c1++;
						c2++;
					}
				}
				if(c2 == card[j].count )  {
					flag = false;		
					break;
				}	
			}
		}
		if(flag)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
}



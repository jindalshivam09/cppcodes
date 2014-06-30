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

#define INTEGER 1000000

int main() {
	ifstream cin("input.txt") ;
	ofstream cout("output.txt") ;
	int t;
	cin >> t;
	for(int test=1;test<=t;test++) {
		int n ;
		cin >> n;
		double a ;
		vd naomi(n) , ken(n) , naomi2(n);
		rep(i,n) {
			cin >> a ;
			naomi2[i] = naomi[i] = a;//*INTEGER ;
		}
		rep(i,n) {
			cin >> a ;
			ken[i] = a;//*INTEGER ;
		}
		int deceitful = 0 , war = 0;
		sort(all(naomi2)) ;
		rep(i,n) {
			double temp = ken[i] ;
			int index = lower_bound(all(naomi2),temp) - naomi2.begin() ;
			if (index < naomi2.size()) {
				deceitful ++;
				naomi2.erase(lower_bound(all(naomi2),temp));
			}
			else {
				naomi2.erase(naomi2.begin());
			}
		}
		sort(all(naomi)) ;
		sort(all(ken)) ;
/*		rep(i,n)
			cout << naomi[i] << " ";
		cout << endl;
		rep(i,n)
			cout << ken[i] << " ";
		cout << endl;
*/		
		int i = 0  , j =  0 ;
		for(;i<n;i++) {
			double temp = naomi[i] ;
			while(j<n && temp > ken[j]) 
				j ++;
//			cout << i << " "<< j<< endl;
			if(j>=n)
				war ++;
			j++;
		}
		cout << "Case #" << test << ": " ;
		cout << deceitful <<  " " << war << endl;
	}
}



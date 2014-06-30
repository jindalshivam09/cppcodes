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

	int t;
	cin >> t;
	while(t--) {
		
		int bt1,bt2,gt1,gt2;
		scanf("%d:%d",&gt1,&gt2);
		scanf("%d:%d",&bt1,&bt2);
		int dist;
		cin >> dist;
//		cout << bt1 << bt2;
		cout << (gt1-bt1)*60 + (gt2-bt2) + dist << ".0 ";
		double time = (gt1-bt1)*60 + (gt2-bt2) - 2*dist ;
		if(time >= 0)
			cout <<  (gt1-bt1)*60 + (gt2-bt2) << ".0";
		else {
			float p = time/2.0;
//			cout << p ;
			printf("%.1f",float(-1*p+(gt1-bt1)*60 + (gt2-bt2)));
		}
		cout << endl;
	}
}



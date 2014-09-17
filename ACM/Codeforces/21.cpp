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

class CatsOnTheLineDiv2 {
	public :
		string getAnswer ( vector<int> pos, vector<int> cats , int time) {
			vector<pair<int,int> > pairs(pos.size()) ;
			rep(i,pos.size()) {
				pairs[i]=mp(pos[i],cats[i]);
			}
			sort(all(pairs)) ;
			int head = pairs[0].first - time ;
			rep(i,pos.size()) {
				int postn = pairs[i].first , num = pairs[i].second ;
				int maxr = max( postn - time , head ) ;
				head = maxr + num ;			
//				if(maxr<=0 && head > 0)
//					head -= 1;
				if( head > pairs[i].first+time+1)
					return "Impossible" ;
//				cout << head << endl;
			}
//			cout << pairs[pos.size()-1].first << endl;
			if( head > pairs[pos.size()-1].first+time+1)
				return "Impossible" ;
			else
				return "Possible" ;
		}
};

int main() {
	vi arr(3),arr1(3) ;
	int time = 2 ;
	int n;
	cin >> n ;
	rep(i,n)
		cin >> arr[i] ;
	rep(i,n)
		cin >> arr1[i] ;
	cin >> time;
	CatsOnTheLineDiv2 ob ;
	cout << ob.getAnswer(arr,arr1,time) ;
}



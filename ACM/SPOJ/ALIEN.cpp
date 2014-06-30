#include <iostream> 
#include <list>
#include <vector>
#include <algorithm>
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
		ll at , bt;
		cin >> at >> bt;
		vi arr(at);
		rep(i,at)
			cin >> arr[i];
			
		vll sum(at);
		sum[0] = arr[0];
		for(int i=1;i<at;i++) {
			sum[i] = sum[i-1]+arr[i];
		}
		ll count = 0 , ans = 0;
		int index = 0;
		for(int i=0;i<at;i++) {
			if (bt >= sum[i]){
				count = i+1;
				ans = sum[i]; 
			}
			else {
				bool flag = false;
				while ( index < at && sum[i]-sum[index] > bt  )
					index++ , flag = true;
				if(!index && !flag)
					continue;
				index--;
				if ( count < i-index )  {
					count = i-index;
					ans = sum[i] - sum[index];
				}
				else if(count==i-index)
					ans = max(ans,sum[i]-sum[index]);
			}
		}
		cout << ans << " " << count << endl;
	}
}



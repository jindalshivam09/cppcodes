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


#define MAX 100
class MiniatureDachshund {
	
	public:
		//int wt , mikman[MAX];
		int maxMikan (vector<int> &mikan , int &weight) {
			
			sort(all(mikan));
			
			int gap = 5000 - weight ;
			int count  = 0 ;
			for(int i=0;i < mikan.size() ;i++) {
				
				if(gap - mikan[i] >= 0) {
					
					gap -= mikan[i];
					count++;
				}
			}	
			return count ;
		}
};





int main() {

	//int 
	vector<int> arr;
	int wt;
	cin >> wt;
	int a;
	cin >> a;
	while(a) {
		
	arr.pb(a);
		cin >> a;
	}
	MiniatureDachshund abc;
	cout << abc.maxMikan(arr,wt);
}



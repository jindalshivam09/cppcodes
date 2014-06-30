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

	int n,k,l,r,sk,sall;
	cin >> n >> k >> l >> r >> sall >> sk;
	
	int temp = k * r;
	int remain = sall - temp;
	
	vi ans(n);

	for(int i=0;i<k;i++)
		ans[i] = r;

//	cout << temp << " " << sk << " " << temp-sk << endl;
	if(temp > sk) {
		
		int xtra = temp - sk;
		int reduce = 0;
		remain += xtra;
		
		for(int i=k-1;i>=0;i--) {
			
			reduce = (xtra)/(i+1);
			xtra -= reduce;
//			cout << reduce << " " << xtra << " " << i+1 << endl;
			ans[i] -= reduce;
		}
	}
	
/*	for(int i=0;i<n;i++)
		cout << ans[i] << " ";
cout << endl;
*/	
	int avg;
//	cout << remain;
	for(int i=k;i<n;i++) {
		
		avg = remain/(n-i);
//		cout << avg;
		ans[i] = avg;
		remain -= avg; 
	}
	
	for(int i=0;i<n;i++)
		cout << ans[i] << " ";
}



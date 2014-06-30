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

	int k;
	cin >> k;
	vi arr;
	string str;
	for(int i=0;i<4;i++) {
		
		cin >> str;
		for(int j=0;j<4;j++) {
			if(str[j] >= '0' && str[j] <= '9')
				arr.pb(str[j]-'0');
		}
	}
	sort(all(arr));
	int count = 0;
	for(int i=0;i<arr.size();) {
		count = 0;
		int temp = arr[i];
//		cout << temp << " " << i << " ";
		while(temp == arr[i++])
			count ++;
		i--;
//		cout << count << endl;
		if(count > 2*k) {
			cout << "NO";
			return 0;
		}
	}
	cout << "YES" ;
	return 0;
}



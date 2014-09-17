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

int n,k;
vi arr ;
vpii freq;

int main() {
	ifstream cin("input.txt") ;
	ofstream cout("output.txt") ;

	int t ;
	cin >> t ;
	for(int test=1;test<=t;test++) {
		cin >> n >> k;
		arr.resize(n) ;
		freq.clear() ;
		rep(i,n)
			cin >> arr[i] ;
		for(int i=0;i<n;) {
			int temp = arr[i] ;
			int cnt = 0 ;
			while(i<n && temp == arr[i])
				i ++,cnt ++;
			freq.pb(mp(temp,cnt)) ;
		}
		while(1) { 
			bool flag = false ;
			vpii temp_freq;
			for(int i=0;i<freq.size();i++) {
				if(freq[i].second>=3)
					flag = true ;
				freq[i].second %= 3 ; ;
			}
			for(int i=0;i<freq.size();) {
				bool zero = false ;
				if(freq[i].second != 0) 
					temp_freq.pb(freq[i]) ;
					
				while(i<freq.size()&&freq[i].second == 0)
					i++ ,zero = true;
				if(zero == false)
					i++;
			}
			freq.clear();
			for(int i=0;i<temp_freq.size();)  {
				int val = temp_freq[i].first  ;
				int sum =  0;
				while(i<temp_freq.size()&&temp_freq[i].first == val) {
					sum += temp_freq[i].second ;
					i ++;
				}
				freq.pb(mp(val,sum)) ;
			}
			if(flag == false)
				break;
		}
		int ans = 0;
		rep(i,freq.size()) {
			ans += freq[i].second ;
		}
		cout << "Case #" << test << ": " << ans << endl;
	}
}



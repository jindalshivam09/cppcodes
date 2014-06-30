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

#define MAX 100009

int main() {

	int n,m,p;
	cin >> n >> m >> p;
	
	vi arr(n);
	map<int,bool> a;
	map<int,bool> b;
	map<int,int> fr;
	int t;
	int count = 0;
	rep(i,n) {
		
		cin >> t;
		arr[i] = t;
		a[t] = true;
	}
	
	rep(i,m) {
		
		cin >> t;
		if(!b[t])
			count++;
		b[t] = true;
		fr[t] ++;
	}
	
//	cout << count << endl;
	
	set<int> ans;
	for(int i=0;i<p;i++) {
		
		map<int,int> freq;
		int c=0;
		int k=0;
		for(int j=i;j<n;j+=p) {
			
			k++;
			int temp = arr[j];
			if(b[temp]) {
				
				freq[temp] ++;
				if(fr[temp] == freq[temp]) 
					c++;				
			} 
			
			if(k == m) {
				
				if(count==c) {
					
					ans.insert(j-(m-1)*p+1);
				}
				int q = arr[j-(m-1)*p];
//				cout << q << " " << j << " " << k <<  " " << c  << endl;
				if(freq[q] == fr[q] && fr[q])
				c--;
				if(freq[q])
				freq[q] --;
				k--;
			}
			
		}
	}
	
	cout << ans.size() << endl;
	for(set<int>::iterator i = ans.begin() ; i != ans.end() ; i++)
		cout << (*i) << " ";
}



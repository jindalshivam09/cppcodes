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

bool cmp(const pii &a,const pii &b) {
	return a.second > b.second;
}
int main() {

	int n,m;
	cin >> n >> m;
	vpii freq(109);
	int a;
	for(int i=0;i<n;i++) {
		cin >> a;
		freq[a].second += 2;
		freq[a].first = a;
	}
	sort(all(freq),cmp);
//	for(int i=0;i<101;i++)
//	cout << freq[i].first << " " << freq[i].second << endl;
	vpii ans(n);
	int count = 0;
	int j=0,i;
	for(i=0;i<=108;i++) {
		
		while(freq[i].second) {
			ans[j].first = freq[i].first;
			freq[i].second--;
			j++;
			if(j==n)
				break;  
		}
		if(j==n)
			break;
	}
	j=0;
	for(;i<=108;i++) {
		while(freq[i].second) {
			ans[j].second = freq[i].first;
			freq[i].second--;
			
			if(ans[j].first != ans[j].second)
				count ++;
			j++;
			if(j==n)
				break;  
		}
		if(j==n)		
			break;
	}
	
	cout<< count << endl;
	for(int i=0;i<n;i++) {
		cout << ans[i].first << " " << ans[i].second << endl;
	}
	
	
}



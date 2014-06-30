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
#define MAX 209
struct item {
	ll s,x,d,p;
}item[MAX] ;

bool cmp_penalty (const struct item &a ,const struct item &b) {
	return a.p > b.p ;
}
bool cmp_start (const struct item &a,const struct item &b) {
	return a.s > b.s ;
}

int cal_penalties (vector<struct item> arr) {
	sort(all(arr),cmp_start);
	
	set<int> s ;
	rep(i,arr.size()) 
		s.insert(arr[i].s) , s.insert(arr[i].d)  ;
	
	vi time(all(s)) , segment;
	repi(i,1,time.size())
		segment.pb (time[i]-time[i-1]);
	ll ans = 0;
	rep(i,arr.size()) {
		int cur = arr[i].x ;
		for(int j=segment.size()-1;j>=0&&cur;j--) {
			if (time[j]>=arr[i].s && time[j]<arr[i].d) {
				if(segment[j]<=cur)	{
					cur -= segment[j];
					segment[j] = 0 ;
				}
				else	{
					segment[j] -= cur;
					cur = 0;
				}
			}
		}
		ans += cur;
	}
	return ans ;
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		rep(i,n)
			cin >> item[i].s >> item[i].x >> item[i].d >> item[i].p ;
		sort(item,item+n,cmp_penalty) ;
		ll ans = 0;
		vector<struct item> arr,newarr;
		ll temp ;
		arr.pb(item[0]);
		repi(i,1,n) {
			struct item q = {item[i].s,item[i].x,item[i].d,item[i].p};
			vector<struct item> newarr = arr ;
			newarr.pb(q);
			temp = cal_penalties(newarr);
			q.x -= temp ;
			ans += temp*item[i].p ;
			arr.pb(q);
		}
		cout << ans << endl;
	}
}

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


#define MAX 200009
int n,m ;
vpii arr ;
vi BIT, inv(MAX), main_arr(MAX) ;
typedef struct q {
	int i,j, left,right,id ;
} q;
vector<q> queries ;	
vector<vi> indexes;
vi val_freq ;
map <pii,int> freq ;

#ifdef ONLINE_JUDGE
#define GETCHAR getchar_unlocked
#define PUTCHAR putchar_unlocked
#endif
#ifndef ONLINE_JUDGE
#define GETCHAR getchar
#define PUTCHAR putchar
#endif
inline ll read_int()
{
int flag=1;
long long n = 0;
char c;
int sign=1;
while (1)
{
c=GETCHAR();
if(c=='-')	sign=-1;
else if(c>='0'&&c<='9') {n = n * 10 + c - '0';flag=0;}
else if(flag!=1) break;
 }
return sign*n;
}

bool cmp (const pii &a, const pii &b) {
	return a.second < b.second ;
}

bool cmpi (const q &a, const q &b) {
	return a.i < b.i ;
}

bool cmpj (const q &a, const q &b) {
	return a.j < b.j ;
}

bool cmpid (const q &a, const q &b) {
	return a.id < b.id ;
}

void update ( int idx, int val) {
	while(idx<BIT.size()) {
		BIT[idx] += val ;
		idx += (idx&-idx) ;
	}
}

int query( int idx ) {
	int ret = 0;
	while(idx>0) {
		ret += BIT[idx] ;
		idx -= (idx&-idx);
	}
	return ret ;
}

int main() {
	
//	ifstream cin("test.txt") ;
//	ofstream cout("1.txt") ;

//	cin >> n >> m ;
	n = read_int() ;
	m = read_int() ;
	
	arr.resize(n);
	
	rep(i,n) {
//		cin >> arr[i].first ;
		arr[i].first = read_int() ;
		arr[i].second = i ;
	}
	sort(all(arr)) ;
	int val = 1;
	for(int i=0;i<n;) {
		int temp = arr[i].first ;
		while( i<n && arr[i].first == temp) 
			arr[i++].first = val;
		val ++ ;
	}
	sort(all(arr),cmp) ;

	val_freq.resize(val) ;
	indexes.resize(val) ;

	rep(i,n) {
		int temp = arr[i].first ;
//		cout << temp << endl;
		val_freq[temp] ++ ;
		freq[mp(temp,i)] = val_freq[temp] ;
		indexes[temp].pb(i) ;
	}

	BIT.resize(val+1) ;
	ll inversions = 0;
	
	rep(i,n) {
		int temp = i-query(arr[i].first) ;
		inversions += temp ;
		inv[i] = temp ;
		update(arr[i].first,1);
	}
	int i,j;
	queries.resize(m) ;

	for(int k=0;k<m;k++) {
//		cin >> i >> j ;
		i = read_int() ;
		j = read_int() ;
		i--,j-- ;
		if(i>j)
			swap(i,j) ;
		queries[k].i = i , queries[k].j = j ;
		queries[k].id = k;
	}

	rep(i,val+1)
		BIT[i] = 0 ;	
	sort(all(queries),cmpi) ;
	
	int pos = 0 ;
	for(int i=0;i<m;i++) {
		int temp = queries[i].i ;
 		while(pos < temp) {
			update(arr[pos].first,1) ;
			pos ++ ;
		}
		int index = queries[i].j ;
		queries[i].right = temp - query(arr[index].first) ;
//		cout << temp << " " << index << " " << queries[i].right << endl;
	}

	rep(i,val+1)
		BIT[i] = 0 ;	

	sort(all(queries),cmpj) ;
	pos = 0 ;
	for(int i=0;i<m;i++) {
		int temp = queries[i].j ;
		while(pos < temp) {
			update(arr[pos].first,1) ;
			pos ++;
		}
		int index = queries[i].i ;
		int t = query(arr[index].first)  ;
		queries[i].left =  temp -  t ;
//		cout << index << " " << temp << " " << t << " " << queries[i].left << endl; 
	}
	
	sort(all(queries),cmpid) ;
	
	int l,r,xa,xb,ya,yb,xval,yval,samex,samey,xi,yi ;
	rep(i,m) {
		l = queries[i].i , r = queries[i].j ;
		xb = inv[l] , xa = queries[i].left  ;
		yb = inv[r] , ya = queries[i].right ;
		xval = arr[l].first , yval = arr[r].first ;
		if(xval > yval)
			yb -- ;
		
		if(xval == yval) {
			cout << inversions << endl;
//			printf("%lld\n",inversions) ;
			continue ;
		}
		
		xi = (lower_bound(all(indexes[xval]),r)-indexes[xval].begin()) ;
		yi = (lower_bound(all(indexes[yval]),l)-indexes[yval].begin()) ;
		
		if( xi == indexes[xval].size() ) 
			xi -- ;
		if(indexes[xval][xi] > r)
			xi -- ;
		xi = indexes[xval][xi] ;
		samex =  freq[mp(xval,xi)] - (freq[mp(xval,l)])  ;
		
		if( yi == indexes[yval].size() )
			samey = 0;
		else {
			yi = indexes[yval][yi] ;
			samey = freq[mp(yval,r)] - freq[mp(yval,yi)] ;
		}
		
/*		cout << i << endl;
		cout << l << " " << r << endl;
		cout << xb << " " << xa << endl;
		cout << yb << " " << ya << endl;
		cout << xi << " " << yi << endl;
		cout << xval << " " << yval << endl;
		cout << samex << " " << samey << endl;
		cout << (xa-xb) << " " << (r-l-1-(xa-xb)-samex) << endl;
		cout << (yb-ya) << " " << (r-l-1-(yb-ya)-samey) << endl;
*/
		ll ans = inversions + ((xa-xb)-(r-l-1-(xa-xb)-samex)) + ((r-l-1-(yb-ya)-samey)-(yb-ya)) ;
		if(xval>yval)
 			ans -- ;
 		else 
 			ans ++;

		printf("%lld\n",ans) ;
//		cout << ans << endl;
	}
}



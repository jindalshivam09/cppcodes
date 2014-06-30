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
#define repi(i,k,n) 		for(ll i=k;i<n;i++)
#define mp 				make_pair
#define pb			 	push_back
#define all(a) 			a.begin(),a.end()
#define imax  			numeric_limits<ll>::max()
#define imin 			numeric_limits<ll>::min()
#define dmax            numeric_limits<double>::max()
#define dmin            numeric_limits<double>::min()

int n , k ,s ;
vpii arr ;
int idx ;
bool flag_idx = false;

bool cmp (const pii &a,const pii &b) {
	return a.first < b.first ;
}

bool cmp2 (const pii &a,const pii &b) {
	return a.first > b.first ;
}

ll cal_func(ll index) {
	ll i = index , count  = 0;
	vll add(n+1) ;
	add[count++] = arr[index].first ;
	index = (index+1)%n ;
	while(count < n) {
		add[count] = add[count-1] + arr[index].first;
		index = (index+1)%n ;
		count ++;	
	}
	ll diff = 0 ;
	int j = 0;
	int start = 0 , last = 0 ;
	if ( s < add[j] ) {
		diff = s ;
	}
	else {
		while(s>=add[j]) j ++ ;
		diff = s - add[j-1] ;
		j -- ;
	}
	last = j ;
	for(int l=0;l<k-1;l++) {
		last = max(last,l+1) ;
		if (s < add[last]-add[l]) {
			diff += s ;
			if(!flag_idx) {
				idx = l+1 ;
				flag_idx = true;
			}
			continue ;
		}
		while( last < n && s >= add[last]-add[l] )
			last ++ ;
		
		diff += s - (add[last-1] - add[l]) ;
		last --; ;
	}
	return ceil(1.0*diff/k) ;
}

void func() {
	sort(all(arr),cmp) ;
	ll ans = imax ;
	int index,id;
	rep(i,n) {
		flag_idx = false;
		ll temp = cal_func(i) ;
  		if ( ans > temp ) {
		  	ans = temp ;
		  	index = i;
		  	if (flag_idx)
		  		id = idx ;
		}
	}
	int count = 0 ;
	vi perm(n) ;
	int temp = index , temp2 = index;
	while(count < n  ) {
		if (flag_idx && temp2 >= id+index)
			break;
		temp2 ++ ;
		perm[count] = arr[index].second+1 ;
		count ++ ;
		index = (index+1)%n ;
	}
	if(flag_idx) {
		for(int i=0;i<temp;i++)
			perm[count++] = arr[i].second+1;
		for(int i=index;i<n;i++)
			perm[count++] = arr[i].second+1;
	}
	rep(i,n)
		printf("%d ",perm[i]) ;
	printf("\n" );
}

int main() {
	int t;
	scanf("%d",&t);
	while(t--) {
		scanf("%d%d%d",&n,&k,&s) ;
		arr.resize(n) ;
		rep(i,n) {
			scanf("%d",&arr[i].first) ;
			arr[i].second = i ;
		}
		func() ;
	}
}

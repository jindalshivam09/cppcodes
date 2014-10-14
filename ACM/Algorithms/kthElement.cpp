#include<bits/stdc++.h>
using namespace std ;

#define MAX 100009
int n, m ;
vector<int> pos(MAX) ;
vector<vector<int> > segment(100,vector<int>(MAX)) ;

void init(int num,int a,int b) {
	if(a==b) {
		segment[num][a] = pos[a] ;
		return ;
	}
	int mid = (a+b) / 2 ;
	init(num+1,a,mid) ;
	init(num+1,mid+1,b) ;
	int i = a, j = mid+1 ;
	int k = a ;
	while(i<=mid && j<=b) {
		if(segment[num+1][i] > segment[num+1][j]) {
			segment[num][k] = segment[num+1][j] ;
			k++, j ++ ;
		}
		else {
			segment[num][k] = segment[num+1][i] ;
			k++, i ++ ;		
		}
	}
	while(i<=mid) {
			segment[num][k] = segment[num+1][i] ;
			k++, i ++ ;
	}
	while(j<=b) {
			segment[num][k] = segment[num+1][j] ;
			k++, j ++ ;	
	}
}

int func(int num, int l, int r, int a, int b) {
	return upper_bound(segment[num].begin()+l, segment[num].begin()+r+1,b) - lower_bound(segment[num].begin()+l,segment[num].begin()+r+1,a) ;
}

int retrieve(int a, int b, int k) {
	int l = 1, r = n ;
	int num = 0  ;
	while(l != r) {
		int mid = (l+r)/2 ;
		int cnt = func(num+1,l,mid,a,b) ;
		if( cnt >= k )		r = mid ;
		else {
			l = mid+1 ;
			k -= cnt ;
		}
		num ++ ;
	}
	return l ;
}

int main() {
	cin >> n >> m ;
	vector<int> arr(n+1), value(n+1), val(n)  ;
	for(int i=1;i<=n;i++) {
		cin >> arr[i] ;
		val[i-1] = arr[i] ;
	}
	sort(val.begin(),val.end()) ;
	for(int i=1;i<=n;i++) {
		int temp = arr[i] ;
		int idx = lower_bound(val.begin(),val.end(),temp) - val.begin() + 1 ;
		pos[idx] = i ;
		value[idx] = arr[i] ;
	}
	init(0,1,n) ;
	int l, r, k ;
	while(m--) {
		cin >> l >> r >> k ;
		cout << value[retrieve(l,r,k)] << endl;
	}
}

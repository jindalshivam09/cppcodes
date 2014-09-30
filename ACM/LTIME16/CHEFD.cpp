#include<bits/stdc++.h>
using namespace std ;
#define MAX 100009
int n ;
vector<int> arr(MAX), newarr(MAX) ;

typedef struct node {
	bool lazy ;
	int two, three, five ;
} node;
vector<node> segment(4*MAX) ;

void init(int num, int i, int j) {
	if(i==j) {
		segment[num].two = segment[num].three = segment[num].five = 0;
		segment[num].lazy = false;
		return ;
	}
	int mid = (i+j)/2 ;
	init(2*num,i,mid) ;
	init(2*num+1,mid+1,j) ;
}

void pushlazy(int num, int i, int j) {
	if(segment[num].lazy == true ) {
		if(i!=j) {
			segment[2*num].lazy = segment[2*num+1].lazy = true ;
			segment[2*num].three += segment[num].three ;
			segment[2*num].two += segment[num].two ;
			segment[2*num].five += segment[num].five ;
			segment[2*num+1].three += segment[num].three ;
			segment[2*num+1].two += segment[num].two ;
			segment[2*num+1].five += segment[num].five ;
			segment[num].two = segment[num].three = segment[num].five = 0 ;				
		}
		segment[num].lazy = false ;
	}
}

void update(int num,int i, int j, int a, int b, int p)  {
	pushlazy(num,i,j) ;
	if(j<a || i>b)
		return ;
	if(i>=a && j<=b) {
		segment[num].lazy = true ;
		if(p==2)	segment[num].two ++ ;
		if(p==3)	segment[num].three ++ ;
		if(p==5)	segment[num].five ++ ;
		pushlazy(num,i,j) ;
		return ;
	}
	int mid = (i+j)/2 ;
	update(2*num,i,mid,a,b,p) ;
	update(2*num+1,mid+1,j,a,b,p) ;
}

void point_update(int num, int i, int j, int a) {
	pushlazy(num,i,j) ;
	if(j<a || i>a)
		return ;
	if(i==j) {
//		cout << segment[num].two << " " << segment[num].three << " " << segment[num].five <<  endl;
		segment[num].two = 0 ;
		segment[num].three = 0 ;
		segment[num].five = 0 ;
		return ;
	}
	int mid = (i+j)/2 ;
	point_update(2*num,i,mid,a ) ;
	point_update(2*num+1,mid+1,j,a) ;
}

vector<node> values(MAX) ;

void retrieve (int num, int a, int b) {
	pushlazy(num,a,b) ; 
	if(a==b) {
		values[a].two = segment[num].two ;
		values[a].three = segment[num].three ;
		values[a].five = segment[num].five ;
//		cout << segment[num].two << " " << segment[num].three << " " << segment[num].five <<  endl;
		
		return ;
	}
	int mid = (a+b)/2 ;
	retrieve(2*num,a,mid) ;
	retrieve(2*num+1,mid+1,b) ;
}


int main() {
	cin >> n ;
	for(int i=1;i<=n;i++) {
		cin >> arr[i] ;
		newarr[i] = arr[i] ;
	}
	init(1,1,n) ;
	int m ;
	cin >> m ;
	while(m--) {
		int type,l,r,p ,d ;
		cin >> type ;
		if(type==1) {
			cin >>  l >> r >> p ;
			update(1,1,n,l,r,p) ;
		}
		else {
			cin >> l >> d ;
			point_update(1,1,n,l) ;
			newarr[l] = d ;
		}
	}
	retrieve(1,1,n) ;
	
	int val = 0, temp ;
	for(int i=1;i<=n;i++) {
		temp = newarr[i] ;
		val = values[i].two;
		while(val && (temp%2==0)) {
			val --;
			temp /= 2 ;
		}
		val = values[i].three;
		while(val && (temp%3==0)) {
			val --;
			temp /= 3 ;
		}
		val = values[i].five;
		while(val && (temp%5==0)) {
			val --;
			temp /= 5 ;
		}
		cout << temp << " ";
	}
}

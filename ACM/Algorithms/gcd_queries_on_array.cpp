#include<bits/stdc++.h>
using namespace std;

typedef struct node {
	int gcd, d, a ;
	bool lazy ;
} node ;

class segmentTree {
	vector<int> arr ;
	vector<node> segment ;
	public :
		segmentTree() {}
		segmentTree(const vector<int> &arr ) {
			this->arr = arr ;
			segment.resize(4*arr.size()) ;
			initSegmentTree(1,0,arr.size()-1) ;
		}
		void initSegmentTree(int num, int a, int b) {
			if(a == b) {
				segment[num].lazy = false ;
				segment[num].a = arr[a] ;
				segment[num].gcd = 0 ;
				segment[num].d = 0 ;
				return ;
			}
			int mid = (a+b)/2 ;
			initSegmentTree(2*num,a,mid) ;
			initSegmentTree(2*num+1,mid+1,b) ;
			
			int val1 = segment[2*num+1].gcd ? segment[2*num+1].gcd : segment[2*num].a ;
			int val2 = segment[2*num].gcd ? segment[2*num].gcd : val1 ;
			segment[num].gcd = __gcd( segment[2*num+1].a, __gcd( val1, val2 ) ) ;
			segment[num].lazy = false;
			segment[num].d = 0 ;
			segment[num].a = segment[2*num].a ;
		}
		void pushlazy(int num, int i, int j) {
			if(segment[num].lazy == true) {
				segment[num].a += segment[num].d ;
				if(i != j) {
					segment[2*num].lazy = segment[2*num+1].lazy = true ;
					segment[2*num].d += segment[num].d ;
					segment[2*num+1].d += segment[num].d ;
				}
				segment[num].d = 0 ;
			}
		}
		void update(int num,int i, int j, int a, int b,int d) {
			pushlazy(num,i,j) ;
			if(i>b || j<a)
				return ;
			if(i>=a && j<=b) {
				segment[num].lazy = true ;
				segment[num].d += d ;
				pushlazy(num,i,j);
				return ;
			}
			int mid = (i+j)/2 ;
			update(2*num,i,mid,a,b,d) ;
			update(2*num+1,mid+1,j,a,b,d) ;
			
			segment[num].a = segment[2*num].a ;
			int num1 = segment[2*num+1].gcd ? segment[2*num+1].gcd : segment[2*num+1].a ;
			int num2 = segment[2*num].gcd ? segment[2*num].gcd : num1 ;
			segment[num].gcd = __gcd( segment[2*num+1].a, __gcd(num1, num2) ) ;
		}
		int retrieve(int num, int i, int j, int a, int b) {
			pushlazy(num,i,j) ;
			if(i>b || j<a) 
				return 0 ;
			if(i==j) {
				return segment[num].a ;
			}
			if(i>=a && j<=b) {
				int ret = __gcd(segment[num].a, segment[num].gcd) ;
				return ret ;
			}
			int mid = (i+j)/2 ;
			int ret1 = retrieve(2*num,i,mid,a,b) ;
			int ret2 = retrieve(2*num+1,mid+1,j,a,b) ;
			if(ret1 == 0)
				return ret2 ;
			else if(ret2 == 0)
				return ret1 ;
			return __gcd(ret1,ret2) ;
		}
};

int main() {
	int n;
	cin >> n ;
	vector<int> arr(n) ;
	for(int i=0;i<n;i++)
		cin >> arr[i] ;
	segmentTree tree(arr) ;
	int q ;
	cin >> q ;
	while(q--) {
		int type,l,r,d ;
		cin >> type >> l >> r ;
		l--,r--;
		if(type == 1) {
			cin >> d ;
			tree.update(1,0,n-1,l,r,d) ;
		}
		else {
			cout << tree.retrieve(1,0,n-1,l,r) << endl;
		}
	}
}


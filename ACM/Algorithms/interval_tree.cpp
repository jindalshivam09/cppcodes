/*
	Name: Interval_tree data structure 
	Copyright: no rights
	Author: jindalshivam09
	Date: 18/04/14 01:35
	Description: to handles the following queries :
			 	 1) enclosing interval searching problems : given a set s of intervals and a query point q , find the number of 
					 intervals that contain this point
			 	 2) overlapping interval searching problem : given a set s of intervals and a query interval q, find the number of 
					 intervals with which the q overlaps
*/


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

#define MAX 10009
int n , num = 1 , root;
vpii pairs ;
map<int,int> x_map , y_map ;

struct nodes {
	double median;
	int left,right; 
	vi X,Y;
} node[MAX] ;

double find_median(const vpii &segments) {
	int n = segments.size() ;
	vd med(n) ;
	rep(i,n)
		med[i] = double( segments[i].first + segments[i].second ) / 2.00 ;
	sort(all(med)) ;
	if (n % 2)
		return med[n/2] ;
	else
		return double(med[n/2]+med[n/2-1])/2.00 ;
}

void interval_tree (const vpii &segments, int &pre) {
	int n = segments.size() ;
	if (n == 0)
		return ;
	double median = find_median(segments) ;
	int a,b ;
	vpii left, right ;
	cout << median << " " << num << endl;
	node[num].median = median ;
//	node[num].left = num + 1 , node[num].right = num + 2 ;
	rep(i,n) {
		a = segments[i].first , b = segments[i].second ;
		if ( a <= floor(median) && b >= ceil(median) ) {
//			cout << a << " " << b << endl;
			node[num].X.pb(a) , node[num].Y.pb(b) ;
		}
		else if ( b <= floor(median) ) 
			left.pb(segments[i]) ;
		else
			right.pb(segments[i]) ;
	}
	pre = num++ ;
	
	sort(all(node[num-1].X)) , sort(all(node[num-1].Y)) ;
	interval_tree(left,node[num-1].left) , interval_tree(right,node[num-1].right); 
}

int enclosing_intervals ( int num , pii point ) {
//	cout << num << endl;
	if ( node[num].X.size() == 0 )
		return 0 ; 
	
	double median = node[num].median ;
	
//	cout << median << " ";
	int a = point.first , b = point.second , ans = 0 ;
		
	if ( a <= floor(median) && b >= ceil(median) ) {
		
		int index = upper_bound(all(node[num].Y),a) - node[num].Y.begin() ;
		if (index < node[num].Y.size() ) 		ans += (node[num].Y.size()-index)  ;
		
		index = lower_bound (all(node[num].X),b) - node[num].X.begin() ;
		if ( index < node[num].X.size() && node[num].X[index] == b )		ans += index + 1 ;
		
//		cout << "in the first if " << ans << endl;
		return ans + enclosing_intervals(node[num].left,point) + enclosing_intervals(node[num].right,point) ;
	}
	else if ( b <= floor(median) ) {
		
		int index = lower_bound (all(node[num].X),b) - node[num].X.begin() ;
		if (  index < node[num].X.size() && node[num].X[index] == b )		ans += index+1 ;		

//		cout << "in the second if " << ans << endl;
		return ans + enclosing_intervals(node[num].left,point) ;
	}
	else  {
		
		int index = upper_bound(all(node[num].Y),a) - node[num].Y.begin() ;
		if (index < node[num].Y.size() ) 		ans += (node[num].Y.size()-index)  ;
	
//		cout << "in the third if " << ans << endl;
		return ans + enclosing_intervals(node[num].right,point) ;		
	}
	return 0 ;
}

int main() {
	ifstream cin("input.txt");
//	ofstream cout("output.txt") ;
	cin >> n ;
	pairs.resize(n) ;
	int a,b ;
	rep(i,n)  {
		cin >> a >> b ;
		pairs[i].first = a ,  pairs[i].second = b ;
		x_map[a] = b , y_map[b] = a ;
	}
	interval_tree(pairs,root) ;
	int q ;
	cin >> q ;
	while(q--) {
		pii point ;
		cin >> point.first >> point.second ;
		cout << enclosing_intervals(root,point) << endl;
	}
}

/*

5
1 4
1 3
5 10
5 8
2 7
10
1 4
4 5
1 10

*/



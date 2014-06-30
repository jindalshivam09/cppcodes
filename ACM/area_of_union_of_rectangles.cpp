/*
	Name: Area of union of rectangle using sweepline algorithm
	Copyright: no rights
	Author: Shivam Jindal
	Date: 29/11/13 14:09
	Description: refer to tutorial on sweep line algorithms on topcoder
*/

#include <bits/stdc++.h>
#include <map>
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

class rectangle {
	
	pii lower,upper;
	int area;
	public :
		rectangle() {}
		rectangle(pii a, pii b) {
			
			a < b ? lower = a : upper = b;
			area = cal_area();		
		}
		void insert(pii a,pii b) {
			
			a < b ? lower = a : upper = b;
			area = cal_area();
		}
		
		int cal_area () {
			
			return abs(lower.first - upper.first) * abs(lower.second - upper.second);
		}
		int give_area() {
			
			return area;
		}
		bool operator < (const rectangle &r) const {
					
			return lower.first == upper.first ? lower.second > upper.second : lower.first > upper.first;
		}
		friend bool cmp(const rectangle &,const rectangle &) ;
		friend int cal_union_area(rectangle *,int);
};


bool cmp(const rectangle &a , const rectangle &b)  {
	
	return a.lower.first == b.upper.first ? a.lower.second < b.upper.second : a.lower.first < b.upper.first;
}

int min_x = imax , max_x = imin;

int union_from_active_elements(  multimap <int,rectangle> &Q , const pair< multimap <int,rectangle>::iterator,  multimap <int,rectangle>::iterator > &range) {
	
	multimap<int,rectangle>::iterator start = range.first , last = range.second , i;
	int area = 0;
	for( ; ; start ++) {
		
		rectangle elem = start->second;
		for( i = Q.begin() ; i != Q.end() ; i ++) {
			
			rectangle elem2 = i->second; 
				
		}
		if(start == last)
			break;
	}
}

int cal_union_area (rectangle *figures,int n) {
	
	multimap <int,rectangle> Q;
	int sweep_line = min_x;
	int k=0;
	int area = 0 , area_union = 0;
	for(; sweep_line <= max_x ; sweep_line ++ ) {
		
		while(figures[k].lower.first == sweep_line) {
		
		
			area += figures[k].give_area();	
			Q.insert(mp(figures[k].upper.first,figures[k]));
			k++;
		}
		
		
		if(Q.count(figures[k].upper.first) > 0) {
		
			pair< map <int,rectangle>::iterator,  map <int,rectangle>::iterator > range = Q.equal_range(figures[k].upper.first);	
			Q.erase(figures[k].upper.first);
			area_union += union_from_active_elements(Q,range);			
		}
		
	}
}

int main() {

	int n;
	cin >> n;
	rectangle figures[n];
	
	int a,b,c,d;
	for(int i=0;i<n;i++){
		
		cin >> a >> b >> c >> d;
		min_x = min(min_x,min(a,c));
		max_x = max(max_x,max(a,c));
		figures[i].insert(mp(a,b),mp(c,d));
	}
	
	sort(figures,figures+n,cmp);
	cout << cal_union_area(figures,n) << endl;
}



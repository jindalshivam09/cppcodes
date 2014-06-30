/*
	Name: Closest pair in 2-dimension plane
	Copyright: no rights
	Author: Shivam Jindal
	Date: 14/11/13 19:27
	Description: using divide and conquer approach
*/


#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <algorithm>
#include <set>
#include <limits>
#include <utility>
#include <iomanip>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cstring>

using namespace std;

typedef long long 		ll;
typedef vector<int> 	vi;
typedef pair<int,int> 	pii;
typedef vector<pair<int,int> > vpii;
typedef vector<double> 	vd;
typedef pair<double,double> 	pdd;
typedef vector<pair<double,double> > vpdd;

#define rep(n)    		for(int i=0;i<n;i++)
#define repi(k,n) 		for(int i=k;i<n;i++)
#define mp 				make_pair
#define pb			 	push_back
#define all(a) 			a.begin(),a.end()
#define imax  			numeric_limits<int>::max()
#define imin 			numeric_limits<int>::min()
#define printall(a)		for_each(all(a),print)
#define dmax            numeric_limits<double>::max()
#define dmin            numeric_limits<double>::min()

void print (const pii &a) {
	
	cout << a.first << " " << a.second << endl;
}

bool cmpy (const pii &a,const pii &b)  {

	return a.second > b.second;
}

bool cmpx (const pii &a,const pii &b)  {

	return a.first < b.first;
}

double dist ( const pii &a, const pii &b ) {
	
	double x = pow ( a.first - b.first , 2 );
	double y = pow ( a.second - b.second , 2 ); 
	return sqrt(x+y);
}

double inter_sets_dist (const vpii &strips,double d) {
	
	
	for(int i=0;i<strips.size();i++) {
		
		for(int j=i+1;j<strips.size() && strips[i].second < strips[j].second ;j++) {
			
			if ( dist(strips[i],strips[j]) < d) 
				d = dist(strips[i],strips[j]);
		}
	}
	return d;
}

double closest_pair (vpdd &points,int a,int b) {
	
	if ( a == b )		
		return imax;
	if ( b-a == 1 )
		return 	dist(points[a],points[b]);
	
	int c = (a+b)/2;
	double d1 = closest_pair(points,a,c);
	double d2 = closest_pair(points,c+1,b);
	
	double d = min (d1,d2);
	vpii strips;
	for (int i = a ; i <= b ; i ++) {
		
		if( abs(points[c].first - points[i].first) <= d ) {
			
			strips.push_back(points[i]);
		}
	}
	double inter_d = inter_sets_dist(strips,d);
	return min(inter_d,d);
}

int main() {

	int n;
	cin >> n;
	
	vpdd points(n);
	
	int a,b;
	for(int i=0;i<n;i++) {
		
		cin >> a >> b;
		points[i] = mp(a,b);
	}
	sort(all(points),cmpy);
	sort(all(points),cmpx);

	cout << closest_pair(points,0,n-1) << endl;
}



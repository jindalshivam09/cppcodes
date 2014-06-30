// under construction---------------

/*
	Name: Bentley Ottman ALgorithm 
	Copyright: no rights
	Author: jindalshivam09
	Date: 20/03/14 22:16
	Description: this algo is to find the intersection of line segment in a plane
			http://geomalgorithms.com/a09-_intersect-3.html
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
typedef pair<double,double> pdd;
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

//-------------main algorithm------------------------------------------------------------------------------------------------------------------

#define LEFT 1
#define RIGHT 2
#define INTERSECT 3

class cmp {
	public :
		bool operator () (const pair<pdd,int> &a,const pair<pdd,int> &b) {
			return a.first.first == b.first.first ? a.first.second > b.first.second : a.first.first > b.first.first ;
		} 
};

typedef struct segment {
	int x1,x2,y1,y2;
	segment () {}
	segment (pdd a,pdd b) {
		x1 = a.first , y1 = a.second;
		x2 = b.first , y2 = b.second;
	}
	bool operator < (const segment &a) 	const{
		cout << "calling < operator for : " << this->x1 << " " << this->y1 << " "<< a.x1 << " " << a.y1 << endl;;
		return this->y1 < a.y1 ; 
	}
}segment;

	ostream & operator << (ostream &cout ,segment seg) {
		cout << seg.x1  << " " << seg.y1 << " " << seg.x2 << " " << seg.y2 << endl;
		return cout ;
	}

class bentley_ottman {
	
//containers--	
	map <segment,int> SL ; // this is to store the segments 
	priority_queue<pair<pdd,int> ,vector<pair<pdd,int> > , cmp> EQ ; //  event queue
	map<pdd ,int> present ; // to check whether an event has inserted doubleo EQ earlier or not
	vector< pdd > IL ; // store the doubleersecting podoubles
	map<pdd,pdd> left, right ; // this srores the segment of endpodoubles
	map<pdd,pair<segment,segment> > inter_seg ; // this stores the doubleersecting segment of the doubleESECT podouble in EQ

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// some private functions :) ---------------------------------------------------
	pdd intersect (segment seg1, segment seg2) {
		
	}
	
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// constructor----
	public :
		bentley_ottman() {}
		bentley_ottman(const vector<pair<pdd,pdd> > &point ) {
			rep(i,point.size()) {
				EQ.push(mp(point[i].first,LEFT)) , EQ.push(mp(point[i].second,RIGHT));		// initialise EQ with all endpointfi of segments
				left[point[i].first] = point[i].second ;
				right[point[i].second] = point[i].first ;
			}
		}
		
		
		vector<pdd> intersecting_points () {
			pair<pdd,int> seg ;
			pdd temp ;
			map<segment , int>::iterator itr , itrBel , itrAbov ;
			segment abovS , belS ,cur ;
			while ( EQ.empty() == false ) {
				seg = EQ.top() ;
				cout << "EQ " << seg.first.first << " " << seg.first.second << endl;
				cout << "side" << seg.second << endl;
				cin.get() ;
				EQ.pop() ;
				if (seg.second == LEFT) {		// if the sweeped segment is left endpoint
					temp = left[seg.first] ;
					segment cur(seg.first,temp);
					SL.insert(mp(cur,1));
					cout << cur << endl;
					itr = SL.find(cur);
					itrAbov = itr  , itrAbov ++ ;
					itrBel = itr , itrBel -- ;
					cout << "shivam" << (itrBel->first).x1 << " " << (itrBel->first).y1 << "jindal" <<  endl; 
//					abovS = aboveSeg(cur);
//					belS = belowSeg(cur);
					if (itrAbov != SL.end()) {
						abovS = (*itrAbov).first ;
						cout << abovS.x1 << " " << abovS.y1 << endl;
						temp = intersect (abovS,seg.first) ;
						cout << "intersection " << temp.first << " " << temp.second << endl;;
						if (temp.first != -1)		EQ.push(mp(temp,INTERSECT)) , present[temp] = 1 , inter_seg[temp] = mp(abovS,cur);
					}
					if (itr != SL.begin()) {
						belS = (*itrBel).first ;
						cout << belS.x1 << " " << belS.y1 << endl;
						temp = intersect (belS,seg.first) ;				
						cout << "intersection " << temp.first << " " << temp.second << endl;;
						if (temp.first != -1)		EQ.push(mp(temp,INTERSECT)) , present[temp] = 1 , inter_seg[temp] = mp(cur,belS);
					}
				}

				else if (seg.second == RIGHT ) {  	// // if the sweeped segment is right endpoint
					temp = right[seg.first] ;
					segment cur(temp,seg.first);
					itr = SL.find(cur);
					itrAbov = itr , itrAbov ++  ;
					itrBel = itr , itrBel -- ;
//					if (itr == SL.end())	continue ;
//					abovS = aboveSeg(cur);
//					belS = belowSeg(cur);
					SL.erase(cur) ;
					if (itrAbov != SL.end() ) { 
						abovS = (*itrAbov).first;
						if (itr != SL.begin()) {
							belS = (*itrBel).first;
							cout << abovS.x1 << " " << abovS.y1 << endl;
							cout << belS.x1 << " " << belS.y1 << endl;
							cout << "intersection " << temp.first << " " << temp.second << endl;;
							if (temp.first != -1 && !present[temp])
								EQ.push(mp(temp,INTERSECT)) , present[temp] = 1 , inter_seg[temp] = mp(abovS,belS);	
						}
					}
				}
/*				else {			
					IL.pb(seg.first);
					segment cur(mp(0,0),seg.first);
					itr = SL.find(cur);
					itr -- ;
					itrAbov = itr ;
					itr ++ , itr ++;
					itrBel = itr;
					abovS = (*itrAbov).first;
					belS = (*itrBel).first;	
					segment seg1 = inter_seg[seg.first].first ;
					segment seg2 = inter_seg[seg.first].second ;			
					if (belS.x1 != -1) { 
						segment r(seg.first,mp(belS.x2,belS.y2));
	//					SL.erase(itrAbov) , SL[t] = 1 ; // to swap the pos of the segments after the intersection points
						SL.erase(itrBel) , SL[r] = 1 ;
						temp = intersect ( seg1 , belS ) ;
						cout << "intersection " << temp.first << " " << temp.second << endl;;
						if (temp.first != -1 && !present[temp])
							EQ.push(mp(temp,INTERSECT)) , present[temp] = 1 , inter_seg[temp] = mp(seg1,belS);	
					}
					if (abovS.x1 != -1) { 	
						segment t(seg.first,mp(abovS.x2,abovS.y2)) ;
						SL.erase(itrAbov) , SL[t] = 1 ; // to swap the pos of the segments after the intersection points
//						SL.erase(itrBel) , SL[r] = 1 ;
						temp = intersect ( seg2 , abovS ) ;
						cout << "intersection " << temp.first << " " << temp.second << endl;;
						if (temp.first != -1 && !present[temp])
							EQ.push(mp(temp,INTERSECT)) , present[temp] = 1 , inter_seg[temp] = mp(abovS,seg2);	
					}
				}
*/
//				for(set<segment>::iterator itr = SL.begin() ; itr != SL.end() ; itr ++) 
//					cout << itr->x1 << " " << itr->y1 << endl;
			}
			return IL ;
		}	
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
};

//---------------------------------------------------------------------------------------------------------------------------------------

int main() {
	int n;
	cin >> n ;
	vector<pair<pdd,pdd> > points(n);
	int x1,x2,y1,y2 ;
	rep(i,n) {
		cin >> x1 >> y1 >> x2 >> y2 ;
		points[i] = mp(mp(x1,y1),mp(x2,y2));
	}
	bentley_ottman lines(points);
	vector<pdd> intersections = lines.intersecting_points () ;
//	cout << intersections.size() ;
//	rep(i,intersections.size()) {
//		cout << intersections[i].first << " " << intersections[i].second << endl;
//	}
}

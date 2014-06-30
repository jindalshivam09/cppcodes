/*
	Name: Kruskal Algorithm
	Copyright: no rights
	Author: Shivam Jindal
	Date: 30/07/13 13:52
	Description: to find minimum spanning tree using unio find ds
*/


#include<iostream>
#include<list>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;

////////////////////////////////////////////////////////////////////////////////
//#include"union_find_operation.h"		// containin a namespace naming ufo
namespace ufo {
	///////////////////////////////////////////////////////////////////////////////
	#define parent first
	#define rank second 
	typedef vector <int> sets;
	typedef vector <int> paths;
	typedef pair <int,int> pairs;
	///////////////////////////////////////////////////////////////////////////////
	
	//-------------input n ouput---------------------------------------------------
	
/*	void input (pairs *p , int n) {
		int a,b;
		for(int i = 0 ; i < n ; i ++) {
			cin >> a >> b;
			p[i] = make_pair(a,b);
		}		
	}
	
	void output (sets s ) {
		for( sets::iterator i = s.begin() ; i != s.end() ; i ++) {
			cout << *i << " " ;
		}
	}
	///////////////////////////////////////////////////////////////////////////////
	
*/	
	void path_compression (paths p ,sets &s, int i) {
		for (auto &j : p) {
			//cout << j;
			s[j] = i; 
		}
	}
	
	pairs find_operation (sets &s , int b) {
		paths p;
		int i = b;
		int count = 0;
		while ( s[i] != i) {
			p.push_back(i);
			i = s[i];
			count ++;
		}	
		path_compression(p,s,i);
		return make_pair(i,count);
	}
	
	
	
	void union_operation (pairs p, sets &s) {
		int a,b;
		pairs r1,r2;
		a = p.first ;
		b = p.second ;
		//cout << a << " " << b << endl;
		if(s[a] == -1 && s[b] == -1) 		s[a] = s[b] = a;	// that is the case when both elements does not belong to any group
		else if( s[a] == -1 )  				s[a] = s[b];
		else if( s[b] == -1)				s[b] = s[a];
		else {
				r1 = find_operation (s,a);
				r2 = find_operation (s,b);
				if(r1.parent != r2.parent) {
					if(r1.rank == r2.rank) 			s[s[b]] = s[a];
					else if(r1.rank < r2.rank)		s[s[a]] = s[b];
					else 							s[s[b]] = s[a];
					//cout << rank1 << " " << rank2 <<  endl;
				}
		}
		//output(s);
		//cout << endl;
	
	}
	
	//////////////////////////////////////////////////////////////////////////////
	
}	
#define weight second
#define vertices first
#define vertice1 first.first
#define vertice2 first.second
typedef pair < pair<int,int> , int > wt_edge;
////////////////////////////////////////////////////////////////////////////////

//-----------------input n output----------------------------------------------
void input (wt_edge *edge , int e) {
	int a,b,wt;	
	for(int i = 0 ; i < e ; i ++) {
		cin >> a >> b >> wt;
		edge[i] = make_pair ( make_pair(a,b) , wt);
	}
}

void output (wt_edge *edge , int v ) {
	int chef = 0 , overall = 0;
	for(int i = 0 ; i < v ; i ++) {
		cout << edge[i].vertice1 << " 	"  << edge[i].vertice2 << " " << edge[i].weight << " ";
		if(edge[i].weight < 0) {
			chef += -1*edge[i].weight;
			overall += -1*edge[i].weight ;
		}
		else
			overall += edge[i].weight ;
	}
	cout << chef << " " << overall << endl;
}
////////////////////////////////////////////////////////////////////////////////
int cmp (const wt_edge &e1 , const wt_edge &e2) {
	return e1.weight < e2.weight;
}

void kruskal (wt_edge *edge , int v , int e , wt_edge *mst) {
	
	ufo::sets s;
	ufo::pairs r1,r2;
	int mst_e = -1;
	
	s.resize (v+1 , -1);
	
	sort (edge , edge + e  , cmp);
//	output(edge , e);
	for (int i =0 ; i < e ; i ++) {
		if ( s[edge[i].vertice1] == -1 || s[edge[i].vertice2] == -1 ) {
			ufo :: union_operation( edge[i].vertices , s );
			mst[  ++ mst_e  ] = edge[i];
		}
		else {
			r1 = ufo :: find_operation (s,edge[i].vertice1);
			r2 = ufo :: find_operation (s,edge[i].vertice2);
			if(r1.parent != r2.parent) {
				ufo :: union_operation( edge[i].vertices , s );
				mst[ mst_e ++ ] = edge[i];	
			}
		}
	}
}

////////////////////////////////////////////////////////////////////////////////

int main() {
	int test;
	cin >> test;
	while(test--) {
		int e , m2 , m1;
		cin >> e >> m1 >> m2;
		int a,b,wt;
		wt_edge edge[m1+m2] , road1[m1+m2] , road2[m1+m2];
			for(int i = 0 ; i < m1 ; i ++) {
				cin >> a >> b >> wt;
				edge[i] = make_pair ( make_pair(a,b) , wt);
			
			}
			for(int i = m1+1 ; i < m1+1+m2  ; i ++) {
				cin >> a >> b >> wt;
				wt *= -1;
				edge[i] = make_pair ( make_pair(a,b) , wt);
			}
		output(edge,e);
//		for(int i=0;i<m2;i++)
//			edge[i] = road2[i] ;
		
		wt_edge mst[e];
		kruskal(edge , e , m2+m1 , mst);
		output (mst,m1+m2);
	}
}

////////////////////////////////////////////////////////////////////////////////

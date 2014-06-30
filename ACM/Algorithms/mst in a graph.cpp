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

namespace ufo {
	///////////////////////////////////////////////////////////////////////////////
	#define parent first
	#define rank second 
	typedef vector <long long> sets;
	typedef vector <long long> paths;
	typedef pair <long long,long long> pairs;
	///////////////////////////////////////////////////////////////////////////////
	
	
	void path_compression (paths p ,sets &s, long long i) {
		for (auto &j : p) {
			//cout << j;
			s[j] = i; 
		}
	}
	
	pairs find_operation (sets &s , long long b) {
		paths p;
		long long i = b;
		long long count = 0;
		while ( s[i] != i) {
			p.push_back(i);
			i = s[i];
			count ++;
		}	
		path_compression(p,s,i);
		return make_pair(i,count);
	}
	
	
	
	void union_operation (pairs p, sets &s) {
		long long a,b;
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
}
	//////////////////////////////////////////////////////////////////////////////
	

////////////////////////////////////////////////////////////////////////////////
using namespace ufo;
#define weight second
#define vertices first
#define vertice1 first.first
#define vertice2 first.second
typedef pair < pair<long long,long long> , long long > wt_edge;
////////////////////////////////////////////////////////////////////////////////

//-----------------input n output----------------------------------------------
void input (wt_edge *edge , long long e) {
	long long a,b,wt;	
	for(long long i = 0 ; i < e ; i ++) {
		cin >> a >> b >> wt;
		edge[i] = make_pair ( make_pair(a,b) , wt);
	}
}

long long output (wt_edge *edge , long long v ) {
	
	long long sum = 0;
	for(long long i = 0 ; i < v ; i ++) {
		sum += edge[i].weight;
	}
	return sum;
}
////////////////////////////////////////////////////////////////////////////////
long long cmp (const wt_edge &e1 , const wt_edge &e2) {
 	//cout << e1.weight << " " << e2.weight << endl;
	return e1.weight < e2.weight;
}

void kruskal (wt_edge *edge , long long v , long long e , wt_edge *mst) {
	
	ufo::sets s;
	ufo::pairs r1,r2;
	long long mst_e = -1;
	
	s.resize (v+1 , -1);
	
	sort (edge , edge + e  , cmp);
//	output(edge , e);
	for (long long i =0 ; i < e ; i ++) {
//		cout << " ss ";
//		cout << s[edge[i].vertice1] << " " << s[edge[i].vertice2] << " ";
		if ( s[edge[i].vertice1] == -1 || s[edge[i].vertice2] == -1 ) {
//			cout << "if";
			ufo :: union_operation( edge[i].vertices , s );
			mst[  ++ mst_e  ] = edge[i];
//			cout << " " << edge[i].weight << " " << mst_e << " " << mst[mst_e].weight;	
		}
		else {
//			cout << "else";
			r1 = ufo :: find_operation (s,edge[i].vertice1);
			r2 = ufo :: find_operation (s,edge[i].vertice2);
			if(r1.parent != r2.parent) {
				ufo :: union_operation( edge[i].vertices , s );
				mst[ mst_e ++ ] = edge[i];	
//				cout << " " << edge[i].weight ;
			}
		}
//		cout << endl;
	}
}

////////////////////////////////////////////////////////////////////////////////

int main() {
	
		int t1,t2;
		long long e , v;
		cin >> v >> e;
		wt_edge edge[e];
		input(edge,e);
		cin >> t1 >> t2;
		//output(edge,e);
		wt_edge mst[v];
		kruskal(edge , v , e , mst);
		long long ans = output (mst,v-1);
//		cout << ans << endl;
		if( ans < 0)	cout << t1 << endl ;
		else 			cout << t2 << endl;
		
}

////////////////////////////////////////////////////////////////////////////////

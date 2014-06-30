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
#include"union_find_operation.h"		// containin a namespace naming ufo

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
	for(int i = 0 ; i < v ; i ++) {
		cout << edge[i].weight << " ";
	}
	cout << endl;
}
////////////////////////////////////////////////////////////////////////////////
int cmp (const wt_edge &e1 , const wt_edge &e2) {
 	//cout << e1.weight << " " << e2.weight << endl;
	return e1.weight < e2.weight;
}

void kruskal (wt_edge *edge , int v , int e , wt_edge *mst) {
	
	ufo::sets s;
	ufo::pairs r1,r2;
	int mst_e = -1;
	
	s.resize (v+1 , -1);
	
	sort (edge , edge + e  , cmp);
	output(edge , e);
	for (int i =0 ; i < e ; i ++) {
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

main() {
	int test;
	cin >> test;
	while(test--) {
		int e , v;
		cin >> v >> e;
		wt_edge edge[e];
		input(edge,e);
		//output(edge,e);
		wt_edge mst[v];
		kruskal(edge , v , e , mst);
		output (mst,v-1);
	}
}

////////////////////////////////////////////////////////////////////////////////

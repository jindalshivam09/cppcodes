/*
	Name:  Union-Find Data Structure 
	Copyright: no rights
	Author: Shivam Jindal
	Date: 29/07/13 19:02
	Description: using union by rank n path compression algo O(nlogn)
*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
using namespace std;

///////////////////////////////////////////////////////////////////////////////
#define parent first
#define rank second 
typedef vector <int> sets;
typedef vector <int> paths;
typedef pair <int,int> pairs;
///////////////////////////////////////////////////////////////////////////////

//-------------input n ouput---------------------------------------------------

void input (pairs *p , int n) {
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



void union_operation (pairs *p, sets &s , int n) {
	int a,b;
	pairs r1,r2;
	for(int i = 0 ; i < n ; i ++) {
		a = p[i].first ;
		b = p[i].second ;
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


main() {
	int t;		// test cases
	cin >> t;
	while(t--) {
		int n, 		// number of pairs 
			m; 		// number of elements
		cin >> n >> m;
		
		pairs p[n];
		input(p,n);
		
		sets s;
		s.resize( m+1 , -1 );
		
		union_operation(p,s,n);
		
		output(s);
		cout << endl;
	}
}

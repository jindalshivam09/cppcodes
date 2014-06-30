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
#include<map>
using namespace std;

///////////////////////////////////////////////////////////////////////////////
#define parent first
#define rank second
#define MAX 1000009 
typedef vector <int> sets;
typedef vector <int> paths;
typedef pair <int,int> pairs;
///////////////////////////////////////////////////////////////////////////////
		int n, 		// number of pairs 
			m; 		// number of elements

sets s(MAX,-1);
vector<int> sum(MAX);
pairs p[MAX];

//-------------input n ouput---------------------------------------------------

void input () {
	int a,b;
	for(int i = 0 ; i < n ; i ++) {
		cin >> a >> b;
		p[i] = make_pair(a,b);
	}		
}
//////////////////////////////////////////////////


void path_compression (int i) {
	for (int j=0;j<n;j++) {
		//cout << j;
		s[j] = i; 
	}
}

pairs find_operation (int b) {
//	paths p;
	int i = b;
	int count = 0;
	while ( s[i] != i) {
//		p.push_back(i);
		i = s[i];
		count ++;
	}	
//	path_compression(p,s,i);
	return make_pair(i,count);
}

void union_operation () {
	int a,b;
	pairs r1,r2;
	for(int i = 0 ; i < n ; i ++) {
		a = p[i].first ;
		b = p[i].second ;
		//cout << a << " " << b << endl;
		if(s[a] == -1 && s[b] == -1) 		s[b] = s[a] = a;	// that is the case when both elements does not belong to any group
		else if( s[a] == -1 )  				s[a] = s[b];
		else if( s[b] == -1)				s[b] = s[a];
		else {
				r1 = find_operation (a);
				r2 = find_operation (b);
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

map<int,int> gp;
void parent() {
	
	for(int i=1;i<m+1;i++) {
		
		pairs p = find_operation(i);
		cout << gp[p.first] << " ";
		gp[p .first] ++;
	}
}


main() {
		cin >> m >> n;
		
//		pairs p[n+1];
		input();
		
		
		union_operation();
		parent();		
//		output(s);
		long long ans = 0;
		int count=0;
		for(map<int,int>::iterator i = gp.begin(); i != gp.end() ; i++) {
			
			if(count)  		sum[count] = sum[count-1] + (*i).second;
			else 			sum[count] = (*i).second;
			count++;
		}	
		int temp = count-1;
		count = 0;
		for(map<int,int>::iterator i = gp.begin(); i != gp.end() ; i++) {
			
			ans += ((*i).second)* (sum[temp]-sum[count++]);
		}
		cout << ans << endl;
}

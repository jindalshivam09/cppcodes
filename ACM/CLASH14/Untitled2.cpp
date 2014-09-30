#include<bits/stdc++.h>
using namespace std;
#define MAX 51
int p,q,l,r ;
vector<pair<int,int> > P(MAX),Q(MAX) ;

bool possible (int shift) {
	
	for(int i=0;i<q;i++) {
		int a = Q[i].first + shift , b = Q[i].second + shift ;
		for(int j=0;j<p;j++) {
			int c = P[j].first , d = P[j].second ;
			if( a > d || b < c) ;
			else	return true ;
		}
	}
	return false ;
}

int main() {
	cin >> p >> q >> l >> r ;
	for(int i=0;i<p;i++)
		cin >> P[i].first >> P[i].second ;
		
	for(int i=0;i<q;i++)
		cin >> Q[i].first >> Q[i].second ;
		
		
	int cnt = 0 ;
	for(int i=l;i<=r;i++) {
		if(possible(i))
			cnt ++ ;
	}
	
	cout << cnt << endl;
}

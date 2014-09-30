#include<bits/stdc++.h>
using namespace std;

#define MAX 20
#define RANGE 501*501*2

int n, desCh, desCa ;
vector<int> surplus(MAX) ;
vector<pair<int,int> > input(MAX) ;
vector<bool> visited(RANGE) ;

int bfs () {
	queue<int> Q, newQ ;
	Q.push(0) ;
	int cnt = 0, maxSurplus = INT_MIN, minSurplus = INT_MAX;
	
	for(int i=0;i<n;i++) {
		maxSurplus = max ( maxSurplus, surplus[i] ) ;
		minSurplus = min ( minSurplus, surplus[i] ) ;
	}
	
	int range = (maxSurplus-minSurplus) + 1 ;
	
	while(Q.empty() == false && visited[0] == false ) {
//		cnt ++ ;
		while(Q.empty()==false) {
			int u = Q.front() ;
//			cout << u << " ";
			Q.pop() ;
			for(int i=0;i<n;i++) {
				int net = u + surplus[i] ;
				if( net >= 0 && visited[net] == false && net < range ) {
					visited[net] = true ;
					newQ.push(net) ;
				}
//				if(net == 0)
//					return cnt ;
			}
		}
		cnt ++;
		swap(Q,newQ) ;
	}
	if(visited[0])
		return cnt;
	return -1 ;
}

int main() {
//	ifstream cin("test.txt") ;
//	ofstream cout("2.txt") ;
	cin >> n;
	for(int i=0;i<n;i++) 
		cin >> input[i].first >> input[i].second ;
	cin >> desCh >> desCa ;

	for(int i=0;i<n;i++) {
		int temp = input[i].first*desCa - input[i].second*desCh ;
		surplus[i] = temp ;
	}
	
	cout << bfs() ;
}

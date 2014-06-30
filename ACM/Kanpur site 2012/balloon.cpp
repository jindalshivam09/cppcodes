#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define MAX 100000

struct abc {

	long long r_cost;
	int balloons;
	int da;
	int db;
}teamA[MAX],teamB[MAX];

bool cmp (const abc &t1,const abc &t2) {

	return t1.r_cost < t2.r_cost;
}

long long cal_min_dist (abc *teamA,abc *teamB,int countA , int countB, int a,int b) {

	int i=0,j=0;
	long long cost = 0;
	while(i < countA && j < countB ) {
 	
//		cout << teamA[i].r_cost << " " << teamB[j].r_cost << endl;
		if (teamA[i].r_cost >= teamB[j].r_cost) {
		
			if (a >= teamA[i].balloons) {
				
				a -= teamA[i].balloons;
				cost += teamA[i].balloons*teamA[i].da;
			}
			else {
			
				if (a) {
					
					a = 0;
					cost += a*teamA[i].da;
					cost += (teamA[i].balloons-a)*teamA[i].db;
					b -= (teamA[i].balloons-a);
				}
				else {
					b -= teamA[i].balloons;
					cost += (teamA[i].balloons)*teamA[i].db;
				}
			}
			i++;
		}
		else {
			
			if (b >= teamB[i].balloons) {
				
				b -= teamB[i].balloons;
				cost += teamB[i].balloons*teamB[i].db;
			}
			else {
				
				if(b) {
					
					b = 0;
					cost += b*teamB[i].db;
					cost += (teamB[i].balloons-b)*teamB[i].da;
					a -= (teamB[i].balloons-b);
				}
				else {
				
					a -= teamB[i].balloons;
					cost += (teamB[i].balloons)*teamB[i].da;
				}
			}
			j++;
		}
//		cout << cost << " " << a << " " << b << " " << i << " " << j << endl;
	}
	
	while (i<countA) {

		if (a >= teamA[i].balloons) {
			
			a -= teamA[i].balloons;
			cost += teamA[i].balloons*teamA[i].da;
		}
		else {
		
			if (a) {
				
				a = 0;
				cost += a*teamA[i].da;
				cost += (teamA[i].balloons-a)*teamA[i].db;
				b -= (teamA[i].balloons-a);
			}
			else {
				b -= teamA[i].balloons;
				cost += (teamA[i].balloons)*teamA[i].db;
			}
		}	
		i++;
//		cout << cost << " " << a << " " << b << " " << i << " " << j << endl;
	}
	
	while(j<countB) {
	
		if (b >= teamB[i].balloons) {
			
			b -= teamB[i].balloons;
			cost += teamB[i].balloons*teamB[i].db;
		}
		else {
			
			if(b) {
				
				b = 0;
				cost += b*teamB[i].db;
				cost += (teamB[i].balloons-b)*teamB[i].da;
				a -= (teamB[i].balloons-b);
			}
			else {
			
				a -= teamB[i].balloons;
				cost += (teamB[i].balloons)*teamB[i].da;
			}
		}
		j++;
//		cout << cost <<  " " << a << " " << b << " " << i << " " << j << endl;
	}
	
 	return cost;
}

int main() {

	int n,a,b;
	cin >> n >> a >> b;
	while(n) {
	
		int k,da,db;
		int countA=0,countB=0;
		for (int i=0;i<n;i++) {
			
			cin >> k >> da >> db;

			if (da < db) {
			
				teamA[countA].balloons = k;
				teamA[countA].da = da;
				teamA[countA].db = db;
				teamA[countA++].r_cost = (db-da);
			}
			else {
//				cout << da << " " << db << endl;
				teamB[countB].balloons = k;
				teamB[countB].da = da;
				teamB[countB].db = db;
				teamB[countB++].r_cost = (da-db);
			}
			
		}
//		cout << teamB[0].balloons << " " << teamB[0].da << endl;
//		cout << countA << " " << countB << endl;

		sort(teamA,teamA+countA,cmp);
		sort(teamB,teamB+countB,cmp);
		
		cout << cal_min_dist (teamA,teamB,countA,countB,a,b) << endl;
		
		cin >> n >> a >> b;
	}
}

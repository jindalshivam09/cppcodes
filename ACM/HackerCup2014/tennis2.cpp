#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <algorithm>
#include <set>
#include <queue>
#include <limits>
#include <fstream>
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
typedef vector<pair<int, int> > vpii;
typedef vector<double> 	vd;
typedef pair<double,double> 	pdd;
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

struct n {
	
	string name;
	int shot,ht;
	int num;
} player[40];

class elem {
	
	public:
		int time;
		int num;

		elem (int t=0,int n=0) {
			
			time = t;
			num = n;
		}
		
		bool operator < (const class elem &a) const {
		
			return this->time == a.time ? this->num > a.num : this->time > a.time;
		}
};

bool cmp (const struct n &a , const struct n &b) {
	
	return a.shot == b.shot ? a.ht > b.ht : a.shot > b.shot;
}

bool cmp2 ( const pair<int,int> &a , const pair<int,int> b) {
	
	return a.first == b.first ? a.second < b.second : a.first < b.first;
}

multiset<string> ans;
void tennis (priority_queue<elem> &team,int p,int m,int n) {
	
	vector<pair<int,int> > arr(p);
	vector<bool> playing1(n+1);
	
	for(int i=0;i<p;i++) {
		
		elem tmp = team.top();
		arr[i].first = tmp.time;
		arr[i].second = tmp.num;
		playing1[arr[i].second] = true;
		team.pop();
//		cout << tmp.num<< endl;
	}
	for(int i=0;i<m;i++) {
		
		for(int j=0;j<p;j++) {

			arr[j].first ++;
		}
		
		sort(arr.begin(),arr.end(),cmp2);		
		elem tmp = team.top();
		team.pop();					
		playing1[arr[p-1].second] = false;
		team.push(elem(arr[p-1].first,arr[p-1].second));
		arr[p-1].first = tmp.time;
		arr[p-1].second = tmp.num;
		playing1[arr[p-1].second] = true;
	
	}
	
	for(int i=0;i<n;i++)
	if(playing1[i])
		ans.insert(player[i].name);
}

int main() {

ifstream in;
ofstream out;

 	in.open("ip.txt",ios_base::in);
 	out.open("op.txt",ios_base::out);
	
	int t;
	in >> t;
	for(int test=1;test<=t;test++) {
		
		ans.clear();
		int n,m,p;
		in >> n >> m >> p;
		
		for(int i=0;i<n;i++) {
			
			in >> player[i].name >> player[i].shot >> player[i].ht;
		}
		
		if(n==2*p) {
			
			for(int i=0;i<n;i++)
				ans.insert(player[i].name);
		}
		else {
	
			sort(player,player+n,cmp);
			for(int i=0;i<n;i++) {
				
				player[i].num = i;
	//			cout << player[i].name << endl;
			}
	
			priority_queue<elem> team1,team2,temp;
	
			for(int i=0;i<n;i++) {
				
				if(i%2) {
					
					team1.push(elem(0,player[i].num));
				}
				else {
					
					team2.push(elem(0,player[i].num));
				}
			}
			
			tennis(team1,p,m,n);
			tennis(team2,p,m,n);
		}
		out << "Case #" << test << ": " ;
		for(multiset<string>::iterator i = ans.begin() ; i != ans.end()  ; i++)
			out << *i << " ";
			out << endl;
	}
}



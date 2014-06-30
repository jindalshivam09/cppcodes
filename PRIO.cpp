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
 #define MAX 100
struct job {
 	int at,bt,tt,wt,ct,prio,pid;
 }jobs[MAX];
bool cmp (const struct job &a, const struct job &b) {
	return a.prio < b.prio;
}
bool cmp2 (const struct job &a, const struct job &b) {
	return a.pid < b.pid;
}
int n;
void prio () {
	sort(jobs,jobs+n,cmp);
	int temp = 0;
	rep(i,n) {
		temp += jobs[i].bt;
		jobs[i].ct = temp;
	}
	int tot_wait = 0;
	rep(i,n)  {
		jobs[i].tt = jobs[i].ct - jobs[i].at;
		jobs[i].wt = jobs[i].tt - jobs[i].bt;
		tot_wait += jobs[i].wt;
	}
	
	sort(jobs,jobs+n,cmp2);
//	cout.setf(ios::fixed);
	cout << "ID\tPRIO\tAT\tBT\tCT\tTT\tWT" << endl;
	rep(i,n) {
		cout.width(4);
		cout << jobs[i].pid << " " << jobs[i].prio << " " <<  jobs[i].at << " " << jobs[i].bt << " " << jobs[i].ct << " " << jobs[i].tt << " " << jobs[i].wt << endl;
	}
	cout << endl;
	cout << "Average Wait time : " << double(tot_wait)/n;
}

int main() {
	cout << "enter the total number of processes : ";
	cin >> n;
	cout << "enter process pid , priority , arrival time , burst time \n";
	rep(i,n) {
		cin >> jobs[i].pid >> jobs[i].prio >> jobs[i].at >> jobs[i].bt;
	}
	prio();
	
}



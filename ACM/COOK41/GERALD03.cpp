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

int main() {

	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		vpii segment(n);
		int a,b;
		for(int i=0;i<n;i++) {
			cin >> a >> b;
			segment[i] = mp(a,b);
		}
		string str;
		int count = 0;
		int l = segment[0].first , r = segment[0].second;
		for(int i=1;i<n;i++) {			
			int templ = segment[i].first , tempr = segment[i].second;
			if(templ <= l) {
				while(templ <  l ) {
//					cout << templ << " " << l << endl;
					str.append("L-");
					count++;
					templ++;
				}
				if(tempr < r) {
					while(tempr<r) {
						//cout << "R-";
						str.append("R-");
						count++;
						tempr++;
					}
				}
				else if(tempr>r){
					while(tempr>r) {
						str.append("R+");
						count++;
						//cout << "R+";
						tempr--;
					}
				}
			}
			else {
//				cout << templ << " " << tempr << " " << l << " " << r << endl;
				while(l < r-1 && l < templ) {
//					cout << "L+";
					str.append("L+");
					count++;
					l++;
				}
				while(templ > l && tempr > r) {
//					cout << "R+L+";
					str.append("R+L+");
					count+=2;
					templ--;
					tempr--;
				}
				while(templ > l && tempr < r) {
//					cout << "R-L+";
					str.append("R-L+");
					count+=2;
					templ--;
					tempr++;
				}
				while(templ > l) {
//					cout << "L+";
					str.append("L+");
					count++;
					templ--;
				}
				while(tempr > r) {
//					cout << "R+";
					str.append("R+");
					count++;
					tempr--;
				}
				while(tempr < r) {
//					cout << "R-";
					str.append("R-");
					count++;
					tempr++;
				}
//				cout << endl;
			}
			l = segment[i].first;
			r = segment[i].second;
		}
		cout << count << endl;
		cout << str;
		cout << endl;
	}
}



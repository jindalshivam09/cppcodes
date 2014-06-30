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
#define MAX 26*26*26*29
vi power26(5);
class SmartWordToy {
	public:
		int encode(string str) {
			int val = 0;
			for(int i=0;i<str.size();i++) {
				val = val*26 + (str[i]-'a');
			}
//			cout << "calculating val in encode function " << str << " : " <<   val << endl;
			return val;
		}
		int minPresses (string start,string finish, vector<string> forbid ) {

			power26[1] = 1;
			for(int i=2;i<=4;i++) {
				power26[i] = power26[i-1]*26; 
			}	
	//		string str2,str2,str3,str4;
			int from = encode(start);
			int to = encode(finish);
			vi dist(MAX,-1) ;
			dist[from] = 0;
			vb forbidded(MAX);
			int temp , temp2;
			string p,q,r,t, o;
			o = "aaaa";
			for(int i=0;i<forbid.size();i++) {
				stringstream sin(forbid[i]);
				sin >> p >> q >> r >> t;
				for(int i=0;i<p.size();i++)
				for(int j=0;j<q.size();j++)
				for(int k=0;k<r.size();k++)
				for(int l=0;l<t.size();l++)  {
					o[0] = p[i] , o[1] = q[j] , o[2] = r[k] , o[3] = t[l];
					temp = encode(o);
					forbidded[temp] = true;
				}
			}
			queue <int> traversed;
			traversed.push(from);
			while(!traversed.empty()) {
				temp2 = temp = traversed.front();
				traversed.pop();
				if(temp == to)
					return dist[temp];
				vi a(4);
				a[3] = temp%26 , temp /= 26 ;
				a[2] = temp%26 , temp /= 26 ;
				a[1] = temp%26 , temp /= 26 ;
				a[0] = temp%26 ;
				for(int dir=-1;dir<=1;dir+=2) {
					for(int i=0;i<4;i++) { 
						temp = temp2 - (a[i]*power26[4-i]) + (((a[i]+dir+26)%26)*power26[4-i]);
						if(forbidded[temp]==false) {
							dist[temp] = dist[temp2] + 1;
							traversed.push(temp);
							forbidded[temp] = true;
						} 					
					}
				}
			}			
			return -1;
 		}
};

int main() {
	power26[1] = 1;
	for(int i=2;i<=4;i++) {
		power26[i] = power26[i-1]*26; 
	}	
	int t;
	cin >> t;
	while(t--) {
		string start, finish ;
		cin >> start >> finish;
		int n;
		cin >> n;
		vector<string> forbid(n);
		rep(i,n)
			cin >> forbid[i];
		SmartWordToy ob;
		cout << ob.minPresses(start,finish, forbid) << endl;
	}
}



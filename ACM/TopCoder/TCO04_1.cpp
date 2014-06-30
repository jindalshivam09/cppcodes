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
#define MAX 1000009
map<int,int> val;
vi arr;
vector<int> adj[MAX];				
class Boxing {
	public:
		void pre(vi a,int pos) {
			for(int i=0;i<a.size();i++) {
				if(!val[a[i]])
					arr.pb(a[i]);
				val[a[i]]++;
				adj[a[i]].pb(pos);
			}
		}
		void dec(vi a ,int key) {
			for(int i=0;i<a.size();i++) {
				if(a[i]-key >= 0 && a[i]-key<=1000 ) 
					val[a[i]]--;
			}
		}
		int maxCredit (vi a , vi b , vi c , vi d, vi e) {
			pre(a,1);	pre(b,2);	pre(c,3);
			pre(d,4); pre(e,5);
			sort(all(arr));
			int key=0 , sum , counter=0;
			for(int i=0;i<arr.size();) {
				//sum = 0;
				key = arr[i];
				sum = val[arr[i]];
				if(sum > 2) {
					counter++ ;
					i++;
					continue ;
				}
				else {
					i++;
					while(arr[i]-key <= 1000 && sum + val[arr[i]] < 3) {
						sum += val[arr[i]];
						for(int k=0;k<adj[arr[i]].size();k++) {
							int temp = adj[arr[i]][k];
							if(temp==1)		dec(a,arr[i]);
							if(temp==2)		dec(b,arr[i]);
							if(temp==3)		dec(c,arr[i]);
							if(temp==4)		dec(d,arr[i]);
							if(temp==5)		dec(e,arr[i]);
						}
						i++;
						
					}
				}
				if(sum + val[arr[i]]> 2) {	
						for(int k=0;k<adj[arr[i]].size();k++) {
							int temp = adj[arr[i]][k];
							if(temp==1)		dec(a,arr[i]);
							if(temp==2)		dec(b,arr[i]);
							if(temp==3)		dec(c,arr[i]);
							if(temp==4)		dec(d,arr[i]);
							if(temp==5)		dec(e,arr[i]);
						}
					counter++ , i ++;
				}
			}	
			return counter;
		}
};



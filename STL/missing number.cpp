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
#define MAX 1000001
vi A(MAX),B(MAX);
int main() {

	int n,m;
	cin >> n;
	
	int miniA = imax;
	rep(i,n){
		cin >> A[i];
		miniA = min(miniA,A[i]);
	}
	
	vi freqA(101);
	rep(i,n) 
		freqA[A[i]-miniA] ++;
	
	cin >> m;
	
	int miniB = imax;
	rep(i,m){
		cin >> B[i];
		miniB = min(miniB,B[i]);
	}
	
	vi freqB(101);
	rep(i,m) 
		freqB[B[i]-miniB] ++;
		
	vi ans;	
	rep(i,101) {
		
		int key = miniB+i;
		int freq = freqB[i];
		
		if(key - miniA > 100)
			ans.pb(key);
		else if(freqB[i] != freqA[key-miniA])
			ans.pb(key);
	}	
	
	for(vi::iterator i = ans.begin() ; i != ans.end() ; i++)
		cout << (*i) << " ";
	cout << endl;
}



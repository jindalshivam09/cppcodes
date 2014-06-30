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

int n,k,p;
vpii chef , boy ;
map<int,int> mapped ;

class cmp {
	public :
		bool operator () (pii &a,pii &b) {
			return a.first > b.first ;
		}
};

bool cmp2 (const pii &a,const pii &b) {
	return a.first < b.first ;
}

bool possible () {
	sort(all(chef),cmp2) ;
	sort(all(boy),cmp2) ;
	int c=-1,b=-1 ;
	int j=0,i=0;
	while(1)  {
		if(chef[i].first < boy[j].first)
			i++;
		else if (chef[i].first > boy[j].first)
			j ++ ;
		else {
			c = i , b = j ;
			break ;
		}
		if ( i == k || j == p)
			return false ;
	}
	vpii arr1(k) , arr2(p) ;
	i=0,j=0;
	for(int l=c;l<c+k;l++) 
		arr1[i++] = chef[l%k] ;
	for(int l=b;l<b+p;l++) 
		arr2[j++] = boy[l%p] ;
	i = 0 , j = 0 ;
	int temp = arr2[j].first ;
	while(1) {
		if ( arr1[i].first == temp) {
			if (arr1[i].second == arr2[j].second) {
				i ++ , j ++ ;
				if (j<p)
					temp = arr2[j].first;
			}
			else  {
				temp = (arr1[i].second+1)%n ;
				i++ ;
			}
		}
		else
			return false ;
		if ( i == k && j == p )
			return true ;
		if ( i == k )
			return false;
	}
	return true ;
		
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		cin >> n >> k >> p ;
		chef.resize(k) ;
		boy.resize(p) ;
		rep(i,k)
			cin >> chef[i].first >> chef[i].second ;
		rep(i,p) {
			cin >> boy[i].first >> boy[i].second ;
		}
		if ( possible() )
			cout << "Yes" << endl;
		else
			cout << "No" << endl;	
	}
}



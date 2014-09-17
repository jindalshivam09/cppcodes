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
ll getInvCount(int arr[], int n)
{
  ll inv_count = 0;
  int i, j;
 
  for(i = 0; i < n - 1; i++)
    for(j = i+1; j < n; j++)
      if(arr[i] > arr[j])
        inv_count++;
 
  return inv_count;
}
 int arr[MAX];
int main(int argv, char** args)
{
//		ifstream cin("test.txt") ;
//	ofstream cout("1.txt") ;

	int n,m;
	cin >> n >> m ;
  rep(i,n)
  	cin >> arr[i] ;
  	int i,j;
  	while(m--) {
  		cin >> i >> j ;
  		i--,j--;
  		swap(arr[i],arr[j]) ;
  cout << getInvCount(arr, n) << endl;;
  swap(arr[i],arr[j]) ;
}
  return 0;
}


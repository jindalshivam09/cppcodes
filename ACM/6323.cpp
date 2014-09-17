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
#define MOD 1000000007
vi values;
int product ;
class GoodSubset{
	public :
		map<pair<int,ll>,ll> memo ;
		int ones = 0;
		long long int power(ll q,ll n)
		{
			 long long int ans;
			 if(n==1)	return q;
			 if(n==0)	return 1;
			 else{
				ans=power(q,n/2)%MOD;
		 		ans*=ans;
				ans%=MOD;
				if(n%2)	{
						  ans*=q;
						  ans%=MOD;
				}
			}
			return ans;
		}

		int recursion(int index, ll pdt) {
			if(pdt == product) {
				return 1 ;
			}
			if(index == values.size() || pdt > product || (pdt && product % pdt) ) 
				return 0;
			if(memo[mp(index,pdt)])
				return memo[mp(index,pdt)] ; 
			ll ret = (recursion(index+1,max(1LL,pdt)*values[index]) + 
					recursion(index+1,pdt))%MOD ;
			return memo[mp(index,pdt)] = ret ;
		}
		
		int numberOfSubsets(int p, vi v) {
			values = v, product = p ;
			rep(i,values.size())
				if(values[i] == 1)
					ones ++ ;
			sort(all(values),greater<int>()) ;
			if(product==1)
				return (power(2,ones)-1+MOD)%MOD; 
			return recursion(0,0) ;
		}
};
int main() {
	GoodSubset obj ;
	int n ;
	cin >> n ;
	vi arr(n) ;
	rep(i,n)
		cin >> arr[i] ;
	int pdt ;
	cin >> pdt ;
	cout << obj.numberOfSubsets(pdt,arr) << endl;
}

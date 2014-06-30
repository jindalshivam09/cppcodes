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

#define MAX 109

bool isPrime[MAX];
vector<int> prime;
vector<vi> factors(MAX,vi(30)), tot_factors(MAX,vi(30)) ; // there are only 25 prime numbers till 100

// ------------------------------------- preprocess ---------------------------------------------------------------------
void sieve(int n) {

	int s=sqrt(n);
	int a;
	for(int i=2;i<=s;i++)
	{
		a=i;
		if(!isPrime[i])
    	for(int j=a*a;j<=n;j+=2*i)
			   isPrime[j]=1;
	}
	int j=2;
	prime.pb(2);
	for(int i=3;i<=n;i+=2)
	if(!isPrime[i])
		prime.pb(i);
}

void factorise (int n) {
	for(int i=2;i<=n;i++) {
		int temp = i ;
		for(int j=0;j<prime.size();j++) {
			while(temp%prime[j] == 0 ) {
				factors[i][j] ++ ;
				temp /= prime[j] ;
			}
			tot_factors[i][j] = factors[i][j] + tot_factors[i-1][j] ;
		}
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int cnt ;
vi result, number, arr;

void ret_factors(int a,int c,int d) {
	result.resize(30);
	for(int k=0;k<prime.size();k++) {
		result[k] = tot_factors[a][k] - tot_factors[a-c][k] ;
		result[k] += factors[d][k] + factors[c+1][k];
		result[k] -= (tot_factors[arr.size()][k] - tot_factors[arr.size()-c-2][k]) ;
	}
}

vector<int> same(30) ;
int total = 0;

void init() {

	rep(j,prime.size()) {
		rep(i,arr.size()) {
			if(arr[i]%prime[j] == 0) {
				same[j]++;
			}
		}
	}	
}

double cal_prob(int a,int c, int d) {
	double prob = 0;
	ll num =1 , den = 1 ;
	bool flag = false; 
	ret_factors(a,c,d) ;
	rep(l,prime.size()) {
		if(result[l]>0)
			num *= (pow(prime[l],result[l])) ,flag = true;
		else if(result[l]<0)
			den *= (pow(prime[l],-result[l])) ,flag = true;
	}
//	cout << num << " " << den << endl;
	if(flag)
	prob = double(num) / den ;
	return prob ;
}

double cal_random_prob() {
	vector<vi> fact(30);
	double prob = 0.0;
	
	int cnt = 0;
	rep(i,arr.size()){
		rep(j,arr.size())
			if((i != j) && arr[i]!=1 && (__gcd(arr[i],arr[j])==1)) 
				cnt ++ ;
	}
	vector<vi> powers(30) ;
	rep(i,prime.size()) {
		int temp = prime[i] ;
		for(int j=0;temp<=100;j++) {
			powers[i].pb(temp);
			temp *= temp ;
		}
	}
	prob = (double)cnt/(arr.size()*(arr.size()-1)) ;
//	cout << prob << endl;	
	rep(i,prime.size()) {
//		cout << prime[i] << endl;
		rep(j,arr.size()) {	
//			cout << arr[j] << "->";
			cnt = 0 ;
			rep(k,arr.size()) {
//				cout << arr[k] << " " ; 
//				cout << __gcd(arr[j],arr[k]) << " ";
				if(j!=k && binary_search(all(powers[i]),__gcd(arr[j],arr[k]))) {
					cnt ++ ;
//					cout << arr[k] << " " ;
				}
			}
//			cout << endl;
			if(cnt)
			fact[i].pb(cnt) ;
		}
	}
	
	for(int i=3;i<=arr.size();i+=2) {
//		cout << "position" << i << endl;
		rep(k,prime.size()) {
			int store = same[k] ;
//			cout << prime[k] << "->" << same[k] << "Fdsfsdabgadsg" ;
			rep(j,fact[k].size()) {
				int temp = fact[k][j] ;
//				cout << temp <<  "fds " ;
				if(same[k]>=i&&(arr.size()-same[k]))  {
					prob += cal_prob(same[k]-1,i-1,arr.size()-same[k]) ;
					if(same[k]-temp>=i) 
						prob -= cal_prob(same[k]-temp-1,i-1,arr.size()-same[k]) ;
//					cout << prob << " " ;
					same[k]--;
				}
				else if(arr.size()==same[k]) {
					if(same[k]%2)
						return 1;
					return 0;
				}
			}
			same[k] = store;
//			cout << endl;
		}
	}
	return prob ;
}

int cal_optimal_prob() {

 	for(int i=0;i<arr.size();i++)
		if(number[i] == 1)
			return 1 ;

	for(int i=0;i<cnt;i++) {
//		if(adj[i]%2)
			return 1 ;
	}
	return 0 ;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main() {
	sieve(100) ;
	factorise(100) ;
	double ti = clock_t();
	ifstream cin("test_SEAGM.txt") ;
	freopen("SEAGM.txt","w",stdout) ;
//	ofstream cout("SEAGM.txt") ;

	int t;
	cin >> t ;
	while(t--) {
		int n ;
		cin >> n ;
		arr.resize(n) ;
		rep(i,n)
			cin >> arr[i] ;
		init() ;
		double prob_random = cal_random_prob() ;
//		int prob_optimal = cal_optimal_prob() ;
		printf("%0.4f\n",prob_random) ;
//		cout << prob_random << endl;
		cnt = 0 ;
		arr.clear() ;
			rep(k,prime.size())
				same[k] = 0 ;
		total = 0 ;
	}
}

#include <bits/stdc++.h>
using namespace std;

typedef long long 		ll;
typedef list<int> 	li;
typedef vector<ll> 	vi;
typedef vector<double> 	vd;
typedef vector<long long> 	vll;
typedef vector<bool> 	vb;
typedef pair<ll,ll> 	pii;
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
//#define DEBUG
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

ll TEMP ;
vi arr ;
vi factorised ;
map<ll,ll> mapped , prime_map, done , already;
bool flag , won ;
void init() {
	rep(i,arr.size())  {
		ll temp = 0 ;
		rep(j,prime.size()) {
			if(arr[i]%prime[j] == 0) {
				temp |= (1<<j) ;
				prime_map[(1<<j)] ++ ;
			}
		}
		mapped[temp] ++ ;
		prime_map[temp]++ ;
	}
	for(map<ll,ll>::iterator itr = mapped.begin() ; itr != mapped.end() ; itr ++) {
		ll u = itr->first ;
		#ifdef DEBUG
		cerr << u << " " << itr->second << endl;
		#endif
		factorised.pb(u) ;
	}
	
	rep(i,prime.size()) {
		ll cnt = 0;
		rep(j,arr.size()) {
			if((arr[j] % prime[i]) == 0)
				cnt ++;
		} 
//		cout << cnt << endl;
		if(cnt==arr.size()) {
			flag = true ;
			if(cnt % 2)
				won = true ;
			else
				won = false ;
		}
	}
}

ll cnt ;
vi result ;

void ret_factors(ll a,ll c,ll d) {
	result.resize(30);
	for(ll k=0;k<prime.size();k++) {
		result[k] = tot_factors[a][k] - tot_factors[a-c][k] ;
		result[k] += factors[d][k];
		result[k] -= (tot_factors[arr.size()][k] - tot_factors[arr.size()-c-1][k]) ;
	}
}


double cal_prob2(ll a,ll c, ll d) {
	double prob = 0;
	if(a<c)
		return 0.00 ;
		#ifdef DEBUG
	cerr << a << " " << c << " " << d << endl;
		#endif
	ll num =1 , den = 1 ;
	bool flag = false; 
	ret_factors(a,c,d) ;
	rep(l,prime.size()) {
		if(result[l]>0)
			num *= (pow(prime[l],result[l])) ,flag = true;
		else if(result[l]<0)
			den *= (pow(prime[l],-result[l])) ,flag = true;
	}
		#ifdef DEBUG
	cerr << num << " "<< den << endl;
		#endif
	if(flag)
		prob = double(num) / den ;
	return prob ;
}

map<pii,double> memo ;

double cal_prob(vi &sets, ll temp,int gcd) {
	double ret = 0.0 ;
		#ifdef DEBUG
	cerr << flag << " " << sets.size() << endl;
		#endif
	int i = sets.size() ;
	if(sets.size()==1) {
		for(ll i=1;i<=arr.size();i+=2)  {
			ret += cal_prob2(sets[0],i,temp) ;
			already[gcd] +=ret;
		}
	}
	else if(sets.size()==2) {
		ll sum = sets[0]+sets[1] ;
		i = 3;
		for(ll i=3;i<=arr.size();i+=2)  {
			ret += cal_prob2(sets[0],i,temp) ;
			ret += cal_prob2(sets[1],i,temp) ;
			already[gcd] +=ret;
		}
	}
	else if(sets.size()==3) {
		i=3;;
		ll sum = sets[0]+sets[1]+sets[2] ;
		for(ll i=3;i<=arr.size();i+=2)  {
			ret += cal_prob2(sets[0],i,temp) ;
			ret += cal_prob2(sets[1],i,temp) ;
			ret += cal_prob2(sets[2],i,temp) ;
			ret += cal_prob2(sets[1]+sets[0],i,temp) ;
			ret += cal_prob2(sets[1]+sets[2],i,temp) ;
			ret += cal_prob2(sets[0]+sets[2],i,temp) ;		
			already[gcd] +=ret;
		}
	}
	else if(done[gcd]==0) {
		ll sum = 0;
		rep(i,sets.size())
			sum += sets[i] ;
		for(ll i=3;i<=arr.size();i+=2) {
			ret += cal_prob2(sum,i,temp) ;
			done[gcd] = ret;
		}
	}
	return ret ;
}

double last_prob (vi &sets,ll gcd) {
	ll cnt = 0, temp = 1 ;
	for(ll i=25;i>=0;i--) {
		if(gcd&(1<<i))
			temp *= prime[i] ;
	}
	for(ll i=0;i<arr.size();i++)
		if(__gcd(temp,arr[i]) == 1)
			cnt ++;
	#ifdef DEBUG
		cerr << temp << " " << gcd << " " << cnt << " " << sets.size()  << endl;
	#endif
	
	if(cnt && (gcd != TEMP))	
		return cal_prob(sets,cnt,gcd) ;
	return 0.00;
}

void prob(ll i, ll gcd ,vi pre_set) { 

	if(i==factorised.size()) {
		#ifdef DEBUG
		cerr << "last element.." ;
		#endif
		return last_prob(pre_set,gcd) ;
	}
	ll temp = factorised[i], cnt = mapped[temp] ;

		#ifdef DEBUG
	cerr << i << " " << (gcd&temp) << endl;
		#endif

//	if(memo.find(mp(i,gcd)) != memo.end())
//		return memo[mp(i,gcd)] ;

	if((gcd&temp) == 0) {
		#ifdef DEBUG
		cerr << "gcd zero...." ;
		#endif
		double ret = 0.0 ; //cal_prob(pre_set,cnt);
		ret = prob(i+1,gcd,pre_set) ;
		#ifdef DEBUG
		cerr << ret << endl;
		#endif
		return memo[mp(i,gcd)] = ret;
	}
	vi sets(pre_set);
	sets.pb(cnt) ;
	double ret = prob(i+1,gcd&temp,sets) +  prob(i+1,gcd,pre_set) ;
	return memo[mp(i,gcd)] = ret;
}

int main() {
	sieve(100) ;
	factorise(100) ;
	ifstream cin("test_SEAGM.txt") ;
	freopen("SEAGM.txt","w",stdout) ;

	ll t;
	cin >> t ;
	while(t--) {
		flag = won = false;
		memo.clear() ;
		mapped.clear() ;
		factorised.clear() ;
		arr.clear();
		done.clear() ;
		prime_map.clear() ;
		cnt = 0 ;
		factorised.clear() ;
		already.clear();

		ll n ;
		cin >> n ;
		arr.resize(n) ;
		rep(i,n)
			cin >> arr[i] ;
		init() ;
		if(flag && won) {
			cout << "1.0000" << endl;
			continue ;
		}
		if(flag && !won) {
			cout << "0.0000" << endl;
			continue ;
		}
		vi pre_set ;
		rep(i,26)
			TEMP |= (1<<i) ;
		prob(0,TEMP,pre_set) ;
		double prob_random =  ;
		cout.precision(4);
		cout.setf(ios::fixed);
		cout << prob_random << endl;
		
	}
}


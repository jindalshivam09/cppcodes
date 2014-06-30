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
#define ROOT_MAX 1000
#define MAX 300009
vi arr ;

vector<bool> isPrime(MAX,true);
vector<int> prime(MAX);
int tot_primes = 1 ;
void sieve(int n) {
	int s=sqrt(n);
	int a;
	for(int i=2;i<=s;i++) {
		a=i;
		if(isPrime[i]==true)
    	for(int j=a*a;j<=n;j+=2*i)
			   isPrime[j]=false;
	}
	for(int i=4;i<n;i+=2)
		isPrime[i] = false;
	prime[0] = 2;
	for(int i=3;i<=s;i+=2)
	if(isPrime[i]==true)
		prime[tot_primes++] = i;
}

struct seg_tree {
	bool prime ;
	map<int,int> freq ;
	int val[200];		// because we have only around 200 primes till sqrt(MAX)
} nodes[MAX];


void init_tree(int node ,int a,int b) {
	if (a==b) {
		int temp = arr[a];
		if(isPrime[temp] == true) {
			nodes[node].freq[temp] ++;
			return ;
		}
 		rep(j,tot_primes) {
 			if (temp%prime[j] == 0)
				nodes[node].val[j] = temp ;
			else
				nodes[node].val[j] = -1 ;
		}
		nodes[node].freq[temp] ++ ;
		return ;
	}
	int mid = (a+b)/2;
	init_tree(node*2,a,mid);
	init_tree(node*2+1,mid+1,b);
	int index1 = 2*node , index2 = 2*node+1 ;
	rep(j,tot_primes)
		nodes[node].val[j] = max(nodes[index1].val[j],nodes[index2].val[j]) ;
	for(map<int,int>::iterator itr=nodes[index1].freq.begin() ; itr != nodes[index1].freq.end() ; itr ++) {
		nodes[node].freq[itr->first] += itr->second ;
	}
	for(map<int,int>::iterator itr=nodes[index2].freq.begin() ; itr != nodes[index2].freq.end() ; itr ++) {
		nodes[node].freq[itr->first] += itr->second ;
	}
}
int g ;
pii query (int node,int a,int b,int i,int j) {

	if ( j < a || i > b )
		return mp(-1,-1);
	if ( a >= i && b <= j ) {
		int ans = imin ;
		if ( isPrime[g] == true ) {
			if(nodes[node].freq[g])
				return mp(g,nodes[node].freq[g]);
			else
				return mp(-1,-1);
		}
		rep(i,tot_primes) {
//		cout << g << " g and prime " << prime[i] << " " << nodes[node].val[i] << endl;
			if (g%prime[i] == 0 && nodes[node].val[i] != -1)
				ans = max(ans,nodes[node].val[i]);
		}
		if(ans != imin)
			return mp(ans,nodes[node].freq[ans]);
		return mp(-1,-1);
	}
	int mid = (a+b)/2;
	pii q = query(2*node,a,mid,i,j);
	pii r = query(2*node+1,mid+1,b,i,j);
	if(q.first>r.first)
		return q;
	else if (q.first < r.first)
		return r;
	else 
		mp(q.first,q.second+r.second);
}

int main() {
	sieve(MAX);
	int n,m;
	scanf("%d%d",&n,&m);
	arr.resize(n+1);
	repi(i,1,n+1)  
		scanf("%d",&arr[i]);
	int temp ;
	init_tree(1,1,n);	
	int x,y;
	while(m--) {
	scanf("%d%d%d",&g,&x,&y);
		pii ans = query(1,1,n,x,y) ;
		if (ans.first < 2 )	printf("-1 -1\n");
		else				printf("%d %d\n",ans.first,ans.second);
	}
}



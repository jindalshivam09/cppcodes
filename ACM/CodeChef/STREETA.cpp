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

#define rep(i,n)    	for(int i=0;i<n;i++)
#define repi(i,k,n) 	for(int i=k;i<n;i++)
#define mp 				make_pair
#define pb			 	push_back
#define all(a) 			a.begin(),a.end()
#define imax  			numeric_limits<int>::max()
#define imin 			numeric_limits<int>::min()
#define dmax            numeric_limits<double>::max()
#define dmin            numeric_limits<double>::min()


#define MAX 300009

ll n,m;
vll a_plan , b_plan , a_cons , b_cons , till_a ;
map<ll,ll> mapped ;
map<ll,ll> irank ;

void update (ll idx,ll val,vll &arr) {
	ll n = arr.size() ;
	while( idx < n ) {
		arr[idx] += val ;
		idx = idx + (idx&-idx) ;
	}
}

ll query (ll idx,vll &arr) {
	ll n = arr.size() ;
	ll ret = 0;
	while( idx > 0 ) {
		ret += arr[idx] ;
		idx = idx - (idx&-idx) ;
	}
	return ret ;
}

struct quer {
	ll type, u, v, a, b, i ;
} q[MAX];


struct node {
	ll a, b, u, v  ;
	bool flag ;
};
vector<node> st ;

#define BETTER -1
#define WORSE -2
#define GREATER 1
#define LESSER 2

pair<ll,ll> intersection (ll u1,ll a1,ll b1, ll u2, ll a2, ll b2) {
	if(a1==a2) {
		if(b1-a1*u1>=b2-a2*u1)
			return mp(BETTER,BETTER) ;
		else
			return mp(WORSE,WORSE) ;
	}
	else if (a1 > a2) {
			ll temp = 	((b2-b1)-(a2*u2-a1*u1)) / (a1-a2) ;
//			if(((b2-b1)-(a2*u2-a1*u1)) % (a1-a2))
				temp++;
			return mp(GREATER,temp) ;
	}
	else {
			ll temp = 	((b2-b1)-(a2*u2-a1*u1)) / (a1-a2) ;
//			if(((b2-b1)-(a2*u2-a1*u1)) % (a1-a2) == 0)
//				temp--;
			return mp(LESSER,temp) ;
//		}
	}
//*/
/*
	i
	f(b2-b1==0)
	{
		if(a1-b1*u1>=a2-b2*u1)
			return make_pair(BETTER,BETTER);
		else
			return make_pair(WORSE,WORSE);
	}
	else if(b2-b1>0)
		return make_pair(GREATER,((a1-a2)-(b1*u1-b2*u2))/(b2-b1)-((((a1-a2)-(b1*u1-b2*u2))%(b2-b1))==0));	
	else
		return make_pair(LESSER,((a1-a2)-(b1*u1-b2*u2))/(b2-b1)+1);
//*/
}

void segment_tree_update(ll node ,ll i,ll j,ll p,ll q,ll u,ll v,ll a, ll b) {
//	cout << i << " " << j << " " << node << " " << p << " " << q << endl;
	if( j < p || i > q )
		return ;
	if ( p <= i && q >= j ) {
		if (st[node].flag == false ){
			st[node].a = a, st[node].b = b, st[node].u = u, st[node].v = v, st[node].flag = true ; 
			return ;
		}
		else if( i == j ) {
			ll val = st[node].a * (irank[i]-st[node].u) + st[node].b ;
			ll val2 = a*(irank[i]-u) + b ;
			if(val < val2) {
				st[node].a = a ,st[node].b = b ,st[node].u = u ,st[node].v = v ; 
			}
			return  ;
		}
		else {
			pair<ll,ll> decision = intersection(u,a,b,st[node].u,st[node].a,st[node].b) ;
			ll x = decision.second ;
			if(decision.first == BETTER) {
				st[node].a = a, st[node].b = b, st[node].u = u, st[node].v = v; 				
			}
			else if(decision.first == LESSER) {
				ll mid1 = irank[(i+j)/2]  , mid2 = irank[(i+j)/2+1];
				ll start = irank[i] ;
				ll last = irank[j] ;
				if ( x >= last)
					st[node].a = a, st[node].b = b, st[node].u = u, st[node].v = v; 
				else if( x > mid1 ) {
					segment_tree_update(node*2+1,(i+j)/2+1,j,p,q,st[node].u,st[node].v,st[node].a,st[node].b) ;
					st[node].a = a, st[node].b = b, st[node].u = u, st[node].v = v; 										
				}
				else if( x >= start && x <= mid1 ) {
					segment_tree_update(node*2,i,(i+j)/2,p,q,u,v,a,b) ;
				} 	
			}
			else if (decision.first == GREATER) {
				ll mid1 = irank[(i+j)/2]  , mid2 = irank[(i+j)/2+1];
				ll start = irank[i] ;
				ll last = irank[j] ;
				if ( x < start) 
					st[node].a = a, st[node].b = b, st[node].u = u, st[node].v = v; 
				else if( x > mid1 && x <= last)
					segment_tree_update(node*2+1,(i+j)/2+1,j,p,q,u,v,a,b) ;
				else if( x >= start && x <= mid1 ) {
					segment_tree_update(node*2,i,(i+j)/2,p,q,st[node].u,st[node].v,st[node].a,st[node].b) ;
					st[node].a = a, st[node].b = b, st[node].u = u, st[node].v = v; 										
				} 	
			}
		}
	}
	else {
		segment_tree_update (2*node,i,(i+j)/2,p,q,u,v,a,b) ;
		segment_tree_update (2*node+1,(i+j)/2+1,j,p,q,u,v,a,b) ;		
	}
}

pair<bool,ll> segment_tree_query(ll node, ll i, ll j, ll k) {
//	cout << i << " " << j << " " << k << endl;
	if ( j<k || i>k || j<i)
		return mp(false,0) ;
	if ( i==j ) {
		if(st[node].flag == false)
			return mp(false,0) ;
		else {
//			cout << st[node].a << " " << irank[k] << " " << st[node].u << " " << st[node].b << endl;
			return mp(true,st[node].a * (irank[k]-st[node].u) + st[node].b ) ; 
		}
	}
	pair<bool,ll> ans;
	if(st[node].flag == false)
		ans = mp(false,0) ;
	else {
//		cout << st[node].a << " " << irank[k] << " " << st[node].u << " " << st[node].b << endl;
		ans = mp(true,st[node].a * (irank[k]-st[node].u) + st[node].b) ;
	}
	pair<bool,ll> ans1 = segment_tree_query(2*node,i,(i+j)/2,k) ;
	pair<bool,ll> ans2 = segment_tree_query(2*node+1,(i+j)/2+1,j,k) ;
	if(ans1.first == true)
		return max(ans,ans1);
	else if(ans2.first == true)
		return max(ans,ans2) ;
	return ans ;
}

int main() {
//	ifstream cin("input.txt");
//	ofstream cout("mine.txt") ;
	cin >> n >> m ;
//	n = 1000000000 , m = 300000;
	ll u,v,a,b ;
	set<ll> index ;
	rep(i,m) {
		cin >> q[i].type ;
//		q[i].type = i%2 + 1;
		if (q[i].type == 3) {
			cin >> q[i].i ; 
//			mapped[q[i].i]; 
			index.insert(q[i].i) ;
		}
		else {
			cin >> q[i].u >> q[i].v >> q[i].a >> q[i].b ;
//			q[i].u = i , q[i].v = max((ll)i,n-i) , q[i].a = q[i].b = 1000000000;
//			mapped[q[i].u] ,mapped[q[i].v]; 
			index.insert(q[i].u), index.insert(q[i].v) ;
		}
	}
//	q[m-1].type = 3 , q[m-1].i = 789786;
//	index.insert(q[m-1].i) ;	
	ll k = 1 ;
	for(set<ll>::iterator itr = index.begin() ; itr != index.end() ; itr ++) {
		mapped[*itr] = k ; 
		irank[k] = *itr ;
		k ++ ;
	}
//	cout << k << endl;
	ll size = index.size() ;
	ll sz = k;
	a_plan.resize(sz) , b_plan.resize(sz) , a_cons.resize(sz) , b_cons.resize(sz) , till_a.resize(sz) ;
//	cout << "heheh" ;
	st.resize(4*size+10) ;
//	cout << st.size() ;
//	cout << size << endl;
	rep(i,m) {
		ll type ;
//		cout << i << " " << size << " ";;
		type = q[i].type , u = mapped[q[i].u], v = mapped[q[i].v], a = q[i].a, b = q[i].b, k = mapped[q[i].i]   ;
		if (type == 1) {	
			segment_tree_update(1,1,size,u,v,q[i].u,q[i].v,a,b) ;
		}
		else if (type == 2) {
//			cout << "in the type 2 query ...\n" ;
//			cout << a << " " << b << " " << u << " " << v << endl;
			update(u,a,a_cons) , update(u,b,b_cons) , update(u,q[i].u*a,till_a) ;
			update(v+1,-a,a_cons) , update(v+1,-b,b_cons) , update(v+1,-q[i].u*a,till_a) ;
		}
		else {
			ll ans = q[i].i*query(k,a_cons) + query(k,b_cons) - query(k,till_a) ;
//			cout << query(k,a_cons) << " " << query(k,b_cons) << " "<< query(k,till_a) << endl;
			pair<bool,ll> ans2 = segment_tree_query(1,1,size,k) ;
			if(ans2.first ==false)
				cout << "NA" << endl;
			else 
				cout << ans + ans2.second << endl;
		}
//		cout << i << " ";
	}
}

#include<cstdio> 
#include<iostream>
#include<cstring>
#include<algorithm> 
using namespace std;  
#define MAX  100009 
#define MAXR 100
#define MOD 1000000009
typedef long long ll;

// power in logn
ll p(int q,ll n)
{
	 ll ans;
	 if(n==1)
       		return q;
	else {
		ans=p(q,n/2)%MOD;
		ans*=ans;
		ans%=MOD;
		if(n%2)
		{
				  ans*=q;
				  ans%=MOD;
		}
	}
	return ans;
}
 
struct ht {     
	ll nr[2], p; 
} h[MAX]; 

ll pos[MAXR][MAX];

int cmp(struct ht a, struct ht b) {     
	return a.nr[0] == b.nr[0] ? (a.nr[1] < b.nr[1] ? 1 : 0) : (a.nr[0] < b.nr[0] ? 1 : 0); 
}  

void print(struct ht a) {
	cout << a.nr[0] << " " << a.nr[1] << " " << a.p << endl; 
}

// to find longest common prefix

ll lcp(ll x, ll y,ll n,ll a) {    
	 ll k;
	 ll ret = 0;   
	 //cout << x << " "  << y << " ";  
	 if (x == y) return n - x;     
	 for (k = a - 1; k >= 0 && x < n && y < n; k --)         
	 	if (pos[k][x] == pos[k][y])             
		 x += 1 << k, y += 1 << k, ret += 1 << k;
	//cout << ret << endl ;     
	return ret; 
}
 
main() {     
	int t;
	ll a,b;
	cin >> t;
	while(t--) {
		int count=0;
		ll n;
		cin >> n;
		ll ht[n],hd[n];
		ll tot = (((n*(n-1))%MOD)*p(2,MOD-2))%MOD;
		for(int i=0;i<n;i++) {
			cin >> ht[i];
			if(i) {
				hd[i-1] = ht[i] - ht[i-1];
			}
		}
		     n--;
		for (int i = 0; i < n; i ++) {        
			pos[0][i] = hd[i]; 
		//	h[i].len = n-i; 
	//		cout << P[0][i] << " ";
			
		}  	
		//cout << count << " ";
	//	cout << endl;
		for ( a= 1, b = 1; b >> 1 < n; a ++, b <<= 1)     {         
			for (int i = 0; i < n; i ++){             
				h[i].nr[0] = pos[a - 1][i];             
				h[i].nr[1] = i + b < n ? pos[a - 1][i + b] : -200;             
				h[i].p = i;         
			}         
		//	for_each(L,L+N,print);
			sort(h, h + n, cmp);         
			//for_each(L,L+N,print);
			for (int i = 0; i < n; i ++) {             
				pos[a][h[i].p] = i > 0 && h[i].nr[0] == h[i - 1].nr[0] && h[i].nr[1] == h[i - 1].nr[1] ? pos[a][h[i - 1].p] : i;
		//		cout << P[stp][L[i].p] << " ";0
			}
		//	cout << endl;
	//		for(int i=0;i<N;i++) {
	//			cout << P[stp][i] << " ";
	//		}
	//		cout << endl; ;
		} 
		ll  sum = 0;
		for(int j=0;j<n-1;j++) {
			sum = (sum + (lcp(h[j].p,h[j+1].p,n,a-1))%MOD )%MOD ;
		}
		cout << (tot - sum)%MOD << endl;
	}
	
}   

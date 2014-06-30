#include<cstdio> 
#include<iostream>
#include<cstring>
#include<algorithm> 
using namespace std;  
#define MAX  100009 
#define MAXR 100
#define MOD 1000000009
typedef long long ll;
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
} h[MAX][2]; 

ll pos[MAXR][MAX];

int cmp(struct ht a, struct ht b) {     
	return a.nr[0] == b.nr[0] ? (a.nr[1] < b.nr[1] ? 1 : 0) : (a.nr[0] < b.nr[0] ? 1 : 0); 
}  

void print(struct ht a) {
	cout << a.nr[0] << " " << a.nr[1] << " " << a.p << endl; 
}
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

void suffix(string p,int k=0) {
	int n = p.size();
		for (int i = 0; i < n; i ++) {        
			pos[0][i] = p[i] - 'a'; 
		//	h[i].len = n-i; 
	//		cout << P[0][i] << " ";
			
		}  	
		//cout << count << " ";
	//	cout << endl;
		int a,b;
		for ( a= 1, b = 1; b >> 1 < n; a ++, b <<= 1)     {         
			for (int i = 0; i < n; i ++){             
				h[k][i].nr[0] = pos[a - 1][i];             
				h[k][i].nr[1] = i + b < n ? pos[a - 1][i + b] : -200;             
				h[k][i].p = i;         
			}         
		//	for_each(L,L+N,print);
			sort(h[k], h[k] + n, cmp);         
			//for_each(L,L+N,print);
			for (int i = 0; i < n; i ++) {             
				pos[a][h[k][i].p] = i > 0 && h[k][i].nr[0] == h[k][i - 1].nr[0] && h[k][i].nr[1] == h[k][i - 1].nr[1] ? pos[a][h[k][i - 1].p] : i;
		//		cout << P[stp][L[i].p] << " ";0
			}
		//	cout << endl;
	//		for(int i=0;i<N;i++) {
	//			cout << P[stp][i] << " ";
	//		}
	//		cout << endl; ;
		} 

} 

void calLength(int *len, int l,string p,string q) {
	int count=1;
	for(int i=0;i<max(p.size(),q.size());i++) {
		count=1;
		for(int j=h[0][i].nr[0] , k = h[1][i].nr[0]; j <= h[0][i].nr[1] && k <= h[1][i].nr[1] && count<=l;j++,k++) {
			if(p[j] == q[k])
			len[count]++;
			else break;
			count++;
		}
	}
}

void print_nr(string p, string q) {
	for(int i=0;i<p.size();i++) {
		cout << h[0][i].nr[0] << " " << h[0][i].nr[1] << endl;;		
	}
	cout << endl;
	for(int i=0;i<q.size();i++) {
		cout << h[1][i].nr[0] << " " << h[1][i].nr[1] << endl;;		
	}
}
main() {     
	int t;
	ll a,b;
	cin >> t;
	while(t--) {
		int l;
		string p,q;
		cin >> p >> q;
		cin >> l;
		suffix(p,0);
		suffix(q,1);
		int len[l+1];
		print_nr(p,q);
		memset(len,0,sizeof(len));
		
		calLength(len,l,p,q);
		for(int i=1;i<=l;i++) {
			cout << len[i] << " ";
		}
		cout << endl;
	}
}   



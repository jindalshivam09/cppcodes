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

int main() {
	int t;
	cin >> t ;
	while (t--) {
		int n,m;
		cin >> n >> m ;
		vector<vi> arr(n,vi(m));
		rep(i,n)	rep(j,m)	
			scanf("%d",&arr[i][j]) ;
		
		if (n==1) {
			if(arr[0][1]>arr[0][m-2]){
	                printf("%d\n3\n",arr[0][1]);
	                printf("0 0\n0 1\n0 0\n");
	        }
			else{
	                printf("%d\n3\n",arr[0][m-2]);
	                printf("0 %d\n0 %d\n0 %d\n",m-1,m-2,m-1);
	    	}
		}
		else if (m==1) {
            if(arr[1][0]>arr[n-2][0]){
                printf("%d\n3\n",arr[1][0]);
                printf("0 0\n1 0\n0 0\n");
            }
			else{
                printf("%d\n3\n",arr[n-2][0]);
                printf("%d 0\n%d 0\n%d 0\n",n-1,n-2,n-1);
	        }
		}
		else {
			int even = 0 , odd = 0;
			rep(i,n)	rep(j,m) {
				if ((i+j)%2 == 0)	even += arr[i][j];
				else				odd += arr[i][j];
			}
			
			if (n%2 == 0) {
				printf("%d\n%d\n",max(even,odd),m*n+1) ;
				if ( odd < even ) {
					rep(i,m)	printf("0 %d\n",m-1-i);
					repi(i,1,n) {
						if(i&1)		rep(j,m-1)	printf("%d %d\n",i,j);
						else		rep(j,m-1)	printf("%d %d\n",i,m-2-j);
					}
					rep(i,n)		printf("%d %d\n",n-1-i,m-1);
				}
				else {
					rep(i,m)	printf("0 %d\n",i);
					repi(i,1,n) {
						if(i&1)		rep(j,m-1)	printf("%d %d\n",i,m-1-j);
						else		rep(j,m-1)	printf("%d %d\n",i,j+1);
					}
					rep(i,n)		printf("%d %d\n",n-1-i,0);				
				}
			}
			else if ( m%2 == 0 ) {
				printf("%d\n%d\n",max(even,odd),m*n+1) ;
				if ( odd < even ) {
					rep(i,n)	printf("%d %d\n",i,m-1);
					for(int i=m-2;i>=0;i--) {
						if(i&1 == 0)		rep(j,n-1)	printf("%d %d\n",n-j-1,i);
						else		rep(j,n-1)	printf("%d %d\n",j+1,i);
					}
					rep(i,m)		printf("0 %d\n",i);
				}
				else {
					rep(i,n)	printf("%d 0\n",i);
					repi(i,1,m) {
						if(i&1)		rep(j,n-1)	printf("%d %d\n",n-1-j,i);
						else		rep(j,n-1)	printf("%d %d\n",j+1,i);
					}
					rep(i,m)		printf("%d %d\n",0,m-1-i);				
				}
			}
			else {
				printf("%d\n",even);
                printf("%d\n",m*n);
                printf("0 0\n");
                for(int i = 0;i+2<m;++i){
                    if(i&1) for(int j = n-1;j>0;--j) printf("%d %d\n",j,i);
                    else for(int j = 1;j<n;++j) printf("%d %d\n",j,i);
                }
                for(int i = n-1;i>1;--i){
                    if(i&1) printf("%d %d\n%d %d\n",i,m-1,i,m-2);
                    else printf("%d %d\n%d %d\n",i,m-2,i,m-1);
                }
                printf("%d %d\n",1,m-1);
                for(int i = m-1;i>=0;--i) printf("%d %d\n",0,i);
			}
		}
	}
}

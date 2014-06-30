#include<iostream>
using namespace std;

long long int calPow(int q,int n)
{
	 long long int ans;
	 if(n==0)
	 return 1;
	 if(n==1)
	 {
			return q;
     }
	else
	{
		ans=calPow(q,n/2);
		ans*=ans;
		if(n%2)
		{
				  ans*=q;
		}
	}
	return ans;
}


int gcd(int a, int b) {
  return b == 0 ? a : gcd(b, a%b) ; 
}
int calCoPrime (int *odd,int *even,int o,int e) {
	int count=0;
	for(int k=0;k<o;k++) {
		for(int l=k+1;l<o;l++)
			if(gcd(odd[k],odd[l])==1)
			count+= calPow(2,o-l-1);
	}
	for(int l=0;l<e;l++) {
		for(int k=0; k<o; k++) {
				if(gcd(odd[k],even[l])==1)
				count+= calPow(2,o+e-k-l-2);
			}		
	}		
	return count;
}

main() {
	int n,t;
	int odd[60],even[60];
	cin >> t;
	while(t--) {
		cin >> n;
		int e=0,o=0,a;
		for(int k=0 ;k<n; k++) {
			cin >> a;
			a%2?odd[o++]=a:even[e++]=a;
		}
		cout << calCoPrime(odd,even,o,e) << endl;
	}
}

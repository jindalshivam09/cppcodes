#include<iostream>
#include<vector>
#include<cstdio>
#include<cmath>
#include<set>
using namespace std;

int factors[101][27];
int arr[] = {1,2,3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
	
long long int calPow(int q,int n,int MOD) {
	long long int ans;
	if(n==1) 	return q;
	if(n==0)	 return 1;
	else {
		ans=calPow(q,n/2,MOD)%MOD;
		ans=(ans*ans)%MOD;
		if(n%2)		ans=(ans*q)%MOD;
	}
	return ans%MOD;
}

void init() {
	
	for(int i=1;i<=100;i++)
	{
		int n=i;
		int pos=1;
		while(n>1)
		{	
			while(n%arr[pos]==0&&n>1)
			{
				factors[i][pos]++;
				n=n/arr[pos];
			}
			pos++;		
		}
	}
}

int temp[100001][26];

void mul_mul(int *in,int n) {
	for(int i = 0 ; i < 26 ; i++) {
		temp[0][i] = factors[in[0]][i];
	}
	
	for(int i = 1 ; i < n ; i ++) {
		for(int j=0;j<26;j++) {
			temp[i][j] = factors[in[i]][j] + temp[i-1][j] ;
		}
	}
/*	for(int i=1 ; i < n ; i++){
		for(int j=0 ; j<26; j++)
		cout << temp[i][j] << " ";
		cout << endl;
	}
	cin.get();
*/	
}
int main() {
	init();
	int n;
	scanf("%d",&n);
	int in[n];
	
	for(int i=0;i<n;i++)
	cin >> in[i];
	
	mul_mul(in,n);
	int t;
	scanf("%d",&t);
	while(t--) {
		int l,r,m;
		scanf("%d%d%d",&l,&r,&m);
		long long ans = 1;
		for(int i=0 ; i < 26; i++) {
			if(l>1) {
				if(temp[r-1][i]-temp[l-2][i]) {
					ans = (ans * calPow(arr[i],temp[r-1][i]-temp[l-2][i], m  ))%m ;
				}
			}
			else if(temp[r-1][i]) {
				ans = (ans * calPow(arr[i] , temp[r-1][i],m ))%m ;
			}
	   	}
		printf("%lld\n",ans%m);
	}
	return 0;
}

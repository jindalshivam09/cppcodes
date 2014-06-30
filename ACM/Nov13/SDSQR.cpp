#include<iostream>
#include<vector>
#include<cmath>
#include<cstdio>
#include<ctime>
#include<cstdlib>
#include<algorithm>
using namespace std;

#define MAX 100000 
long long arr[MAX];
int size = 0;

void preprocess() {
	
	long long temp;
	bool flag = false;
	
	for(long long i = 1 ; i <= MAX ; i++) {
		
		temp = i*i;

		
		flag = false;
		while(temp) {
			
			int a = temp%10;
			if(a==0 || a==1 || a == 4 || a==9)		temp /= 10;
			else									{flag = true; break;}
		}
		
		if(!flag)		arr[size++] = i*i;
		
		
	}
	
//	for(int i=0;i<16;i++)
//	cout << arr[i] << " ";
//	cout << size << "  " << arr[size-1] << endl;
}
/*
int search(long long a,int p = 1,int q = size-1) {
	
	int r = (p+q)/2;
	cout << arr[r] << " " << a << endl;
	cout << p << " " << r << " " << q << endl;
	cin.get();
	if(arr[r] == a) 					return r;
	else if(p>q)						return -1;		
	else if( p == q && arr[r] < a )		return r+1;
	else if( p == q && arr[r] > a )		return r-1;
	else if( arr[r] > a )				return search(a,p,r-1);
	else								return search(a,r+1,q);
} 
*/

int search (long long a) {
	
	if(a==1)			return 0;
	for(int i=1;i<121;i++) {
	
		if(a <= arr[i])
		return i;
	}	
	return 120;
}

int main() {
	
//	float r = clock_t()/CLOCKS_PER_SEC;

	preprocess();
	
	int t;
//	cin >> t;
//	t=500;	

	scanf("%d",&t);
	while(t--) {
		
		long long a,b;
//		cin >> a >> b;
//		a = rand()%10000000000;
//		b = rand()%10000000000;		

		scanf("%lld%lld",&a,&b);
		
		int i = search(a);
		int j = search(b);	
		
//		cout << i << " " << j << endl;
//		cout << arr[i] << " " <<  arr[j] << endl;
	
		if(arr[i] < a)			i++;
		if(arr[j] > b)			j--;
		
		
//		cout << j-i+1 << endl;

		printf("%d\n",j-i+1);
	}	
	
//	cout << float(clock_t()/CLOCKS_PER_SEC - r) ;
}

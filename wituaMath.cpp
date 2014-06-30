#include<iostream>	
#include<cstdlib>
#include<map>
#define TEST 10
#define TEN 1000000000
using namespace std;
unsigned long long mulMod(unsigned long long a,unsigned long long b,unsigned long long n) {
	unsigned long long	a_low = a % TEN;
	 unsigned long long	a_high = a / TEN;
	 
	unsigned long long 	b_low = b % TEN;
	unsigned long long  	b_high = b / TEN;
	  
	  unsigned long long	result = (a_high * b_high) % n;
	 
	 for(int i=0;i<9;i++)
	     result = (result * 10) % n;
	 result = (result + a_low*b_high + b_low*a_high) % n;
	 for(int i=0;i<9;i++)
	    result = (result * 10) % n;
	 result = (result + a_low*b_low) % n;
	 return result;
}
unsigned long long  calPow(unsigned long long q,unsigned long long n,unsigned long long MOD) {
	 long long int ans;
	 if(n==1)
			return q;
	else	{
		ans=calPow(q,n/2,MOD)%MOD;
		ans=mulMod(ans,ans,MOD);
		ans%=MOD;
		if(n%2)	{
				  ans=mulMod(ans,q,MOD);
				  ans%=MOD;
		}
	}
	return ans;
}

bool isPrime(unsigned long long n) {
	unsigned long long  a;
	if(n==2 || n==3)
	return true;
	if(!(n%2))
	return false;
	int i=0,t=TEST;
	unsigned long long first;
	unsigned long long temp = n-1;
	while(!(temp&1)) {
		temp = temp>>1;
		i++;
	}
	while(t--) {
		bool flag= false;
		a = rand()%(n-1)+1;
		first = calPow(a,temp,n);
		if(first == 1)
		continue;
		else {
			if(first == n-1)
			continue;
			for(int j=1;j<i;j++) {
				first =mulMod(first,first,n)%n;
				if(first == n-1){
					flag = true;
					break;
				}
			}
			if(!flag)
			return false;
			flag=false;
		}
	}
	return true; 
}

main() {
	int t;
	unsigned long long n;
	cin >> t;
	while(t--) {
		cin >> n;
		for(unsigned long long  i=n;i>1;i--) {
		//	cout << i << endl;
			if(isPrime(i)) {
				cout << i << endl;
				break;
			}
	//		cin.get();
		}
	}
}

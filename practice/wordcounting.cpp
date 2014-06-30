#include<iostream>
#include<cstring>

#define MOD 1000000007
#define MAX 100
using namespace std;
long long int fact[501],invers[501];
long long p(long long n,long long m)
{
	if(m==0)
		return 1;
	long long temp=p(n,m/2);
	if(m%2)
		return (((temp*temp)%MOD)*n)%MOD;
	else
		return (temp*temp)%MOD;
}
int init()
{
	   fact[0]=1;
	   for(int i=1;i<=500;i++)
	   fact[i]=(fact[i-1]*i)%MOD;
	   invers[500]=p(fact[500],MOD-2);
	   
	   for(int i=499;i>=0;i--){
	   invers[i]=(invers[i+1]*(i+1))%MOD;
	  // invers[0]=1;
	  // cout<<fact[i]<<endl<<invers[i]<<endl;
	}
}
main()
{
	int t;
	char a;
	long long int count;
	cin>>t;
	init();
	while(t--)
	{
			
			int freq[201]={0};
			count=0;
			cin.get();
//			cin.sync(); //to flush istream
			while((a=cin.get())!='\n')
			{
				freq[a]++;
			/*	if(a>='a'&&a<='z')
					freqL[a-97]++;

				else if(a>='A'&&a<='Z')
					freqU[a-65]++;*/
					count++;
			}
			long long int ans=fact[count];
			/*for(int i=0;i<26;i++)
			{
				 cout<<freqL[i]<<" "<<freqU[i]<<endl;
			}*/
			//cout<<ans<<endl;
			for(int i=0;i<=200;i++)
			{
		//		cout<<" "<<invers[freqL[i]]<<" "<<invers[freqU[i]]<<" ";
				ans=(ans*invers[freq[i]])%MOD;
	//			ans=(ans*invers[freqU[i]])%MOD;
			}
			cout<<ans<<endl;
	}
	return 0;
}

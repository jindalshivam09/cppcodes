#include<iostream>
#include<cstring>

#define MOD 1000000007
#define MAX 100
using namespace std;
int fact[501],invers[501];
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
	   invers[500]=p(fact[11],MOD-2);
	   
	   for(int i=499;i>=1;i--){
	   invers[i]=(invers[i+1]*(i+1))%MOD;
	 //  cout<<fact[i]<<endl<<invers[i]<<endl;
	}
}
main()
{
	int t;
	char a;
	long long int count;
	int COUNT;
	cin>>t;
	while(t--)
	{
			init();
			int freqL[26]={0},freqU[26]={0};
			count=0;
			cin.get();
			//cin.sync(); //to flush istream
			while((a=cin.get())!='\n')
			{
				if(a>='a'&&a<='z')
					freqL[a-97]++;
				else if(a>='A'&&a<='Z')
					freqU[a-65]++;
					count++;
			}
			int ans=fact[count];
			for(int i=0;i<26;i++)
			{
	//			cout<<" "<<invers[freqL[i]]<<" "<<invers[freqU[i]]<<" ";
				ans=(ans*invers[freqL[i]])%MOD;
				ans=(ans*invers[freqU[i]])%MOD;
			}
			cout<<ans<<endl;
	}
}

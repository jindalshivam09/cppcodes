#include<iostream>
#define MOD 1000000007
using namespace std;
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
main()
{
	int temp;
	long long int array[11]={1,1,2,6,24,120,720,5040,40320,362880,3628800};
	for(int i=0;i<11;i++)
	{
		temp=array[i];
		array[i]=p(array[i],MOD-2);
		//cout<<"hi";
	}
	for(int i=0;i<11;i++)
	cout<<array[i]<<endl;
	cin.get();
	
}

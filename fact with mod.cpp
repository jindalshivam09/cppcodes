#include<iostream>
#include<vector>
#define MOD 1000000007
using namespace std;
main()
{
	int temp;
	int array[11]={1,1,2,6,24,120,720,5040,40320,362880,3628800};
	for(int i=0;i<11;i++)
	{
		temp=array[i];
		for(int j=2;j<=MOD-2;j++ )
		array[i]=((temp%MOD)*(array[i]%MOD))%MOD;
		cout<<"hi";
	}
	for(int i=0;i<11;i++)
	cout<<array[i]<<"shivam"<<endl;
	cin.get();
	
}

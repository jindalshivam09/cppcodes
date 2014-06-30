#include<iostream>
#include<conio.h>
using namespace std;
void simpleFraction(int &num,int &den)
{
	  for(int i=den;i>1;i--)
	  {
			if(!(num%i)&&!(den%i))
			{
				num/=i;
				den/=i;
			}
	  }
}
main()
{
		int n;
		cout<<"enter total number of fractions: ";
		cin>>n;
		int count=n;
		int a,b;
		int num[n],den[n];
		while(count--)
		{
				cin>>a>>b;
				num[n-1-count]=a;
				den[n-1-count]=b;
		}
		int index;
		cout<<"enter the index :";
		cin>>index;
		int numSum=0,denSum=0;
		float fraction=0;
		for(int i=index-1;i<n;i++)
		{
				if(fraction<((float)(numSum+num[i])/(denSum+den[i])))
				{
					numSum+=num[i];
					denSum+=den[i];
					//cout<<fraction<<endl;
					fraction=(float)(numSum+num[i])/(denSum+den[i]);
				}
				else
				break;

		}
		simpleFraction(numSum,denSum);
		cout<<numSum<<"/"<<denSum;
		getch();

}

#include<iostream>
#include<limits.h>
using namespace std;
main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int moves;
		cin>>moves;
		int arr[moves];
		for(int i=0;i<moves;i++)
		cin>>arr[i];
		int i=0;
		int flag=0;
		int count=1;
		int max;
		while(1)
		{
              max=INT_MIN;
			  for(int j=i+arr[i];j>i;j--)
			  {
						  if(max<(arr[j]+j))
						  {
						         max=arr[j]+j;
						         flag=j;
						  }
			  }
			 // cout<<"flag"<<flag<<endl;
			  i=flag;
			  if(i>=moves-1)
			  break;
			  count++;
			 // cout<<i<<" "<<count<<endl;
			 
		}
		cout<<count<<endl;
    }
    return 0;
}

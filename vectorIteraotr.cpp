#include<iostream>
#include<vector>
using namespace std;
main()
{
	int  m;
	vector<int> arr(4);
	vector<int>::iterator ptr=arr.begin();
	for(int i=0;i<5;i++)
	{
		cin>>m;
		arr.push_back(m);
		ptr++;
	}
	for(ptr=arr.begin();ptr!=arr.end();ptr++)
	cout<<*ptr<<" ";
	for(int i=0;i<arr.size();i++)
	cout<<arr[i]<<" ";
	while(1);
}

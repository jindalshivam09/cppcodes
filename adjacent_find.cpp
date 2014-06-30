#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
main()
{
	vector<int > v(10);
	vector<int>::iterator ptr=v.begin(),p;
	for(int i=0;i<5;i++){
		v[i]=2*i+5;
		ptr++;
	}
	if((p=adjacent_find(v.begin(),ptr,5))<ptr)
	cout<<"value found";
	else
	cout<<"no value found";
	
}

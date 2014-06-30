#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

vector<int > ans1;
vector<int> ans2;
bool b1,b2;

struct xxx
{
	long long  index;
	long long  value;
	
};

bool cmp(const xxx &a,const xxx &b)
{
	return a.value < b.value;
	
}

int main()
{
 
long long  i;
xxx array[10000];
long long  n,k;
cin>>n>>k;
b1=b2=false;
for( i=0;i<n;++i)
{
cin>>array[i].value;
array[i].index=i+1;

}



	sort(array,array+n,cmp);
	
	
	long long sum;
for(i=0;i<=n-k;++i)
{	sum=0;

		for(int j=0;j<k-1;++j)
		sum += array[i+j].value;
			
	if(sum > array[i+k-1].value ) 
	{
		for(int j=0;j<k;++j)
			{
			ans1.push_back(array[i+j].index);
			}
			b1=true;
			i=i+k;
		break;
		
	
		}
}
	
		for( ;i<=n-k;i++)
		{
			sum = 0;
		for(int j=0;j<k-1;++j)
			sum += array[i+j].value;
			if( sum > array[i+k-1].value)
			{
					for(int j=0;j<k;++j)
			{
			ans2.push_back(array[i+j].index);
	//		cout<<array[i+j].value<<endl;
			}
				b2=true;
		break;
			}			
		}

		if(b1 && b2 ) 
		{
	cout<<"Yes\n";
		for(int i=0;i<k;++i)
			cout<<ans1[i]<<" ";
		for(int i=0;i<k;++i)
			cout<<ans2[i]<<" ";	
			cout<<endl;
			}

		else 
			cout<<"No\n";

return 0;
}/*

15 6
45 78 09 3454 678 434 354 67878797998 6576456 09090 2324 4 7 65 3545
*/

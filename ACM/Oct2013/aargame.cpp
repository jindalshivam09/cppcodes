#include<iostream>
#include<algorithm>
#include<vector>
#include<climits>
using namespace std;


int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		vector<int> x;
		vector<int> y;
		x.resize(n);
		y.resize(n);
		for(int i=0;i<n;i++)
		{	
		cin>>y[i];
		if(y[i]==1)
			y[i]=INT_MAX;
		if(y[i]==2)
			y[i]=4;
		else
			y[i]=y[i];
		}		
		for(int i=0;i<n;i++)
		{
			cin>>x[i];		
			if(x[i]==1)
				x[i]=INT_MAX;
			if(x[i]==2)
				x[i]=4;
			else
				x[i]=x[i];
		}	
		sort(x.begin(),x.end());
		sort(y.begin(),y.end());
					
		long long total=0;
		int pos=-1;
		for(int i=0;i<n;i++)
		{
			int element=x[i];
			if(pos==-1)
				pos=0;
			while(y[pos]<element&&pos<y.size())
				pos++;	
			pos=pos-1;
			
			total=total+(pos+1);
		}
		
		cout.precision(6);
		cout.setf(ios::fixed);
		cout<<((double)total)/n<<endl;
	}
}

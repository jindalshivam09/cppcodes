#include<iostream>
#include<string.h>
#include<limits>
#include<vector>
using namespace std;

long long getL(long long n,long long D,vector<long long> &d, vector<long long> &c)
{
	int L=0;
	int 		start=0;
	
	while(start<n)
	{
		long long D_temp=D;
		while(D_temp>=d[start]&&start<n)
		{
			D_temp-=d[start];
			start++;
		}
		L++;
	}
	return L;
}

vector<long long> reverse_time(long long n,long long D,vector<long long> &d)
{
	long long start=n-1;
	long long L=1;
	vector<long long> time(n+1);
	while(start>0)
	{
		long long D_temp=D;
		while(D_temp>=d[start]&&start>0)
		{
			D_temp-=d[start];
			time[start]=L;
			start--;
		}
		L++;
	}
	time[0]=time[1];
	return time;
}

long long lookuptable[200000];
long long DFS(long long N,long long D,vector<long long> &d,vector<long long> &c,vector<long long> &s, int L,int days=0,long long i=0)
{
	if(i==N)
		return 0;
	if(s[N-1]-s[i-1]<=D&&days==L-1)
		return c[i];
	else if(days>=L)
		return numeric_limits<long long>::max();
	else if(lookuptable[i]!=-1)
	{
		cout<<"RETURNING "<<lookuptable[i]<<" at "<<i<<endl;
			return lookuptable[i];
	}	
	else
	{
		long long travel_cost=0;
		long long MIN=numeric_limits<long long>::max();
		for(long long j=i+1;j<N;j++)
		{
			travel_cost+=d[j];
			if(travel_cost>D)
			{
				break;
			}
			else
			{
				MIN=min(MIN,DFS(N,D,d,c,s,L,days+1,j));	
			}
		}
		cout<<"Look up table of "<<i<<" = "<<lookuptable[i]<<endl;
		lookuptable[i]=max(MIN,c[i]);
		return max(MIN,c[i]);
	}
}



int main()
{
	long long t;
	cin>>t;
	while(t--)
	{
		long long N,D;
		cin>>N>>D;
		vector<long long> d,c;
		vector<long long> s;
		d.reserve(N); 
		c.reserve(N);
		s.reserve(N);
		
		d.push_back(0);
		c.push_back(0);
		s.push_back(0);
		
		for(long long i=0;i<N;i++)
		{
			long long d_temp;
			cin>>d_temp;
			d.push_back(d_temp);
			s.push_back(d_temp+s.back());
			long long c_temp;
			cin>>c_temp;
			c.push_back(c_temp);
		}
		N++;
		
		memset(lookuptable,-1,sizeof(lookuptable));
		
		long long L=getL(N,D,d,c);
		vector<long long> rtime=reverse_time(N,D,d);
		
		for(int i=0;i<rtime.size();i++)
		{
			cout<<rtime[i]<<endl;
		}
		cout<<L<<" "<<DFS(N,D,d,c,s,L)<<endl;
	}
}

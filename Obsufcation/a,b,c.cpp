#include<iostream>
using namespace std;
int calPow(int q,int n,int ans=0)
{
	 //c\out<<"n="<<n<<" "2;
	 if(!n)
	 return 1;
	 else if(n==1)
	 {
          //   a*=q;
		//	cout<<n<<" "<<ans<<" "<<q<<" ";
			return q;
     }
	else if(n>1)
	{
		ans=calPow(q,n/2,ans);
	//	cout<<"ret ans= "<<ans<<" ";
		ans*=ans;
		if(n%2)
		{
				  ans*=q;
		}
//		cout<<n<<" "<<ans<<" "<<q<<" ";
	}
	return ans;
}

main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    long int a,b,c;
     	cin>>a>>b>>c;
    	long int n,m;
      	cin>>n>>m;
      	n-=1;
    	int ans=calPow(c,n/2);
	    ans=((a%m*ans%m)%m+(((b%m)*(c%m)*((ans%m-1%m)%m))/((c%m-1%m)%m))%m)%m;
     	n%2?cout<<(ans+b%m)%m:cout<<ans;
     	cout<<"\n";
    }
}

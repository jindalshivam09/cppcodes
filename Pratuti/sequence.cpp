#include<iostream>
#include<math.h>
using namespace std;
main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int a;
		cin>>a;
		int i;
		int root=sqrt(a),sum;
	    cout<<root<<endl;
		for( i=root;1;i--)
		{
					sum=(i*(i+1)*(2*i+1))/6;
					if(sum<=a)
					break;
		}
		int gp=i;
		int sumGp=sum;
		
		if(sum!=a){
				gp+=1;
				sumGp+=(gp*gp);
		}
		else
		sum-=i*i;
        cout<<sum<<" ";
		cout<<gp<<" "<<sumGp<<endl;
        int gpPos=(a-sum)/gp;
        cout<<gpPos<<" ";
        if((a-sum)%gp)
        gpPos+=1;
		int freq=gp*(gp+1)/2;
		cout<<gpPos<<" "<<freq<<endl;
		cout<<(freq-(gp-gpPos))<<endl;
		
		
	}
	return 0;
}


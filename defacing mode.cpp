#include<iostream>
#define MAX 10
#include<cstring>
#include<conio.h>
using namespace std;
main()
{
	int decEqv[]={126,48,109,121,51,91,95,112,127,123};
	int t;
	char m[MAX],n[MAX];
	cin>>t;
	while(t--)
	{
		cin>>m>>n;
		int lm=strlen(m);
		int ln=strlen(n);
        int temp,j=0;
		if(ln>lm)
		{
			
			while(j<lm)
			{
				temp=decEqv[(m[j]-48)];
				//	   cout<<"t"<<temp;
					 for(int i=0;i<10;i++)
					 if((temp&decEqv[9-i])==temp)
					 {
					//		cout<<"hi"<<9-i;
					      m[j]=(48+9-i);
						//	 cout<<"m"<<m[j];
						  break;
					 }
			  j++;
			 }
		}
		else
		{
			while(j<lm)
			{
               temp=decEqv[(m[j]-48)];
               for(int i=0;i<10;i++)
							if((temp&decEqv[9-i])==temp&&((9-i)<=(n[j]-48)))
					        {
							        m[j]=48+9-i;
							        break;
					        }
			   j++;

		   }
		}
		cout<<m<<endl;
		
	}
	getch();
	return 0;
}

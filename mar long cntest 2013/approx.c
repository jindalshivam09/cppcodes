#include<stdio.h>
main()
{
	int t;
	scanf("%d",&t);
	//int num=103993,den=33102;
	int mod,i;
	int ans;
	char print[]="415926530119026040722614947737296840070086399613316";
	int n,rem,j=0;
	int res;
	while(t--)
	{
		scanf("%d",&n);
//		mod=4687;
		j=0;
		if(!n)
		printf("3");
		else
		{
			printf("3.1");
			n--;
			if(n>0)
			{

				if(n<51)
				{

				   res=print[n];
					print[n]='\0';
					printf("%s",print);
				}
				else{
					int m=n/51;
					for(i=0;i<m;i++)
					printf("%s",print);
					n=n-m*51;
					res=print[n];
                    print[n]='\0';
					printf("%s",print);

				}
				print[n]=res;
				
				
			}
	}
/*		    for(i=0;i<n-1;i++)
		    {
				if(i>=51)
				j%=51;
				   printf("%c",print[j]);
				   j++;
	        }
		}
	*/	printf("\n");

	}
	return 0;
}

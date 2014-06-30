#include<stdio.h>
#define MAX 1000002
main()
{
	char pallin[MAX];
	int t,i,j,k,flag=1;
	char a;
	int NINE=0,EQUAL=0,ZERO=0;
	int pre1,pre2,pre3;
	scanf("%d",&t);
	fflush(stdin);
	while(t--)
	{
	//	printf("shivam");
			i=0;
			NINE=0;
			EQUAL=0;
			pre1=pre2=0;
			flag=0;
			ZERO=0;
			while((a=getchar())!='\n')
			{
				 //printf("hi");
/*				 if(a=='0'&&!ZERO)
				 continue;
				 ZERO=1;
*/
				 if(a=='9')
				 NINE++;
				 else NINE=0;
				 pallin[i++]=a;
			}
		   //printf("\n");
			if(i%2)
			k=i/2;
			else
			k=i/2-1;
			//printf(" %d ",k);
			if(NINE==i)//&&ZERO)
			{
			      printf("1");
			      for(j=0;j<i-1;j++)
			      printf("0");
			      printf("1\n");
			}
	/*		else if(!ZERO)
			printf("1\n");
		*/	else
			{

			for(j=0;j<=k;j++)
			{
                pre3=pallin[i-j-1];
				if(pallin[j]==pallin[i-j-1])
				EQUAL++;
				else
				EQUAL=0;
		        //	if(pallin[j]>pallin[i-j-1])
				  pallin[i-j-1]=pallin[j];
				pre2=pallin[i-j-1];
			//	printf(" %c %c %d ",pre3,pre2,flag);
			   if(pre2<pre3)
			   {
			           flag=1;
			   }
			   else if(pre2>pre3)
			   flag=0;
			   //if(pallin)
			}
		//	printf(" %d \n",k);
			if(flag||(EQUAL==k+1))
			{
			      if(pallin[k]=='9'&&(i%2))
			      {
						//printf("shivam");
						pallin[k]='0';
					//	printf(" %d %d ",k-1,i-k);
						pallin[k-1]=pallin[i-k]=pallin[k-1]+1;
			      }
			      else if(pallin[k]=='9')
				  {
	    	      		pallin[i-k-1]=pallin[k]='0';
						pallin[k-1]=pallin[i-k]=pallin[k-1]+1;
				  }
				  else
				  pallin[k]=pallin[i-k-1]=pallin[k]+1;

			}
			for(j=0;j<i;j++)
			printf("%c",pallin[j]);
			printf("\n");

			}
	}
	return 0;
}

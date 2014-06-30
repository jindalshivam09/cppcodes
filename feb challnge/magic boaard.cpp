#include<string.h>
#include<stdio.h>
#define MAX 10000
#include<stdlib.h>
main()
{
	    int arr[MAX][2];
		int m,n;
		 scanf("%d%d",&m,&n);
		   int row=0,col=0;
		while(n--)
		{
		           char query[10];
				   scanf("%s",query);
		           if(!strcmp(query,"RowQuery"))
		           {
							 int a;
							 scanf("%d",&a);
							 if(arr[a-1][0]!=m)
                                 printf("%d\n",(m-row));
							 else printf("0\n");
        	       }
        	       else if(!strcmp(query,"ColQuery"))
        	       {
                              int a;
                             scanf("%d",&a);
							  
                              if(arr[a-1][1]!=m)
                              printf("%d\n",(m-col));
							  else  printf("0\n");
        	       }
        	       else if(!strcmp(query,"RowSet"))
        	       {
                        int a,b;
                        scanf("%d%d",&a,&b);
						if(b)
						{
							  arr[a-1][0]= m;
							  col++;
						}
						else
						{
							arr[a-1][0]=0;
							if(col)
							col--;
						}
						//printf("%d",col);
        	       }
        	       else if(!strcmp(query,"ColSet"))
        	       {
                        int a,b;
                        scanf("%d%d",&a,&b);
						if(b)
						{
							  arr[a-1][1]=m;
							  row++;

							  
						}
						else
						{
							arr[a-1][1]=0;
							if(row)
							row--;
						}
						//printf("%d",row);
        	       }
        	       printf("row=%d col=%d",row,col);
			}
return 0;
}

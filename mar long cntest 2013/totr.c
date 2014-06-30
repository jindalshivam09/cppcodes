#include<stdio.h>
#define MAX 200
main()
{
	int t,i;
	char str[27],enter[MAX];
	scanf("%d",&t);
	scanf("%s",str);
	while(t--)
	{
		  scanf("%s",enter);
		  for(i=0;(enter[i]!='\0');i++)
		  {
			//	printf("%c",enter[i]);
				if(enter[i]>96&&enter[i]<123)
				printf("%c",str[enter[i]-97]);
				else if(enter[i]>64&&enter[i]<91)
				printf("%c",str[enter[i]-65]-32);
				else if(enter[i]=='_')
				printf(" ");
				else
				printf("%c",enter[i]);
		  }
		  printf("\n");
	}
	return 0;
}

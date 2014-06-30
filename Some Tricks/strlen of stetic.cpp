#include<stdio.h>
#include<string.h>
#include<conio.h>
main()
{
	int i;
	   static  char a[]={'s','h','i','v','a','m','\0'};
		printf(" %d ",strlen(a));
		char *p[]={a,a+1,a+3,a,a,a};
		for(i=0;i<strlen(a);i++)
		printf("%c %p ",*p[i],p[i]);
		getchar();
}

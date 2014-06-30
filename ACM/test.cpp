#include<stdio.h>
long int globl(int n,int g,int start,int stop);
int main()
{int n,g,start,stop;long int point;scanf("%d",&n);point=globl(n,g,start,stop);printf("%ld",point);}long int globl(int n,int y,int start,int stop){if(n==1)return 1;else return (n*globl(n-1,y,start,stop));}

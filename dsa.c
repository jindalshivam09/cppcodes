#include<stdio.h>
int main()
{
  int a[2][5]={1,2,3,4,5,6,7,8,9,10};
printf("%d\n%d\n%d\n",sizeof(int),sizeof(*a),sizeof(a));
printf("%d\n%d\n%d",*a,a,&a);
return 0;
}

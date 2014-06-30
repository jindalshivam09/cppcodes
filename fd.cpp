#include<stdio.h>
int main()
{
  int a[2][5]={1,2,3,4,5,6,7,8,9,10};
printf("%d\n%d\n%d\n",sizeof(int),sizeof(*a),sizeof(a));
for(int i=0;i<20;i++) {
	
printf("%d %d %d\n",*(a+i),a+i,&a);
;	
}


return 0;
}

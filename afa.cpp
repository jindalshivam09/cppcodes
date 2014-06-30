#include<stdio.h>
#include<string.h>

int main()
{
unsigned long int tc,i,cD=0,day=0,cDlast=0;
char s[1000000];
scanf("%ld",&tc);

while(tc>0)
{
scanf("%s",&s);
for(i=1;i<strlen(s)-1;i++)
{
if(s[i]=='.')
{
cD++;
if(s[i+1]=='.')
{
continue;
}
else
{
if(cDlast<cD)
{
day++;
cDlast=cD;
}
cD=0;

i++;//cuz its a '#'
}
}

}

printf("%d\n",day);
tc--;
cD=cDlast=day=0;

}
return 0;
}

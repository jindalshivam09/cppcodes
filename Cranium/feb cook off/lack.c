#include<stdio.h>
#include<string.h>
int main()
{
int t;
scanf("%d",&t);
getchar();

while(t--)
{
int hashmap[50];
int space=0;
memset(hashmap,0,sizeof(hashmap));
int count=26;
char str[500];
gets(str);
for(int i=0;str[i];i++)
{
if(count==0)
break;
else
if(str[i]>='a'&&str[i]<='z')
{
if(!hashmap[str[i]-'a'])count--;
hashmap[str[i]-'a']++;
}
else if(str[i]>='A'&&str[i]<='Z')
{
if(!hashmap[str[i]-'A'])count--;
hashmap[str[i]-'A']++;
}
/*else if(str[i]==' ')
{ if(!space) count--;
space++;
}*/
}
if(!count) printf("~\n");
else
{

for(int i='a'-'a';i<='z'-'a';i++)
{
if(!hashmap[i])
printf("%c",i+'a');
}
printf("\n");
}
}
return 0;


}

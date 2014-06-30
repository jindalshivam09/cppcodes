#include<stdio.h>
#include<string.h>
#define MAX 130
main()
{
	int t;
	scanf("%d",&t);
	char a;
	int i,count;
	int J[26],S[26],j[26],s[26];
	char q[MAX],w[MAX];
	while(t--)
	{
			   count=0;
			   scanf("%s%s",q,w);
			   for(i=0;i<26;i++)
			   j[i]=s[i]=J[i]=S[i]=0;
	 		   for(i=0;q[i]!='\0';i++)
			   {
			    	if(q[i]>='A'&&q[i]<='Z')
					J[q[i]-'A']++;
					else
					j[q[i]-'a']++;
			   }
			   for(i=0;w[i]!='\0';i++)
			   {
					if(w[i]>='A'&&w[i]<='Z')
					S[w[i]-'A']++;
					else
					s[w[i]-'a']++;
              }
              for(i=0;i<26;i++)
              {
					if(J[i])
					{
								count+=S[i];
					}
					if(j[i])
					{
								count+=s[i];
					}
              }
              printf("%d\n",count);
	}
	return 0;
}

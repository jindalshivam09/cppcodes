#includ<stdio.h>
#include<stdlib.h>
struct poly
{
    int deg; float coef[100];
    }
main()
{
    int a,i,j,k;
    struct poly p[10];
    printf("Enter rhe number of polynomial");
    scanf("%d",a);
    for(i=0;i<a;i++)
    printf("Enter the degree of poly%d",i+1);
    scanf("%d",&p[i].deg);
    printf("enter the coef of:");
    for(j=p[i].deg,j>=0,j--)
    {
        k=0;
        printf("x%d",p[i].deg);
        scanf("%f",&p[i].coef[k]);
        k++;
    }j=0;k=0;
    for(i=0;i<a;i++)
    {
        while(p[i].deg>=0)
       {
           if(p[i+1].deg>=0)
           {
               if(p[i].deg==p[i+1].deg)
               {
                   p[i+1].coef[j]=p[i].coef[k]+p[i+1].coef[j];
                   k++;
                   j++;p[i].deg--;p[i+1].deg--;
               }

           else if(p[i].deg>p[i+1].deg)
                   {
                       p[i+1].coef[j]=p[i].coef[k];
                           j++:k++;p[i].dge--;
                   }
       else if(p[i].deg<p[i+1].deg)
                   {

                           j++;p[i+1].dge--;
                   }   }
    }

}for

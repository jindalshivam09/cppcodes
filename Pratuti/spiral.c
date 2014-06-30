#include<stdio.h>
#include<math.h>
main()
{
      int w,e,f,n,k=1,l=0,**a,i,j,o,g=1,z=0;
      scanf("%d",&n);
      n*=n;
       e=pow(n,0.5);
//       printf("[%d]",e);

      w=pow(e,2);//printf("{%d}",w); 
           if(n!=w)
       ++e;
//printf("%d",e);
       if(!w%2)
       ++e;
       f=e;
       //printf("(%d %d)",e,f);
       //if()
       a=(int **)calloc(e+1,sizeof(int));
       for(i=0;i<e;i++)
       a[i]=(int *)calloc(e+1,sizeof(int));
      // for(i=0;i<e;i++)
       //for(j=0;j<e;j++)
       // printf("  %d ",a[i][j]);
        e=e/2;i=e;j=e;
       // printf("(%d %d %d)",e,i,j);
       a[i][j]=1;
       for(o=0;o<n;o++)
       {
                    
              switch(o%4)
              {      
                     case 0:
                     while((l++)<g&&k<n)
              //       printf("[%d]",++k);
              a[i][++j]=++k;
                     break;
                     case 1:
                     while((l++)<g&&k<n)
              //       printf("[%d]",++k); 
              a[--i][j]=++k;
                     break;
                     case 2:
                    while((l++)<g&&k<n)
              //        printf("[%d]",++k);
              a[i][--j]=++k;
                     break;
                     case 3:
                     while((l++)<g&&k<n)
              //        printf("[%d]",++k);
              a[++i][j]=++k;
                     break;
              }
              if(k==n)
              break;
              l=0;
     if(o%2)
     g++;     
      } 
     for(i=0;i<f;i++)
      {
              for(j=0;j<=f;j++)
              {
                         if(a[i][j]>0&&a[i][j]<=n)
                         printf("%-5d",a[i][j]);
                         //else
                       //  printf("   ");
              }// printf("hey");
      printf("\n"); //printf("hey");
      }     
     // printf("hey");

      getch();
}


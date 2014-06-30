#include<stdio.h>
#define MAX 100
char Survey(int x, int y) {
    printf("S %d %d\n", x, y);
    fflush(stdout);
    char res;
    scanf(" %c", &res);
    return res;
}

void Neutralize(int x, int y) {
    printf("N %d %d\n", x, y);
    fflush(stdout); /* but it is not necessary here */
}
int grid[MAX][MAX];
inline void zero(int i,int j,int n)
{
     											if(i-1>=0&&j-1>=0&&i-1<n&&j-1<n)      grid[i-1][j-1]=1;
                                                if(i-1>=0&&j>=0&&i-1<n&&j<n)          grid[i-1][j]=1;
                                                if(i-1>=0&&j+1>=0&&i-1<n&&j+1<n)      grid[i-1][j+1]=1;
                                                if(i>=0&&j-1>=0&&i<n&&j-1<n)          grid[i][j-1]=1;
                                                if(i>=0&&j+1>=0&&i<n&&j+1<n)          grid[i][j+1]=1;
                                                if(i+1>=0&&j-1>=0&&i+1<n&&j-1<n)       grid[i+1][j-1]=1;
                                                if(i+1>=0&&j>=0&&i+1<n&&j<n)          grid[i+1][j]=1;
                                                if(i+1>=0&&j+1>=0&&i+1<n&&j+1<n)      grid[i+1][j+1]=1;
}
main()
{
      int n,m,k;
      //int grid[MAX][MAX]={0};
      scanf("%d%d%d",&n,&m,&k);
      int count=0;
      int i=0,j=0;
      char res;
      int c;
     // int loopx,loopy;
      for(i=0;i<n;i++)
      {
              for(j=0;j<n;j++)
              {
                      if(!(grid[i][j]))
                      {          
                              res=Survey(i,j);
                              grid[i][j]=1;
                              if(res=='M')
                              {
                                    count++;
                                    Neutralize(i,j);
                               }
                               else if(res=='0')
                               {
                                               // printf("hi");
                                                if(i-1>=0&&j-1>=0&&i-1<n&&j-1<n)      grid[i-1][j-1]=1;
                                                if(i-1>=0&&j>=0&&i-1<n&&j<n)          grid[i-1][j]=1;
                                                if(i-1>=0&&j+1>=0&&i-1<n&&j+1<n)      grid[i-1][j+1]=1;
                                                if(i>=0&&j-1>=0&&i<n&&j-1<n)          grid[i][j-1]=1;
                                                if(i>=0&&j+1>=0&&i<n&&j+1<n)          grid[i][j+1]=1;
                                                if(i+1>=0&&j-1>=0&&i+1<n&&j-1<n)       grid[i+1][j-1]=1;
                                                if(i+1>=0&&j>=0&&i+1<n&&j<n)          grid[i+1][j]=1;
                                                if(i+1>=0&&j+1>=0&&i+1<n&&j+1<n)      grid[i+1][j+1]=1;
                               }
                              else if((j==0)&&res>='3')
                               {
                                     Neutralize(i+1,j+1);
                                      Neutralize(i+1,j);
                                       Neutralize(i,j+1);
                                       grid[i][j+1]=1;
                                       grid[i+1][j]=1;
                                       grid[i+1][j+1]=1;
                                       count+=3;
                                       
                                       }
                               else if((i+1)==n&&res=='1')
                                   {
                                      
                                       Neutralize(i,j+1);
                                       grid[i][j+1]=1;
                                       count++;

                                       }
                              else if(res>='4')
                               {
                                     Neutralize(i+1,j+1);
                                      Neutralize(i+1,j);
                                       Neutralize(i,j+1);
                                       Neutralize(i+1,j-1);
                                       grid[i][j+1]=1;
                                       grid[i+1][j]=1;
                                       grid[i+1][j+1]=1;
                                        grid[i+1][j-1]=1;
                                       count+=4;

                                       }
                            
                               else{
                                    
                                        if(i>=0&&j+1>=0&&i<n&&j+1<n&&!grid[i][j+1])         
                                        { 
                                                   grid[i][j+1]=1;    
                                                   res=Survey(i,j+1); 
                                                  if(res=='M') {count++; Neutralize(i,j+1);}
                                                   else if(res=='0')
                                                   {
														zero(i,j+1,n);
                                                   }
                                                   
                                        }
                                        if(i+1>=0&&j-1>=0&&i+1<n&&j-1<n&&!grid[i+1][j-1])
                                        { 
                                                   grid[i+1][j-1]=1;    
                                                   res=Survey(i+1,j-1); 
                                                   if(res=='M') { count++; Neutralize(i+1,j-1);}
                                                    else if(res=='0')
                                                   {
														zero(i+1,j-1,n);
                                                   }
                                        }
                                        if(count==m)
              {
                printf("Done");
                return 0;
              }
                                        if(i+1>=0&&j>=0&&i+1<n&&j<n&&!grid[i+1][j])         
                                        { 
                                                    grid[i+1][j]=1;
                                                    res=Survey(i+1,j); 
                                                    if(res=='M') {count++; Neutralize(i+1,j);  }
                                                     else if(res=='0')
                                                   {
														zero(i+1,j,n);
												}
                                        }
                                        if(count==m)
              {
                printf("Done");
                return 0;
              }
                                        if(i+1>=0&&j+1>=0&&i+1<n&&j+1<n&&!grid[i+1][j+1])     
                                        { 
                                                    grid[i+1][j+1]=1;    
                                                    res=Survey(i+1,j+1); 
                                                    if(res=='M') { count++; Neutralize(i+1,j+1);}
                                                     else if(res=='0')
                                                   {
														zero(i+1,j+1,n);
                                                   }
                                        }
                               
                                }
                       }

              if(count==m)
              {
                printf("Done");
                return 0;
              }
			}
     }
}

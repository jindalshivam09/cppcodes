#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>
#define MAX 1000001
int prime[MAX]={0};
void sieve(){
 int i,j;
 prime[0]=1;
 prime[1]=1;
 for(i=2;i<MAX;i++){
  j=2;
  if(!prime[i])                   
  while(i*j<MAX){
   prime[i*j]=1;              
   j++;               
  }                  
 }
}
void sieve_seg(int* arr,long long L,long long R){
 long long i,bal;
  if(L<2)
    arr[0]=1;       
 
 for(i=2;i<=sqrt(R);i++){
   
   if(!prime[i]){
   
      bal=L%i;     
      if(bal)
       bal=i-bal; 
      while(L+bal<=R){
       if((L+bal)!=i)
         arr[bal]=1;
         bal+=i;
      }              
  }                                             
 }    
}
int main(){
 int t,*arr,i,num;
 long count=0;
 long long L,R,power;
 sieve();
 scanf("%d",&t);   
 while(t--){
 count=0;
  scanf("%lld%lld",&L,&R); 
 // printf("%lld%lld",L,R);          
  arr=(int*)calloc((R-L+1),sizeof(int));
  sieve_seg(arr,L,R);
  for(i=0;i<R-L+1;i++){
   if(!arr[i]){
     count++;
  
   }
}
  printf("%d\n",count);          
 }   
 getch();
 return 0;    
}

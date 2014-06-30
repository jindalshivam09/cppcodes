                          //-----------------  WYTHOFF'S GAME  ------------------------//
                          //-----------     Author: Shivam Jindal      [O(1) solution]--------------//
/*   ->  there are 2 heaps n we are startinsg with ALICE ,one can either pick any no. of any heap  or equal no. of elements from both hea
         tell who wil win
     ->  simply after observation it concluded that larger heap either must be proper diviso of 13 or have remainder 0,2,5,7,10 n     
           smaller with 8 or havae remainder with 0,1,3,4,6
*/
#include<iostream>
using namespace std;
#include<conio.h>
#define ALICE 0
#define BOB 1
int checker[]={2,1,-1,1,1,-1,1,-1,0,0,-1};       //make a hash table on the basis of observation
int win(int m,int n)
{
        int mrem=m%13,nrem=n%8;
        if((!mrem||!nrem||(checker[mrem]==-1&&checker[nrem]==1))&&m!=n)        //n!=m for cases like 44 44
        return BOB;
        else return ALICE;
}
main()
{
      
      int m,n,winner;
      int t;
      cin>>t;             //test cases
      while(t--)
      { 
                cin>>m>>n;           //heaps 
                if(m>n)                               //send larger n smaller heap in proper order
                winner=win(m,n);
                else 
                winner=win(n,m);
                winner?cout<<"BOB":cout<<"ALICE";
                cout<<"\n";
      }
      getch();

}

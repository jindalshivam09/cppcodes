#include<iostream>
using namespace std;

int main() {
    
    int t;
    cin >> t;
    while(t--) {
         
         int n;
         cin >> n;
         
         if (!(n%3)) {
            for(int i=0;i<n;i++)
            cout << 5 ;
            cout << endl;            
         }           
         else {
              int i;
              for(i=1;i<=n;i++) {
                  if(!((n-5*i)%3)&&(n-5*i)>=0) 
                  break;           
              }     
//              cout << i;
              if((n-5*i)%3 || (n-5*i) < 0)
              cout << -1 ;
              else {
                  for(int j=0;j<n;j++) {
                       if(j<n-5*i)
                       cout << 5 ;
                       else
                       cout << 3;  
                  }
              }
              cout << endl;
         }
    }    
}

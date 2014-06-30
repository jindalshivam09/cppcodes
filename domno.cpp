#include<iostream>
#include<vector>
using namespace std;

int main() {

    int n;
    cin >> n;
    vector<int> dom1(n) , dom2(n);

    int sum1 = 0 , sum2  = 0;

    for(int i=0;i<n;i++) {

        cin >> dom1[i] >> dom2[i]; 
        sum1 += dom1[i] ;
        sum2 += dom2[i];
    }


    int count = 0;

    for(int i=n-1;i>=0;i--) {

    
        if( !(sum1 % 2) && !(sum2 % 2) )
        break;
        
        else if(sum1%2 && sum2%2) {

            if(dom1[i] % 2  && !(dom2[i] % 2) ) {

                sum1 = sum1 - dom1[i] + dom2[i];
                sum2 = sum2 - dom2[i] + dom1[i];
                count ++ ; 
            
            }
            else if (dom2[i] % 2  && !(dom1[i] % 2) ) {

                sum1 = sum1 - dom1[i] + dom2[i];
                sum2 = sum2 - dom2[i] + dom1[i];            
	            count ++ ; 

            }                        
        }
        else {
            
            if(dom1[i] % 2  && !(dom2[i] % 2) ) {

                sum1 = sum1 - dom1[i] + dom2[i];
                sum2 = sum2 - dom2[i] + dom1[i];
				count ++ ;
  
            }
            else if (dom2[i] % 2  && !(dom1[i] % 2) ) {

                sum1 = sum1 - dom1[i] + dom2[i];
                sum2 = sum2 - dom2[i] + dom1[i];
				count ++ ;            
            }                         
 
        }
        
//        cout << sum1 << " " << sum2 << endl;
    }    
    
    if((sum1 % 2) || (sum2 % 2))		cout << -1 << endl;
    else							    cout << count << endl;
}

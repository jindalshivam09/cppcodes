/*
	Name: Ugly Numbers
	Copyright: no rights
	Author: Shivam Jindal
	Date: 23/09/13 02:22
	Description: ugly numbers are those numbers which have only 2,3,5 as factors
*/

#include<iostream>
#include<vector>
#include<cstdlib>
using  namespace std;

int getNthUglyNo(int n)
{
    int ugly[n];
    int i2 = 0, i3 = 0, i5 = 0;
    int i;
    int next_multiple_of_2 = 2;
    int next_multiple_of_3 = 3;
    int next_multiple_of_5 = 5;
    int next_ugly_no = 1;
    *(ugly+0) = 1;
 
    for(i=1; i<n; i++)
    {
       next_ugly_no = min(next_multiple_of_2,
                           min(next_multiple_of_3,
                           next_multiple_of_5));
       *(ugly+i) = next_ugly_no;                   
       if(next_ugly_no == next_multiple_of_2)
       {
           i2 = i2+1;      
           next_multiple_of_2 = *(ugly+i2)*2;
       }
       if(next_ugly_no == next_multiple_of_3)
       {
           i3 = i3+1;
           next_multiple_of_3 = ugly[i3]*3;
       }
       if(next_ugly_no == next_multiple_of_5)
       {
           i5 = i5+1;
           next_multiple_of_5 = *(ugly+i5)*5;
       }
       cout << ugly[i] << " ";
    } /*End of for loop (i=1; i<n; i++) */
    return next_ugly_no;
}
 
int main() {

	int n;
	cin >> n;
	vector<int> ugly(n+1);
	
	ugly[0] = 1;
	int i2=0,i3=0,i5=0;
	
	
	for (int i=1;i<=n;i++) {
	
		int temp = min (2*ugly[i2],min(3*ugly[i3],5*ugly[i5]));
		
		if (temp == 2*ugly[i2]) {
		
			ugly[i] = temp;
			i2++;
		}
		if (temp == 3*ugly[i3]) {
		
			ugly[i] = temp;
			i3++;
		}
		if (temp == 5*ugly[i5]) {
		
			ugly[i] = temp;
			i5++;
		}
		cout << ugly[i] << " ";
	}
//	cout << getNthUglyNo(n) << endl;
}


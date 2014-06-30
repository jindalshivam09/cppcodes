#include<bits/stdc++.h>
using namespace std;

unsigned long long powers[26][53];

void fx()
{
	for(int i =1 ;i<=25;++i) {	
		powers[i][0] = 1; 
		for(int j =1;j<53;++j)	{
			powers[i][j] = powers[i][j-1] * i;
		}		
	}
}

int main()
{
//	ifstream in;
//	in.open("input.txt");
//	ofstream out;
//	out.open("output.txt");
	int t,i,j; unsigned long long n,rem;string str;int z,len,ndigits;

	fx();	
	cin>>t;
	for(z=1;z<=t;++z) {
		cin>>str;
		cin>>n;
		rem = n;
		len = str.size();;;	
		if(len ==1 ) 
		{
			cout << "Case #" << z << ": "; 
			for(int x=1;x<=n;++x) {
				cout<<str;
			}
			cout<<endl;
		}
		else {
			for(i=1;i<52 && powers[len][i]>powers[len][i-1];++i) {
				if( rem > powers[len][i] ) { 
					rem = rem - powers[len][i] ;
					continue;
				}
				else {		
					rem--;		
					break;
				}
			}	
			ndigits =  i-1;		
			cout<<"Case #"<<z<<": ";
			while(ndigits >= 0 ){	
				cout<<str[(int)(rem/powers[len][ndigits])];
				rem = rem % powers[len][ndigits] ;
				ndigits--;
			}
			cout<<endl;
		}
	}
}

#include<iostream>
#include<vector>
#include<limits>
using namespace std;

int main() {

	int t;
	cin >> t;
	while(t--) {
	
		int n,k,ans;
		cin >> n >> k >> ans;
		vector<int> input(n);
		for(int i=0 ;i<n ;i++)
		cin >> input[i];
		string op ;
		cin >> op;
		int a = numeric_limits<int>::max();
		
		if(k==0)	{	cout << ans << endl; }
		else {
	 		if (op == "XOR") {
				for (int i=0;i<n;i++)  {
			
					if(!i) a  = input[i];
					else
					a ^= input[i];	
	//				cout << a << " ";		
				}
	//			ans ^= a;
	//			if(k>1)
	//			ans ^= a;
	//			cout << ans << " " << a << endl;
				if(k%2)			cout << (ans^a) << endl;
				else			cout << ans << endl;
			}
			else if (op == "AND") {
				for (int i=0;i<n;i++)  {
			
					if(!i) a  = input[i];
					else
					a &= input[i];			
				}
				ans &= a;
				ans &= a;
				cout << ans << endl;
			}
			if (op == "OR") {
				for (int i=0;i<n;i++)  {
			
					if(!i) a  = input[i];
					else
					a |= input[i];			
				}
				ans |= a;
				ans |= a;
				cout << ans << endl;
			}
		}
	}
}

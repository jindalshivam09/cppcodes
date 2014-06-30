#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

int main() {
	
	int n,k;
	cin >> n >> k;
	
	vector<bool> tweets(n+1);
	int count = 0;
	
	while(k--) {
		
		string str;
		cin >> str;
		if(str == "CLICK") {
			
			int a;
			cin >> a;
//			cout << tweets[a] << endl;
//			cout << tweets[1] << endl;
			if(tweets[a]) {
				
//				cout << a << endl;
				tweets[a] = false;
				count --;
			}
			else {
				
				tweets[a] = true;
				count ++;
			}
			
		}
		else {
			count = 0;
			for(int i=1;i<=n;i++)		tweets[i] = false;
//			cout << tweets[1] << endl;
		}
		
		cout << count << endl;

	}
}

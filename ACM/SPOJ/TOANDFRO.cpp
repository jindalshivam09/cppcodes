#include<iostream>
#include<vector>
using namespace std;
vector<vector<char > > ans (201,vector<char>(200));
int main() {
	int t;
	cin >> t;
	while(t) {
		string str;
		cin >> str;
		int count = 0;
		int j=0;
		while(count < str.size()) {
			for(int i=0;i<t;i++)
				ans[j][i] = str[count++];
			j++;
			if(count<str.size()) {
				for(int i=t-1;i>=0;i-- )
					ans[j][i] = str[count++];
				j++;
			}
		}
		for(int i=0;i<t;i++)
			for(int k=0;k<j;k++)
				cout << ans[k][i];
		cout << endl;
		cin >> t;
	}
}



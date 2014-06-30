#include<iostream>
#include<cstring>
#include<vector>
using namespace std;


main() {
	int t;
	cin >> t;
	cin.get();
	while(t--) {
		vector<int > arr;
		int last[10002];
		int max=0,sum=0;;
		int count=0;
		int alp[26]={0};
		int i=0,j=0;
		char c;
		while((c=cin.get())!='\n') {
			if(c != '#') {
				alp[c-97]++;
				if(max < alp [c-97])
				max = alp[c-97];
			}
			else {
				count++;
				memset(alp,0,sizeof(alp));
				arr.push_back(max);
				j++;
				max = 0;
			}
		}
		arr.push_back(max);
		j++;
		max = 0;
		///for(int f=0;f<j;f++) 
		//cout << arr[f] << " ";
	//	cout << endl;
		if(count < 3 || j< 3)
		cout << 0 << endl;
		else {
			for(vector<int>::iterator i=arr.begin(); i!=arr.end(); i++)
			cout << *i << " ";

		}
	}
}

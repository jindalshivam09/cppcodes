#include<iostream>
#include<cstring>
using namespace std;


main() {
	int t;
	cin >> t;
	cin.get();
	while(t--) {
		int arr [10002];
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
				arr[j++] = max;
				max = 0;
			}
		}
		bool flag=false;
		arr[j++] = max;
		for(int f=0;f<j;f++) 
		cout << arr[f] << " ";
		cout << endl;
		if(count < 3)
		cout << 0 << endl;
		else {
			for(int f=0;f<j;f++) {
			//	cout << count << " " ;
				sum+=arr[f];
				if(arr[f]){
					count++;
				}
				else
				count=0;
				
				if(count==4)
				flag=true;
			}
			if(flag)
			cout << sum+3 << endl;
			else
			cout << 0 << endl;
		}
	}
}

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
		arr[j++] = max;
		for(int f=0;f<j;f++) 
		cout << arr[f] << " ";
	//	cout << endl;
		/*if(count < 3)
		cout << 0 << endl;
		else {
			for(int f=0;f<j;f++) {
				for(int q=f;q < f+4 ;q++) {
					if(arr[f]) {
						sum+= arr[f];
					}
					else {
						sum = 0;
						f = q +1;
					}			
				}
				if(max < sum)
				max =sum;
				sum = 0;
			}
			max ? cout << max + 3 : cout << max ;
			cout << endl;		
		}*/
	}
}

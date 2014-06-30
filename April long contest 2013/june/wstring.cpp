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
		max = 0;
		///for(int f=0;f<j;f++) 
		//cout << arr[f] << " ";
	//	cout << endl;
		if(count < 3 || j<3)
		cout << 0 << endl;
		else {
			int q,c;
			for(int f=0;f<j;f++) {
				c = 0;
				for(q=f;q < f+4 && q < j;q++) {
			//		cout << q << " ";
					c++;
					if(arr[q]) {
						sum+= arr[q];
					}
					else {
						sum = 0;
						//f = q + 1;
						break;
					}			
				}
			//	cout << endl ;
			//	cout << " c " << c  << endl;
				if(c<4)
				sum = 0;   
				if(max < sum)
				max =sum;
				sum = 0;
			}
			max ? cout << max + 3 : cout << max ;
			cout << endl;		
		}
	}
}

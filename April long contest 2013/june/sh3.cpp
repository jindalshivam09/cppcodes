#include<iostream>
#include<cstring>
using namespace std;
main() {
	int n;
	cin >> n;
	//cin.get();
	while(n--) {
		int hash[100002];
		int value[100002];
		char str[100002];
		int lvalue[100002];
		int rvalue[100002];
		int max=0,sum=0,MAX=0;
		int alp[26]={0};
		int i,j=0,k=0;
		cin >> str;
		i=strlen(str);
		char c;
		for(int w=0;w < i;w++) {
			c = str[w];
			if(c != '#') {
				alp[c-97]++;
				if(max < alp [c-97])
			max = alp[c-97];
			}
			else {
				hash[j++] = w;
				memset(alp,0,sizeof(alp));
				value[k++] = max;
				max = 0;
			}
		}
		value[k++] = max;
		/*for(int q=0;q<j;q++)
		cout << hash[q] << " ";
		cout << endl;
		for(int q=0;q<k;q++)
		cout << value[q] << " ";
		cout << endl;
		cout << str;
		cout << endl;*/
		max=0;
		int lk=0;
		
		memset(alp,0,sizeof(alp));
		for(int w=0;w < i;w++) {
			c = str[w];
			if(c != '#') {
				alp[c-97]++;
				if(max < alp [c-97])
				max = alp[c-97];
			}
			else {
				//hash[j++] = w;
		//		memset(alp,0,sizeof(alp));
				lvalue[lk++] = max;
			}
		}
		lvalue[lk++] = max;
		int rk=j;
		max=0;
		
				memset(alp,0,sizeof(alp));
		for(int w=i-1;w>-1;w--) {
			c = str[w];

		//	cout <<max << " ";
			if(c != '#') {
				alp[c-97]++;
				if(max < alp [c-97])
				max = alp[c-97];
			}
			else {
			 //	hash[j++] = w;
			//	memset(alp,0,sizeof(alp));
				rvalue[rk--] = max;
			//	max = 0;
			}
		}
		rvalue[0]=max;
		rk=j+1;
		/*for(int q=0;q<j;q++)
		cout << hash[q] << " ";
		cout << endl;
		for(int q=0;q<k;q++)
		cout << value[q] << " ";
		cout << endl;
		for(int q=0;q<lk;q++)
		cout << lvalue[q] << " ";
		cout << endl;
		for(int q=0;q<rk;q++)
		cout << rvalue[q] << " ";
		cout << endl;
		
		cout << str;
		cout << endl;*/
		max=0;
		for(int q=0;q<j-2;q++) {
			//cout << lvalue[q]<<value[q+2]<<value[q+1]<<rvalue[q+3] << " ";
			if(lvalue[q]&&value[q+2]&&value[q+1]&&rvalue[q+3])
			sum=lvalue[q]+value[q+2]+value[q+1]+rvalue[q+3]+3;
			if(sum > max)
			max=sum;
		}
		cout << max << endl;
		
		
		/*
		for(int q=0;q <j;q++) {
			for(int f=q;f<q+3 && f<j;f++) {
				if((!f || !count)&& hash[f] && hash[f]!= i-1)
				count++;
				else if (hash[f] != hash[f-1]+1 && hash[f] && hash[f] != i-1 && f>0)
				count++;
				else {
					count=0;
					break;
				}
		//			cout << count << " f " << f<< " c ";
			}
		//	cout << endl;
			if(count==3) {
				max=0;
				memset(alp,0,sizeof(alp));
		//		cout << "q=" << q << endl;
				for(int f=0;f<hash[q];f++) {
					c = str[f];
					if(c != '#') {
						alp[c-97]++;
						if(max < alp [c-97])
						max = alp[c-97];
					}
						
				}
		//		cout << max << " " << value[q+1] << " " << value[q+2] << " "; 
				sum = max;
				sum += value[q+1] + value[q+2];
				if(!max )
				sum = 0;
				memset(alp,0,sizeof(alp));
				max=0;
				for(int f=hash[q+2];f<i;f++) {
					c=str[f];
		//			cout << c << " " ;
					if(c != '#') {
						alp[c-97]++;
						if(max < alp [c-97])
						max = alp[c-97];
					}
						
				}
				if(sum && max)
				sum+=max;
				else
				sum=0;
				//cout << max << endl;
				if(MAX < sum)
				MAX = sum;				
				sum=0;
			}
			count=0;
		}
		MAX > 3 ? cout << MAX + 3 << endl : cout << 0 << endl;;
	}*/
}
	return 0;
}

#include<iostream>
#include<cstdlib>
using namespace std;

///////////////////////////////////////////////////////////////
// compare func for qsort

int cmp(const void *a,const void *b)
{
	return *(int *)a-*(int *)b;
}

////////////////////////////////////////////////////////////////
// swap func to swap numbers 
void swap(int *num,int k,int j) {
	int temp;
	temp=num[k];
	num[k]=num[j];
	num[j]=temp;
}

///////////////////////////////////////////////////////////////////

main() {
	int *number;
	number=(int *)malloc(sizeof(int)*10);
	char n;
	int i=0;
	n=cin.get();
	do {
	//	cout<<"hi.";
		number[i++]=n-48;		
	}while((n=cin.get())!='\n');
	int j,k;
	bool flag=false;
	//cout<<"jkl..";
	for(j=i-1;j>=0;j--){
		for(k=j-1;k>=0;k--) {
			if(number[k]<number[j]){
	//			cout<<number[k] << " " <<number[j] << endl;
				swap(number,k,j);
				flag=true;
				break;
			}
		}
		if(flag)
		break;
	}
	//cout << k;
	for(int q=0;q<=k;q++)
	number++;

	qsort(number,i-k-1,sizeof(int),cmp);
	number-=k+1;

	for(int q=0;q<i;q++)
	cout<<number[q];
}

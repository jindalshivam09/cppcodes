//----------------Longest Common Subsequence-----------------------------------
//-----------------O(mn) approach---------------------------------------------

#include<iostream>
#define MAX 1000
using namespace std;

int arr[MAX][MAX]; 								
char sub[MAX]; 											// to store subsequence

int max(int a,int b) {
	if(a>b)
	return a;
	return b;
}

char * reconstruct (const string p,const string q) {		// to construct the subsequence from array
	int m=q.length();
	int n=p.length();	
	int i=m,j=n;		// i is the row and j is the column
	int k=0;
	
	while(i>0 && j>0) {
//		cout << i << " " << j << endl;
		if(q[i-1] == p[j-1]) {
			sub[arr[m][n]- k-1] = q[i-1];
//			cout << k << " " << arr[m][n]- k << endl;
			k++;
			i--;
			j--;
		}
		else if (arr[i][j-1] > arr[i-1][j]) {
			j--;
		}
		else i--;
	}
	
	sub[k]='\0';
	return sub ;
}


char * lcs (const string p,const string q) {
	for (int i=1;i<=q.length();i++) {
		for(int j=1;j<=p.length();j++) {
			if(q[i-1]==p[j-1]) {
				arr[i][j]=arr[i-1][j-1]+1;
			}
			else {
				arr[i][j]=max(arr[i-1][j],arr[i][j-1]);
			}						
		}
	}
	return reconstruct(p,q);	
}

main() {

	string p,q;
	cout << "enter the strings: " << endl;
	cin >> p >> q;
	cout << "lcs is\n";
	cout << lcs(p,q); 
	cout << endl;
	//cout << p.length() << " " << q.length() << endl;
/*	for (int i=1;i<=q.length();i++) {
		for(int j=1;j<=p.length();j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
*/
}

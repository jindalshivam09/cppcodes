#include<iostream>
#include<fstream>
#include<istream>
#include<ostream>
#include<cstring>
bool isVowel(char *arr ) {
	int cou
	int=0;
	for(int i=0;i<strlen(arr);i++) {
		if(arr[i]=='a' || arr[i]=='A')
		count++;
		if(arr[i]=='e' || arr[i]=='E')
		count++;
		if(arr[i]=='i' || arr[i]=='I')
		count++;
		if(arr[i]=='o' || arr[i]=='O')
		count++;
		if(arr[i]=='u' || arr[i]=='U')
		count++;
	}
	if(count>=3)
	return true;
	return false;
}
using namespace std;
main() {
	ifstream input ("file.txt");
	ofstream output ("f2.txt");
	if(!input || !output){
		cout << " unable to open file" ;
	}
	bool flag=false;
	char arr[1000];
	input >> arr;
	do {
		for(int i=0;i<strlen(arr);i++) {
			if(arr[i] < 'A' || arr[i] > 'Z') {
				flag=true;
				break;
			}
		}
		if(!flag || isVowel(arr))	
		output << arr;
		output << endl ;
		flag=false;
	
	}while(input);
}

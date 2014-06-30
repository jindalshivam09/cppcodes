#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
using namespace std;

int main() {
	
	int n,m;
	cin >> n >> m;
	
	char matrix[n][m+1];
	cin.get();
	for(int i=0;i<n;i++) {
	
		gets(matrix[i]);		
	}
	
	int l;
	cin >> l;
	
	char input[n][250];
	cin.get();
	for(int i=0;i<l;i++)
	{
		cin.getline(input[i],'\n');		
	}
	
	vector<int> chars(256);
	for(int i=0;i<n;i++) {
		
		for(int j=0;j<m;j++) {
			
			char a;
			a = matrix[i][j];
			cout << a << " ";
			if(a >= 'A' && a <= 'Z'){
				
				chars[a-32]++;
			}
			else chars[a]++;
		}
	}
	
	bool flag = false;
	
	for(int i=0;i<l;i++) {

		vector<int> temp(256);		
		flag = false;
//		cin >> input[i];
//		cout << "d";
		for(int j=0;j<strlen(input[i]);j++){
		
//			cout << input[i] << " ";	
			char a;
			a = input[i][j];
			cout << a;
			if(a >= 'A' && a <= 'Z'){
				
				temp[a-32]++;
			}
			else
				 temp[a]++;
		}
		for(int k=0;k<256;k++) {
			
//			cout << temp[k] << " " << chars[k] << " g ";
			if(temp[k]!=chars[k]) {
				flag = true;
				break;
			}
		}
//		cin.get();		
		if(!flag){
			cout << input[i] << endl;
			return 0;
		}
//		cout << endl;
	}
}

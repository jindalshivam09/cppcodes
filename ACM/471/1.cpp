#include<bits/stdc++.h>
using namespace std;

int main() {
	map<int,int> arr ;
	int a ;
	for(int i=0;i<6;i++) {
		cin >> a ;
		arr[a] ++ ;
	}
	vector<int> len ;
	bool same = false, four = false ;
	for(map<int,int>::iterator itr = arr.begin() ; itr != arr.end() ; itr ++) {
		int temp = itr->second; 
		len.push_back(temp) ;		
	}
	sort(len.begin(),len.end()) ;
	if(len.size() == 1) 
		cout << "Elephant" << endl;
	else if(len.size() == 2) {
		if((len[0] == 2 && len[1] == 4) ) 
			cout << "Elephant" << endl;
		else if ( len[0] == 1 )
			cout << "Bear" << endl;
		else
			cout << "Alien" << endl;	
	}
	else if(len.size()==3) {
		if((len[2] == 4 && len[0] == len[1])   )	
			cout << "Bear" << endl;
		else
			cout << "Alien" << endl;
	}
	else
		cout << "Alien" << endl;
	
}

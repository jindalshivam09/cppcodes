#include<bits/stdc++.h>
using namespace std;

vector<int> lcd(10), arr ;
int full ;
void init() {
	lcd[0] = 126;
	lcd[1] = 48;
	lcd[2] = 109;
	lcd[3] = 121;
	lcd[4] = 51;
	lcd[5] = 91;
	lcd[6] = 95;
	lcd[7] = 112;
	lcd[8] = 127;
	lcd[9] = 123 ;
	full = 127 ;
}

void display(int a) {
	vector<int> str ;
	while(a) {
		str.push_back(a%2) ; ;
		a /= 2 ;
	}
	for(int i=str.size()-1;i>=0;i--)
		cout << str[i] ;
	cout << endl;
}

string func() {
	string ans ; 
	int cnt =0 , broken,value;
	for(int i=0;i<10;i++) {
		int temp = (full^lcd[i]) ;
		if( temp & arr[0] )
			continue ;	
		int bad = (lcd[i]^arr[0]) ;
		int val = i-1,j=1;
		if(val<0)
			val = 9 ;
		if(arr.size()==1) {
			cnt ++ ;
			value = i ;
			broken = bad ;
		}
		else {
			cout << i << endl;
			bool flag = false;
			for(j=1;j<arr.size();j++) {
				if( (bad & arr[j]) || (arr[j] & (full^lcd[val])))  {
					flag = true;
					break;
				}
				bad |= (lcd[val]^arr[j]) ;			
				val -- ;
				if(val<0)
					val = 9 ;
			}
			if(flag == false) {
				cnt ++ ;
				value = val ;
				broken = bad ;
	 		}
	 	}
	}
	if(cnt == 1) {
		string str ;
		int temp = lcd[value] & (full^broken);
		for(int i=0;i<7;i++)
			str.push_back(char(temp%2 + '0')) , temp/= 2;
		reverse(str.begin(),str.end());
		return str ;	
	}
	return "ERROR!";
}

int main() {
//	ifstream cin("input.txt") ;
//	ofstream cout("output.txt") ;
	init() ;
	int t ;
	cin >> t ;
	for(int test=1;test<=t;test++) {
		int n ;
		cin >> n ;
		cout << n << endl;
		arr.resize(n) ;
		string str;
		for(int i=0;i<n;i++) {
 			cin >> str ;
 			cout << str << " " ;
			int val = 0 ;
			for(int j=0;j<str.size();j++) {
				val = (val)*2 + str[j]-'0'; 
			}
			arr[i] = val ;
		}
		cout << endl;
		cout << "Case #" << test << ": " << func() << endl;
	}
}

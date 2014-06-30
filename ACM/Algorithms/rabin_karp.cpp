/*
	Name: Rabin Karp String Matching Algorithm
	Copyright: no rights
	Author: Shivam Jindal
	Date: 28/09/13 16:20
	Description: 
*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

#define MAX 100
#define MOD 1000000007

int rabin_karp (const string &t,const string &p , const vector<int> &text,const vector<int> &pattern ,int radix) {
	
	int s = p.size();
	int vp = pattern[s-1],vt = text[s-1];
	int q =1;
	for(int i=0;i<s-1;i++)
	q *= radix;
//	cout << q << radix << endl;
	
	for (int i = s-1 ; i < t.size() ; i++ ) {

//		cout << vp << " " << vt << " " << i << endl;		
		if (vp==vt) {
		
			bool flag = false;
			for (int j=0;j<s;j++) {

//				cout << t[i-s+j+1] << " " << p[j] << endl;				
				if(t[i-s+j+1] != p[j]) {
				
					flag = true;
					break;
				}
			}
			if(!flag)
			return i-s+1;
		}
		
		else if(i<t.size()-1){
//			cout << t[i-s+1] << " " << t[i+1] << endl;
			vt = ((vt - q*(t[i-s+1]-96))*radix + t[i+1]-96)%MOD ;  
		}
 	}
 	return -1;
	
} 

int main() {
	
	string t,p;
	cin >> t ;
	cin >> p ;
	int radix = 26;
	int q = MOD ;
	
	vector<int> text(MAX),pattern(MAX);
	
	int temp = 0;
	for(int i=0; i<t.size() ; i++) {
		
		text[i] = temp = (temp*radix + t[i]-96) % MOD ;
//		cout << text[i] << endl;
	}
	
	temp = 0;
	for(int i=0; i<p.size() ; i++) {
		
		pattern[i] = temp = (temp*radix + p[i]-96) % MOD ;
//		cout << pattern[i] << endl;
	}
	
//	cout << "calling functions...";
	cout << "pattern matching occurs at " << rabin_karp(t,p,text,pattern,radix);
}


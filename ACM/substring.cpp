/*
	Name: KMP (Knuth Morris Pratt)
	Copyright: no rights
	Author: Shivam Jindal
	Date: 14/11/13 01:58
	Description: using longest prefix and suffix of string 
*/

#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <algorithm>
#include <set>
#include <limits>
#include <cstdlib>
#include <cstdio>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

//#define rep(n)   for(int i=0;i<n;i++)
//#define rep(k,n) for(int i=k;i<n;i++) 
#define mp make_pair
#define MAX 1000000


vi prefix(MAX), start,last ;

void prefix_func (const string &text, const string &pattern ) {
	
	prefix[0] = 0;	
	int k = 1 , len = 0;
	while ( k < pattern.size() ) {
		
		if ( pattern[len] == pattern[k] ) {
			
			len++;
			prefix[k++] = len;
		}
		else {
			
			if ( len )
				len = prefix[len-1];
			else
				prefix[k++] = 0;
		}
	}
//	for(int i=0;i<pattern.size();i++)
//		cout << prefix[i] << " ";
//	cout << endl;
}

void kmp ( const string &text , const string &pattern ,bool flag) {
	
	prefix_func (text,pattern);
	
	int t = text.size();
	int p = pattern.size();
	int i=0,j=0;
//	cout << text << " " << pattern << endl;
	while ( i < t ) {
		
		if ( pattern[j] == text[i] ) {
			
			i++;
			j++;
		}
		else {
			
			if(j)
				j = prefix[j-1];
			else
				i++;
		}
		if ( j == p ) {
			if(flag == true )
				start.push_back( i-j );
			else
				last.push_back(i-j);
		}
	}
//	return -1;
}

int main() {
	string str , t1 , t2;
	while(cin >> str) {
		cin >> t1 >> t2 ;
		kmp(str,t1,true);
		kmp(str,t2,false);
		int count = 0 ;
		map<int,int> lengths ;
		for(int i=0;i<start.size();i++) {
			for(int j=0;j<last.size();j++) {
				int len = last[j] - start[i] ;
				if (len >= 0 && !lengths[len]) {
					lengths[len] = 1;
					count ++ ;
				}
			}
		}
		start.clear() ; 
		last.clear();
		cout << count << endl;
	}
}

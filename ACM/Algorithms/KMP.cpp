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


vi prefix(MAX), occurences ;

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
	for(int i=0;i<pattern.size();i++)
		cout << prefix[i] << " ";
	cout << endl;
}

void kmp ( const string &text , const string &pattern ) {
	
	prefix_func (text,pattern);
	
	int t = text.size();
	int p = pattern.size();
	int i=0,j=0;
	
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
			occurences.push_back( i-j );
		}
	}
//	return -1;
}

int main() {
	int t ;
	while(cin >> t) {
		string text , pattern;
		pattern.reserve(t+1) ;
		cin >>  pattern >> text;
		kmp(text,pattern);
		for(int i=0;i<occurences.size();i++)
			cout << occurences[i] << endl;	
		occurences.clear();
	}
}

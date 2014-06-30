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
#include <utility>
#include <iomanip>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cstring>

using namespace std;

typedef long long 		ll;
typedef vector<int> 	vi;
typedef pair<int,int> 	pii;	

#define rep(n)    		for(int i=0;i<n;i++)
#define repi(k,n) 		for(int i=k;i<n;i++) 
#define mp 				make_pair
#define pb			 	push_back
#define all(a) 			a.begin(),a.end()
#define imax  			numeric_limits<int>::max()
#define imin 			numeric_limits<int>::min()
#define MAX 1000000


vi prefix(MAX);

void prefix_func (const string &text, const string &pattern ) {
	
	prefix[0] = 0;	
	int k = 1 , len = 1;
	while ( k < pattern.size() ) {
		
		if ( pattern[len+1] == pattern[k] ) {
			
			prefix[k++] = len++;
		}
		else {
			
			if ( len )
				len = prefix[len-1];
			else
				prefix[k++] = 0;
		}
	}
}

int kmp ( const string &text , const string &pattern ) {
	
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
			
			return i-j+1;
		}
	}
	return -1;
}

int main() {
	
	int t;
	cin >> t;
	while(t--) {
		
		int n;
		cin >> n;
		int a,b;
		
		cin >> a;
		string text;
		int j=0;
		for(int i=1;i<n;i++) {
			
			cin >> b;
			if(b-a > 0 )		text.append("G");
			else if (b-a < 0)	text.append("L");
			else				text.append("E");
			a = b;
		}
//		cout << text;
		string pattern;
		cin >> pattern;
		
		if(kmp(text, pattern)!=-1)		cout << "YES" << endl;
		else							cout << "NO" << endl;
	}
}

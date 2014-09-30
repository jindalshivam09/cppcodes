#include<bits/stdc++.h>
using namespace std;
#define MAX 200009
vector<int> text(MAX), pattern(MAX);
int t,p ;


vector<int> prefix(MAX);
int occurences ;

void prefix_func ( ) {
	
	prefix[0] = 0;	
	int k = 1 , len = 0;
	while ( k < p ){
		
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
}

void kmp (  ) {
	
	prefix_func ();
	
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
		if (  j==p ) {
			j = prefix[j-1] ;
			occurences ++;
		}
	}
//	return occurences;
}

int main() {
	cin >> t >> p  ;
	int a, pre;
	for(int i=0;i<t;i++) {
		cin >> a ;
		if(i)
			text[i-1] = pre-a;
		pre = a;
	}
	for(int i=0;i<p;i++) {
		cin >> a;
		if(i)
			pattern[i-1] = pre-a;
		pre =a ;
	}
	if(p == 1) {
		cout << t << endl;
		return 0;
	}
	t--, p--;
//	cout << kmp() << endl;
	kmp() ;
	cout << occurences << endl ;
}

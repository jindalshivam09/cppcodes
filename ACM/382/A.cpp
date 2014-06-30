#include <bits/stdc++.h>
using namespace std;

typedef long long 		ll;
typedef list<int> 	li;
typedef vector<int> 	vi;
typedef vector<double> 	vd;
typedef vector<long long> 	vll;
typedef vector<bool> 	vb;
typedef pair<int,int> 	pii;
typedef vector<pair<int,int> > vpii;
typedef pair<double,double> 	pdd;
typedef vector<pair<double,double> > vpdd;

#define rep(i,n)    		for(int i=0;i<n;i++)
#define repi(i,k,n) 		for(int i=k;i<n;i++)
#define mp 				make_pair
#define pb			 	push_back
#define all(a) 			a.begin(),a.end()
#define imax  			numeric_limits<int>::max()
#define imin 			numeric_limits<int>::min()
#define dmax            numeric_limits<double>::max()
#define dmin            numeric_limits<double>::min()

int main() {
	string str1 , str2;
	cin >> str1 >> str2 ;
	int sec2 = str2.size() , sec1 = str1.size();
	int left=0 , right;
	while(str1[left]!='|')
		left++;
	right = sec1 - left - 1;
//	cout << left << " " << right << endl;
	int mid = (left+right+sec2)/2;
	if ( right == left && sec2%2 )
		cout << "Impossible" << endl;
	else if( (right+left+sec2)%2==0 ) {
		if(mid>=left && mid>=right){
			int i=0,j=0;
			int temp=0;
			for(i=0;i<left;i++)
				cout << str1[i];
			for(j=0;j<mid-left;j++)
				cout << str2[temp++];
			cout << "|";
			for(i=left+1;i<sec1;i++)
				cout << str1[i];
			for(;j<sec2;j++)
				cout << str2[j];
			cout << endl;
		}
		else
			cout << "Impossible" << endl;
	}
	else
		cout << "Impossible" << endl;
}



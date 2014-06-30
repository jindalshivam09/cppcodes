	#include <vector>
	#include <list>
	#include <map>
	#include <iostream>
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
		int t;
		cin >> t;
		while(t--) {
			string str;
			cin >> str;
			int  len = str.size();
			bool allnine = true;
			for(int i=0;i<len;i++) {
				if(str[i]!='9')
					allnine = false;
			}
			if(len==1) {
				if(str[0]=='9') 
					cout << "11" << endl;
				else {
					str[0]++;
					cout << str[0] << endl;
				}
				continue;
			}
			if(allnine) {
					cout << "1";
					for(int i=0;i<len-1;i++)
					cout << "0";
					cout << "1";
					cout << endl;
					continue;
			}
			
			bool flag = false;
			for(int start=0,end=len-1;start<end;start++,end--) {			
				if( str[start] > str[end] ) 					flag = false;
				else if( str[start] <= str[end] )				flag = true;
				str[end] = str[start];
			}
	//		cout << str << " " << len << endl;
	//		cout << flag << endl;
			if(flag) {
				int mid = len/2;
	//			cout << mid << endl;
				if(len%2) {
					if(str[mid] == '9') {
						str[mid] = '0';
						int temp = 1;
						bool  nine = true;
						while(str[mid-temp] == '9' && mid+temp < len) {
							str[mid-temp] = str[mid+temp] = '0';
							temp++;
						}
						if(mid+temp < len) {
							str[mid+temp]++;
							str[mid-temp]++;
							nine = false;
						}
						if ( nine ) {
							str.append("1");
							str.insert(0,"1");
						}
						
					}
					else 
						str[mid]++;
	//				cout << "shivamjindal";
				}
				else {
					if(str[mid]=='9') {
						int temp = 0;
						bool nine = true;
						while(str[mid-1-temp]=='9') {
							str[mid+temp] = str[mid-1-temp] = '0';	
							temp++;				
						}
						if(mid+temp < len) {
							str[mid+temp]++;
							str[mid-1-temp]++;
							nine = false;
						}
						if ( nine ) {
							str.append("1");
							str.insert(0,"1");
						}
	
					}
					else {
						str[mid]++;
						str[mid-1]++;
	//					cout << "shivam";
					}
				}	
			}
			cout << str << endl;
		}
	}
	


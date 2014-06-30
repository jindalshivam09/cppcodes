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

class BusinessTasks {
	public:
		string getTask(vector<string> &str,int n) {
			vector<bool> arr(str.size());
			int size = str.size() , temp, pos = -1;
			while(size>1) {
				temp = n%size;
				if(!temp)
					temp = size;
				cout << "temp" << temp << endl;
				for(int i=0;i<temp;) {					
					pos++;
					pos %= str.size();
					if(arr[pos]==false) {
						i++;
						cout << " (  " << pos << " ) ";
					}
					cout << pos << " ";
				} 
				arr[pos] = true;
				size--;
			}
			for(int i=0;i<str.size();i++)
				if(arr[i]==false)
					return str[i];
			return string("fds");
		} 
};

int main() {
	int n;
	cin >> n;
	vector<string > str(n);
	rep(i,n)
		cin >> str[i];
	int k;
	cin >> k;
	BusinessTasks a;
	cout << a.getTask(str,k);
}



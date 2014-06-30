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

void foo( char *data) {
	char buf[5];
	printf("stack : \n%p\n%p\n%p\n%p\n%p\n%p\n%p\n%p\n%p\n%p\n%p\n%p\n%p\n");
	char temp[] = {0x10,0x14,0x40};
//	cout << temp << endl;
//	cout << data << endl;
	strcat(data,temp);
//	cout << data << endl;
	strcpy(buf,data);
	//  *( buf + 40 )  = bar ;
//	strcat (buf,temp);
//	cout << buf << endl;
	printf("after data : \n%p\n%p\n%p\n%p\n%p\n%p\n%p\n%p\n%p\n%p\n%p\n%p\n%p\n");	
}

void bar() {
	cout << "hehe,hacked :)" ;
	return ;
}

int main(int argc,char *argv[]) {
	char input[] = {"aaaaaaaaaaaaaa"};
//	cin >> input ;
	printf("foo : %p\n",foo);
	printf("bar :%p\n",bar);
	foo(input);
}

// input : aaaaaaaaaaaaaa

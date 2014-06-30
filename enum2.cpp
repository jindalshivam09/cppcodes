#include<iostream>
#include<cstring>
using namespace std;
main() {
	enum ENUM {a,b,c,d};
	ENUM e=(ENUM)3;
	cout<<"a "<<e<<" shivam \0shivam ";
	char str[]="shivam'\0 ' jindal";
	cout<<str<<strlen(str);
}

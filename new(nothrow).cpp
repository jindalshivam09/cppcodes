#include<iostream>
#include<cstdlib>
#include<new>
using namespace std;
void * operator new [] (size_t t, const nothrow_t &n) {
	void *p=malloc(t);
	cout<<"memory:";
	if ( !p ) {
		cout << "No memory found ";
	}
	return p;
	
}
int main()
{
	int *p =new(nothrow)  int[1000000000000000000000000000000000000000000000000000000];        //nothrow will not allow new to throw exception
}

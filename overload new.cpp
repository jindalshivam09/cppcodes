#include<iostream>
#include<conio.h>
#include<stdlib.h>
using namespace std;
void* operator new(size_t size)
{
	void *p;
//	cout<<"hi";
	p=malloc(size);
	cout<<*((int *)p);
	return p;
}
void operator delete(void *p)
{
	free(p);
};
main()
{
	void *p;
	p=new int;
	*(int*)p=1;
	
	cout<<endl<<*((int*)p);
	delete p;
	getch();
}

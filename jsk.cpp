#include<iostream>
using namespace std;
main(){
	int a=4;
	const int h=a;
	cout<<h;
	int q;
	int *w=&q;
	cout<<" "<<q<<" "<<w;
}

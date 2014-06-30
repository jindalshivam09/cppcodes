#include<iostream>
#include<memory>
using namespace std;


int main()
{
	int a;
	auto_ptr<int> ob(&a);
	cout<<ob;

}

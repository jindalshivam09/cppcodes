#include<iostream>
#include<stdio.h>

#define MACRO printf("hi");
//#undef MACRO
using namespace std;
main()
{
	//label:
		#undef MACRO
	#define MACRO printf("hey")
	//#undef MACRO
	MACRO;
	//#undef MACRO
	//goto label;
//	#undef MACRO
	//printf("my name is %s T%s",2);
	int a;
	//MACRO
	cin>>a;
}

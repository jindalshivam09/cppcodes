//----------Program Name: templates ----------------------
//------------Author: Shivam Jindal(jindalshivam09)---------
//------------Date:------------------------
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#define MOD 1000000007
using namespace std;

//----------------------------------------
#define SIZE_ERROR 4

//----template----------------------

template<class c,int i> class STRING
{
		c array[i];
		int size;
		public:
			STRING():size(i)
			{}
			template<class d,int a> friend void operator =(STRING<char d,int a> , STRING<char d,int b> );

};
template<class c,int i>void operator=(STRING<char d,int a> , STRING<char d,int b>)
{
			try
			{
					if(str2.size>str.size)
					throw SIZE_ERROR;
			}
			catch(int a)
			{
					cerr<<"Error: Size of destination array is smaller\n";
			}
			for(int j=0;j<str.size;j++)
			{
					str.array[j]=str2.array[j];
			}
}


main()
{
	STRING<char,5> str;
	STRING <char ,n> name;
	str=name;
    return 0;
}

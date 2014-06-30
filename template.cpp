#include<iostream>
#include<cstring>
#include<conio.h>
#include<vector>
#define MAX 10
using namespace std;
template<class t> class str
{
	t name;
	public:
		str(t enter=0)
		{
			name=enter;
		}
		str(t *enter)
		{
				strcpy(name,enter);
		}
		void display()
		{
			cout<<name;
		}
};
main()
{
	int t=9;
	str<int > INT(t);
	//str<char > CHAR("shivam");
	INT.display();
	//CHAR.display();
	//getch();
}

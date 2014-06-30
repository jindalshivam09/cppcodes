// Sir somehow i am just able to run this program but i am not unable to know about the arguments to be passed in set_terminate()
// i tried to learn it from book but unable to understand again

#include<iostream>
#include<cstdlib>
#include<exception>
using namespace std;
void userDefined()
{
	cout<<"userDefined ";
	exit(1234);
}
main()
{
	set_terminate(userDefined);                    //to change the terminate handler(set_terminate)
	set_unexpected(userDefined);
	try
	{
        cout<<boolalpha<<uncaught_exception()<<"hi"<<endl;					// uncaught_exception return true if exception is caugth else false
		throw 4.5;								// in this case userDefined terminate() func will be called
	}
	catch(int)
	{
		cout<<uncaught_exception();
		cout<<endl<<"int";
	}
	/*catch(...)
	{
		cout<<"...";
	}*/
}

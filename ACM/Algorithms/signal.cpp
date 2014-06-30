#include <iostream>
#include <csignal>
#include<cstdlib>
#include<cstdio>
using namespace std;

void signalHandler( int signum )
{
    cout << "Interrupt signal (" << signum << ") received.\n";

	exit(signum);

}

int main ()
{
    // register signal SIGINT and signal handler  
    signal(SIGINT, signalHandler);  

    while(1){
       cout << "Going to sleep...." << endl;
       for( int i =0;i<1000000000;++i)
       {
       	int  j = 56;
       	
       }
       raise( SIGINT);
    }

    return 0;
}

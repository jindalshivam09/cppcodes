#include<iostream>
using namespace std;
main()
{
         FILE *fp=fopen("File handling.cpp","r");
         if(!fp)
         {
                cout<<"Error";     
         }
         char c;
         while((c=fgetc(fp))!=EOF)
         cout<<c;
         cin.get();
}

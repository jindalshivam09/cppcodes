#include<iostream>
#include<string>
using namespace std;
void func(char s[][10])
{
}
main()
{
     char sr[2][10]={"Shivam","Jindal" };
     cout<<*sr
           <<'\t'
          <<*(sr+1);      
     cin.get();
     string s1,s2;
     func(sr);
     s1="shivam";
     s2="jindal";
     cout<<s1<<s2;
     s1=s2;
     cout<<s1<<endl<<s2;
     cin.get();
}

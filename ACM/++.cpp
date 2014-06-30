#include<iostream>
using namespace std;
long Function(int x, int y = 5, float z = 5)
{
return(++x * ++y + (int)++z);
}
int main()
{
cout<< Function(20, 10);
return 0;
}

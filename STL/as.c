#include<stdio.h>
void foo()
{
fork();
if(fork() || !fork())
printf("Hello World");
}
main()
{
foo();
}

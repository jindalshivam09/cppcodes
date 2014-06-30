#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
struct sample
{
	int r;
	int w;
	char q;
}*s,*t;
main()
{
	s=(struct sample *)malloc(sizeof(struct sample));
	s->r=1;
	s->w=5;
	s->q='t';
	printf("%d %d %c ",s->r,s->w,s->q);
	t=s;
	printf("%d %d %c ",t->r,t->w,t->q);
	printf(" %p %p",s,t);
	cin.get();
}

#include<iostream>
#include<list>
#include<string>
#include<conio.h>
#define MAX 10
using namespace std;
struct nme{
	int n;
	char name;
	nme *link;
};
nme stru;
main()
{
	/*for(int i=0;i<3;i++)
	cin>>stru[i].n>>stru[i].name;*/
	list<nme> stru;
	typedef list<nme>::iterator L;
	int j=0;
	for(L i=stru.begin();j<3;i++,j++)
	{
			 nme &e=*i;
			 cin>>e.n>>e.name;
	}
	
	
	j=0;
	for(L i=stru.begin();j<3;i++,j++)
	{
		cout<<" hi ";
		nme&e=*i;
		cout<<e.n<<" "<<e.name;
	}
	getch();
}

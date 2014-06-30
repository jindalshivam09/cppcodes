#include<iostream>
#include<list>
using namespace std;

//typedef list < pair <int , pair < node , node > > > node; 
//typedef list<pair <int,int> > node;

typedef struct n {
	
	int value;
	struct n *l,*r;	
} node;

int main() {

	list<int> i,j ;
//	i.push_back(1);
//	j  = i;
//	node n[4];
//	n[0].push_back ( make_pair ( 4 , make_pair(i,j) ) );
//	n[1].push_back (make_pair ( 4 , make_pair(i,j) ));
//	list<int>::iterator i = l.begin() , j = i ;
	cout <<  *(i.begin());
//	pair<int , pair <list<int> , list<int>  > > p = *(n.begin());
//	cout << (*(n.begin())).first;
}

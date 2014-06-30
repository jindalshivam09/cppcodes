#include<iostream>
#include<map>
#include<algorithm>
using namespace std;
class cmp {
	public :
		bool operator() (int a,int b) {
			return a>b;
		}
};
void print(pair<int,int> p) {
	cout << p.first  << " " << p.second << endl;
}
main() {
	map <int,char> m;
	map <int,char >::key_type f;
	map <int,int,cmp> t;                  // why giving error
	map <int,int> g(t.key_comp());				// with t.key_comp()

	g.swap(t);

	int j;
	for(int i=0;i<4;i++)
	cin >>  t[i];
	pair<map<int,int>::iterator,bool> pr=t.insert(make_pair(2,142))	;  // it will not work as there is already a entry corresponding to key=2 in map t
	cout << boolalpha << pr.second << endl;						
	map<int,int >::iterator i=t.begin()++;;
//	t.erase(2);          /// is error if i=m.end(); then use erase(i,m,end());
	for_each(t.begin(),t.end(),print);
	//	cout << f << endl << t;;

	//cout << g[4];
	}

#include<iostream>
using namespace std;
class abcd
{
	int a,b,c;
 public:
	 ~abcd()
     {
				delete &a;
     }
};
main()
{
	abcd ob[10];
	cout<<sizeof(ob);
	int r;
	cin>>r;
}

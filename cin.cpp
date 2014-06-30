#include<iostream>
using namespace std;
class abc {
	public :
		private:
	int a;
	public :
		abc(int i=0):a(i)
		{}
};

istream & operator >> (istream & cin ,abc &ob) {
	cin >> ob.a;
}
main() {
	abc ob;
	cin >> ob.a;
}

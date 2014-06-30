#include<iostream>
#include<bitset>
using namespace std;
main()
{
	bitset<10> bits(7);
	
	cout<<bits.any()<<endl;           // to count if there is any one in bits
	cout<<"counter: "<<bits.count();
	bits=bits.flip();
	cout<<"\ncounter: "<<bits.count()<<endl;
/*	bits=bits.reset();
	cout<<"\ncounter: "<<bits.count();
	bits=bits.set(2,0);
	cout<<"\ncounter: "<<bits.count()<<endl;
*/	cout<<bits[1320]<<endl;
	cout<<bits.size()<<endl;
	cout<<bits.to_ulong()<<endl;
	cout<<bits.to_string();
}

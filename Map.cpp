#include<iostream>
#include<map>
using namespace std;
main()
{
	int value;
	char key;
	map<char,int> MAP;
	map<char,int>::iterator p=MAP.begin(),ptr=MAP.begin();
	for(int i=0;i<5;i++)
	{
		cout<<"key n value? :";
		cin>>key>>value;
		MAP.insert(pair<char,int>(key,value));
		ptr++;
	}
	ptr--;
	cout<<ptr->second;
	pair<char,int> PAIR('f',7);
	// MAP.clear();          -> to clear the map
	cout<<" "<<boolalpha<<MAP.empty()<<endl;
	//MAP.erase(ptr);
	cout<<MAP.size()<<endl;
	cout<<MAP[PAIR.first]<<endl;
	for(p=MAP.begin();p!=MAP.end();p++)
	{
		cout<<p->first<<" "<<p->second<<endl;
	}
	cout<<"press any key :";
	char c;
	cin>>c;
	p=MAP.find(c);
	if(p!=MAP.end())
	cout<<p->first<<" "<<p->second<<endl;
	else
	cout<<"no result found";
	while(2);
}

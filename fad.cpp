#include<iostream>
#include<map>
using namespace std;

int main()
{
	int n;
	cin>>n;
	map<int,int> smaller;
	
	int a;
	cin>>a;
	smaller[a]++;
	for(int i=0;i<n-1;i++)
	{
		
		int a;
		cin>>a;
		
		if(!smaller[a])
		{
			map<int,int>::iterator x=smaller.find(a);
			if(x!=smaller.begin())
				x--;
			cout << x->first << " ";
			if(x->second)
				x->second--;
			if(x->second==0)
				smaller.erase(x);
			smaller[a]++;
		}
	}
	for(map<int,int>::iterator itr = smaller.begin() ; itr != smaller.end() ; itr++)
		cout << itr->first << " " ;
	cout<<smaller.size();
}

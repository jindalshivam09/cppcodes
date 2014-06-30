#include<iostream>
#include<math.h>
using namespace std;
main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int minDis=0;
		int bombs;
		cin>>bombs;
		int squad[2];
		int pos[bombs][2];
		cin>>squad[0]>>squad[1];
		for(int i=0;i<bombs;i++)
		{
			cin>>pos[i][0]>>pos[i][1];
		}
		for(int i=0;i<bombs;i++)
		{
			int x=pos[i][0]-squad[0];
            int y=pos[i][1]-squad[1];
		//\	cout<<x<<" \" "<<y<<endl;

			if(x<0)
			 x*=-1;
			if(y<0)
			y*=-1;
			minDis+=2*(x+y);
			//cout<<minDis<<endl;

		}
		cout<<minDis<<endl;
	}
	return 0;
}

#include<iostream>
using namespace std;
        
		#define right _right
		#define left _left                          
long long top,up,down,sum,temp,bottom,right,left;

void move_d()
{
	//	cout<<"\nMoving down";	
	temp=top;
	
	top=up;
	up=bottom;
	bottom=down;
	down=temp;
	
	sum += top;
	//cout<<"\nSum="<<sum;
	
}

void single_l()
{
	
	//cout<<"\nMoving single left";	
	temp=top;
	top=right;
	right=bottom;
	bottom=left;
	left=temp;
	
	sum += top;
	//cout<<"\nSum="<<sum;
	
}

void single_r()
{
	//cout<<"\nMoving singhle right";	
	temp=top;
	top=left;
	left=bottom;
	bottom=right;
	right=temp;
	
	sum += top;
	//cout<<"\nsum="<<sum;	
}

void move_l(long long n)
{
	
	sum += (n/4) * 14;
//	cout<<"\nMoving left";
//		cout<<"\nSum="<<sum;;	
	for(long long i=0;i< n%4;++i) single_l();
	
	
	
}

void move_r(long long n)
{
//	cout<<"\nMoving rught";	
	sum += (n/4) * 14;
//	cout<<"\nSum="<<sum;;	
	for(long long i=0;i< n%4;++i) single_r();	
}


int main()
{
	long long r,c;
	cin>>r>>c;
	
	top=2;
	bottom=5;
	right=3;
	left=4;
	up=1;
	down=6;
	sum=0;
	
	for(long long i=0;i<r;++i)
	{

		move_d();
		
		if(i%2==0)
		move_r(c-1);
		
		else 
		move_l(c-1);
		
		
		
	}
	
	cout<<sum<<endl;
	
	
	return 0;
}

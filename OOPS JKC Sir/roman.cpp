#include<iostream>
#include<cstring>
#include<conio.h>
#define MAX 10
using namespace std;
enum numera{
			M=1000,
			D=500,
			C=100,
			L=50,
			X=10,
			V=5,
			I=1
};
char hashMap2[9][5]={"I","II","III","IV","V","VI","VII","VIII","IX"};
int  hashMap[26]={0,0,100,500,0,0,0,0,1,0,0,50,1000,0,0,0,0,0,0,0,0,5,0,10,0,0};
class roman
{
	char rom[MAX];
	int intEquiv;
	public:
		roman()
		{}
		roman(char *arr)
		{
				int i=0;
				while(arr[i]!='\0')
				{
				   rom[i]=arr[i];
				   //cout<<arr[i]<<" "<<rom[i]<<" ";
				   i++;
				}
			//	cout<<endl;
				rom[i]='\0';
				intEquiv=convertToInt();
		}
		int convertToInt()
		{
			int len=0,i=0;
			int intEq=0;
			int right=0;
			while(rom[i++]!='\0')
			len++;
			for(int i=len-1;i>=0;i--)
			{
					if(hashMap[rom[i]-65]>=right)
					{
						  intEq+=hashMap[rom[i]-65];
					}
					else
					intEq-=hashMap[rom[i]-65];
					right=hashMap[rom[i]-65];
			//	cout<<right;
			}
			return intEq;
		}
		roman intToRoman(int ans)
		{
			int quo;
			int i=-1;
			roman r;
			//-------M---------
			quo=ans/M;
			if(quo)
			{
				for(int j=0;j<quo;j++)
				r.rom[++i]='M';
				ans%=M;
			}
            //-------D---------
			quo=ans/D;
			if(quo)
			{
				for(int j=0;j<quo;j++)
				r.rom[++i]='D';
				ans%=D;
			}
			//-------C---------
			quo=ans/C;
			if(quo)
			{
				for(int j=0;j<quo;j++)
				r.rom[++i]='C';
				ans%=C;
			}
			//-------L---------
			quo=ans/L;
			if(quo)
			{
				for(int j=0;j<quo;j++)
				r.rom[++i]='L';
				ans%=L;
			}
			//-------X---------
			quo=ans/X;
			if(quo)
			{
				for(int j=0;j<quo;j++)
				r.rom[++i]='X';
				ans%=X;
			}
			r.rom[++i]='\0';
			if(ans)
			{
				  strcat(r.rom,hashMap2[ans-1]);
			}
			return r;
			
		}
		roman operator +(roman r)
		{
			 int a=intEquiv,b=r.intEquiv;
			 int ans=a+b;
			 return intToRoman(ans);
		}
		void display()
		{
			int i=-1;
			while(rom[++i]!='\0')
			cout<<rom[i];
		}

};
main()
{
	char str[10],str2[10];
	cin>>str>>str2;
	roman romNumeral(str);
	roman romNumeral2(str2);
	roman romNumeral3=romNumeral+romNumeral2;
	romNumeral3.display();
	getch();
}

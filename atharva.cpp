#include<stdio.h>
#include<conio.h>
#include<math.h>
#define e 2.71
using namespace std;

float zzz[31][10]={\
0.0000,0.0040,0.0080,0.0120,0.0160,0.0199,0.0239,0.0279,0.0319,0.0359,\
0.0398,0.0438,0.0478,0.0517,0.0557,0.0596,0.0636,0.0675,0.0714,0.0753,\
0.0793,0.0832,0.0871,0.0910,0.0948,0.0987,0.1026,0.1064,0.1103,0.1141,\
0.1179,0.1217,0.1255,0.1293,0.1331,0.1368,0.1406,0.1443,0.1480,0.1517,\
0.1554,0.1591,0.1628,0.1664,0.1700,0.1736,0.1772,0.1808,0.1844,0.1879,\
0.1915,0.1950,0.1985,0.2019,0.2054,0.2088,0.2123,0.2157,0.2190,0.2224,\
0.2257,0.2291,0.2324,0.2357,0.2389,0.2422,0.2454,0.2486,0.2517,0.2549,\
0.2580,0.2611,0.2642,0.2673,0.2704,0.2734,0.2764,0.2794,0.2823,0.2852,\
0.2881,0.2910,0.2939,0.2967,0.2995,0.3023,0.3051,0.3078,0.3106,0.3133,\
0.3159,0.3186,0.3212,0.3238,0.3264,0.3289,0.3315,0.3340,0.3365,0.3389,\
0.3413,0.3438,0.3461,0.3485,0.3508,0.3531,0.3554,0.3577,0.3599,0.3621,\
0.3643,0.3665,0.3686,0.3708,0.3729,0.3749,0.3770,0.3790,0.3810,0.3830,\
0.3849,0.3869,0.3888,0.3907,0.3925,0.3944,0.3962,0.3980,0.3997,0.4015,\
0.4032,0.4049,0.4066,0.4082,0.4099,0.4115,0.4131,0.4147,0.4162,0.4177,\
0.4192,0.4207,0.4222,0.4236,0.4251,0.4265,0.4279,0.4292,0.4306,0.4319,\
0.4332,0.4345,0.4357,0.4370,0.4382,0.4394,0.4406,0.4418,0.4429,0.4441,\
0.4452,0.4463,0.4474,0.4484,0.4495,0.4505,0.4515,0.4525,0.4535,0.4545,\
0.4554,0.4564,0.4573,0.4582,0.4591,0.4599,0.4608,0.4616,0.4625,0.4633,\
0.4641,0.4649,0.4656,0.4664,0.4671,0.4678,0.4686,0.4693,0.4699,0.4706,\
0.4713,0.4719,0.4726,0.4732,0.4738,0.4744,0.4750,0.4756,0.4761,0.4767,\
0.4772,0.4778,0.4783,0.4788,0.4793,0.4798,0.4803,0.4808,0.4812,0.4817,\
0.4821,0.4826,0.4830,0.4834,0.4838,0.4842,0.4846,0.4850,0.4854,0.4857,\
0.4861,0.4864,0.4868,0.4871,0.4875,0.4878,0.4881,0.4884,0.4887,0.4890,\
0.4893,0.4896,0.4898,0.4901,0.4904,0.4906,0.4909,0.4911,0.4913,0.4916,\
0.4918,0.4920,0.4922,0.4925,0.4927,0.4929,0.4931,0.4932,0.4934,0.4936,\
0.4938,0.4940,0.4941,0.4943,0.4945,0.4946,0.4948,0.4949,0.4951,0.4952,\
0.4953,0.4955,0.4956,0.4957,0.4959,0.4960,0.4961,0.4962,0.4963,0.4964,\
0.4965,0.4966,0.4967,0.4968,0.4969,0.4970,0.4971,0.4972,0.4973,0.4974,\
0.4974,0.4975,0.4976,0.4977,0.4977,0.4978,0.4979,0.4979,0.4980,0.4981,\
0.4981,0.4982,0.4982,0.4983,0.4984,0.4984,0.4985,0.4985,0.4986,0.4986,\
0.4987,0.4987,0.4987,0.4988,0.4988,0.4989,0.4989,0.4989,0.4990,0.4990};
																
long long fact(int x)
{
	long long ans=1;
	while(x)
	{
		ans*=x;
		--x;
	}
	return ans;
}

long long ncr(int n,int r)
{
long long num=1,den=1;
int i;
for(i=n;i>=n-r+1;--i)
num*=i;	
for(i=1;i<=r;++i)
den*=i;	
return num/den;	
}

void binomial()
{
	float p,q;
	float ans;
	int n,x,a,b,c,choice,i;
	printf("\nENTER THE FOLLOWING PARAMETERS:"); 
	printf("\nProbability of success(p):");
	scanf("%f",&p);
	if(p>1.00f||p<0.00f)
	{
	printf("\nSuccess probability must be less than 1.00 and greater than 0.00\n\
	EXITING THE MODULE.......[PRESS ANY KEY TO CONTINUE]...");
	getch();
	return;
	}
	q=1-p;
	printf("\nMAX no. of trails(N):");
	scanf("%d",&n);
	if(n<=0)
	{
	printf("\nValue of N must be a positive integer\n\
	EXITING THE MODULE.......[PRESS ANY KEY TO CONTINUE]...");
	getch();
	return;	
	}
		printf("\n Please specify the way you want to calculate:\n\
					1--P(X=c)\n\
					2--P(a<=X<=b)\n\
					3--P(c<=X<=N)\n\
					4--P(0<=X<=c)\n");
		scanf("%d",&choice);
		switch(choice)
		{
		case 1:printf("\nEnter the value of X:");
				scanf("%d",&x);
				if(x<0||x>n)
				{
					printf("\nValue of X must lie between 0 and N\n\
	EXITING THE MODULE.......[PRESS ANY KEY TO CONTINUE]...");
				getch();
				return;
				}
				ans=ncr(n,x)*pow(p,x)*pow(q,n-x);
				printf("\nPROBABILITY=%f",ans);
				printf("\n[PRESS ANY KEY TO CONTINUE]");
				getch();
				break;
		case 2:printf("\nEnter the lower and upper limit of X(separated by a apace):");
				scanf("%d %d",&a,&b);
				if(a<0||b>n||b<a)
				{
					printf("\nInappropriate conditions\n\
	EXITING THE MODULE.......[PRESS ANY KEY TO CONTINUE]...");
				getch();
				return;
				}
				ans=0;
				for(i=a;i<=b;++i)
				ans+=ncr(n,i)*pow(p,i)*pow(q,n-i);
				printf("\nPROBABILITY=%f",ans);
				printf("\n[PRESS ANY KEY TO CONTINUE]");
				getch();
				break;
			
		case 3:printf("\nEnter the lower bound of X:");
				scanf("%d",&c);
				if(c<0||c>n)
				{
					printf("\nValue of lower bound must lie between 0 and N\n\
	EXITING THE MODULE.......[PRESS ANY KEY TO CONTINUE]...");
				getch();
				return;
				}
				ans=0.0f;
				for(i=c;i<=n;++i)
				ans+=ncr(n,i)*pow(p,i)*pow(q,n-i);
				printf("\nPROBABILITY=%f",ans);
				printf("\n[PRESS ANY KEY TO CONTINUE]");
				getch();
				break;
			
		case 4:printf("\nEnter the upper bound of X:");
				scanf("%d",&c);
				if(c<0||c>n)
				{
					printf("\nValue of upper bound must lie between 0 and N\n\
	EXITING THE MODULE.......[PRESS ANY KEY TO CONTINUE]...");
				getch();
				return;
				}
				ans=0.0f;
				for(i=0;i<=c;++i)
				ans+=ncr(n,i)*pow(p,i)*pow(q,n-i);
				printf("\nPROBABILITY=%f",ans);
				printf("\n[PRESS ANY KEY TO CONTINUE]");
				getch();
				break;
			
			default:printf("\nInvalid choice\n\
	EXITING THE MODULE.......[PRESS ANY KEY TO CONTINUE]...");
				getch();
				return;

		}
}

void poisson()
{	float p,q;
	float ans;
	int n,x,a,b,c,i,choice;
		float m; 
	printf("\nEnter the mean of distribution(%c):",230);
	scanf("%f",&m);
	if(m<0.00f)
	{
	printf("\nMean must be greater than 0.00\n\
	EXITING THE MODULE.......[PRESS ANY KEY TO CONTINUE]...");
	getch();
	return;
	}
	
	printf("\n Please specify the way you want to calculate:\n\
				1--P(X=c)\n\
				2--P(a<=X<=b)\n\
				3--P(c<=X<%c)\n\
				4--P(0<=X<=c)\n",236);
		scanf("%d",&choice);
		switch(choice)
		{
		case 1:printf("\nEnter the value of X:");
				scanf("%d",&x);
				if(x<0)
				{
					printf("\nValue of X must be than 0\n\
	EXITING THE MODULE.......[PRESS ANY KEY TO CONTINUE]...");
				getch();
				return;
				}
				ans=pow(m,x)*pow(e,-1*m)/fact(x);
				printf("\nPROBABILITY=%f",ans);
				printf("\n[PRESS ANY KEY TO CONTINUE]");
				getch();
				break;
		case 2:printf("\nEnter the lower and upper limit of X(separated by a apace):");
				scanf("%d %d",&a,&b);
				if(a<0||b<a)
				{
					printf("\nInappropriate conditions\n\
	EXITING THE MODULE.......[PRESS ANY KEY TO CONTINUE]...");
				getch();
				return;
				}
				ans=0;
				for(i=a;i<=b;++i)
				ans+=pow(m,i)*pow(e,-1*m)/fact(i);
				printf("\nPROBABILITY=%f",ans);
				printf("\n[PRESS ANY KEY TO CONTINUE]");
				getch();
				break;
			
		case 3:printf("\nEnter the lower bound of X:");
				scanf("%d",&c);
				if(c<0)
				{
					printf("\nValue of lower bound must be greater than 0\n\
	EXITING THE MODULE.......[PRESS ANY KEY TO CONTINUE]...");
				getch();
				return;
				}
				ans=0.0f;
				for(i=0;i<c;++i)
				ans+=pow(m,i)*pow(e,-1*m)/fact(i);
				ans=1-ans;
				printf("\nPROBABILITY=%f",ans);
				printf("\n[PRESS ANY KEY TO CONTINUE]");
				getch();
				break;
			
		case 4:printf("\nEnter the upper bound of X:");
				scanf("%d",&c);
				if(c<0)
				{
					printf("\nValue of upper bound must be greater than 0\n\
	EXITING THE MODULE.......[PRESS ANY KEY TO CONTINUE]...");
				getch();
				return;
				}
				ans=0.0f;
				for(i=0;i<=c;++i)
				ans+=pow(m,i)*pow(e,-1*m)/fact(i);
				printf("\nPROBABILITY=%f",ans);
				printf("\n[PRESS ANY KEY TO CONTINUE]");
				getch();
				break;
			
			default:printf("\nInvalid choice\n\
	EXITING THE MODULE.......[PRESS ANY KEY TO CONTINUE]...");
				getch();
				return;

		}
	
	
	
}

void normal()
{	int row,col;
	float p,x,q,m,d,a,b,c,z;
	float ans,ans1,ans2,z1,z2;
	int n,choice;
	printf("\nEnter the value  of mean( %c ):",230);
	scanf("%f",&m);
	printf("\nEnter the value  of standard deviation( %c ):",229);
	scanf("%f",&d);	
	
	printf("\n Please specify the way you want to calculate:\n\
				1--P(a<=X<=b)\n\
				2--P(c<=X)\n\
				3--P(X<=c)\n");
		scanf("%d",&choice);
		switch(choice)
		{
				case 1:printf("\nEnter the lower and upper limit of X(separated by a apace):");
				scanf("%f %f",&a,&b);
				if(b<a)
				{
					printf("\nInappropriate conditions\n\
	EXITING THE MODULE.......[PRESS ANY KEY TO CONTINUE]...");
				getch();
				return;
				}
				ans=0;
				z1=(a-m)/d;
				//printf("xx %f xx",z);
					row =fabs(z1)*10;
						col=(fabs(z1)*100);
						col=col%10;
					ans1=zzz[row][col];
					//printf("xx %f xx",ans1);
				z2=(b-m)/d;
				//printf("xx %f xx",z);
					row =fabs(z2)*10;
						col=(fabs(z2)*100);
						col=col%10;
					ans2=zzz[row][col];
					//printf("xx %f xx",ans2);
					if(z1*z2<0)
					ans=ans1+ans2;
					else
					ans=fabs(ans1-ans2);
				printf("\nPROBABILITY=%f",ans);
				printf("\n[PRESS ANY KEY TO CONTINUE]");
				getch();
				break;
			
		case 2:printf("\nEnter the lower bound of X:");
				scanf("%f",&c);
				ans=0.0f;
					z=(c-m)/d;
					row =fabs(z)*10;
						col=(fabs(z)*100);
						col=col%10;
					ans1=zzz[row][col];
					if(z<0)
					ans=ans1+0.5;
					else
					ans=0.5-ans1;
				printf("\nPROBABILITY=%f",ans);
				printf("\n[PRESS ANY KEY TO CONTINUE]");
				getch();
				break;
			
		case 3:printf("\nEnter the upper bound of X:");
				scanf("%d",&c);
				ans=0.0f;
					z=(c-m)/d;
					row =fabs(z)*10;
						col=(fabs(z)*100);
						col=col%10;
					ans1=zzz[row][col];
					if(z<0)
					ans=0.5-ans1;
					else
					ans=0.5+ans1;
				printf("\nPROBABILITY=%f",ans);
				printf("\n[PRESS ANY KEY TO CONTINUE]");
				getch();
				break;
			
			default:printf("\nInvalid choice\n\
	EXITING THE MODULE.......[PRESS ANY KEY TO CONTINUE]...");
				getch();
				return;

		}
}


int main()
{
	int choice;
	label:
  	//clrscr();
	printf("\n Please select  an opeartion :\n\
				1--BIONOMIAL DISTRIBUTION\n\
				2--POISSON DISTRIBUTION\n\
				3--NORMAL DISTRIBUTION\n\
				4--QUIT THE PROGRAM\n");
	scanf("%d",&choice);
	switch(choice)
	{
	case 1:binomial();goto label;	
	case 2:	poisson();goto label;
	case 3:	normal();goto label;
	case 4:break;
	default:printf("\nPlease enter a valid choice.\n\
	[PRESS ANY KEY TO CONTINUE]");
	getch();
	goto label;	
	}
return 0;	
}

//-------------------------bisection method to calculate positive root of a  polynomial---------------------------------------------
// ----------------incomplete as further close value of x has to b calculated----------------------------------------------------
#include<iostream>
#include<cstdlib>
#include<cmath>
using namespace std;

//------struct for polynomial---------------------------------
struct poly{
	int exp;
	float coef;
}p[10];

//-----------to calculate value of poly at x=a---------------------------
float calPoly(struct poly *p,int n,float a){
	float ans=0;
	for(int i=0;i<n;i++){
		ans+=p[i].coef*pow(a,p[i].exp);
	}
	return ans;
}

//------------cal value of x for which poly is negative------------------
float calA (struct poly *p,int n) {
	float a=-1,ans;
	do{
		a++;
		ans=calPoly(p,n,a);
	}while(ans>0);
	cout<<"a="<<a <<endl;
	return a;
}

//--------------cal value of x for which poly is positive--------------------
float calB (struct poly *p,int n,int a){
	float b=a,ans;
	do{
		b++;
		ans=calPoly(p,n,b);
	}while(ans<0);
	cout<<"b= "<<b <<endl;
	return b;
}

double bisectionMethod(struct poly *p,int n,float a,float b){
	float c=(a+b)/2,ans;
	ans=calPoly(p,n,c);
	cout<<"hi.."<<ans << " " << c <<endl;
	if(ans>-0.3&&ans<0.3) {
		cout<<"returning c= "<< c << endl;
		return c;
	}
	if(ans>0)
	c=bisectionMethod(p,n,a,c);
	else
	c=bisectionMethod(p,n,c,b);
	return c;
}
//////////////////////////////////////////////////////////////////////////////

main(){
	int n,e;
	float a=0,b=0;
	float c,root;
	cout<<"enter total terms: ";
	cin>>n;
	cout<<"enter exp n coef of the terms: ";
	for(int i=0;i<n;i++){
	 	cin>>e>>c;
	 	p[i].exp=e;
	 	p[i].coef=c;
	}
	a=calA(p,n);
	b=calB(p,n,a);
//	root=bisectionMethod(p,n,a,b);
	cout<<"root of poly is :"/*<<root */<<" " << bisectionMethod(p,n,a,b);;
}

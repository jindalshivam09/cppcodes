#include <cstdio>
#include <algorithm>
using namespace std;

int Tn,i,D;

struct Frac{long long chi,zna;}a,p,q,d,ret; // fraction type

Frac operator+(Frac a,Frac b){ // + operator for fractions
	Frac ret;
	long long common=a.zna/__gcd(a.zna,b.zna)*b.zna;
	a.chi*=common/a.zna;
	b.chi*=common/b.zna;
	ret.chi=a.chi+b.chi;
	ret.zna=common;
	return ret;
}

Frac operator-(Frac a,Frac b){ // - operator for fractions
	Frac ret;
	long long common=a.zna/__gcd(a.zna,b.zna)*b.zna;
	a.chi*=common/a.zna;
	b.chi*=common/b.zna;
	ret.chi=a.chi-b.chi;
	ret.zna=common;
	return ret;
}

Frac operator*(Frac a,Frac b){ // * operator for fractions
	Frac ret;
	ret.chi=a.chi*b.chi;
	ret.zna=a.zna*b.zna;
	long long common=__gcd(ret.chi,ret.zna);
	ret.chi/=common;
	ret.zna/=common;
	return ret;
}

Frac operator/(Frac a,Frac b){ // / operator for fractions
	Frac ret;
	ret.chi=a.chi*b.zna;
	ret.zna=a.zna*b.chi;
	long long common=__gcd(ret.chi,ret.zna);
	ret.chi/=common;
	ret.zna/=common;
	return ret;
}

Frac ReadFrac(){ // reading the fraction as a decimal one and then converting it to the common fraction
	char ch,fla=0;
	Frac ret;
	ret.chi=ret.zna=0;
	while(1){
		ch=getchar();
		if(ch<33)if(fla)break;else continue;
		if(ch=='.')continue;
		if(ch>='0'&&ch<='9')ret.chi=ret.chi*10+ch-'0';
		fla=1;
	}
	ret.zna=100;
	return ret;
}

int main(){
	d.chi=d.zna=1;
//	freopen("in.txt","r",stdin);
	scanf("%d",&Tn);
	for(;Tn;Tn--){
		a=ReadFrac();
		p=ReadFrac();
		q=ReadFrac();
		scanf("%d",&D);
		ret=(p*a*(d-a)+q*a)/((d-a)*(d-a)); // the final formula
		printf("%lld",ret.chi/ret.zna); // output the integer parts
		putchar('.');
		ret.chi%=ret.zna;
		for(i=1;i<=D;i++){ // outputting D characters after the decimal point
			ret.chi*=10;
			putchar(ret.chi/ret.zna+'0');
			ret.chi%=ret.zna;
		}
		puts("");
	}
	return 0;
}
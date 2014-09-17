#include<bits/stdc++.h>
using namespace std;
long long power(long long int a,long long int b,long long MOD)
{	
	long long x=1,y=a; 
	while(b > 0)
	{
		if(b%2 == 1)
		{
			x=(x*y);
			if(x>MOD) x%=MOD;
		}
		y = (y*y);
		if(y>MOD) y%=MOD; 
		b /= 2;
	}
	return x;
}
long long solve(long long N,long long int M){
	pair<long long int,long long int> X=make_pair(N/30,N%30);
	pair<long long int,long long int> Y=X;
	pair<long long int,long long int> powerOne=make_pair(0,N);
	pair<long long int,long long int> powerFive;
	pair<long long int,long long int> powerFour;
	pair<long long int,long long int> powerThree;
	pair<long long int,long long int> ans=make_pair(0,0);
	pair<long long int,long long int> T;
	
	for(int i=2;i<=5;i++)
  	{
  		T.second = (X.second*Y.second);
  		T.first  = ((30*X.first*Y.first + X.first*Y.second + X.second*Y.first + T.second/30))%M;
  		T.second = T.second%30;
  	  	Y=T;
		if(i==3)
  	  	powerThree=Y;
  	  	else if(i==4)
  	  	powerFour=Y;
  	  	else if(i==5)
  	  	powerFive=Y;
  	  }
  	  
 // 	cout<<powerFive.first<<" "<<powerFive.second<<"\n";
  //	cout<<powerFour.first<<" "<<powerFour.second<<"\n";
  //	cout<<powerThree.first<<" "<<powerThree.second<<"\n";

	ans.first  = 6*powerFive.first + 15*powerFour.first + 10*powerThree.first - powerOne.first;
	ans.second = 6*powerFive.second + 15*powerFour.second + 10*powerThree.second - powerOne.second;
//	cout<<ans.first<<" "<<ans.second<<"\n";
	ans.first+=ans.second/30;
	return ans.first%M;
}

int main(){
	ifstream cin("test.txt") ;
	ofstream cout("4.txt") ;

	int t;
	cin>>t;
	while(t--){
		long long int N,M;
		cin>>N>>M;
		long long int ans=0;
		for(int i=1;i<=sqrt(N);i++){
			ans=(ans+(power(i,4,M)*(N/i))%M)%M;
		}
		long long int upperLimit=N;
		for(int i=2;i<=sqrt(N);i++){
			long long int lowerLimit=N/i;
			ans=(ans+((i-1)*((solve(upperLimit,M)-solve(lowerLimit,M)+M)%M))%M)%M;
			upperLimit=lowerLimit;
		}
		
		for(int i=sqrt(N)+1;i<=upperLimit;i++){
//			cout<<"in loop";
			ans=(ans+(power(i,4,M)*(N/i))%M)%M;
		}
		  
		cout<<ans<<"\n";
	}
}


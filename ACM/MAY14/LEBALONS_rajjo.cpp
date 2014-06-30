#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include<fstream>
using namespace std;
typedef long long ll;
map<ll , pair<ll,ll> > M;
map<pair<,ll> , pair<ll,ll> > memo ;
map<pair<ll,ll>,int > visited;
pair<ll,ll> rangs(map<ll ,pair<ll,ll> >::iterator it , ll index ,ll color,pair<ll,ll> p ) 
{
	pair<ll,ll> k;
	if(M.size()-index<color)
		return make_pair(0,0);
 	if( memo[make_pair(index,color)].second)
		return memo[make_pair(index,color) ];
	if(color == 0 ) 
	{
		for( ; it != M.end(); ++it) {
			p.first = (p.first) * ((it->second).second + 1) +  (it->second).first* p.second ;
			p.second = p.second*((it->second).second+1);
		}
		return p;
	}
	if( it == M.end()) 
	 return make_pair(0,1);
	pair<ll,ll> P2 = make_pair(0,0);
	k = make_pair( p.second *(it->second).first + p.first * (it->second).second , p.second * (it->second).second );
	pair<ll,ll > P1 = rangs( ++it ,index+1, color - 1 ,k );
	P2 = rangs( it ,index+1 ,color , p) ;
	visited[make_pair(index,color)] = 1;
	return memo[make_pair(index,color) ] = make_pair(P1.first + P2.first , P1.second + P2.second);
//	return make_pair(P1.first + P2.first , P1.second + P2.second);
} 
int  main(){
//	ifstream cin("output.txt") ;
//	ofstream cout("lebalon_rajjo.txt") ;

	ll t;
	cin>>t;
	cout.setf(ios::fixed,ios::floatfield);
	cout.precision(6);
	while(t--){
		ll n,m;
		M.clear();
		//ans = 0;
		cin>>n>>m;
		ll a,b;
		for(ll i= 1 ;i<=n;i++)
		{
			cin>>a>>b;
			M[a] =  make_pair(b+(M[a]).first,(M[a]).second + 1 );;
		}
		for(auto i = M.begin() ; i != M.end() ; ++i) {
			(i->second).first = pow(2,(i->second).second - 1 ) * (i->second).first;
			(i->second).second  = pow(2,(i->second).second) - 1;
	//		cout<< i->first <<" "<< (i->second).first << " "<<(i->second).second<<endl;
		}
	 pair<ll,ll> px = rangs(M.begin(),0,m,make_pair(0,1)); 
		cout<<(double)px.first / px.second<<endl;
		for(map<pair<ll,ll>,pair<ll,ll> >::iterator itr = memo.begin() ; itr != memo.end() ; itr ++ )
			cout << (itr->second).first << " " << (itr->second).second << endl;
		memo.clear();
		visited.clear() ;
	}
}
		
		
		

#include<iostream>
#include<map>
#include<algorithm>
using namespace std;

typedef pair<int,int> PII;
typedef long long LL;


int gcd(int a,int b){
    if(b>a) return gcd(b,a);
    return b==0?a:gcd(b,a%b);
}

int T,N;
int A[110];
map<PII,LL> cache;

LL go(int ind,int g){
    if(ind==N){
        if(g==1) return 1;
        else return 0;
    }
    PII key = make_pair(ind,g);
  //  cout << key.first << " " << key.second << endl;
    if(cache.find(key)!=cache.end()) {
//		cout << "cache " << cache[key] << endl;
		return cache[key];
	}
//	cout << "cache2 " << cache[key] << endl ;
    return cache[key]=go(ind+1,g)+go(ind+1,gcd(g,A[ind]));
}


int main(){
    cin>>T;
    while(T--){
        cin>>N;
        for(int i=0;i<N;++i) cin>>A[i];
        cache.clear();
        LL res = 0;
        for(int i=0;i<N;++i) res+=go(i+1,A[i]);
        // go(i+1,A[i]) << endl;
		cout<<res<<endl;
    }
    return 0;
}
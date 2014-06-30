#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

int T,n,m,i,num,q,ls,j,trie[1005][26],enwei[1005],G[1005][26],dp[1005][1005],c,choi,Link[1005],pv[1005],pch[1005],ew[1111];
char a[1005],s[1005];

int getlink(int k);
int Go(int k,int j);

int getlink(int k){ // suffix link standard calculation
	if(Link[k]==0)
		if(k==1||pv[k]==1)Link[k]=1;else Link[k]=Go(getlink(pv[k]),pch[k]);
	return Link[k];
}

int Go(int k,int j){ // Aho-Corasick's automaton transition
	if(G[k][j]==0)
		if(trie[k][j]!=0)
			G[k][j]=trie[k][j];
		else
			G[k][j]=k==1?1:Go(getlink(k),j);
	return G[k][j];
}

int main (int argc, char * const argv[]) {
	scanf("%d",&T);
	for(;T;T--){
		scanf("%d%d",&n,&m);
		for(i=1;i<=n;i++){
			a[i]=getchar();
			while((a[i]<'a'||a[i]>'z')&&(a[i]!='?'))a[i]=getchar();
		}
		num=1;
		gets(s);
		for(i=1;i<=m;i++){
			gets(s);ls=strlen(s);
			q=1;
			for(j=0;j<ls;j++)if(!trie[q][s[j]-'a']){ // building the trie
				trie[q][s[j]-'a']=++num; // new transition
				pv[num]=q;pch[num]=s[j]-'a'; // parent vertice and character for the node
				q=num;
			}else q=trie[q][s[j]-'a'];
			++enwei[q]; // number of strings the end in this node
		}
		for(i=1;i<=num;i++){ // calculating the number of strings that end in the node and all it's suffixes
			j=i;ew[j]=0;
			while(j>1){
				ew[i]+=enwei[j];
				j=getlink(j);
			}
		}
		for(i=1;i<=num;i++)enwei[i]=ew[i];
		for(i=0;i<=n;i++)for(j=1;j<=num;j++)dp[i][j]=-1000000000; // dp initialization 
		// dp[i][j] - answer for the substring [i; N] when the current node of the automaton is j
		for(j=1;j<=num;j++)dp[n][j]=enwei[j]; 
		for(i=n-1;i>=0;i--)for(j=1;j<=num;j++){ // dp calculation
			if(a[i+1]=='?')
				for(c=0;c<26;c++)dp[i][j]=max(dp[i][j],enwei[j]+dp[i+1][Go(j,c)]);else
								 dp[i][j]=max(dp[i][j],enwei[j]+dp[i+1][Go(j,a[i+1]-'a')]);
		}
		printf("%d\n",dp[0][1]); // optimal result: all the characters of the string are processed and we start in the first node (like in the standard algo)
		for(q=1,i=1;i<=n;i++){
			if(a[i]!='?')choi=a[i]-'a';else{ // if there's only one option
				choi=0;
				for(j=0;j<26;j++)if(dp[i][Go(q,j)]>dp[i][Go(q,choi)])choi=j; // otherwise we should just take the most optimal one
			}
			putchar('a'+choi);
			q=Go(q,choi);
		}
		puts("");
		for(i=1;i<=num;i++){
			enwei[i]=Link[i]=pv[i]=pch[i]=ew[i]=0;
			for(j=0;j<26;j++)trie[i][j]=G[i][j]=0;
		}
	}
    return 0;
}

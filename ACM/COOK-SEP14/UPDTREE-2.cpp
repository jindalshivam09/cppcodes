#include<bits/stdc++.h>
using namespace std;
#define assn(n,a,b) assert(n<=b && n>=a)
#define pb push_back
#define mp make_pair
#define clr(x) x.clear()
#define sz(x) ((int)(x).size())
#define F first
#define S second
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,b) for(i=0;i<b;i++)
#define rep1(i,b) for(i=1;i<=b;i++)
#define pdn(n) printf("%d\n",n)
#define sl(n) scanf("%lld",&n)
#define sd(n) scanf("%d",&n)
#define pn printf("\n")
typedef pair<int,int> PII;
typedef vector<PII> VPII;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef long long LL;
#define MAXN 100009
#define LOGMAXN 17
int T[MAXN],P[MAXN][LOGMAXN],L[MAXN],N;
// T[i] = parent of node i
// P dp
// L[i] =  height of node i
VI deg[MAXN]; // degree sequence
int pos[16*MAXN][3],poscnt=0;
int neg[16*MAXN][3],negcnt=0;
// pos for positive addition, neg for negative addition
int distleft[MAXN][2],distright[MAXN][2]; // value at left dfs, value at right dfs
// 0 index for pos, 1 index for neg
LL sum[MAXN][2];

//DP for LCS calculation
void process3()
{
    int i, j;
    for (i = 0; i < N; i++)
        for (j = 0; 1 << j < N; j++)
            P[i][j] = -1;
    for (i = 0; i < N; i++)
        P[i][0] = T[i];
    for (j = 1; 1 << j < N; j++)
        for (i = 0; i < N; i++)
            if (P[i][j - 1] != -1)
                P[i][j] = P[P[i][j - 1]][j - 1];
    cout << "fdf" ;
    for( int j=0;1<<j < N ; j++) {
		for(int i=0;i<N;i++)
			cout << P[i][j] << " ";
		cout << endl;
	}
}

//DFS for calculating array T and L
void dfs(int node, int p)
{
    if(p!=-1)
        T[node]=p,L[node]=L[p]+1;
    vector < int >::iterator it;
    for(it=deg[node].begin(); it!=deg[node].end(); it++)
        if((*it)!=p)dfs(*it,node);
}

//DFS for calculating dfsleft and dfsright arrays
void dfs_new(int node, int p)
{
    vector < int >::iterator it;
    for(it=deg[node].begin(); it!=deg[node].end(); it++)
    {
        if((*it)!=p)
        {
            dfs_new((*it),node);
            distleft[node][0]+=distleft[(*it)][0];
            distright[node][0]+=distright[(*it)][0];
            distleft[node][1]+=distleft[(*it)][1];
            distright[node][1]+=distright[(*it)][1];
        }
    }
}

//BFS for storing the sum till node i from the root
int vis[MAXN];
int Queue[MAXN];
void bfs()
{
    Queue[0]=0;
    int st=0,end=1,node;
    while(st<end){
        node=Queue[st];
        st++;
        for(vector<int>::iterator it=deg[node].begin();it!=deg[node].end();it++){
            if((*it)!=T[node]){
                sum[(*it)][0]=(sum[(*it)][0]+sum[node][0]);
                sum[(*it)][1]=(sum[(*it)][1]+sum[node][1]);
                Queue[end]=(*it);
                end++;
            }
        }
    }
}


//calculates lca of  nodes p and q
int lca(int p, int q)
{
    int tmp, log, i;
    if (L[p] < L[q])
        tmp = p, p = q, q = tmp;
    for (log = 1; 1 << log <= L[p]; log++);
    log--;
    for (i = log; i >= 0; i--)
        if (L[p] - (1 << i) >= L[q])
            p = P[p][i];
    if (p == q)
        return p;
    for (i = log; i >= 0; i--)
        if (P[p][i] != -1 && P[p][i] != P[q][i])
            p = P[p][i], q = P[q][i];
    return T[p];
}

//finds the intersecting path between A-B and C-D.
void foo(int a, int b, int c, int d)
{
    if(a==b || c==d)return;
    int p=lca(a,c);
    if(p==c)
    {
        int q=lca(b,d);
        if(q==d && L[d]<=L[b] && L[d]>L[a])neg[negcnt][0]=a,neg[negcnt][1]=d,neg[negcnt][2]=lca(a,d),negcnt++;
        else if(q==b)neg[negcnt][0]=a,neg[negcnt][1]=b,neg[negcnt][2]=lca(a,b),negcnt++;
        else
        {
            int pp=lca(b,d);
            if(lca(pp,a)==a)neg[negcnt][0]=a,neg[negcnt][1]=pp,neg[negcnt][2]=a,negcnt++;
        }
    }
    else if(p==a)
    {
        int q=lca(b,d);
        if(q==d && L[c]>=L[a] && L[c]<L[b] && L[d]<=L[b])neg[negcnt][0]=c,neg[negcnt][1]=d,neg[negcnt][2]=lca(c,d),negcnt++;
        else if(q==b && L[c]>=L[a] && L[c]<L[b] && L[d]>=L[b])neg[negcnt][0]=c,neg[negcnt][1]=b,neg[negcnt][2]=lca(c,b),negcnt++;
        else
        {
            int pp=lca(b,d);
            if(lca(pp,c)==c)neg[negcnt][0]=c,neg[negcnt][1]=pp,neg[negcnt][2]=c,negcnt++;
        }
    }
}
int main()
{
    int n,m1,u,v,m2;
    sd(n),sd(m1),sd(m2);
    N=n;
    T[0]=-1;
    for(int i=1; i<n; i++)
    {
        sd(u),sd(v);
        u--,v--;
        deg[u].pb(v);
        deg[v].pb(u);
    }
    cout << "fd";
    dfs(0,-1);
    process3();
    while(m1--)
    {
        int a,b,c,d;
        sd(a),sd(b),sd(c),sd(d);
        a--,b--,c--,d--;
        int p=lca(a,b);
        int q=lca(c,d);
        pos[poscnt][0]=a;
        pos[poscnt][1]=b;
        pos[poscnt][2]=p;
        poscnt++;
        //break down the queries into 4 parts
        if(p==a && q==c)foo(a,b,c,d);
        else if(p==a && q!=c)foo(a,b,q,c),foo(a,b,q,d);
        else if(p!=a && q==c)foo(p,b,c,d),foo(p,a,c,d);
        else foo(p,a,q,c),foo(p,a,q,d),foo(p,b,q,c),foo(p,b,q,d);
    }

    //update the positive paths
    for(int i=0; i<poscnt; i++)
    {
        int anc=pos[i][2];
        distleft[pos[i][0]][0]++;
        distright[pos[i][1]][0]++;
        distright[anc][0]--;
        distleft[anc][0]--;
    }

    //update the negative paths
    for(int i=0; i<negcnt; i++)
    {
        int anc=neg[i][2];
        distleft[neg[i][0]][1]++;
        distright[neg[i][1]][1]++;
        distright[anc][1]--;
        distleft[anc][1]--;
    }
    
    dfs_new(0,-1);

    //build the sum array
    for(int i=0; i<n; i++)
        for(int j=0; j<2; j++)
            sum[i][j]=(LL)distleft[i][j] + (LL)distright[i][j];

    bfs();

    while(m2--)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        a--,b--;
        int anc=lca(a,b);
        LL ans1=sum[a][0]+sum[b][0]-2ll*sum[anc][0];
        LL ans2=sum[a][1]+sum[b][1]-2ll*sum[anc][1];
        printf("%lld\n",ans1-ans2);
    }
    return 0;
}	

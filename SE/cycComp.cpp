#include<iostream>
#define MAX 10
using namespace std;
int node[MAX];
int adjMat[MAX][MAX],edges,nodes,sinks;
void getInput()
{
	int a,b;
	while(1)
	{
		cin>>a>>b;
		if(!a||!b)
		break;
		edges++;
		adjMat[a-1][b-1]=1;
		if(!node[a-1])
		{
			node[a-1]=1;
			nodes++;
		}
		if(!node[b-1])
		{
			node[b-1]=1;
			nodes++;
		}
	}

}
int countSink()
{
	int flag;
	for(int i=0;i<nodes;i++){
.

		flag=0;
		for(int j=0;j<nodes;j++){
			if(adjMat[i][j])
			{
				flag=1;
				break;
			}
		}
		if(!flag)
		sinks++;
	}
	return sinks;
}
int calCycComp()
{
	return edges-nodes+(2*sinks);
}
main()
{
	int n;
	cout<<"Enter the connected pair of graph(ended by zero): ";
	getInput();
	sinks=countSink();
	cout<<"Edges: "<<edges<<" Nodes: "<<nodes<<" Sinks: "<<sinks<<endl<<"V(G):  "<<calCycComp();
}

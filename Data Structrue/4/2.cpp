#include <iostream>
#include <cstring>
#define MaxV 100

using namespace std;

bool used[MaxV]={};
int k,start,dest,tot=0,path[MaxV]={};

typedef struct node
{
	int adjvex;				//表示邻接点
	struct node *prev;
}ArcNode,*FirstArc;

typedef struct gragh
{
	FirstArc head[MaxV];   //head[i]表示节点 i 所邻接的第一条边
	int VertNum,EdgeNum;
}ALGraph;


void CreateArc(ALGraph &g, const int a, int b)   //新建一条 a->b 的边
{
	ArcNode *p=new ArcNode;
	p->adjvex=b;
	p->prev=g.head[a];   
	g.head[a]=p;
}

void GetGraph(ALGraph &g)
{
	cin>>g.VertNum>>g.EdgeNum>>k>>start>>dest;
	for (int i=1;i<=g.VertNum;i++)
		g.head[i]=NULL;             
	for (int i=1;i<=g.EdgeNum;i++)
	{
		int x,y;
		cin>>x>>y;
		CreateArc(g,x,y);
		CreateArc(g,y,x);
	}
}

void Print()
{
	tot++;
	cout<<"Path "<<tot<<": "<<start<<"->";
	for (int i=1;i<=k-1;i++)
		cout<<path[i]<<"->";
	cout<<dest<<endl;
}

void dfs(const ALGraph &g, const int now, const int length)   //now 表示现在所在的点 length表示从 start 到 now 的路径长度
{
	if (length==k&&now==dest)     //如果k 步到达了目标点
	{
		Print();
		return;
	}
	if (length<k)
	{
		for (FirstArc i=g.head[now]; i; i=i->prev)
		if (used[i->adjvex]==0)		//如果还有邻接的边
		{
			path[length+1]=i->adjvex;
			used[i->adjvex]=true;
			dfs(g,i->adjvex,length+1);
			path[length+1]=0;    	//回溯
			used[i->adjvex]=false;
		}
	}
}

void DFSTraverse(const ALGraph &g)
{
	used[start]=true;
	dfs(g,start,0);
}

int main(int argc, char const *argv[])
{
	ALGraph MyGraph;
	GetGraph(MyGraph);
	DFSTraverse(MyGraph);
	if (0==tot) cout<<"No Answer!"<<endl;
	return 0;
}
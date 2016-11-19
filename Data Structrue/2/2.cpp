#include <iostream>
#define MaxSize 1000
#define MaxN 100

using namespace std;

typedef struct 
{
	int x,y,value;
} Triple;

typedef struct 
{
	Triple data[MaxSize];
	int rpos[MaxN];
	int n,m,tot;
} RLSMatrix;    //行逻辑矩阵

typedef struct 
{
	Triple data[MaxSize];
	int cpos[MaxN];
	int n,m,tot;
} CLSMatrix;    //列逻辑矩阵
//为行逻辑矩阵加一个元素
void PushRLSElement(RLSMatrix &a,const int i,const int j,const int x)
{
	a.data[++a.tot].x=i;
	a.data[a.tot].y=j;
	a.data[a.tot].value=x;
}

void InitRLSMatrix(RLSMatrix &a)
{
	cin>>a.n>>a.m;
	for (int i=1;i<=a.n;i++)
		for (int j=1;j<=a.m;j++)
		{
			int x;
			cin>>x;
			if (0==x) continue;
			PushRLSElement(a,i,j,x);
			if (0==a.rpos[i]) a.rpos[i]=a.tot;
		}
}

void InitCLSMatrix(CLSMatrix &a)
{
	Triple temp[MaxSize]={};
	int pos[MaxSize]={},sum[MaxN]={};
	cin>>a.n>>a.m;
	//暂时用 temp 数组行逻辑存储矩阵
	for (int i=1;i<=a.n;i++)
		for (int j=1;j<=a.m;j++)
		{
			int x;
			cin>>x;
			if (0==x) continue;
			temp[++a.tot].x=i;
			temp[a.tot].y=j;
			temp[a.tot].value=x;
			++sum[j];
		}
	//将 temp 中的数据转为列逻辑存在 a 中
	for (int i=1;i<=a.m;i++)
	{
		sum[i]+=sum[i-1];
		a.cpos[i]=pos[i]=sum[i-1]+1;   
	}
	for (int i=1;i<=a.tot;i++)
	{
		a.data[pos[temp[i].y]].x=temp[i].x;
		a.data[pos[temp[i].y]].y=temp[i].y;
		a.data[pos[temp[i].y]].value=temp[i].value;
		pos[temp[i].y]++;
	}
}

void MultiplifyMatrix(const RLSMatrix a,const CLSMatrix b,RLSMatrix &c)
{
	c.n=a.n; c.m=b.m;
	for (int i=1;i<=a.n;i++)
		for (int j=1;j<=b.m;j++)
		{
			int ans=0,nowa=a.rpos[i],nowb=b.cpos[j];
			while ((a.data[nowa].x==i)&&(b.data[nowb].y==j))  //遍历第 I 行第 j 列的值
			{
				if (a.data[nowa].y==b.data[nowb].x) ans+=a.data[nowa++].value*b.data[nowb++].value;
					else if (a.data[nowa].y<b.data[nowb].x) nowa++;
						else nowb++; 
			}
			if (ans) PushRLSElement(c,i,j,ans);
		}
}

int Order(const RLSMatrix a,int i)
{
	return (a.m*a.data[i].x+a.data[i].y);
}

void PrintRLSMatrix(const RLSMatrix a)
{
	for (int i=1,now=1;i<=a.n;i++)
		for (int j=1;j<=a.m;j++)
		{
			if (Order(a,now)==(i*a.m+j)) { cout<<a.data[now++].value<<' '; }
			else cout<<"0 ";
			if (a.m==j) cout<<endl;
		}
}

bool multiable(const RLSMatrix a,const CLSMatrix b)
{
	if (a.m==b.n)  return 1;
	else return 0;
}

int main(int argc, char const *argv[])
{
	RLSMatrix a={{},{},0,0,0},c={{},{},0,0,0};
	CLSMatrix b={{},{},0,0,0};
	cout<<"Please input the matrix A:"<<endl;
	InitRLSMatrix(a);
	cout<<"Please input the matrix B:"<<endl;
	InitCLSMatrix(b); 
	if (multiable(a,b)) 
	{
		MultiplifyMatrix(a,b,c);
		cout<<"The answer matrix would be:"<<endl;
		PrintRLSMatrix(c);
	}
	else cout<<"Matrix A cannot multiplify matrix B."<<endl;
	return 0;
}

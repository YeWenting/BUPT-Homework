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
} RLSMatrix;

void PushElement(RLSMatrix &a,const int i,const int j,const int x)
{
	a.data[++a.tot].x=i;
	a.data[a.tot].y=j;
	a.data[a.tot].value=x;
}

void InitMatrix(RLSMatrix &a)
{
	cin>>a.n>>a.m;
	for (int i=1;i<=a.n;i++)
		for (int j=1;j<=a.m;j++)
		{
			int x;
			cin>>x;
			if (0==x) continue;
			PushElement(a,i,j,x);
			if (0==a.rpos[i]) a.rpos[i]=a.tot;
		}
}

int Order(const RLSMatrix a,int i)
{
	if (i>a.tot) return MaxSize+1;
	else return (a.m*a.data[i].x+a.data[i].y);
}

void AddMatrix(const RLSMatrix a,const RLSMatrix b,RLSMatrix &c)
{
	int i=1,j=1;
	c.m=a.m; c.n=a.n;
	while (i<=a.tot||j<=b.tot)    //玄机
	{
		if (Order(a,i)<Order(b,j)) 
		{
			PushElement(c,a.data[i].x,a.data[i].y,a.data[i].value);
			i++; 
		}
			else if (Order(a,i)==Order(b,j)) 
			{
				PushElement(c,a.data[i].x,a.data[i].y,a.data[i].value+b.data[j].value);
				i++; j++;
			}
			else 
				{
					PushElement(c,b.data[j].x,b.data[j].y,b.data[j].value);
					j++;
				}
	}
}

void PrintMatrix(const RLSMatrix a)
{
	for (int i=1,now=1;i<=a.n;i++)
		for (int j=1;j<=a.m;j++)
		{
			if (Order(a,now)==(i*a.m+j)) { cout<<a.data[now++].value<<' '; }
			else cout<<"0 ";
			if (a.m==j) cout<<endl;
		}
}

bool plusable(const RLSMatrix a,const RLSMatrix b)
{
	if (a.n==b.n&&a.m==b.m)  return 1;
	else return 0;
}

int main(int argc, char const *argv[])
{
	RLSMatrix a={{},{},0,0,0},b={{},{},0,0,0},c={{},{},0,0,0};
	cout<<"Please input the matrix A:"<<endl;
	InitMatrix(a);
	cout<<"Please input the matrix B:"<<endl;≈
	InitMatrix(b);
	if (plusable(a,b)) 
	{
		AddMatrix(a,b,c);
		cout<<"The answer matrix would be:"<<endl;
		PrintMatrix(c);
	}
	else cout<<"Matrix A and Matrix B can not add."<<endl;
	return 0;
}
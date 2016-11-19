#include <iostream>
#include <cmath>

using namespace std;

typedef struct it
{
	int n,l,m;  	//n 表示表长，l 表示每格块的长度
	int *data,*index;  		//分别存储数据和索引
} IndexTable;

void Create_IndexTable(IndexTable &a)
{
	int tot=1;
	cin>>a.n>>a.l;
	a.m=ceil((float)a.n/a.l);
	a.data= new int[a.n];
	a.index= new int[a.m];
	if (a.data==NULL || a.index==NULL)
	{
		cerr<<"Overflow!!"<<endl;
		return;
	}
	for (int i=1; i<=a.m; i++)
	{
		int max=0;
		while (tot<=i*a.l&&tot<=a.n)
		{
			cin>>a.data[tot];
			max=a.data[tot]>max?a.data[tot]:max;
			tot++;
		}
		a.index[i]=max;
	}
}

void Destroy_IndexTable(IndexTable &a)
{
	free(a.data);
	free(a.index);
}

int BiSearch(const IndexTable &a, const int &num)   //找到满足 index[i-1]<num<=index[i]
{
	int l=1,r=a.m;
	while (l<r)
	{
		int x= (l+r)>>1;
		if (a.index[x]==num) l=r=x;
			else if(a.index[x]>num) r=x-1;
				else l=x+1;
	}
	if (a.index[l]>=num) return l;
		else return l+1;
}

void Work(const IndexTable &a)
{
	int q;
	cin>>q;
	for (int i=0; i<q; i++)
	{
		int num,pos,j;
		cin>>num;
		pos=BiSearch(a,num);
		for (j=(pos-1)*a.l+1; j<=pos*a.l&&j<=a.n; j++)
			if (a.data[j]==num) break;
		if (j<=pos*a.l&&j<=a.n) cout<<"Succeed! Its location is "<<j<<"."<<endl;
			else cout<<"No Answer!"<<endl;
	}
}

int main(int argc, char const *argv[])
{
	IndexTable MyData;
	Create_IndexTable(MyData);
	Work(MyData);
	Destroy_IndexTable(MyData);
	return 0;
}
#include <iostream>
#include <cstring>
#include <cstdio>
#define MaxN 27
#define BigNum 233333    //代指无穷

using namespace std;

int name[MaxN]={},dist[MaxN][MaxN],n,e;  //name 存储字符到对应下标的转换， data 存储下标到对应字母的转换
char data[MaxN]={}; 
string path[MaxN][MaxN]={};

void Initialize()
{
	memset(dist,63,sizeof(dist));
	cin>>n>>e;
	for (int i=1; i<=n; i++) dist[i][i]=0; //初始化dist 数组
	for (int i=1, k=1; i<=e; i++)
	{
		//读入字符 a,b 还有一个整形 w
		char a,b; 
		int w;
		getchar();
		cin>>a;
		getchar();
		cin>>b;
		cin>>w; 
		//处理字符和数字的对应关系    
		if (0==name[a-'a']) 
		{
			name[a-'a']=k;
			data[k++]=a;
		}
		if (0==name[b-'a']) 
		{
			name[b-'a']=k;
			data[k++]=b;
		}
		//对 dist 数组赋初值
		dist[name[a-'a']][name[b-'a']]=w;
	}
}

void Floyd()
{
	for (int k=1; k<=n; k++)
		for (int i=1; i<=n; i++)
			for (int j=1; j<=n; j++)
			{
				if (dist[i][j]>dist[i][k]+dist[k][j])
				{
					dist[i][j]=dist[i][k]+dist[k][j];
					path[i][j]=path[i][k]+"->"+data[k]+path[k][j]; 
				}
			}
}

void Print()
{
	for (int i=1; i<=n; i++)
		for (int j=1; j<=n; j++)
		{
			if (i==j) continue; 
			if (dist[i][j]>BigNum) cout<<"There is no way from "<<data[i]<<" to "<<data[j]<<endl;

				else if (!path[i][j].empty()) cout<<data[i]<<" to "<<data[j]<<" shortest way: "<<data[i]<<path[i][j]<<"->"<<data[j]<<", and length: "<<dist[i][j]<<endl;

					else cout<<data[i]<<" to "<<data[j]<<" shortest way: "<<data[i]<<"->"<<data[j]<<", and length: "<<dist[i][j]<<endl;
		}
}

int main(int argc, char const *argv[])
{
	Initialize();
	Floyd();
	Print();
	return 0;
}

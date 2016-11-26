#include <iostream>
#include <cstdio>
#define MaxN 22;

using namespace std;

int main(int argc, char const *argv[])
{
	int b[MaxN][MaxN][MaxN]={}, t;
	char map[MaxN][MaxN];
	cin>>t;
	for (int counter=1; counter <= t; counter++)
	{
		int n,m,k;
		cin>>n>>m>>k; getchar();
		for (int i=1; i<=n; i++)
		{
			for (int j=1; j<=m; j++)
				cin>>map[i][j];
			getchar();
		}
	}
	return 0;
}
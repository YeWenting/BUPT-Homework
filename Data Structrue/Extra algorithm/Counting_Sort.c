//设区间为[0,m] 统计区间内所有数字出现的次数 然后从 data[i] 从后往前开始 sorted[i]=sum[data[i]] 然后 sum[data[i]]--;
//data[]数据，sorted[]排序后,sum[i]比i小的有多少个

#include <stdlib.h>
#include <stdio.h>
#define MaxN 1010
#define MaxM 1010

int main(int argc, char const *argv[])
{
	int n,m,data[MaxN],sorted[MaxN],sum[MaxM]={};
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&data[i]);
		sum[data[i]]++;
	}
	for (int i=1;i<=m;i++)
	{
		sum[i]+=sum[i-1];
	}
	for (int i=1;i<=n;i++)
	{
		sorted[sum[data[i]]]=data[i];
		sum[data[i]]--;
	}
	for (int i=1;i<=n;i++)
	{
		printf("%d ",sorted[i]);
	}
	return 0;
}
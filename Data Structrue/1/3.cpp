#include <iostream>
#define MaxT 1000
#define MaxN 100

using namespace std;

int cost[MaxN]={},t,ans[MaxN],n,counter=0;

void PrintList()
{
	printf("The solution %d:",++counter);
	for (int i=0;i<n;i++)
		cout<<ans[i]<<' ';
	cout<<endl;
}

void dfs(int now,int left)
{
	if ((n-1)==now)
	{
		if (0!=left%cost[n-1]) return;
		ans[n-1]=left/cost[n-1];
		PrintList();
	}
	else 
		for (int i=0;i<=left/cost[now];i++)
		{
			ans[now]=i;
			dfs(now+1,left-i*cost[now]);
			ans[now]=0;
		}
}

int main(int argc, char const *argv[])
{
	cin>>t>>n;
	for (int i=0;i<n;i++)
		cin>>cost[i];
	dfs(0,t);
	if (0==counter) cout<<"No Solution!!"<<endl;
	return 0;
}
#include <iostream>
#include <cstdlib>
#define MaxN 1000
#define MinNum ((-1)<<31)

using namespace std;

int FindMax(const int a[],const int n)
{
	int max=MinNum;
	for (int i=0;i<n;i++)
		if (a[i]>max) max=a[i];
	return max;
}

void CountSort(int a[],int n,int exp)    //n个数 范围0~n^3-1
{
	int m=n*n*n-1;
	int *sorted=new int,
	int sum[m]={};

	for (int i=0;i<n;i++) sum[a[i]/exp]++;
	for (int i=1;i<=m;i++)
	{
		sum[i]+=sum[i-1];
	}
	for (int i=0;i<n;i++)
	{
		sorted[sum[a[i]/exp]=a[i]/exp;
		sum[a[i]/exp]--;
	}
	for (int i=0;i<n;i++)
		a[i]=sorted[i];
}

void RadixSort(int a[],const int n)
{
	int max=FindMax(a,n);
	for (int x=1;max/x>0;x*=n)
		CountSort(a,n,x);
	for(int i=0;i<n;i++)
		cout<<a[i]<<' ';
	cout<<endl;
}

int main(int argc, char const *argv[])
{
	int a[]={12,34,24,53,24,21,20,44};
	int n=sizeof(a)/sizeof(a[0]);
	RadixSort(a,n);

	return 0;
}
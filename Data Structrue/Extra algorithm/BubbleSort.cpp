#include <iostream>
#include <cstdlib>
#define MaxN 1000

using namespace std;

void swap(int &a,int &b)
{
	int temp=a;
	a=b;
	b=temp;
}

void BubbleSort(int a[],int n)
{
	do
	{
		int NewN=0;
		for (int i=0;i<n-1;i++)
			if (a[i]>a[i+1])
			{
			 	swap(a[i],a[i+1]);	
			 	NewN=i+1;
			} 
		n=NewN;
		cout<<n;
	}while (n>0);
}

int main(int argc, char const *argv[])
{
	int n,a[MaxN]={};
	cin>>n;
	for (int i=0;i<n;i++)
		cin>>a[i];
	BubbleSort(a,n);
	for (int i=0;i<n;i++)
		cout<<a[i]<<' ';
	return 0;
}
//迭代算法求解斐波那契数列中a[10]的值
#include <iostream>
#define MaxN 1000

using namespace std;

int main(int argc, char const *argv[])
{
	int f[MaxN]={0,1},n=10;
	for (int i=2;i<n;i++)
		f[i]=f[i-1]+f[i-2];
	cout<<f[n]<<endl;
	return 0;
}
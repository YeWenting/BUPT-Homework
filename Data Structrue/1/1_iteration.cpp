//迭代算法求解斐波那契数列中a[10]的值
#include <iostream>
#include <ctime>
#include <iomanip>
#define MaxN 1000

using namespace std;

int main(int argc, char const *argv[])
{
	int f[MaxN]={0,1},n=10;
	clock_t start=clock();
	for (int i=2;i<=n;i++)
		f[i]=f[i-1]+f[i-2];
	clock_t end=clock();
	cout.setf(ios::fixed);
	cout<<"f[10]="<<f[n]<<", consuming time is "<<setprecision(6)<<(double)(end-start)/CLOCKS_PER_SEC<<'.'<<endl;
	return 0;
}
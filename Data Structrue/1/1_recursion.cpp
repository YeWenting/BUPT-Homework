//递归算法求解斐波那契数列中a[10]的值
#include <iostream>
#include <ctime>
#include <iomanip>
#define MaxN 1000

using namespace std;

int Fib(int n)
{
	if (1>=n) return n;
	else return Fib(n-1)+Fib(n-2);
}

int main(int argc, char const *argv[])
{
	int f[MaxN]={0,1},n=40,ans;
	clock_t start=clock();
	ans=Fib(n);
	clock_t end=clock();
	cout.setf(ios::fixed);
	cout<<"f[40]="<<ans<<", consuming time is "<<setprecision(6)<<(double)(end-start)/CLOCKS_PER_SEC<<'.'<<endl;
	return 0;
}
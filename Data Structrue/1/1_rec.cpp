//递归算法求解斐波那契数列中a[10]的值
#include <iostream>
#define MaxN 1000

using namespace std;

int Fib(int n)
{
	if (n<=1) return n;
	else return Fib(n-1)+Fib(n-2);
}

int main(int argc, char const *argv[])
{
	int f[MaxN]={0,1},n=10;
	cout<<Fib(n)<<endl;
	return 0;
}
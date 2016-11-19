//题目要求随机生成一个1~1000的数字，让用户输入数字，若没猜对则提供两数的大小关系，直到猜对了为止
//考察知识点：标准流输入输出，while循环结构，通过调用 rand() ,srand(time(NULL))生成随机数
#include <iostream>
#include <cstdlib>
#include <ctime>
#define MaxPrice 1000
#define MinPrice 1

using namespace std;

int main(int argc, char const *argv[])
{
	srand(time(NULL));
	int Price=(rand()%MaxPrice)+1;
	cout<<"I have an amazing price in my mind,would you want to guess?"<<endl;
	int x;
	cin>>x;
	while (x!=Price)
	{
		if (x>Price)  cout<<"I have to say, this number is too big."<<endl;
		else cout<<"No this price, it's too small."<<endl;
		cin>>x;
	}
	cout<<"Wow! you are so damn clever! "<<Price<<" is exactly the price!!"
		<<endl<<"See you next time:)";
	return 0;
}
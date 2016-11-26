#include <iostream>
#include <ctime>
#include <cstdlib>

const int MaxNum = 201, multiple = 100000;

using namespace std;

int times, n;

int main(int argc, char const *argv[])
{
	int **a;

	srand(time(NULL));
 	cout<<"Please input N and K"<<endl;
 	cin>>n>>times;
 	a = new int* [multiple*n];
 	for (int i = 0; i < multiple*n; i++)
 	{
 		a[i] = new int [n];
 		for (int j = 0; j < n; j++)
 			a[i][j] = (rand() % (MaxNum + 1)) - MaxNum / 2;
 	}

 	clock_t start, end;
 	double duration;
 	start = clock();
 	for (int counter = 1; counter <= times; counter++)
 	{
 		int sum=0;
 		for (int i = 0; i < n; i++)
	 		for (int j = 0; j < multiple*n; j++)
	 			sum += a[j][i];
 	}
 	end = clock();
 	duration = (double)(end - start)/CLOCKS_PER_SEC;
 	cout<<"Tot:"<<duration<<" aver:"<<duration/times<<endl;
	return 0;
}
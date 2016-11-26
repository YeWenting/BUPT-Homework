#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int times1,times2;
const int MaxNum = 200;

void function1(int *a, int n)
{
	clock_t start, end;
 	double duration;

	start = clock();
	for (int counter = 1; counter <= times1; counter++ )
	{
		int ans = 0;
		for (int i = 0; i < n; i++)
			for (int j = i; j <n; j++)
			{
				int ThisSum=0;
				for (int k = i; k <= j; ThisSum += a[k], k++);
				if (ThisSum > ans) ans = ThisSum;
			}
//		if (counter == times) cout<<"The answer of algorithm1 is "<<ans<<endl;
	}
 	end = clock();
 	duration = (double)(end - start)/CLOCKS_PER_SEC;
 	cout<<"Algorithm1 \nTicks: "<<end-start<<"\nTotal time: "
 			<<duration<<"\nAverage execution time:"<<duration/times1<<endl;
 	return;
}

void function2(int *a, int n)
{
	clock_t start, end;
 	double duration;

	start = clock();
	for (int counter = 1; counter <= times2; counter++ )
	{
		int ans = 0, ThisSum = 0;
		for (int i = 0; i <n; i++)
		{
			ThisSum += a[i];
			if (ThisSum > ans) ans = ThisSum;
			if (ThisSum < 0) ThisSum = 0;
		}
//		if (counter == times) cout<<"The answer of algorithm3 is "<<ans<<endl;
	}
 	end = clock();
 	duration = (double)(end - start)/ (double)CLOCKS_PER_SEC;
 	cout<<"Algorithm3 \nTicks: "<<end-start<<"\nTotal time: "
 			<<duration<<"\nAverage execution time:"<<duration/times2<<endl;
 	return;
}

int main(int argc, char const *argv[])
{
 	int *a=NULL, n;

 	srand(time(NULL));
 	cout<<"Please input N, K1 and K2."<<endl;
 	cin>>n>>times1>>times2;
 	a = new int[n];
 	for (int i = 0; i < n; i++)
 		a[i] = (rand() % (MaxNum + 1)) - MaxNum / 2;
 	function1(a, n);
 	function2(a, n);
	return 0;
}
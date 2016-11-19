#include <iostream>
#include <cstdlib>
#define Row 4
#define Line 5

using namespace std;

void SetMatrix(int a[][Line])
{
	cout<<"Please input the matrix:"<<endl;
	for (int i=0;i<Row;i++)
		for (int j=0;j<Line;j++)
		{
			cin>>a[i][j];
			if (cin.fail()) cout<<endl<<"It's not a number！
				Please restart the program and try again"<<endl;
			if (cin.fail()) exit(-1);
		}
}
void PrintMatrix(const int a[][Line])
{
	for (int i=0;i<Row;i++)
		for (int j=0;j<Line;j++)
		{
			cout<<a[i][j];
			if (j==Line-1) cout<<endl;
			else cout<<' ';
		}
}
void Add(const int a[][Line],const int b[][Line],int c[][Line])
{
	for (int i=0;i<Row;i++)
		for (int j=0;j<Line;j++)
			c[i][j]=a[i][j]+b[i][j];
}
void Subtract(const int a[][Line],const int b[][Line],int c[][Line])
{
	for (int i=0;i<Row;i++)
		for (int j=0;j<Line;j++)
			c[i][j]=a[i][j]-b[i][j];
}
int main(int argc, char const *argv[])
{
	int a[Row][Line]={},b[Row][Line]={},c[Row][Line]={};
	SetMatrix(a);
	SetMatrix(b);
	Add(a,b,c);
	cout<<"a+b is equal to :"<<endl;
	PrintMatrix(c);
	Subtract(a,b,c);
	cout<<"a-b is equal to :"<<endl;
	PrintMatrix(c);
	return 0;
}


// 1 2 3 4 5
// 1 2 3 4 5
// 1 2 3 4 5
// 1 2 3 4 5
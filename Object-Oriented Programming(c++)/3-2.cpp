#include <iostream>
#include <cstdlib>
#define Row 4
#define Line 5

using namespace std;

void Initialize_Matrix(int **&a)
{
	a=(int **) new int *[Row];
	for (int i=0;i<Row;i++)
	{
		a[i]=new int[Line];
		memset(a[i],0,sizeof(int)*Line);
	} 
}
void SetMatrix(int **a)
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
void PrintMatrix(int **a)
{
	for (int i=0;i<Row;i++)
		for (int j=0;j<Line;j++)
		{
			cout<<a[i][j];
			if (j==Line-1) cout<<endl;
			else cout<<' ';
		}
}
void Add(int **a,int **b,int **c)
{
	for (int i=0;i<Row;i++)
		for (int j=0;j<Line;j++)
			c[i][j]=a[i][j]+b[i][j];
}
void Subtract(int **a,int **b,int **c)
{
	for (int i=0;i<Row;i++)
		for (int j=0;j<Line;j++)
			c[i][j]=a[i][j]-b[i][j];
}
int main(int argc, char const *argv[])
{
	int **a,**b,**c;
	Initialize_Matrix(a);
	Initialize_Matrix(b);
	Initialize_Matrix(c);
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
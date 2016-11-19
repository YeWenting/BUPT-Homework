#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

class Matrix
{
	public:
		Matrix(int,int);             //用指针动态创建数组
		Matrix(const Matrix&);		//拷贝赋值函数
		~Matrix();                  //析构函数
		void SetMatrix();			//给矩阵赋值
		void PrintMatrix();			//打印矩阵
		int GetNum(int i,int j) const { return num[i][j]; }
		Matrix operator+ (const Matrix&);
		Matrix operator- (const Matrix&);
	private:
		int **num,row,line;
};
Matrix::Matrix(int row,int line)
{
	this->row=row;
	this->line=line;
	num=(int **) new int *[row];
	for (int i=0;i<row;i++)
	{
		num[i]=new int[line];
		memset(num[i],0,sizeof(int)*line);
	} 
}
Matrix::Matrix(const Matrix& b)
{
	num=(int **) new int *[b.row];
	for (int i=0;i<b.row;i++)
	{
		num[i]=new int[b.line];
		for (int j=0;j<b.line;j++)
			num[i][j]=b.num[i][j];
	} 
}
Matrix::~Matrix()
{
	for (int i=0;i<row;i++)
		delete[] num[i];
	delete[] num;
	num=NULL;
}
void Matrix::SetMatrix()
{
	cout<<"Please input the matrix:"<<endl;
	for (int i=0;i<row;i++)
		for (int j=0;j<line;j++)
		{
			cin>>num[i][j];
			if (cin.fail()) cout<<endl<<"It's not a number！Please restart the program and try again!"<<endl;
			if (cin.fail()) exit(-1);
		}
}
void Matrix::PrintMatrix()
{
	for (int i=0;i<row;i++)
		for (int j=0;j<line;j++)
		{
			cout<<GetNum(i,j);
			if (j==line-1) cout<<endl;
			else cout<<' ';
		}
} 

Matrix Matrix::operator+ (const Matrix& b)
{
	Matrix c(row,line);
	if ((row!=b.row)||(line!=b.line)) 
	{
		cout<<"These matrixs are not in the same size, you bad bad:("<<endl;
		exit(-1);
	}
	for (int i=0;i<row;i++)
		for (int j=0;j<line;j++)  
			c.num[i][j]=num[i][j]+b.num[i][j];    //可否用 private 成员
	return c;
}

Matrix Matrix::operator- (const Matrix& b)
{
	Matrix c(row,line);
	if ((row!=b.row)||(line!=b.line)) 
	{
		cout<<"These matrixs are not in the same size, you bad bad:("<<endl;
		exit(-1);
	}
	for (int i=0;i<row;i++)
		for (int j=0;j<line;j++)
			c.num[i][j]=num[i][j]-b.num[i][j];
	return c;
}

int main(int argc, char const *argv[])
{
	int row,line;
	//用定义方式
	cout<<"Please input the size of matrix A:"<<endl;
	cin>>row>>line;
	Matrix a(row,line);
	a.SetMatrix();
	cout<<"Please input the size of matrix B:"<<endl;
	cin>>row>>line;
	Matrix b(row,line);
	b.SetMatrix();
	cout<<"The a+b is equal to:"<<endl;
	(a+b).PrintMatrix();
	cout<<"The a-b is equal to:"<<endl;
	(a-b).PrintMatrix();
 	// 用 new 动态申请 matrix 类
	cout<<"Please input the size of matrix A:"<<endl;
	cin>>row>>line;
	Matrix *aPtr=new Matrix(row,line);
	aPtr->SetMatrix();
	cout<<"Please input the size of matrix B:"<<endl;
	cin>>row>>line;
	Matrix *bPtr=new Matrix(row,line);
	bPtr->SetMatrix();
	cout<<"The a+b is equal to:"<<endl;
	(*aPtr+*bPtr).PrintMatrix();
	cout<<"The a-b is equal to:"<<endl;
	(*aPtr-*bPtr).PrintMatrix();
	delete aPtr;
	delete bPtr;
	return 0;
}
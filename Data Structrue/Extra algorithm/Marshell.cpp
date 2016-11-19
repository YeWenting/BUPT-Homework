#include <iostream>

using namespace std;

class MyMap
{
	public:
		void Read_Data();
		void Print_Matrix();
		void Get_Closure();
		void Print_Closure();
	private:
		int a[10][10],n,w[10][10];
};

void MyMap::Read_Data()
{
	int e;
	memset(a,0,sizeof(a));
	cin>>n>>e;
	for (int i=0;i<e;i++)
	{
		char x,y;
		cin>>x>>y;
		a[x-'a'+1][y-'a'+1]=1;
		w[x-'a'+1][y-'a'+1]=1;
	}
}

void MyMap::Print_Matrix()
{
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
		{
			cout<<a[i][j]<<" ";
			if (j==n) cout<<endl;
		}
} 

void MyMap::Print_Closure()
{
	cout<<"The closure of the graphis :"<<endl;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
		{
			cout<<w[i][j]<<" ";
			if (j==n) cout<<endl;
		}
} 

void MyMap::Get_Closure()
{
	for (int k=1;k<=n;k++)
	{
		for (int i=1;i<=n;i++)
			for (int j=1;j<=n;j++)
				w[i][j]=w[i][j]||(w[i][k]&&w[k][j]);
	}
}

int main(int argc, char const *argv[])
{
	MyMap a;
	a.Read_Data();
	a.Get_Closure();
	a.Print_Closure();
	return 0;
}

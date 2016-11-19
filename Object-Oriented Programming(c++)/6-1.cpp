#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>

using namespace std;

int main(int argc, char const *argv[])
{
	ofstream MyFile;
	int a=1;
	unsigned int b=12333;
	long c=250;
	float d=5.201314;
	char s[]="Hello World!";
	MyFile.open("Experiment.txt",ios::trunc);
	if (InFile.fail()) 
	{
		cout<<"There is some problem when opening the file"<<endl;
		return -1;
	}
	MyFile<<a<<endl;
	MyFile<<b<<endl;
	MyFile<<c<<endl;
	MyFile<<d<<endl;
	MyFile<<s<<endl;
	MyFile<<b<<' '<<hex<<b<<endl; //调用一次 hex 以后始终生效
	MyFile<<b<<' '<<oct<<b<<endl;
	MyFile<<setw(8)<<a<<' '<<b<<endl;
	MyFile<<d<<' '<<setprecision(4)<<d<<endl;
	MyFile.close();
	return 0;
}

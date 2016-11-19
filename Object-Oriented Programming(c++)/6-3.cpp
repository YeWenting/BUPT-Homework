#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <fstream>
#include <cstring>

using namespace std;

int main(int argc, char const *argv[])
{
	int x;
	string Origin,Target;
	cin>>Origin;
	ifstream InFile;
	ofstream OutFile;
	Target="New "+Origin;
	InFile.open(Origin,ios::in);
	if (InFile.fail()) 
	{
		cout<<"There is some problem when opening the original file"<<endl;
		return -1;
	}
	OutFile.open(Target,ios::trunc);
	if (InFile.fail()) 
	{
		cout<<"There is some problem when opening the target file"<<endl;
		return -1;
	}
	int Line=1;
	while (!InFile.eof())
	{
		string s;
		getline(InFile,s);
		OutFile<<setw(3)<<Line<<' '<<s<<endl;
		Line++;
	}
	InFile.close();
	OutFile.close();
	return 0;
}
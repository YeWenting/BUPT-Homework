#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
	{
		std::vector<int> a;
		a.push_back(1);
		a.push_back(2);

		std::vector<int> b;
		b.push_back(1);
		b.push_back(3);

		auto i = a.begin() + 1;
		auto j = b.begin() + i;

		cout<<*j<<endl;
		return 0;
	}	
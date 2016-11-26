#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <fstream>

using namespace	std;

int main(int argc, char const *argv[])
{
	int flag, n;
	ofstream outfile("data.dat");

	cout<<"What kind of data you want to generate? 1:worst 2:best 3.random\n";
	cin>>flag;
	cout<<"And size?\n";
	cin>>n;

	vector<int> data;
	switch (flag)
	{
		case 1:
				for (int i = 0; i < n; ++i) data.push_back(n-i-1);
				break;
		case 2:
				for (int i = 0; i < n; ++i) data.push_back(i);
				break;
		case 3:
				for (int i = 0; i < n; ++i) data.push_back(i);
				random_shuffle(data.begin(), data.end());
				break;
	}

	outfile<<n<<endl;
	copy(data.begin(), data.end(), ostream_iterator<int>(outfile, " "));
	return 0;
}
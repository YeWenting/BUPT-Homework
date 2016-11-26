#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;

	std::vector<int> data(n);
	for (vector_iterator<int> iter = data.begin(); iter < data.end(); iter++)
		cin>>*iter;
	copy(data.begin(), data.end(), ostream_iterator<int>(cout, "\n"));
	return 0;
}
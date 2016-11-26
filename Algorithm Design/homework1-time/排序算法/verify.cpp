//
//  main.cpp
//  HomeWork II
//
//  Created by YeWenting. on 16/4/13.
//  Copyright © 2016年 School of Computer Science. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
#include <fstream>
#include <string>

using namespace std;

bool Orderly(const vector<int> &data)
{
    for (auto i = data.begin()+1; i < data.end(); ++i)
        if (*(i-1) > *i) return 0;
    return 1;
}

void Initialize(std::vector<int> &data)
{
	int n;
	ifstream infile("Sorted_data.txt");
	infile>>n;
	for (int i = 0; i < n; ++i)
	{
		int x;
		infile>>x;
		data.push_back(x);
	}
}

int main(int argc, char const *argv[])
{
	std::vector<int> data;
	Initialize(data);
	if (Orderly(data)) cout<<"The data is sorted!"<<endl;
	else cout<<"The data is not sorted:("<<endl;
	return 0;
}
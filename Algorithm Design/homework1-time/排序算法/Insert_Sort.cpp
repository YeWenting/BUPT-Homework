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
#include <ctime>
#include <cstdlib>

using namespace std;

class SortCost
{
public:
    int compare, move;
    SortCost(){ compare = 0; move = 0; }
};

void Initialize(vector<int> &data)
{
	ifstream infile("data.dat");
	int n;

	infile>>n;
	for (int i = 0; i < n; ++i)
	{
		int x;
		infile>>x;
		data.push_back(x);
	}
}

void Insert_Sort(vector<int> data)
{
    SortCost cost;
    clock_t start, end;
    double duration;
    ofstream outfile("Sorted_data.txt");

    start = clock();
    for (int i = 1; i < data.size(); ++i)
    {
        int j = i-1;
        while (j >= 0 && data[j] > data[i]) j--;            //j 指向的是最大的比 data[i]小的数字，j+1是data[i]应该放的地方
        cost.compare += i - j;
        cost.move += i - j + 1;
        int temp = data[i];
        for (int iter = i; iter > j+1; iter--)
            data[iter] = data[iter-1];
        data[j+1] = temp;
    }
    end = clock();
    duration = (double)(end - start)/ (double)CLOCKS_PER_SEC;
    outfile<<data.size()<<endl;
    copy(data.begin(), data.end(), ostream_iterator<int>(outfile, " "));
    cout<<endl;
    outfile<<"Use "<<cost.compare<<" compare operations and "<<cost.move<<" move operation!"<<endl;
}

int main(int argc, char const *argv[])
{
	std::vector<int> data;

	Initialize(data);
	Insert_Sort(data);
	return 0;
}

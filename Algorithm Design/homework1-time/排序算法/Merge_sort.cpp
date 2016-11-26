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


void Merge(vector<int> &source, vector<int> &dest, int l, int m, int r, SortCost &cost)
{
    int i = l, j = m, k = l;                                //第一次 k = 0 bug
    
    while (i < m && j < r)
    {
        if (source[i] < source[j]) dest[k++] = source[i++];
        else dest[k++] = source[j++];
    }
    cost.compare += k - l;
    if (i < m)
        for (; i < m; ++i)  dest[k++] = source[i];
    else
        for (; j < r; ++j)  dest[k++] = source[j];
}

void Merge_Pass(vector<int> &source, vector<int> &dest, const int &len, SortCost &cost)
{
    int i = 0;                                              //Q:迭代器写法
    
    while (i + 2 * len <= source.size())                    //最后一个元素如果没有越界
    {
        Merge(source, dest, i, i + len, i + 2 * len, cost);
        i += 2 * len;
    }
    if (i + len < source.size())
        Merge(source, dest, i, i + len, (int)source.size(), cost);
    else
    {
        while (i < source.size())
        {
            dest[i] = source[i];
            i++;
        }
    }
    cost.move += source.size();
}

void Merge_Sort(vector<int> data)
{
    vector<int> clone(data.size());
    int len = 1;
    SortCost cost;
    clock_t start, end;
    double duration;
    ofstream outfile("Sorted_data.txt");
    
    start = clock();
    while (len < data.size())
    {
        Merge_Pass(data, clone, len, cost);
        len = len << 1;
        Merge_Pass(clone, data, len, cost);
        len = len << 1;
    }
    end = clock();
    duration = (double)(end - start)/ (double)CLOCKS_PER_SEC;
    outfile<<data.size()<<endl;
    copy(data.begin(), data.end(), ostream_iterator<int>(outfile, " "));
    outfile<<endl;
    outfile<<"Use "<<cost.compare<<" compare operations and "<<cost.move<<" move operation!"<<endl;
}

int main(int argc, char const *argv[])
{
	std::vector<int> data;

	Initialize(data);
	Merge_Sort(data);
	return 0;
}

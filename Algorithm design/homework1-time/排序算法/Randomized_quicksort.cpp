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

void QuickSort(vector<int> &data, const int &l, const int &r, SortCost &cost)
{
    int i = l, j = r, m = l + rand() % (r - l + 1);
    if (r - l + 1 <= 1) return;
    int num = data[m];
    while (i <= j)
    {
        while (data[i] < num) i++;
        while (num <= data[j]) j--;
        if (i < j)
        {
            int temp = data[i];
            data[i] = data[j];
            data[j] = temp;
            i++; j--;
            cost.move += 3;
        }
    }
    cost.compare += r - l + 1;
    if (i < r) QuickSort(data, i, r, cost);
    if (l < j) QuickSort(data, l, j, cost);
}

double Quick_Sort(vector<int> data)
{
    SortCost cost;
    clock_t start, end;
    double duration;
    ofstream outfile("Sorted_data.txt");
    
    start = clock();

    QuickSort(data, 0, (int)data.size() - 1, cost);

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
	Quick_Sort(data);
	return 0;
}

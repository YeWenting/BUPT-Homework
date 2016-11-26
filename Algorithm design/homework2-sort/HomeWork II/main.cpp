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


void Initialize(vector<int> &data, int n)
{
    int flag;
    
    data.clear();
    srand((unsigned) time(NULL));
    flag = 3;
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
}

bool Orderly(const vector<int> &data)
{
    for (auto i = data.begin()+1; i < data.end(); ++i)
        if (*(i-1) > *i) return 0;
    return 1;
}

SortCost Insert_Sort(vector<int> data)
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
    return cost;
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

SortCost Merge_Sort(vector<int> data)
{
    vector<int> clone(data.size());
    int len = 1;
    SortCost cost;
    clock_t start, end;
    double duration;
    
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
    return cost;
//    if (Orderly(data)) cout<<"The merge sort gives the right answer in "<<duration<<
//        " , use "<<cost.compare<<" compare operation and "<<cost.move<<" move operation!"<<endl;
//    else cout<<"The merge sort gives the wrong answer:("<<endl;
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

SortCost Quick_Sort(vector<int> data)
{
    SortCost cost;
    clock_t start, end;
    double duration;
    
    start = clock();
    QuickSort(data, 0, (int)data.size() - 1, cost);
    end = clock();
    duration = (double)(end - start)/ (double)CLOCKS_PER_SEC;
    return cost;
//    if (Orderly(data)) cout<<"The quick sort gives the right answer in "<<duration<<
//        " , use "<<cost.compare<<" compare operation and "<<cost.move<<" move operation!"<<endl;
//    else cout<<"The quick sort gives the wrong answer:("<<endl;
}

int main(int argc, char const *argv[])
{
    vector<int> data;
    vector<double> used_time1, used_time2, used_time3;
    
        Initialize(data, 10000);
    cout<<Insert_Sort(data).compare<<endl;
    cout<<Merge_Sort(data).compare<<endl;
    cout<<Quick_Sort(data).compare<<endl;
    cout<<Insert_Sort(data).move<<endl;
    cout<<Merge_Sort(data).move<<endl;
    cout<<Quick_Sort(data).move<<endl;
//
//    
//    ofstream outfile("Time_Figure.nb");
//    outfile<<"data1={";
//    for (int i = 0; i < used_time1.size(); i++)
//        outfile<<used_time1[i]<<',';
//    outfile<<"}"<<endl;
//    outfile<<"data2={";
//    for (int i = 0; i < used_time2.size(); i++)
//        outfile<<used_time2[i]<<',';
//    outfile<<"}"<<endl;
//    outfile<<"data3={";
//    for (int i = 0; i < used_time3.size(); i++)
//        outfile<<used_time3[i]<<',';
//    outfile<<"}"<<endl;
    return 0;
}
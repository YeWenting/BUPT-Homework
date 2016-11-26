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

typedef vector<int>::iterator iter;

void Initialize(vector<int> &data)
{
    int flag, n;
    
    cout<<"What kind of data you want to generate? 1:worst 2:best 3.random\n";
    cin>>flag;
    cout<<"And size?\n";
    cin>>n;
    
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

void Insert_Sort(vector<int> data)
{
    for (auto i = data.begin(); i < data.end(); ++i)
    {
        auto j = i;
        while (*j < *(j-1) && j > data.begin()) j--;
        data.insert(j);
    }
}

int main(int argc, char const *argv[])
{
    vector<int> data;
    
    Initialize(data);
    //Insert_Sort(data);
    //Merge_Sort(data);
    //Quick_Sort(data);
    return 0;
}
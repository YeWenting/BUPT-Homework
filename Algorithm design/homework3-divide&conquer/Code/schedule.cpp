//
//  schedule.cpp
//  Algorithm No.3 Work
//
//  Created by YeWenting. on 16/4/23.
//  Copyright © 2016年 School of Computer Science. All rights reserved.
//

#include <stdio.h>
#include <fstream>
#include "schedule.h"

using namespace std;

int schedule::Get_Duration(const int &n)
{
    if (n % 2 == 1) return n;
    else return n - 1;
}

schedule::schedule(int n):date(n), compete(n)
{
    for (int i = 0; i < n; ++i)
    {
        date[i].resize(n);
        compete[i].resize(n);
    }
    success = 0;
}

schedule::schedule(ifstream &infile):date(0), compete(0)
{
    int days;
    infile >> n >> days;
    date.resize(n + 1);
    compete.resize(n + 1);
    for (int i = 0; i < n + 1; ++i)
    {
        date[i].resize(n + 1);
        compete[i].resize(n + 1);
    }
    for (int i = 1; i <= days; ++i)
        for (int j = 1; j <= n; ++j)
            infile >> date[i][j];
    m = days;
}

void schedule:: Make_Schedule(const int &n)
{
    if (n == 2)                             //table[i][subgroup + 1] 闲人和谁打
    {
        date[1][1] = 2;
        date[1][2] = 1;
        return;
    }
    int sub_group = (n + 1) / 2, duration = Get_Duration(sub_group);
    Make_Schedule(sub_group);
    //内部比赛
    for(int i = 1; i <= duration; i++)
        for (int j = sub_group + 1; j <= 2 * sub_group; j++)
            if (date[i][j - sub_group] == 0)
            {
                date[i][j - sub_group] = j;
                date[i][j] = j - sub_group;
            }
            else date[i][j] = date[i][j - sub_group] + sub_group;
    //两个 subgroup 互打
    int k = (sub_group % 2 == 1)? 1 : 0;
    for (int i = duration + 1; k < sub_group; k++, i++)
        for (int j = 1; j <= sub_group; j++)
        {
            int next;
            if ((j + k) % sub_group == 0) next = 2 * sub_group;
            else next = sub_group + (j + k) % sub_group;
            date[i][j] = next;
            date[i][next] = j;
        }
    //delete the fake people
    if (n % 2 == 1)
        for (int i = 1; i <= Get_Duration(n); ++i)
            date[i][date[i][2 * sub_group]] = 0;
}

void schedule::Print_Schdule()
{
    ofstream outfile("Schedule.txt");
    int n = (int) date.size() - 1;
    int days = n;
    
    if (n % 2 == 0) days--;
    outfile << n <<' '<< days <<endl;
    for (int i = 1; i <= days; ++i, outfile<<endl)
        for (int j = 1; j <= n; ++j)
            outfile << date[i][j] << ' ';
}



//
//  main.cpp
//  Algorithm No.3 Work
//
//  Created by YeWenting. on 16/4/22.
//  Copyright © 2016年 School of Computer Science. All rights reserved.
//
//

#include <iostream>
#include <vector>
#include <fstream>
#include "schedule.h"

using namespace std;

void Arrange_Game(const int day, const int x, schedule &table, const int &spare)        //in "day" day, participant x
{
    int n = (int) table.date.size() - 1;                                                //the num of participant
    if (x > n)
    {
        table.success = 1;
        return;
    }
    //如果选手 x 已经被安排或是闲人，则跳过
    if (table.date[day][x] != 0 || x == spare)
        Arrange_Game(day, x + 1, table, spare);
    else for (int i = x + 1; i <= n; ++i)
        if (table.compete[x][i] == 0 && i != spare && table.date[day][i] == 0)          //如果没比赛过且可以当做对手
        {
            table.date[day][x] = i; table.date[day][i] = x;
            table.compete[i][x] = 1; table.compete[x][i] = 1;
            Arrange_Game(day, x + 1, table, spare);
            if (table.success == 1) return;
            table.date[day][x] = 0; table.date[day][i] = 0;                             //回溯
            table.compete[i][x] = 0; table.compete[x][i] = 0;
        }
}

void Naive_Algorithm(const int &n)
{
    schedule table(n + 1);
    
    if (n % 2 == 0)
        for (int day = 1; day <= n-1; ++day)                                            //n-1 days
        {
            table.success = 0;
            Arrange_Game(day, 1, table, 0);
        }
    else
        for (int day = 1; day <= n; ++day)                                              //n days
        {
            //in day x, participant n - x + 1 is spare out
            table.success = 0;
            Arrange_Game(day, 1, table, n - day + 1);
        }
    table.Print_Schdule();
}

int main(int argc, const char * argv[]) {
    
    int n;
    cin >> n;
//    Naive_Algorithm(n);
    schedule table(n + 1);
    table.Make_Schedule(n);
    table.Print_Schdule();
    return 0;
}

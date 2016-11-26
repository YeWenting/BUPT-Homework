//
//  check_rightness.cpp
//  Algorithm No.3 Work
//
//  Created by YeWenting. on 16/4/23.
//  Copyright © 2016年 School of Computer Science. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <fstream>
#include "schedule.h"

using namespace std;

void Quit(int x)
{
    if (x == 1)
        cout << "The answer is correct." << endl;
    else
        cout << "The answer is wrong:(" << endl;
    exit(0);
}

int main(int argc, const char * argv[])
{
    ifstream infile("Schedule.txt");
    
    schedule table(infile);
    for (int day = 1; day <= table.m; ++day)
    {
        vector <bool> used(table.n + 1);
        for (int i = 1; i <= table.n; ++i)
            if (used[table.date[day][i]] == 0 && table.compete[i][table.date[day][i]] == 0)     // new and spare opponent
            {
                used[table.date[day][i]] = 1;
                table.compete[i][table.date[day][i]] = 1;
            }
            else
                Quit(0);
    }
    Quit(1);
    return 0;
}
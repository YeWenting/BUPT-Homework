//
//  schedule.h
//  Algorithm No.3 Work
//
//  Created by YeWenting. on 16/4/23.
//  Copyright © 2016年 School of Computer Science. All rights reserved.
//

#ifndef schedule_h
#define schedule_h

#include <vector>

class schedule
{
public:
    schedule():date(0),compete(0){}
    schedule(int);
    schedule(std::ifstream &);
    std::vector< std::vector<int> >   date;         //存放时间安排表
    std::vector < std::vector<bool> > compete;      //compete[i][j] 表示 i 和 j是否打过比赛
    bool success;
    int n, m;                                       // n 是人数 m 是所要的天数
    void Make_Schedule(const int &);
    int Get_Duration(const int &);
    void Print_Schdule();
};


#endif /* schedule_h */

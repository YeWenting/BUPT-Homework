//
//  create_data.cpp
//  Algorithm Homework No. 4
//
//  Created by YeWenting. on 16/5/14.
//  Copyright © 2016年 School of Computer Science. All rights reserved.
//

#include <iostream>
#include <ctime>
#include <fstream>

#include "pyramid.h"

using namespace std;

int main(int argc, const char * argv[])
{
    
//生成1000个规模为15的随机数据，比较两个算法的结果是否一致。用于测试算法正确性
    int right = 0;
    for (int i = 0; i < 1000; ++i)
    {
        pyramid a(15);
        if (a.DP_make_money() == a.DC_make_money(0, 0)) right++;
        else
        {
            cout << a.DP_make_money() << endl;
            a.print_route();
            cout << a.DC_make_money(0, 0) << endl;
            a.print_route();
        }
    }
    cout <<"Test 1000 examples, the two algorithm give "<< right << " right answers of 1000, accept rate is " << (double) right / 10 <<"%."<< endl;

    
//生成不同规模的数据，分别统计两个算法的耗时。用于测试算法时间复杂度。
    ofstream ofile("time.nb");
    
    ofile << "data1={";
    for (int i = 2; i < 25; i++)
    {
        pyramid a(i);
        clock_t start = clock();
        a.DC_make_money(0, 0);
        clock_t end = clock();
        double duration = (double)(end - start) / CLOCKS_PER_SEC;
        ofile << '{'<<i<<','<<duration<<'}';
    }
    
    ofile << "}\n" << "data2={";
    for (int i = 2; i < 5000; i+=50)
    {
        pyramid a(i);
        clock_t start = clock();
        a.DP_make_money();
        clock_t end = clock();
        double duration = (double)(end - start) / CLOCKS_PER_SEC;
        ofile << '{'<<i<<','<<duration<<'}';
    }
    ofile << "}" << endl;
    return 0;
}
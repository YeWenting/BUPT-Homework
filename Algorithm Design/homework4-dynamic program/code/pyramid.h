//
//  pyramid.h
//  Algorithm Homework No. 4
//
//  Created by YeWenting. on 16/5/13.
//  Copyright © 2016年 School of Computer Science. All rights reserved.
//

#ifndef pyramid_h
#define pyramid_h

#include <vector>

class pyramid
{
public:
    pyramid(int);
    void get_pyramid();
    int DP_make_money();
    int DC_make_money(int, int);
    void print_route();
    
private:
    
    int n;
    std::vector < std::vector<int> > value;
    std::vector < std::vector<int> > route;
};


#endif /* pyramid_h */

//
//  main.cpp
//  Algorithm Homework No. 4
//
//  Created by YeWenting. on 16/5/13.
//  Copyright © 2016年 School of Computer Science. All rights reserved.
//

#include <iostream>

#include "pyramid.h"

using namespace std;

int main(int argc, const char * argv[])
{
    pyramid a;
    
    a.get_pyramid();
    
    cout << a.DP_make_money() << endl;
    a.print_route();
    return 0;
}

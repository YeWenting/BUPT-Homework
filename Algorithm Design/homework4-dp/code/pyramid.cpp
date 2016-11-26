//
//  pyramid.cpp
//  Algorithm Homework No. 4
//
//  Created by YeWenting. on 16/5/13.
//  Copyright © 2016年 School of Computer Science. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include "pyramid.h"

#define max(a,b) ((a) > (b) ? (a) : (b))

using namespace std;

pyramid::pyramid(int x)
{
    
    srand((unsigned int)clock());
    
    n = x;
    
    value.resize(n);
    route.resize(n);
    
    for (int i = 0; i < n; ++i)
    {
        value[i].resize(i + 1);
        route[i].resize(i + 1);
        
        for (int j = 0; j < i + 1; ++j)
            value[i][j] = rand() % 100;
    }
    
    route[0][0] = 0;
}

void pyramid::get_pyramid()
{
    cout << "Please input the size of pyramid and the pyramid:" << endl;
    cin >> n;
    
    value.resize(n);
    route.resize(n);
    
    for (int i = 0; i < n; ++i)
    {
        value[i].resize(i + 1);
        route[i].resize(i + 1);
        
        for (int j = 0; j < i + 1; ++j)
            cin >> value[i][j];
    }
    
}

int pyramid::DC_make_money(int x, int y)
{
    if (x == n - 1)
        return value[x][y];
    else
    {
        int l = DC_make_money(x + 1, y), r = DC_make_money(x + 1, y + 1);
        if (l >= r)
        {
            route[x][y] = y;
            return value[x][y] + l;
        }
        else
        {
            route[x][y] = y + 1;
            return value[x][y] + r;
        }
    }
}

int pyramid::DP_make_money()
{
    vector < vector<int> > f(n);
    int ans = 0;
    
    for (int i = 0; i < n; ++i)
        f[i].resize(n);
    
    for (int i = 0; i < n; ++i)
        for (int j = 0;j < n; ++j)
            f[i][j] = 0;
    
    f[0][0] = value[0][0];
    
    for (int i = 1; i < n; ++i)
        for (int j = 0; j <= i; ++j)
            if (j > 0)
                f[i][j] = max(f[i - 1][j], f[i - 1][j - 1]) + value[i][j];
            else
                f[i][j] = f[i - 1][j] + value[i][j];
    
    for (int j = 0; j < n; ++j)
        if (ans < f[n - 1][j]) ans = f[n - 1][j];
    
    for (int i = n - 2; i >= 0; --i)
        for (int j = 0; j <= i; ++j)
            if (f[i + 1][j] > f[i + 1][j + 1])
                route[i][j] = j;
            else
                route[i][j] = j + 1;
    
    return ans;
}

void pyramid::print_route()
{
    cout << "The best way is :";
    
    int i = 0, j = 0;
    while (i < n - 1)
    {
        cout << '(' << i + 1 << ',' << j + 1 <<',' << value[i][j] << ")->";
        j = route[i][j];  i++;
    }
    cout << '(' << i + 1 << ',' << j + 1 <<',' << value[i][j] << ')' << endl;
    cout << endl;
}
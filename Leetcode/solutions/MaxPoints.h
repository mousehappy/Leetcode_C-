//
//  MaxPoints.h
//  impala_be
//
//  Created by shwang on 8/20/14.
//  Copyright (c) 2014 shwang. All rights reserved.
//

#ifndef __impala_be__MaxPoints__
#define __impala_be__MaxPoints__

#include <iostream>
#include <vector>
using namespace std;

struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};

class MaxPoints {
public:
    int maxPoints(vector<Point> &points);
};

#endif /* defined(__impala_be__MaxPoints__) */

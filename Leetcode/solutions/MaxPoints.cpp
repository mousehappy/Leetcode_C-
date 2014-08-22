//
//  MaxPoints.cpp
//  impala_be
//
//  Created by shwang on 8/20/14.
//  Copyright (c) 2014 shwang. All rights reserved.
//

#include "MaxPoints.h"
#include <map>
#include <ext/hash_map>
#include <limits>

#define getGrad(p1, p2) (float)(p1.y - p2.y)/(p1.x-p2.x)


int MaxPoints::maxPoints(vector<Point> &points)
{
    if(points.size() <= 2)
    {
        return points.size();
    }
    map<float, int> LineMap;
    
    int pointCnt = points.size();
    int max = 0;
    int samePoints = 1;
    
    for(int i = 0; i < pointCnt; i++)
    {
        LineMap.clear();
        samePoints = 1;
        for (int j = i+1; j < pointCnt; j++) {
            Point p1 = points[i];
            Point p2 = points[j];
            
            float grad = 0;
            if(p1.x == p2.x && p1.y == p2.y)
            {
                samePoints++;
            }
            else
            {
                if (p1.x == p2.x)
                {
                    grad = std::numeric_limits<float>::infinity();
                }
                else
                {
                    grad = getGrad(p1, p2);
                }
                
                if(LineMap.find(grad) == LineMap.end())
                {
                    LineMap[grad] = 2;
                }
                else
                {
                    LineMap[grad] ++;
                }
            }
        }
        
        if(LineMap.size() == 0)
        {
            if(max < samePoints)
            {
                max = samePoints;
            }
        }
        else
        {
            map<float, int>::iterator iter = LineMap.begin();
            for (; iter != LineMap.end(); iter++) {
                if (max < iter->second + samePoints -1) {
                    max = iter->second + samePoints -1;
                }
            }
        }
    }
    
    return max;
}


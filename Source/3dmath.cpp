//
//  3dmath.cpp
//  Racing
//
//  Created by Brownlee on 11-08-25.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include"3dmath.h"

float degToRad(float deg){
    return deg/180.0f *PI;
}

float radToDeg(float rad){
    return rad* 180.0f /PI;
}

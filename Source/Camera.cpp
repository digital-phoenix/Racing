//
//  Camera.cpp
//  Racing
//
//  Created by Brownlee on 11-08-31.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include"Camera.h"

void Camera::clear(){
    Camera  identity;
    (*this) = identity;
}
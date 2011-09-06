//
//  Frustum.cpp
//  Racing
//
//  Created by Brownlee on 11-08-25.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "Frustum.h"
#include "3dmath.h"

    
std::vector<GLfloat> Frustum::constructFrustum(GLfloat aspect, GLfloat angle, GLfloat near, GLfloat far){
    
    //std::cout<<"aspect="<<aspect<<" angle="<<angle<<" near="<<near<<" far="<<far<<'\n';
    angle = degToRad(angle);
    
    GLfloat frustrum[]={ 1/tan(angle), 0, 0, 0,
                        0, aspect/tan(angle), 0, 0,
                        0, 0, (far+near)/(far - near), 1,
                        0, 0, -2.0f*far*near/(far - near), 0};
    
    return std::vector<GLfloat>(frustrum, frustrum +sizeof(frustrum)/sizeof(GLfloat) );
 
}
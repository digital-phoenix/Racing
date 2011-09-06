//
//  Vector.cpp
//  Racing
//
//  Created by Brownlee on 11-09-04.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include <iostream>

#include "Vector.h"

Vector::Vector(){
    x = 0.0f ;
    y = 0.0f ;
    z = 0.0f ;
    w = 1.0f;
}

Vector::Vector(GLfloat x, GLfloat y, GLfloat z, GLfloat w){
    this->setValues(x,y,z,w);
}

void Vector::setValues(GLfloat x, GLfloat y, GLfloat z, GLfloat w){
    
    this->x = x;
    this->y = y;
    this->z = z;
    this->w = w;
    
}


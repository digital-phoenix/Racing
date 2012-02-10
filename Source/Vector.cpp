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

Vector::Vector(const Vector &v){

    x = v.getX();
    y = v.getY();
    z = v.getZ();
    w = v.getW();

}

Vector::Vector( Matrix m){
    if (m.getHeight() != 4 || m.getWidth() != 1 ) {
        std::cout<<"Error matrix m is a "<<m.getHeight()<< " by "<<m.getWidth()<<" matrix not a 1 by 4 matrix\n";
        setValues(0,0,0,0);
    }
    x= m[0];
    y= m[1];
    z= m[2];
    w= m[3];
}

Vector::Vector(GLfloat x, GLfloat y, GLfloat z, GLfloat w){
    this->setValues(x,y,z,w);
}

Vector Vector::operator=(const Vector& rhs){
    x = rhs.getX();
    y = rhs.getY();
    z = rhs.getZ();
    w = rhs.getW();
    
    return *this;
}

void Vector::setValues(GLfloat x, GLfloat y, GLfloat z, GLfloat w){
    
    this->x = x;
    this->y = y;
    this->z = z;
    this->w = w;

}

GLfloat Vector::dot (Vector other){
    return (x * other.getX() + y * other.getY() + z * other.getZ() );
}

void Vector::print(){
    std::cout<<x<<" "<<y<<" "<<z<<" \n";
}
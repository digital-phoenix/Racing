//
//  Matrix4f.cpp
//  
//
//  Created by Brownlee on 11-08-24.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include"Matrix4f.h"
#include"3dmath.h"



Matrix4f Matrix4f::operator=(const Matrix& rhs ){
    if(rhs.getWidth()!=4 || rhs.getHeight()!=4)
        return *this;
    Matrix::operator=(rhs);
    return *this;
}

const Matrix4f Matrix4f::operator*(const Matrix4f &rhs)const{
    Matrix4f newMatrix = *this;
    newMatrix *=rhs;
    return newMatrix;
}

const Matrix Matrix4f::operator*(const Vector &rhs)const{
    
    
    std::vector<GLfloat> v;
    v.push_back( rhs.getX());
    v.push_back( rhs.getY());
    v.push_back( rhs.getZ());
    v.push_back( rhs.getW());
    
    Matrix vectorMatrix( 1, 4, v);
    
    Matrix newMatrix = *this;
    
    newMatrix *=vectorMatrix;
    
    return newMatrix;

}


std::vector<GLfloat> Matrix4f::constructIdentity(){
    GLfloat m[]={1,0,0,0,
                0,1,0,0,
                0,0,1,0,
                0,0,0,1};
    return std::vector<GLfloat>(m, m + sizeof(m)/sizeof(GLfloat) );
}

Matrix4f Matrix4f::translate(GLfloat x, GLfloat y, GLfloat z){
    
    GLfloat m[]={1.0, 0.0, 0.0, 0.0,
        0.0, 1.0, 0.0, 0.0,
        0.0, 0.0, 1.0, 0.0,
        x,   y,   z,   1.0};
    
    Matrix4f translationMatrix(std::vector<GLfloat>(m, m+ sizeof(m)/sizeof(GLfloat) ) );
    (*this) *= translationMatrix;
    
    return  *this;
    
}

Matrix4f Matrix4f::scale(GLfloat x, GLfloat y, GLfloat z){
    
    GLfloat m[]={x,0.0, 0.0, 0.0,
        0.0, y,0.0, 0.0,
        0.0, 0.0, z,   0.0,
        0.0, 0.0, 0.0, 1.0};

    Matrix4f scaleMatrix(std::vector<GLfloat>(m, m+ sizeof(m)/sizeof(GLfloat) ) );
    (*this) *= scaleMatrix;
    
    return  *this;
    
}

Matrix4f Matrix4f::rotate(GLfloat x, GLfloat y, GLfloat z){
    
    x = degToRad(x);
    y = degToRad(y);
    z = degToRad(z);
    
    if( !(x<EPSILON && x>-EPSILON) ){
        GLfloat xRotation[]={ 1, 0, 0, 0,
                            0, cos(x), sin(x), 0,
                            0, -sin(x), cos(x), 0,
                            0, 0, 0, 1};
        std::vector<GLfloat>xVal(xRotation, xRotation +sizeof(xRotation) /sizeof(GLfloat) );
        Matrix4f xRotationMatrix(xVal);
    

        (*this) *= xRotationMatrix;
    }  
    
    if( !( y<EPSILON && y>-EPSILON) ){
        GLfloat yRotation[]={ cos(y), 0, -sin(y), 0,
                            0, 1, 0, 0,
                            sin(y), 0, cos(y), 0,
                            0, 0, 0, 1};
        std::vector<GLfloat> yVal(yRotation, yRotation +sizeof(yRotation) /sizeof(GLfloat) ); 
        Matrix4f yRotationMatrix(yVal);
        
        (*this)*=yRotationMatrix;
    }
    
    if( !( z<EPSILON && z>-EPSILON) ){
        GLfloat zRotation[]={ cos(z), sin(z), 0, 0,
                            -sin(z), cos(z), 0, 0,
                            0, 0, 1, 0,
                            0, 0, 0, 1};
        std::vector<GLfloat> zVal(zRotation, zRotation +sizeof(zRotation) /sizeof(GLfloat) );
        Matrix4f zRotationMatrix(zVal);
    
        (*this) *= zRotationMatrix;
    }
    
    return *this;

}

void Matrix4f::loadUniform(GLint loc){
    
    GLfloat m[NUM_ELEMENTS];
    
    for(int i=0;i<NUM_ELEMENTS; i++){
        m[i] = values.at(i);
    }
    glUniformMatrix4fv(loc, 1, false, m);
    
}

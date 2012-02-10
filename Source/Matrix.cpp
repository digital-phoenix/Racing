//
//  Matrix.cpp
//  Racing
//
//  Created by Brownlee on 11-08-24.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include<assert.h>
#include"Matrix.h"
#include"3dmath.h"

Matrix::Matrix(int width, int height, std::vector<GLfloat> v){
    this->width = width;
    this->height = height;
    assert(v.size() == (unsigned) (width*height) );
    for(int i=0; i<v.size(); i++)
        values.push_back(v.at(i));
    
}

Matrix::Matrix(Matrix const &other){
    width = other.getWidth();   
    height = other.getHeight();
    for(int i=0; i<width * height; i++)
        values.push_back( other[i]);

}
void Matrix::operator=(const Matrix &rhs){
    
    if(this==&rhs)
        return;
    
    width = rhs.getWidth();
    height = rhs.getHeight();
    values.clear();
    
    for (int i=0; i<width *height; i++) {
        values.push_back(rhs[i]);
    }
}

Matrix & Matrix::operator*=(const Matrix &rhs){
    if( width != rhs.getHeight()){
        return *this;
    }

    std::vector<GLfloat> newValues;
    GLfloat n;
    for(int i=0; i<rhs.getWidth(); i++) {

        for (int j=0; j<height; j++) {

            n = 0.0f;
            for (int k=0; k<width; k++) {
                n+=values.at(k*height +j) * rhs[k + i*rhs.getHeight()];
            }
            
            newValues.push_back(n); 
        } 
    }
    Matrix newMatrix( rhs.getWidth(), height, newValues);
    *this = newMatrix;

    return *this;
}

const Matrix  Matrix::operator*(const Matrix &rhs)const{
    Matrix newMatrix( *this);
    newMatrix*=rhs;
    return newMatrix;
}

const GLfloat Matrix::operator[](const int n)const{
    return  values.at(n);
}

void Matrix::printMatrix(){
    for( int i=0; i<height; i++){
        for (int j=0; j<width; j++) {
            std::cout<<values.at( j*height + i)<<" ";
        }
        std::cout<<"\n";
    }
}
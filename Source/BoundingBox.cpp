//
//  BoundingBox.cpp
//  
//
//  Created by Brownlee on 11-09-23.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include<stdlib.h>

#include"BoundingBox.h"

BoundingBox::BoundingBox(): min(), max(), translation(){
    rotation[0] = 0.0f;
    rotation[1] = 0.0f;
    rotation[2] = 0.0f;
    
}

BoundingBox::BoundingBox( std::list<Vector> vectors){
    Vector min, max;
    findMinandMax( vectors, min, max);
    
}

BoundingBox::BoundingBox(Vector min, Vector max){
    
    this->min = min;
    this->max = max;
    
}

BoundingBox BoundingBox::operator=( const BoundingBox& rhs){

    min = rhs.getMin();
    max = rhs.getMax();
    translation = rhs.getTranslation();
    
    rhs.getRotation( rotation );
    
    return *this;
    
}

void BoundingBox::Update( Vector translation, GLfloat rot[3] ){

    this->translation = translation;
    
    for (int i=0; i<NUM_DIMENSIONS; i++) {
        rotation[i] = rot[i];
    }

}

bool BoundingBox::intersects( std::list<Vector> vectors, BoundingBox &other){
    
    GLfloat rot[3];
    other.getRotation( rot);
    
    Matrix4f transformationMatrix;
    Matrix4f rotationMatrix;
    
    rotationMatrix.rotate( -rotation[0], -rotation[1], -rotation[2]);
    
    rotationMatrix.rotate( rot[0], rot[1], rot[2]);
    
    Matrix4f axis;
    
    GLfloat mins[3], maxes[3];
                        
    for (int i=0; i<NUM_DIMENSIONS; i++) {
        
        Vector v( axis[ i * (NUM_DIMENSIONS +1) ], axis[ i * (NUM_DIMENSIONS +1) +1], axis[i* (NUM_DIMENSIONS +1) +2] );
        
        Matrix matrixVector = rotationMatrix * v;
        Vector newV(matrixVector);
        
        findExtremePoint(vectors, newV, mins + i, maxes + i);
    }
    
    Vector newMin( mins[0], mins[1], mins[2]);
    Vector newMax( maxes[0], maxes[1], maxes[2]);
    
    Vector translate(other.getTranslation());
    transformationMatrix.rotate( rotation[0], rotation[1], rotation[2]);
    transformationMatrix.translate( translation.getX(), translation.getY(), translation.getZ());
    transformationMatrix.rotate( -rot[0], -rot[1], -rot[2]);
    transformationMatrix.translate( -translate.getX(), -translate.getY(), -translate.getZ());

    newMin = transformationMatrix * newMin;
    newMax = transformationMatrix * newMax;
    
    if ( newMax.getX() + EPSILON < other.getMin().getX() || other.getMax().getX() + EPSILON< newMin.getX() )
        return false;
    if ( newMax.getY() + EPSILON < other.getMin().getY() || other.getMax().getY() + EPSILON< newMin.getY() )
        return false;
    if ( newMax.getZ() + EPSILON < other.getMin().getZ() || other.getMax().getZ() + EPSILON< newMin.getZ() )
        return false;
    
    return true;
}

void BoundingBox::getRotation( GLfloat rot[3])const{
    
    for (int i=0; i<NUM_DIMENSIONS; i++) {
        rot[i] = rotation[i];
    } 
}

void BoundingBox::findExtremePoint( std::list<Vector> vectors, Vector axis, GLfloat *min, GLfloat *max){
    
    *min = vectors.front().dot( axis);
    *max = vectors.front().dot(axis);
    
    for ( std::list<Vector>::iterator it = vectors.begin(); it != vectors.end() ; it++ ) {
        
        GLfloat proj = it->dot(axis);
        
        if( proj < *min)
            *min = proj;
        
        if (proj > *max)
            *max = proj;
        
            
    }
}


void BoundingBox::findMinandMax( std::list<Vector> vectors, Vector &min, Vector &max){
    Matrix4f axis;
    
    GLfloat mins[3], maxes[3];
    
    for (int i=0; i<NUM_DIMENSIONS; i++) {
        Vector v( axis[ i * (NUM_DIMENSIONS +1) ], axis[ i * (NUM_DIMENSIONS +1) +1], axis[i* (NUM_DIMENSIONS +1) +2] );        
        findExtremePoint(vectors, v, mins + i, maxes + i);
    }
    
    min.setValues( mins[0], mins[1], mins[2]);
    max.setValues( maxes[0], maxes[1], maxes[2]);
    
}





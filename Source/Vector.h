//
//  Vector.h
//  Racing
//
//  Created by Brownlee on 11-09-04.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#ifndef Racing_Vector_h
#define Racing_Vector_h

#include"Graphics.h"
#include"Matrix.h"
/*
 **A mathematical vector class.
 */
class Vector{
    
    public: 
        /**
         *A constructor.
         */
        Vector();
            
        /**
         *A constructor.
         */
        Vector(const Vector &v);
    
        /**
         *a copy constructor that copies the matrix values
         *@param m a 1 by 4 Matrix to copy
         */
        Vector( Matrix m);
    
        /**
         *A constructor.
         *@param x GLfloat the x value of the vector.
         *@param y GLfloat the y value of the vector.
         *@param z GLfloat the z value of the vector.
         *@param w GLfloat the w value of the vector.
         */
        Vector(GLfloat x, GLfloat y, GLfloat z, GLfloat w = 1.0f);
        
        /**
         *overloads the = operator
         */
        Vector operator=(const Vector& rhs);

        /**
         *setValues sets the values of the vector.
         *@param x GLfloat the x value of the vector.
         *@param y GLfloat the y value of the vector.
         *@param z GLfloat the z value of the vector.
         *@param w GLfloat the w value of the vector.
         */
        void setValues(GLfloat x, GLfloat y, GLfloat z, GLfloat w = 1.0f);
    
        /**
         *getX returns the x value of the vector.
         *@return returns the x value as a GLfloat.
         */
        GLfloat getX()const{return x;}
        
        /**
         *getY returns the y value of the vector.
         *@return returns the y value as a GLfloat.
         */

        GLfloat getY()const{return y;}
    
        /**
         *getZ returns the z value of the vector.
         *@return returns the z value as a GLfloat.
         */

        GLfloat getZ()const{return z;}
        
        /**
         *getW returns the w value of the vector.
         *@return returns the w value as a GLfloat.
         */

        GLfloat getW()const{return w;}
    
        /**
         * dot returns the dot product of this and another vector
         *@param other vector the other vector used to compute the dot product
         *@return returns the resulting scalar of the dot product as a GLfloat
         */
    
        GLfloat dot( Vector other);
        
        void print();
    
    private:
        
        GLfloat x,y,z,w;
    
};


#endif

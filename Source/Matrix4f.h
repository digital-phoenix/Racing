//
//  Matrix4f.h
//  
//
//  Created by Brownlee on 11-08-24.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#ifndef _Matrix4f_h
#define _Matrix4f_h

#include"Matrix.h"
#include"Vector.h"
#include<vector>

#define NUM_ELEMENTS 16

/**
 *Matrix4f a 4x4 matrix class.
 *
 */
class Matrix4f: public Matrix{
    
    public:
        
        /**
         *overloads the = operator.
         *@param rhs the other matrix.
         *@return this matrix with its new values.
         */
        Matrix4f operator=(const Matrix& rhs);
        
        
        /**
         *Multiplies this matrix with a vector
         *@param rhs the vector to multiply by.
         *@return returns a constant matrix created by multiplying this by rhs
         */
        const Matrix4f operator*(const Matrix4f &rhs)const;
        
        /**
         *Multiplies this matrix with a vector
         *@param rhs the vector to multiply by.
         *@return returns a constant matrix created by multiplying this by rhs
         */
        const Matrix operator*(const Vector &rhs)const;

        /**
         *A constructor that sets this matrix to the identity matrix.
         */
        Matrix4f():Matrix(4,4,constructIdentity()){}
        
        /**
         *A constructor that sets this matrix to values.
         *@param values a 16 element vector<GLfloat> representing the values to set this matrix to.
         */
        Matrix4f( std::vector<GLfloat> values):Matrix(4,4,values){};
    
        Matrix4f(std::vector<Vector>values);
        /**
         *transforms this matrix by rotating it.
         *@param  x GLfloat the x angle to be rotated by.
         *@param  y GLfloat the y angle to be rotated by.
         *@param  z GLfloat the z angle to be rotated by.
         *@return returns this newly transformed matrix.
         */
        Matrix4f rotate(GLfloat x, GLfloat y, GLfloat z);
        
        /**
         *transforms this matrix by translating it.
         *@param x GLfloat the x distance to be translated by.
         *@param y GLfloat the y distance to be translated by.
         *@param z GLfloat the z distance to be translated by.
         *@return returns this newly transformed matrix.
         */

        Matrix4f translate(GLfloat x, GLfloat y, GLfloat z);
        
        /**
         *transforms this matrix by scaling it.
         *@param x GLfloat the x amount to be scaled by.
         *@param y GLfloat the y amount to be scaled by.
         *@param z GLfloat the z amount to be scaled by.
         *@return returns this newly transformed matrix.
         */

        Matrix4f scale(GLfloat x, GLfloat y, GLfloat z);
    
        /**
         *sends the data of this matrix as a matrixuniform.
         *@param loc the corresponding location.
         */
        void loadUniform(GLint loc);
    private:
        std::vector<GLfloat> constructIdentity();

};

#endif

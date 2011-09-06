//
//  Matrix.h
//  Racing
//
//  Created by Brownlee on 11-08-24.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#ifndef Racing_Matrix_h
#define Racing_Matrix_h

#include<vector>

#include<GL/glew.h>

#ifdef __APPLE__
#include <glut/glut.h>          // OS X version of GLUT
#else
#define FREEGLUT_STATIC
#include <GL/glut.h>            // Windows FreeGlut equivalent
#endif

/** 
 *A matrix class.
 *A matrix that is stored column major.
 */
class Matrix{
    public:
        /**
         *A constructor.
         *@param width an int the width of the matrix
         *@param height an int the height of the matrix
         *@param v a vector<GLfloat> the contents of the matrix
         */
        Matrix(int width, int height, std::vector<GLfloat> v);
    
        /**
         *A copy constructor.
         *@param other the other matrix to copy
         */
        Matrix(Matrix const &other);
        
        /**
         *overloads the = operator.
         *@param rhs the other matrix to copy
         */
        void operator=(const Matrix &rhs);
        
        /**
         *overloads the *= operator.
         *@param rhs the other matrix to multiply by
         *@return returns this matrix
         */
        Matrix & operator*=(const Matrix &rhs);
        
        /**
         *overloads the * operator
         *@param rhs the other matrix to multiply by.
         *@return returns a constant matrix created by multiplying this by rhs
         */
        const Matrix operator*(const Matrix &rhs)const;
    
        /**
         *overloads the [] operator.
         *@param n as an int representing the index
         *@return the nth element
         */
        const GLfloat operator[](const int n)const;
        
        /**
         *getWidth returns the width
         *@return the width of the matrix as an int
        */

        int getWidth()const{return width;}
        
        /**
        *getHeight returns the height
        *@return the height of the matrix as an int
        */
        int getHeight()const{return height;}
        
    
    protected:
        int width;
        int height;       
        std::vector<GLfloat> values;
};


#endif

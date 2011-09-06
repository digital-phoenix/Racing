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
         *@param x GLfloat the x value of the vector.
         *@param y GLfloat the y value of the vector.
         *@param z GLfloat the z value of the vector.
         *@param w GLfloat the w value of the vector.
         */
        Vector(GLfloat x, GLfloat y, GLfloat z, GLfloat w = 1.0f);
        
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
        GLfloat getX(){return x;}
        
        /**
         *getY returns the y value of the vector.
         *@return returns the y value as a GLfloat.
         */

        GLfloat getY(){return y;}
    
        /**
         *getZ returns the z value of the vector.
         *@return returns the z value as a GLfloat.
         */

        GLfloat getZ(){return z;}
        
        /**
         *getW returns the w value of the vector.
         *@return returns the w value as a GLfloat.
         */

        GLfloat getW(){return w;}
    
    private:
        
        GLfloat x,y,z,w;
    
};


#endif

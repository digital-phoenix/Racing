//
//  Camera.h
//  Racing
//
//  Created by Brownlee on 11-08-31.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#ifndef Racing_Camera_h
#define Racing_Camera_h

#include"Matrix4f.h"

/**
 *A camera class. 
 *A camera used to control and alter the view of the user.
 */
class Camera: public Matrix4f{
    
    public:
        
        /**
         * A constructor.
         *The constructor set the camera matrix to an identity matrix
         */
        Camera():Matrix4f(){};
        
        /**
         *moves the camera forward.
         *@param foward a GLfloat representing the amount to move the camera forward can be negative to move the camera back.
         */
        void moveFoward(GLfloat foward){ Matrix4f::translate(0.0f,0.0f,-foward); }
        
        /**
         *moves the camera right.
         *@param right a GLfloat representing the amount to move the camera right can be negative to move the camera left.
         */
        void moveRight(GLfloat right){ Matrix4f::translate(-right,0.0f,0.0f); }
        
        /**
         *moves the camera up.
         *@param up a GLfloat representing the amount to move the camera up can be negative to move the camera down.
         */
        void moveUp(GLfloat up){ Matrix4f::translate(0.0f,-up,0.0f); }
    
    
};


#endif

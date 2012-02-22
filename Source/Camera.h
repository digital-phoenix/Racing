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
#include"Vector.h"
#include<vector>
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
            
        Camera(std::vector<Vector>values):Matrix4f(values){};
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
        
        /**
         *moves the camera.
         *@param x a GLfloat representing the amount to move the camera in the x direction.
         *@param y a GLfloat representing the amount to move the camera in the y direction.
         *@param z a GLfloat representing the amount to move the camera in the z direction.
         */
        void move(GLfloat x, GLfloat y, GLfloat z){ Matrix4f::translate(-x,-y,-z); }
        
        void move(const Vector& p){move(p.getX(), p.getY(), p.getZ() ); }
        /**
         *moves the camera.
         *@param x a GLfloat representing the amount to move the camera in the x direction.
         *@param y a GLfloat representing the amount to move the camera in the y direction.
         *@param z a GLfloat representing the amount to move the camera in the z direction.
         */
        void rotate(GLfloat x, GLfloat y, GLfloat z){ Matrix4f::rotate(-x,-y,-z); }
        
        //void lookAt( Vector view, Vector position);
        void clear();
};


#endif

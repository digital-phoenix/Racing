//
//  Player.h
//  
//
//  Created by Brownlee on 11-10-13.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#ifndef _Player_h
#define _Player_h

#include<string>
#include"Camera.h"
#include"Matrix4f.h"
#include"Sprite.h"
#include"Vector.h"

#define MAX_SPEED 1.0f
#define MAX_REVERSE_SPEED -0.5f
#define CAMERA_DISTANCE 12.0f
class Player : public Sprite{
    
    public:
        
        Player(std::string filename, Vector p, GLfloat xRot =0.0f, GLfloat yRot =0.0f, GLfloat zRot =0.0f);
    
        void update();
    
        void SetAcceleration( GLfloat );
        void SetRotation( GLfloat );
        void SetSpeed( GLfloat );
        
        Camera getCamera(){ return camera; }
    
    private:
        
        Camera camera;
        GLfloat acceleration;
        GLfloat speed;
        GLfloat rotationChange;
        
    
};


#endif

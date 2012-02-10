//
//  Sprite.h
//  
//
//  Created by Brownlee on 11-10-01.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#ifndef _Sprite_h
#define _Sprite_h

#include<list>
#include<string>

#include"BoundingBox.h"
#include"Graphics.h"
#include"Matrix4f.h"
#include"Model.h"
#include"Vector.h"

class Sprite{
    public:
    
        Sprite( std::string filename, Vector p, GLfloat xRot =0.0f, GLfloat yRot =0.0f, GLfloat zRot =0.0f);
        ~Sprite(){ numSprites--;}

        int getID(){ return spriteId; }
        
        BoundingBox& getBoundingBox(){ return box;}
    
        virtual void draw(Matrix4f projectionMatrix, shaderResources shader);
        virtual void update();
        
        virtual void collision( Sprite &other);
    
    protected:
        
        int spriteId;
        int type;
    
        BoundingBox box;
    
        Model model;
        Vector position;
        GLfloat rotation[3];
        
        std::list<Vector> coordinates;

    private:
    
        static int numSprites;

        
};


#endif

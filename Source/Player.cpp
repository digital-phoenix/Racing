//
//  Player.cpp
//  
//
//  Created by Brownlee on 11-10-13.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include"Player.h"

Player::Player(std::string filename, Vector p, GLfloat xRot, GLfloat yRot, GLfloat zRot): Sprite(filename, p, xRot , yRot, zRot), camera(){

    camera.move( p.getX(), p.getY() + 5.0f, p.getZ() - CAMERA_DISTANCE );
    camera.rotate(30.0f, 0.0f, 0.0f);
    speed = 0.0f;
    
                
}

void Player::update(){
    
    SetSpeed( speed + acceleration);

    
    std::cout<<" position z="<<position.getZ()<<" speed= "<<speed<<" rotationChange = "<<rotationChange<<'\n';
    
    Matrix4f rotationMatrix;
    rotationMatrix.rotate( rotation[0], rotation[1], rotation[2]);
    Vector direction(0.0f,0.0f,1.0f);
    Matrix newDirection = rotationMatrix *direction;
    position.setValues( position.getX() + (speed * newDirection[0]), position.getY() + (speed * newDirection[1])  , position.getZ() + (speed * newDirection[2]) );

    
    
    rotation[1] += rotationChange;
    
    camera.clear();
    camera.rotate(30.0f, 0.0f, 0.0f);

    camera.move( position.getX(), position.getY() + 5.0f, position.getZ() - CAMERA_DISTANCE );

    camera.rotate(rotation[0] , rotation[1], rotation[2]);

    
    Sprite::update();
}


void Player::SetAcceleration( GLfloat a){
    acceleration = a;
}


void Player::SetRotation( GLfloat r ){
    rotationChange = r;
}

void Player::SetSpeed( GLfloat s){
    if( s > MAX_SPEED )
        speed = MAX_SPEED;
    else if( s< MAX_REVERSE_SPEED)
        speed = MAX_REVERSE_SPEED;
    else
        speed = s;
}

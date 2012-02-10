//
//  Sprite.cpp
//  
//
//  Created by Brownlee on 11-10-01.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include <fstream>
#include <iostream>
#include"Sprite.h"

int Sprite::numSprites = 0;

Sprite::Sprite( std::string filename, Vector p, GLfloat xRot, GLfloat yRot, GLfloat zRot) : model(filename), position(p){
    
    spriteId = numSprites;
    numSprites++;
    
    std::ifstream fin(filename.c_str(), std::ifstream::in);
    if (!fin.is_open() ) {
        std::cout<<"error opening file "<<filename<<'\n';
        exit(0);
    }
    
	std::string s;
	
	int nfaces=0;
	int nvertices=0;
	
    fin>>nvertices>>nfaces; 
    
    while ( fin>>s && s=="v") {
        
        GLfloat vertices[3];

        for ( int i=0; i<NUM_DIMENSIONS; i++) {
            fin>>vertices[i];
        }
        Vector v( vertices[0], vertices[1], vertices[2]);
        coordinates.push_back(v);
        
    }
    
    box = BoundingBox(coordinates);
    
    rotation[0] = xRot;
    rotation[1] = yRot;
    rotation[2] = zRot;
    
}

void Sprite::update(){
    box.Update( position, rotation);
}

void Sprite::draw(Matrix4f projectionMatrix, shaderResources shader){
    GLfloat vRed[] = { 1.0f, 0.0f, 0.0f, 1.0f };

    glUseProgram( shader.program );
    glUniform4f( shader.uniforms.colour, vRed[0], vRed[1], vRed[2], vRed[3] );
    
    Matrix4f modelView;
    
    modelView.translate( position.getX(), position.getY(), position.getZ() );
    
    modelView.rotate( rotation[0], rotation[1], rotation[2]);
    
    
   /* std::cout<<"rotation =";
    for (int i=0; i<3; i++) {
        std::cout<<rotation[i]<<" ";
    }
    std::cout<<" position =";
    position.print(); */

    Matrix4f modelViewProjectionMatrix = projectionMatrix * modelView;
    
    modelViewProjectionMatrix.loadUniform( shader.uniforms.modelViewProjectionMatrix );
    
    model.draw( shader.attributes.pos);
}

void Sprite::collision( Sprite &other){
    
    if( box.intersects( coordinates, other.getBoundingBox() ) ){
        std::cout<<"Sprite "<<spriteId<<" has collided with Sprite "<<other.getID()<<'\n';
    }
}










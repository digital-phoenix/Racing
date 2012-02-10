//
//  SpriteManager.cpp
//  
//
//  Created by Brownlee on 11-10-01.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include"SpriteManager.h"

SpriteManager::SpriteManager(){
    
}

SpriteManager::SpriteManager( std::list<Sprite*> sprites){
    this->sprites = sprites;
}

SpriteManager::~SpriteManager(){
    
    for (std::list<Sprite*>::iterator it = sprites.begin(); it!=sprites.end(); it++) {
        delete (*it);
    }

}
void SpriteManager::AddSprite( Sprite* s ){
    sprites.push_back( s );
}

void SpriteManager::DeleteSprite( Sprite *s){
    
    for ( std::list<Sprite*>::iterator it =sprites.begin() ; it != sprites.end(); it++ ) {
        if ( s->getID() == (*it)->getID() ) {
            delete s;
            sprites.erase( it );
        }
    }
}

SpriteManager *SpriteManager::pSpriteManager = 0;

SpriteManager *SpriteManager::instance(){
    if (pSpriteManager == 0) {
        pSpriteManager = new SpriteManager();
        if (pSpriteManager == 0) {
            printf(" ERROR not enough memory to allocate SpriteManager\n");
        }
    }
    
    return pSpriteManager;
    
}

void SpriteManager::draw( Matrix4f projectionMatrix, shaderResources shader){

    
    for (std::list<Sprite*>::iterator it = sprites.begin(); it!=sprites.end(); it++) {
        //std::cout<<"drawing sprite\n";
        
        (*it)->draw(projectionMatrix, shader);
    }
}

void SpriteManager::update(){
    for (std::list<Sprite*>::iterator it = sprites.begin(); it!=sprites.end(); it++) {
        (*it)->update();
    }
        
    for (std::list<Sprite*>::iterator it = sprites.begin(); it!=sprites.end(); it++) {
            
        for (std::list<Sprite*>::iterator it2 =it; it2!=sprites.end(); it2++) {
            if( it == it2)
                continue;
            (*it)->collision( (**it2) );
        }

    }

    
}












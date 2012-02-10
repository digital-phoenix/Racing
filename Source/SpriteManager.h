//
//  SpriteManager.h
//  
//
//  Created by Brownlee on 11-10-01.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#ifndef _SpriteManager_h
#define _SpriteManager_h

#include<list>
#include"Matrix4f.h"
#include"Graphics.h"
#include"Sprite.h"

class SpriteManager{
    public:
    
    SpriteManager();
    
    SpriteManager( std::list<Sprite*> sprites );
    
    ~SpriteManager();
    
    void AddSprite( Sprite* );
    
    void DeleteSprite( Sprite *s);
    
    static SpriteManager *instance();
    
    void draw( Matrix4f projectionMatrix, shaderResources shader );
    void update();
    
    private:
    
    std::list<Sprite*>sprites;
    static SpriteManager *pSpriteManager; 
    
};

#endif

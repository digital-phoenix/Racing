//
//  Model.h
//  Racing
//
//  Created by Brownlee on 11-09-04.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#ifndef Racing_Model_h
#define Racing_Model_h

#include "Graphics.h"

/**
 *A graphical model class.
 */
class Model{
    public:  
        
        /**
         *a constructor.
         *sets the data of the model name to the information int the ogl file.
         *@param filename a char* the name of the ogl file.
         */
        Model( char* filename);
        
        /**
         *Draws the model.
         *@param pos the GLint that corresponds to the shader vector input data.
         */
        void draw(GLint pos);
        
    private:
        
        int nfaces, nVertices;
        GLuint vertexBuffer;
        GLuint elementBuffer;

};


#endif

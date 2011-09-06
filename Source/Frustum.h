//
//  Frustum.h
//  Racing
//
//  Created by Brownlee on 11-08-25.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#ifndef Racing_Frustum_h
#define Racing_Frustum_h

#include"Matrix4f.h"

/**
 *A Frustrum class.
 */
class Frustum:public Matrix4f{
    
    public:
        /**
         *A constructor.
         *Sets the frustum to an identity matrix.
         */
        Frustum():Matrix4f(){}
        
        /**
         *setPerspective sets the orientation of the frustrum
         *@param aspect a GLfloat that sets the aspect ratio of the frustum
         *@param angle a GLfloat that sets the viewing angle of the frustum
         *@param near a GLfloat that sets the near value of the frustum
         *@param far a GLfloat that sets the far value of the frustum
         */
        void setPerspective(GLfloat aspect, GLfloat angle, GLfloat near,GLfloat far){values = constructFrustum(aspect, angle, near, far);}
    
    private:
        std::vector<GLfloat> constructFrustum(GLfloat aspect, GLfloat angle, GLfloat near, GLfloat far);
};

#endif

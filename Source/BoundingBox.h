//
//  BoundingBox.h
//  
//
//  Created by Brownlee on 11-09-23.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#ifndef _BoundingBox_h
#define _BoundingBox_h

#include <list>
#include"3dmath.h"
#include"Vector.h"
#include"Graphics.h"
#include"Matrix4f.h"
/*
 **A bounding box for geometric data
 */
class BoundingBox{

    public:
    
    /**
     *An empty constructor
     */
    BoundingBox();
    /**
     *constructs a bounding box using the points to be contained
     *@param vectors list<Vector> the list of points for the bounding box to contain
     */
    BoundingBox( std::list<Vector> vectors );
    
    /** constructs a bounding box using the boxes min and max points
     *@param min the minimum point of the bounding box
     *@param max the maximum point of the bouding box
     */
    BoundingBox(Vector min, Vector max);
    
    /**
     *overloads the = operator
     */
    BoundingBox operator=(const BoundingBox& rhs);

    /**Updates the bounding box
     *@param vector list<Vector> the points to be contained in the bouding box
     */
    void Update(Vector translation, GLfloat rot[3]);
    
    /** intersect checks if this bounding box intersects with the other bounding box
     *@param other BoundingBox
     *@return returns true if the boundnig boxes intersect and false otherwise
     */
    bool intersects( std::list<Vector> vectors, BoundingBox &other);
    
    /**
     *returns min
     *@return returns min
     */
    Vector getMin()const{ return min;}
    
    /**
     *returns max
     *@return returns max
     */
    Vector getMax()const{ return max;}
    
    /**
     *returns translation
     *@return returns translation
     */
    Vector getTranslation()const{ return translation;}
    
    /**
     *returns rotation
     *@return returns rotation
     */
    void getRotation( GLfloat rot[3])const;
    
    
    
    private:
    
    void findExtremePoint( std::list<Vector> vectors, Vector axis, GLfloat *min, GLfloat *max);
    void findMinandMax( std::list<Vector>, Vector &min, Vector &max);
    
    Vector min,max;
    Vector translation;
    GLfloat rotation[3];
    
};

#endif

//
//  3dmath.h
//  Racing
//
//  Created by Brownlee on 11-08-24.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#ifndef Racing__dmath_h
#define Racing__dmath_h

#include<math.h>

#define PI 3.14159265 /**< The mathematical constant PI.*/
#define EPSILON 0.0001/**< EPSILON is used to compare float values*/

/**degToRad converts degrees to radians.
 *@param deg a float to be converted into radians
 *@return the corresponding radian value as a float
 */
float degToRad(float deg);

/**radToDeg converts degrees to radians.
 *@param rad a float to be converted into degrees
 *@return the corresponding degree value as a float
 */
float radToDeg(float rad);

#endif

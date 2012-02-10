//
//  Graphics.h
//  Racing
//
//  Created by Brownlee on 11-09-03.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#ifndef Racing_Graphics_h
#define Racing_Graphics_h

#include<GL/glew.h>

#ifdef __APPLE__
#include <glut/glut.h>          // OS X version of GLUT
#else
#define FREEGLUT_STATIC
#include <GL/glut.h>            // Windows FreeGlut equivalent
#endif

#define NUM_DIMENSIONS 3

/**
 *Structure containing shader resources
 */
typedef struct{
    
    GLuint vertexShader, fragmentShader, program;
    
    struct {
        GLint colour;  
        GLint modelViewProjectionMatrix;
    }uniforms;
    
    struct{
        GLint pos;
    }attributes;
    
}shaderResources;


/**
 *makeBuffer creates a buffer object
 *@param target a GLenum that specifiecs the type the object is bound to.
 *@param data a void* the data the buffer will be associated with.
 *@param data_size a GLsizei the size of the data.
 *@param use a GLenum representing the intended use of the buffer.
 *@return returns a buffer object of type GLuint
 */
GLuint makeBuffer( GLenum target, const void *data, GLsizei data_size, GLenum use);

/**
 *storFile reads and returns data from a file
 *@param filename the name of the file as const char*
 *@param length a GLint& returns the length of the file
 *@return returns a GLchar* that stores the text of the file
*/
GLchar *storeFile(const char *filename, GLint &length);

/**
 *makeShader makes and returns a shader
 *@param type the type of shader
 *@param filename the file name as a const char*
 *@return returns a GLuint that is associated with the shader on success and on failure returns -1
 */
GLuint makeShader( GLenum type, const char *filename);

/**
 *makeProgram creates a shader program
 *@param vertexShader the vertex shader as a GLuint
 *@param fragmentShader the fragment shader as a GLuint 
 *@return on success returns the associated GLuint and on failure returns -1
 */
GLuint makeProgram( GLuint vertexShader, GLuint fragmentShader);

#endif

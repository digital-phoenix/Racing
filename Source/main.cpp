/*
 *  model.h
 *  
 *
 *  Created by Brownlee on 11-07-11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

// Triangle.cpp

#include<fstream>
#include<iostream>
#include <new>
#include<string>
#include<vector>

#include"3dmath.h"
#include"Camera.h"
#include"Frustum.h"
#include"Graphics.h"
#include"Matrix.h"
#include"Matrix4f.h"
#include "Model.h"

#include<math.h>



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

Frustum projectionMatrix;
shaderResources shader;
Model *test;
Camera camera;

void ChangeSize(int w, int h)
{
	
	glViewport(0, 0, w, h);
    
    if(h==0)
        h=EPSILON;
       
    projectionMatrix.setPerspective(float(w)/float(h), 35.0f, 1.0f, 100.0f);

	
}


void SetupRC()
{
	glEnable(GL_DEPTH_TEST);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f );
    
    shader.vertexShader = makeShader( GL_VERTEX_SHADER, "resources/Shaders/identity.vs");
    if(shader.vertexShader == 0){
        printf("failed to make vertex shader");
        exit(0);
    }
    
    shader.fragmentShader = makeShader(GL_FRAGMENT_SHADER, "resources/Shaders/identity.fs");
    if(shader.fragmentShader == 0){
        printf("failed to make fragment shader");
        exit(0);
    }

    shader.program = makeProgram(shader.vertexShader, shader.fragmentShader);
    if(shader.program == 0){
        printf("failed to make program");
        exit(0);
    }
    
    shader.uniforms.colour = glGetUniformLocation( shader.program, "colour");
    
    if( shader.uniforms.colour == -1){
        printf( "failed to locate uniform colour location");
        exit(0);
	}
    
    shader.uniforms.modelViewProjectionMatrix = glGetUniformLocation(shader.program, "modelViewProjectionMatrix");
    
    if( shader.uniforms.modelViewProjectionMatrix == -1){
        printf("failed to locate uniform modelViewProjectionMatrix");
        exit(0);
    }
    
    
    shader.attributes.pos = glGetAttribLocation( shader.program, "position");
    
    test = new Model("resources/Models/cube.ogl");
}



void RenderScene(void)
{
	//std::cout<<"Rendering Scene\n";
	// Clear the window with current clearing color
    
    
    
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

    
	GLfloat vRed[] = { 1.0f, 0.0f, 0.0f, 1.0f };
    Matrix4f modelView;
 
    Matrix4f modelViewProjectionMatrix; 
    modelViewProjectionMatrix =   projectionMatrix * camera * modelView;
	glUseProgram( shader.program );
	
    glUniform4f( shader.uniforms.colour, vRed[0], vRed[1], vRed[2], vRed[3] );
    
    modelViewProjectionMatrix.loadUniform(shader.uniforms.modelViewProjectionMatrix);
    
    test->draw(shader.attributes.pos);

    // Perform the buffer swap to display back buffer
	glutSwapBuffers();
	
	glutPostRedisplay();
}

void SpecialKeys(int key, int x, int y){
    
    GLfloat dist = 1.0f;
    
    if (key == GLUT_KEY_UP) {
        camera.moveFoward(dist);
    }
    if (key == GLUT_KEY_DOWN) {
        camera.moveFoward(-dist);
    }
    if (key == GLUT_KEY_LEFT) {
        camera.moveRight(-dist);
    }
    if (key == GLUT_KEY_RIGHT) {
        camera.moveRight(dist);
    }
}

int main(int argc, char* argv[])
{
	
    
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH | GLUT_STENCIL);
	glutInitWindowSize(800, 600);
	glutCreateWindow("Model");
    
    glutReshapeFunc(ChangeSize);
    glutSpecialFunc(SpecialKeys);
    glutDisplayFunc(RenderScene);
	
	GLenum err = glewInit();
	if (GLEW_OK != err) {
		fprintf(stderr, "GLEW Error: %s\n", glewGetErrorString(err));
		return 1;
	}
	
	SetupRC();
	
	glutMainLoop();
	return 0;
}

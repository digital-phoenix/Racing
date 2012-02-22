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
#include"SpriteManager.h"
#include"Vector.h"
#include"Player.h"

#include<time.h>
#include<math.h>




Frustum projectionMatrix;
shaderResources shader;
Model *test;
Player *player;
Camera camera;
bool cameraLock=true;
bool isPaused =false;

void ChangeSize(int w, int h)
{
	
	glViewport(0, 0, w, h);
    
    if(h==0)
        h=EPSILON;
       
    projectionMatrix.setPerspective(float(w)/float(h), 35.0f, 1.0f, 100.0f);

	
}


void SetupRC()
{
    
    SpriteManager *sprites = SpriteManager::instance();
    
    Vector p(0.0f,0.0f,-1.0f);
    player = new Player("resources/Models/cube.ogl", p);
    
    sprites->AddSprite( player);
    
    std::string filename="resources/Models/cube.ogl";
    test = new Model(filename);
    
    /*
    Vector v((GLfloat)(0), (GLfloat)(0), (GLfloat) (5) );
    sprites->AddSprite( new Sprite("resources/Models/cube.ogl", v) );
    */
    for (int i=0; i<30; i++) {
        
        Vector v((GLfloat)(0), (GLfloat)(i *3 ), (GLfloat) (10) );
        
        sprites->AddSprite(  new Sprite("resources/Models/cube.ogl", v, i*8, i*2, i*5) );
        
    }
    
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
    

}



void RenderScene(void)
{
    
    
    static clock_t lastTime = 0;
    
    clock_t now;
    
    now = clock();
    

    SpriteManager* sprites = SpriteManager::instance();
    
    if (!isPaused && now -lastTime > CLOCKS_PER_SEC/60) {
        sprites->update();
    }
    
    lastTime = now;
    
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
    
    Matrix4f ViewProjectionMatrix;
    
    if (!cameraLock) {
        ViewProjectionMatrix =   projectionMatrix * camera;
    }else{
        ViewProjectionMatrix =   projectionMatrix * player->getCamera();
    }

    
    /*
    GLfloat vRed[] = { 1.0f, 0.0f, 0.0f, 1.0f };
    
    
    glUseProgram( shader.program );
    glUniform4f( shader.uniforms.colour, vRed[0], vRed[1], vRed[2], vRed[3] );
        

    Matrix4f modelView;
    //modelView.rotate( [0], rotation[1], rotation[2]);
    modelView.translate( 0, 0, 5 );
    
    Matrix4f modelViewProjectionMatrix =ViewProjectionMatrix * modelView;
    
    modelViewProjectionMatrix.loadUniform( shader.uniforms.modelViewProjectionMatrix);
    
    test->draw( shader.attributes.pos );
*/
    sprites->draw( ViewProjectionMatrix, shader);
    
    // Perform the buffer swap to display back buffer
	glutSwapBuffers();
	
	glutPostRedisplay();
}

void Keys(unsigned char key, int x, int y){
    
    if ( key =='c') {
        if (!cameraLock) {
            camera = player->getCamera();
        }
        cameraLock = !cameraLock;
    }
    
    if (key == 'p') {
        isPaused = !isPaused;
    }
}

void SpecialKeys(int key, int x, int y){
    
    GLfloat dist = 1.0f;
    
    if( !cameraLock ){
        
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
    else{
        GLfloat acceleration =0.0f;
        GLfloat rotationChange =0.0f;
        
        if (key == GLUT_KEY_UP) {
            acceleration =0.1f;
        }
        if (key == GLUT_KEY_DOWN) {
            acceleration =-0.1f;
        }
        if (key == GLUT_KEY_LEFT) {
            rotationChange = 3.0f;
        }
        if (key == GLUT_KEY_RIGHT) {
            rotationChange = -3.0f;
        }
        player->SetAcceleration( acceleration );
        player->SetRotation(rotationChange);
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
    glutKeyboardFunc( Keys );
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

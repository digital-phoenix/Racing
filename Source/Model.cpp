//
//  Model.cpp
//  Racing
//
//  Created by Brownlee on 11-09-04.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include <fstream>
#include <iostream>
#include "Model.h"

Model::Model( char* filename){
    
    
	
	std::ifstream fin(filename, std::ifstream::in);
    if (!fin.is_open() ) {
        std::cout<<"error opening file "<<filename<<'\n';
        exit(0);
    }
	std::string s;
	
	int nfaces=0;
	int nvertices=0;
	
    fin>>nvertices>>nfaces; 
    
    GLfloat *vertices;
    try {
        vertices = new GLfloat[nvertices * 4];
    } catch (std::bad_alloc &ba) {
        std::cout<<ba.what()<<"\n";
        delete [] vertices;
        exit(0);
    }
    
    GLuint *faces;
    try {
        faces = new GLuint[nfaces * 3];
    } catch (std::bad_alloc &ba) {
        std::cout<<ba.what()<<"\n";
        delete [] faces;
        exit(0);
    }
    
    GLfloat *normals;
    try {
        normals = new GLfloat[nfaces * 3];
    } catch (std::bad_alloc &ba) {
        std::cout<<ba.what()<<"\n";
        delete [] normals;
        exit(0);
    }
    
    
    int nindex;
    int vindex=0;
    int findex=0;
    
	while ( fin>>s ) {

		if(s=="v"){
			
            for (int i=0; i<NUM_DIMENSIONS; i++) {
                fin>>vertices[vindex++];
            }
            vertices[vindex -1] += 10.0f;
            vertices[vindex++] = 1.0f;
			
		}else if(s=="f"){
			
            
			for (int i=0 ; i<NUM_DIMENSIONS ; i++) {
				
                
				fin>>normals[nindex++];
                
				
			}
            
            for (int i=0 ; i<NUM_DIMENSIONS ; i++) {
				
                
				fin>>faces[findex++];
				
			}
            
		}
	}
	
    this->nfaces = nfaces;
    nVertices = nvertices;
    
    std::cout<<"nfaces="<<nfaces<<" nvertices="<<nVertices<<'\n';
    vertexBuffer = makeBuffer(GL_ARRAY_BUFFER, vertices, sizeof(GLfloat)*nvertices*4, GL_STATIC_DRAW);
    
    //test.normalBuffer = makeBuffer(GL_ARRAY_BUFFER, normals, sizeof(normals), GL_STATIC_DRAW);
    
    elementBuffer = makeBuffer(GL_ELEMENT_ARRAY_BUFFER, faces, sizeof(GLuint)*nfaces*3, GL_STATIC_DRAW);
    
    delete [] vertices;
    delete [] faces;
    delete [] normals;
    


}

void Model::draw(GLint pos){
    
    glBindBuffer( GL_ARRAY_BUFFER, vertexBuffer);
    glVertexAttribPointer( pos, 4, GL_FLOAT, GL_FALSE, sizeof(GLfloat)*4, (void*)0 );
    glEnableVertexAttribArray( pos);
    
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, elementBuffer);
    
    glDrawElements(GL_TRIANGLES, nfaces *3, GL_UNSIGNED_INT, (void*)0 );
    
    glDisableVertexAttribArray(pos);

}
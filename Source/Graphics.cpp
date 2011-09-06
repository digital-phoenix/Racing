//
//  Graphics.cpp
//  Racing
//
//  Created by Brownlee on 11-09-03.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include<fstream>
#include"Graphics.h"

GLuint makeBuffer( GLenum target, const void *data, GLsizei data_size, GLenum use){
    
    GLuint buffer;
    glGenBuffers(1, &buffer);
    glBindBuffer(target, buffer);
    glBufferData(target, data_size, data, use);
    return buffer;
}


GLchar *storeFile(const char *filename, GLint &length){
    
    std::ifstream fin;
    fin.open(filename, std::ifstream::in);
    
    
    if( !fin.is_open() ){
        std::cout<<"failed to open file "<<filename<<'\n';
        length=0;
        return "";
    }
    
    
    fin.seekg (0, std::ios::end);
    length = fin.tellg();
    fin.seekg (0, std::ios::beg);
    
    
    GLchar *s=(GLchar*) new char[length+1];
    int i=0;
    while(fin.good()){
        s[i]= (char) fin.get();
        if( !fin.eof())
            i++;
    }
    
    s[i]='\0';
    
    fin.close();
    
    return s;
}

GLuint makeShader( GLenum type, const char *filename){
    
    GLint length;
    GLchar *source = storeFile( filename, length);
    GLuint shader;
    GLint shader_ok;
    
    if( length==0 ){
        fprintf(stderr, "failed to load source\n");
        return 0;
    }
    
    
    shader = glCreateShader(type);
    glShaderSource(shader, 1, (const GLchar**) &source, NULL);
    
    free(source);
    
    glCompileShader(shader);
    
    
    glGetShaderiv(shader, GL_COMPILE_STATUS, &shader_ok);
    
    if(!shader_ok){
        
        fprintf(stderr, "Failed to compile %s:\n", filename);
        GLint logLength;
        char* log;
        
        glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &logLength);
        log = (char*) malloc(logLength);
        glGetShaderInfoLog(shader,logLength, NULL, log);
        fprintf(stderr, "%s", log);
        
        free(log);
        return 0;
    }
    
    return shader;
}


GLuint makeProgram( GLuint vertexShader, GLuint fragmentShader){
    
    GLint programOk;
    
    GLuint program = glCreateProgram();
    glAttachShader( program, vertexShader);
    glAttachShader(program, fragmentShader);
    glLinkProgram(program);
    
    glGetProgramiv(program, GL_LINK_STATUS, &programOk);
    
    if(!programOk){
        
        fprintf(stderr, "Failed to link shader program:\n");
        
        GLint logLength;
        char *log;
        
        glGetProgramiv(program, GL_INFO_LOG_LENGTH, &logLength);
        log = (char*) malloc(logLength);
        
        glGetProgramInfoLog( program, logLength, NULL, log);
        
        fprintf(stderr, log);
        
        free(log);
        glDeleteProgram(program);
        
        return 0;
        
    }
    
    return  program;
}

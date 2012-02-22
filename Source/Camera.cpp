//
//  Camera.cpp
//  Racing
//
//  Created by Brownlee on 11-08-31.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include"Camera.h"

void Camera::clear(){
    Camera  identity;
    (*this) = identity;
}
/*
void Camera::lookAt(Vector view, Vector position){
    Matrix4f rotationMatrix;
    rotationMatrix.rotate(0.0f, 90.0f, 0.0f);
    Vector side(view);
    side=rotationMatrix * side;
    
    
    std::vector<Vector>values;
    side.setW(0.0f);
    values.push_back(side);
    Vector up = view*side;
    up.setW(0.0f);
    values.push_back(up);
    view.setW(0.0f);
    values.push_back(view);
    position.setW(1.0f);
    values.push_back(position);
    
    std::cout<<"camera lookat vectors\n";
    std::cout<<"side=";
    side.print();
    std::cout<<"up=";
    up.print();
    std::cout<<"view=";
    view.print();

    position.print();
    
    Camera newCamera(values);
    (*this) =newCamera;
}*/





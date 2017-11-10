//
//  obstacles.h
//  raceToTheSun
//
//  Created by Gustavo Colaco on 09/11/17.
//  Copyright © 2017 Gustavo Colaço. All rights reserved.
//



#ifndef obstacles_h
#define obstacles_h


#endif /* obstacles_h */
#include <stdio.h>
#include <OpenGL/gl.h>
#include <OpenGl/glu.h>
#include <GLUT/glut.h>
#include <iostream>


float size1 = 0.098f;

void bottom(){
    glVertex3f(-size1,-size1,-size1);
    glVertex3f( size1,-size1,-size1);
    glVertex3f( size1,-size1,-size1);
    glVertex3f( size1,-size1, size1);
    glVertex3f( size1,-size1, size1);
    glVertex3f(-size1,-size1, size1);
    glVertex3f(-size1,-size1, size1);
    glVertex3f(-size1,-size1,-size1);
}

void top(){
    glVertex3f(-size1, size1,-size1);
    glVertex3f( size1, size1,-size1);
    glVertex3f( size1, size1,-size1);
    glVertex3f( size1, size1, size1);
    glVertex3f( size1, size1, size1);
    glVertex3f(-size1, size1, size1);
    glVertex3f(-size1, size1, size1);
    glVertex3f(-size1, size1,-size1);
}

void left(){
    glVertex3f(-size1,-size1,-size1);
    glVertex3f(-size1, size1,-size1);
    glVertex3f(-size1, size1,-size1);
    glVertex3f(-size1, size1, size1);
    glVertex3f(-size1, size1, size1);
    glVertex3f(-size1,-size1, size1);
    glVertex3f(-size1,-size1, size1);
    glVertex3f(-size1,-size1,-size1);}

void right(){
    glVertex3f( size1,-size1,-size1);
    glVertex3f( size1, size1,-size1);
    glVertex3f( size1, size1,-size1);
    glVertex3f( size1, size1, size1);
    glVertex3f( size1, size1, size1);
    glVertex3f( size1,-size1, size1);
    glVertex3f( size1,-size1, size1);
    glVertex3f( size1,-size1,-size1);
}

void front(){
    glVertex3f(-size1,-size1, size1);
    glVertex3f( size1,-size1, size1);
    glVertex3f( size1,-size1, size1);
    glVertex3f( size1, size1, size1);
    glVertex3f( size1, size1, size1);
    glVertex3f(-size1, size1, size1);
    glVertex3f(-size1, size1, size1);
    glVertex3f(-size1,-size1, size1);
}

void back(){
    glVertex3f(-size1,-size1,-size1);
    glVertex3f( size1,-size1,-size1);
    glVertex3f( size1,-size1,-size1);
    glVertex3f( size1, size1,-size1);
    glVertex3f( size1, size1,-size1);
    glVertex3f(-size1, size1,-size1);
    glVertex3f(-size1, size1,-size1);
    glVertex3f(-size1,-size1,-size1);
}

void DrawCube2(void)
{
    glColor3f(1.0f, 0.0f, 1.0);
    
    glBegin(GL_LINES);
    // bottom
    bottom();
    
    // top
    top();
    
    // left
    left();
    
    // right
    right();
    
    // front
    front();
    
    // back
    back();
    glEnd();
}

void DrawCube4(void)
{
    glColor3f(1.0f, 0.0f, 0.0);
    
    glBegin(GL_LINES);
    // bottom
    bottom();
    
    // top
    top();
    
    // left
    left();
    
    // right
    right();
    
    // front
    front();
    
    // back
    back();
    glEnd();
}

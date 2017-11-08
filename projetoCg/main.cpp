//
//  main.cpp
//  projetoCg
//
//  Created by Gustavo Colaco on 07/11/17.
//  Copyright © 2017 Gustavo Colaço. All rights reserved.
//

#include <OpenGL/gl.h>
#include <OpenGl/glu.h>
#include <GLUT/glut.h>
#include <iostream>
#include <stdio.h>
#import "obstacles.h"
#import "playerSpaceship.h"

float posX = 0.0f, posY = -0.45f, posZ =  1.0f; // posiçao da nave, vars usadas para fazer o movimento na func SpecialKeys

//---------------------------------------------------------------
void free_mem(void)
{
    std::clog << "Exiting...\n";
}

//---------------------------------------------------------------
// setando as teclas para interação com o game!
void SpecialKeys(int tecla, int x, int y){
    
    //movimento da nave
    switch(tecla){
            
        case GLUT_KEY_LEFT:
            posX -= 0.018;
            break;
            
        case GLUT_KEY_RIGHT:
            posX += 0.018;
            break;
    }
    
    
}

//---------------------------------------------------------------
void display(void)
{
    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    glViewport(0, 0, 1024, 768);
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    
    gluPerspective( 55.0f, 1.0f, 0.1f, 100.0f );
    
    gluLookAt(	0.0f, 0.0f, 2.5f,
              0.0f, 0.0f, 0.0f,
              0.0f, 1.0f, 0.0f);
    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
    //nave na cena
    glTranslatef(posX, posY, posZ);
    Spaceship();
    glLoadIdentity();
    
    // *********************************
    //  desenhando a pista
    
    glRotatef( -135, 0, 0, 1 );
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_LINES);
    glVertex3f(0.0, 0.0, 0.0);
    glVertex3f(15.0, 0, 0.0);
    glEnd();
    glLoadIdentity();
    
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_LINES);
    glVertex3f(0.0, 0.0, 0.0);
    glVertex3f(15.0, 0, 0.0);
    glEnd();
    glLoadIdentity();
    
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_LINES);
    glVertex3f(0.0, 0.0, 0.0);
    glVertex3f(-15.0, 0, 0.0);
    glEnd();
    glLoadIdentity();
    
    glRotatef( -45, 0, 0, 1 );
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_LINES);
    glVertex3f(0.0, 0.0, 0.0);
    glVertex3f(15.0, 0, 0.0);
    glEnd();
    glLoadIdentity();
    // *********************************
    
    glEnd();
    
    glutSwapBuffers();
    glutPostRedisplay();
}




//---------------------------------------------------------------
int main(int argc, char **argv)
{
    std::clog << "Begin...\n";
    
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);
    glutInitWindowSize(1024, 768);
    glutInitWindowPosition(100,100);
    glutCreateWindow("Race to the sun");
    glutSpecialFunc(SpecialKeys);
    
    glDisable(GL_LIGHTING);
    glEnable(GL_DEPTH_TEST);
    
    glutDisplayFunc(display);
    
    atexit(free_mem);
    
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    
    glutMainLoop();
    
    return 0;
}

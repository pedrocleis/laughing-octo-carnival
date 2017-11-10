//
//  playerSpaceship.h
//  raceToTheSun
//
//  Created by Gustavo Colaco on 09/11/17.
//  Copyright © 2017 Gustavo Colaço. All rights reserved.
//

#ifndef playerSpaceship_h
#define playerSpaceship_h
#import "obstacles.h"


void Spaceship(void)
{
    glColor3f(1.0f, 1.0f, 1.0);
    
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

#endif /* playerSpaceship_h */

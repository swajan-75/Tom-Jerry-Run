//
//  Basic_Element.hpp
//  CG_project
//
//  Created by Swajan Baruah on 2/5/24.
//

#ifndef Basic_Element_hpp
#define Basic_Element_hpp

#include <stdio.h>
#include "MacOxide.h"
#endif /* Basic_Element_hpp */
void circle (GLfloat x, GLfloat y , GLfloat radius ,int R , int G , int B);
void bar(double x1,double y1 , double x2 , double y2,int r, int g, int b);
void add_bar_with_animation(double x1 , double y1 , double x2 , double y2 , double position_updater_x , double position_updater_y ,double position_updater_z);
void love();
void draw_love(int quantity);
void cup(double x1 ,double y1 , double x2 , double y2);
void add_cup_with_animation(double new_position_x,double new_position_y,double new_position_z);


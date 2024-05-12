//
//  Basic_Element.cpp
//  CG_project
//
//  Created by Swajan Baruah on 2/5/24.
//

#include "Basic_Element.hpp"

# define PI           3.14159265358979323846
int a = 161 ;
int b = 108 ;
int c = 91 ;
void circle (GLfloat x, GLfloat y , GLfloat radius ,int R , int G , int B){
    int i;

    int triangleAmount = 1000;
    

    GLfloat twicePi = 2.0f * PI;

    glColor3ub(R,G,B);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(x, y); // center of circle
        for(i = 0; i <= triangleAmount;i++) {
            glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                        y + (radius * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
}

void bar(double x1,double y1 , double x2 , double y2,int r,int g, int b){
    //glLoadIdentity();
    glBegin(GL_POLYGON);
    glColor3ub(r,g,b);
    glVertex2f(x1,y1+0.1);
    glVertex2f(x1,y1);
    glVertex2f(x2,y2);
    glVertex2f(x2,y2+0.1);
    glEnd();
    
}

void add_bar_with_animation(double x1 , double y1 , double x2 , double y2 , double position_updater_x , double position_updater_y ,double position_updater_z){
    glPushMatrix();
    glTranslatef(position_updater_x,position_updater_y , position_updater_z);
    bar(x1,y1,x2,y2,a,b,c);
    glPopMatrix();
}
void love(){
    //glColor3b(1.0f, 0, 0);
    circle(-0.85f, 0.815f, 0.03,138, 15, 27);
}
void draw_love(int quantity){
    if(quantity<=0){
        return;
    }else{
        love();
        for(int i=1;i<quantity;i++){
            glTranslatef(0.1, 0, 0);
            love();
        }
        glLoadIdentity();
        
    }
    
}
void cup(double x1 ,double y1 , double x2 , double y2)
 {
    glPushAttrib(GL_CURRENT_BIT);
  //  glPushMatrix();
    glColor4f(0.178, 0.190, 0.181,0.5);  // Set color (R, G, B)
   // glTranslatef(0.4f, -0.6f, 0.0f);
    //glTranslatef(x1, y1+y1, 0.0f);
    glScalef(.4,.5,0);
    glColor4f(0.178, 0.190, 0.181,0.5);  // Set color (R, G, B)

    glBegin(GL_POLYGON);
    glVertex2f(0.1,0);
    glVertex2f(0.15,-0.03);
    glVertex2f(0.35,-0.03);
    //glVertex2f(x1,y1);
    glVertex2f(0.4,0);
    glVertex2f(0.4,0.2);
    glVertex2f(0.1,0.2);
    glVertex2f(0.1,0);

    glEnd();
    glColor4f(0.178, 0.190, 0.181,0.5);  // Set color (R, G, B)
    glBegin(GL_POLYGON);
    glVertex2f(0,0.09);
    glVertex2f(0.1,0.03);
    glVertex2f(0.1,0.17);
    glVertex2f(0,0.12);
    glVertex2f(0,0.09);

    glEnd();
    glColor3ub(153,204,255);// Set color (R, G, B)
    glBegin(GL_POLYGON);
    glVertex2f(0.1,0.06);
    glVertex2f(0.03,0.1);
    //glVertex2f(x2,y2);
    glVertex2f(0.1,0.14);
    glVertex2f(0.1,0.06);

    glEnd();
   // glPopMatrix();
    glPopAttrib();
}
void add_cup_with_animation(double x1 , double y1, double x2 , double y2,double new_position_x,double new_position_y,double new_position_z)
{
   
    glPushMatrix();
    glTranslatef(new_position_x,new_position_y , new_position_z);
    cup(x1,y1,x2,y2);
    glPopMatrix();


}



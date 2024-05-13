//
//  Characters.cpp
//  CG_project
//
//  Created by Swajan Baruah on 13/5/24.
//

#include "MacOxide.h"
void tom_test()
{
glBegin(GL_POLYGON);//face
glColor3f(0.2, 0.7, 0.9);
glVertex2f(0.45f, 0.57f);
glVertex2f(0.52f, 0.59f);
glVertex2f(0.52f, 0.74f);
glVertex2f(0.45f, 0.8f);
glVertex2f(0.3f, 0.8f);
glVertex2f(0.25f, 0.79f);
glVertex2f(0.2f, 0.69f);
glVertex2f(0.21f, 0.52f);
glVertex2f(0.4f, 0.45f);
glVertex2f(0.4f, 0.5f);
glVertex2f(0.45f, 0.57f);
glEnd();

glBegin(GL_POLYGON);//0.5 face
glColor3f(1,1,1);
glVertex2f(0.4f, 0.45f);
glVertex2f(0.4f, 0.5f);
glVertex2f(0.45f, 0.57f);
glVertex2f(0.52f, 0.59f);
glVertex2f(0.57f, 0.59f);
glVertex2f(0.57f, 0.54f);
glVertex2f(0.52f, 0.5f);
glVertex2f(0.499f, 0.45f);
glVertex2f(0.4f, 0.45f);
glEnd();
glBegin(GL_POLYGON);//nose
glColor3f(0,0,0);
glVertex2f(0.50,0.58);
glVertex2f(0.52,0.58);
glVertex2f(0.52,0.56);
glVertex2f(0.50,0.56);
glVertex2f(0.51,0.58);

glEnd();
glBegin(GL_POLYGON);//eyes
glColor3f(1,1,1);
glVertex2f(0.52,0.59);
glVertex2f(0.52,0.73);
glVertex2f(0.49,0.73);
glVertex2f(0.49,0.59);
// glVertex2f(0.5,0.59);
// glVertex2f(0.5,0.73);
glVertex2f(0.52,0.59);
glEnd();
glBegin(GL_POLYGON);//pupil
glColor3f(0,0,0);

glVertex2f(0.49,0.59);
glVertex2f(0.52,0.59);
glVertex2f(0.52,0.65);
glVertex2f(0.49,0.65);
glVertex2f(0.49,0.59);

glEnd();
glBegin(GL_POLYGON);//eyes
glColor3f(1,1,1);
glVertex2f(0.469,0.59);
glVertex2f(0.469,0.73);
glVertex2f(0.43,0.73);
glVertex2f(0.43,0.59);
glVertex2f(0.469,0.59);
glEnd();
glBegin(GL_POLYGON);//pupil
glColor3f(0, 0, 0);
glVertex2f(0.43, 0.59);
glVertex2f(0.47, 0.59);
glVertex2f(0.47, 0.65);
glVertex2f(0.43, 0.65);
glVertex2f(0.43, 0.59);
glEnd();
glBegin(GL_POLYGON);//mouth
glColor3f(1, 0, 0);
glVertex2f(0.45, 0.49);
glVertex2f(0.45, 0.51);
glVertex2f(0.51, 0.51);
glVertex2f(0.49, 0.49);
glVertex2f(0.45, 0.49);
glEnd();
    glBegin(GL_LINE_STRIP);//ear
    glColor3f(0, 0, 0);
    glVertex2f(0.37, 0.8);
    glVertex2f(0.25, 0.87);
    glVertex2f(0.15, 0.87);
    glVertex2f(0.24, 0.78);

    //glVertex2f(0.23, 0.78);
    glEnd();
glBegin(GL_POLYGON);//ear
glColor3f(0.2, 0.7, 0.9);
glVertex2f(0.37, 0.8);
glVertex2f(0.25, 0.87);
glVertex2f(0.15, 0.87);
glVertex2f(0.24, 0.78);
// glVertex2f(0.39, 0.8);

glEnd();
glBegin(GL_TRIANGLE_FAN);//ear
glColor3f(0.2, 0.7, 0.9);
glVertex2f(0.25, 0.78);
glVertex2f(0.19, 0.82);
glVertex2f(-0.01, 0.8);
glVertex2f(0.3,0.7);
glVertex2f(0.23, 0.7);

glEnd();
glBegin(GL_TRIANGLE_FAN);//ear
glColor3f(0.763,0.844,0.48);
glVertex2f(-0.009, 0.8);
glVertex2f(0.21, 0.6);
glVertex2f(0.22, 0.72);

glVertex2f(0.19, 0.78);


glEnd();

glLineWidth(1);

glBegin(GL_LINE_STRIP);//m
glColor3f(0, 0, 0);
glVertex2f(0.51, 0.57);
glVertex2f(0.6, 0.62);
glEnd();
glBegin(GL_LINE_STRIP);//m

glVertex2f(0.51, 0.57);
glVertex2f(0.4,0.57);

glEnd();
glBegin(GL_LINE_STRIP);//m

glVertex2f(0.51, 0.57);
glVertex2f(0.4,0.54);

glEnd();
glBegin(GL_LINE_STRIP);//m
glVertex2f(0.51, 0.57);
glVertex2f(0.6, 0.59);
glEnd();
    glBegin(GL_POLYGON);//tail

    glColor3f(0.2, 0.7, 0.9);

    glVertex2f(-0.15,0.03);
    glVertex2f(-0.05,0.1);
    glVertex2f(-0.24,0.5);

    glVertex2f(-0.34,0.45);

    glEnd();
    glBegin(GL_TRIANGLE_FAN);//0.5 tail
    glColor3f(1,1,1);
    glVertex2f(-0.35,0.53);

    glVertex2f(-0.34,0.45);
    glVertex2f(-0.24,0.5);
    glVertex2f(-0.3,0.57);
   glVertex2f(-0.4,0.6);
    glEnd();
glBegin(GL_TRIANGLE_FAN);//body
glColor3f(0.2, 0.7, 0.9);

glVertex2f(0.21,0.52);
glVertex2f(-0.38,0.01);
glVertex2f(-0.38,-0.2);
glVertex2f(-0.2,-0.2);
    
    glVertex2f(-0.2,-0.1);
    glVertex2f(0.1,-0.1);
    glVertex2f(0.1,-0.2);
    glVertex2f(0.3,-0.2);

    glVertex2f(0.3,0.01);
    glVertex2f(0.3,0.2);
    glVertex2f(0.4,0.5);
  
    glEnd();

    glBegin(GL_TRIANGLE_FAN);//0.5 leg
    glColor3f(1,1,1);

    glVertex2f(-0.38,-0.2);
    glVertex2f(-0.43,-0.25);
    glVertex2f(-0.38,-0.3);
    glVertex2f(-0.2,-0.3);
    glVertex2f(-0.2,-0.2);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);//0.5 leg
    glColor3f(1,1,1);

    glVertex2f(0.1,-0.2);
    glVertex2f(0.1,-0.3);
    glVertex2f(0.3,-0.3);
    glVertex2f(0.33,-0.25);
    glVertex2f(0.3,-0.2);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);//hand
    glColor3f(0.2, 0.7, 0.9);

    glVertex2f(0.3,0.37);
    glVertex2f(0.45,0.19);
    glVertex2f(0.45,0.29);
         
         glVertex2f(0.3,0.50);
         
       
         glEnd();
    glBegin(GL_TRIANGLE_FAN);//0.5hand
    glColor3f(1,1,1);

    
    glVertex2f(0.45,0.19);
    glVertex2f(0.45,0.29);
    glVertex2f(0.50,0.22);
    glVertex2f(0.50,0.10);

         glEnd();
    glLineWidth(7);

    glBegin(GL_LINE_STRIP);//f
    glColor3f(1,1,1);
    glVertex2f(0.46, 0.20);
    glVertex2f(0.49, 0.26);
       
    glEnd();
    glLineWidth(1);

    glBegin(GL_LINE_STRIP);//f
    glColor3f(0,0,0);
    glVertex2f(0.48, 0.20);
    glVertex2f(0.50,0.19);

    glEnd();
    glLineWidth(1);

    glBegin(GL_LINE_STRIP);//f
    glColor3f(0,0,0);
    glVertex2f(0.48, 0.17);
    glVertex2f(0.50,0.16);

    glEnd();
    
    glBegin(GL_POLYGON);//0.5 body

    glColor3f(0.763,0.844,0.48);

    glVertex2f(0.35,0.4);
    glVertex2f(0.25,0.4);
    glVertex2f(-0.1,0.1);

    glVertex2f(-0.145,-0.1);
    glVertex2f(0.1,-0.10);
    glVertex2f(0.28,0.2);

    //glVertex2f(0.19, 0.78);


    glEnd();
    glBegin(GL_TRIANGLE_FAN);//hand
    glColor3f(0.2, 0.7, 0.9);

    glVertex2f(0.07,0.4);
    glVertex2f(0.37,0.15);
    glVertex2f(0.37,0.27);
         
         glVertex2f(0.2,0.4);
         
       
         glEnd();
    glBegin(GL_TRIANGLE_FAN);//0.5hand
    glColor3f(1,1,1);
    glVertex2f(0.37,0.15);
    glVertex2f(0.37,0.27);
    glVertex2f(0.43,0.19);
    glVertex2f(0.43,0.05);

         glEnd();
    glLineWidth(7);

    glBegin(GL_LINE_STRIP);//f
    glColor3f(1,1,1);
    glVertex2f(0.39, 0.19);
    glVertex2f(0.41, 0.25);
       
    glEnd();
    glLineWidth(1);

    glBegin(GL_LINE_STRIP);//f
    glColor3f(0,0,0);
    glVertex2f(0.40, 0.19);
    glVertex2f(0.43, 0.14);
       
    glEnd();
    glLineWidth(1);

    glBegin(GL_LINE_STRIP);//f
    glColor3f(0,0,0);
    glVertex2f(0.40, 0.15);
    glVertex2f(0.43, 0.10);
       
    glEnd();
   
    
}
void jerry_test()
{
    glBegin(GL_POLYGON);//face
    glColor3f(0.833,0.37,0.6);
    glVertex2f(0.45f, 0.57f);
    glVertex2f(0.52f, 0.59f);
    glVertex2f(0.52f, 0.74f);
    glVertex2f(0.45f, 0.8f);
    glVertex2f(0.3f, 0.8f);
    glVertex2f(0.25f, 0.78f);
    glVertex2f(0.2f, 0.69f);
    glVertex2f(0.21f, 0.52f);
    glVertex2f(0.4f, 0.45f);
    glVertex2f(0.4f, 0.5f);
    glVertex2f(0.45f, 0.57f);
    glEnd();
    
    glBegin(GL_POLYGON);//0.5 face
    glColor3f(0.763,0.844,0.48);
    glVertex2f(0.4f, 0.45f);
    glVertex2f(0.4f, 0.5f);
    glVertex2f(0.45f, 0.57f);
    glVertex2f(0.52f, 0.59f);
    glVertex2f(0.57f, 0.59f);
    glVertex2f(0.57f, 0.54f);
    glVertex2f(0.52f, 0.5f);
    glVertex2f(0.499f, 0.45f);
    glVertex2f(0.4f, 0.45f);
    glEnd();
    glBegin(GL_POLYGON);//nose
    glColor3f(0,0,0);
    glVertex2f(0.50,0.58);
    glVertex2f(0.52,0.58);
    glVertex2f(0.52,0.56);
    glVertex2f(0.50,0.56);
    glVertex2f(0.51,0.58);

    glEnd();
    glBegin(GL_POLYGON);//eyes
    glColor3f(1,1,1);
    glVertex2f(0.52,0.59);
    glVertex2f(0.52,0.73);
    glVertex2f(0.49,0.73);
    glVertex2f(0.49,0.59);
   // glVertex2f(0.5,0.59);
   // glVertex2f(0.5,0.73);
    glVertex2f(0.52,0.59);
    glEnd();
    glBegin(GL_POLYGON);//pupil
    glColor3f(0,0,0);
   
    glVertex2f(0.49,0.59);
    glVertex2f(0.51,0.59);
    glVertex2f(0.51,0.65);
    glVertex2f(0.49,0.65);
    glVertex2f(0.49,0.59);

    glEnd();
    glBegin(GL_POLYGON);//eyes
    glColor3f(1,1,1);
    glVertex2f(0.469,0.59);
    glVertex2f(0.469,0.73);
    glVertex2f(0.43,0.73);
    glVertex2f(0.43,0.59);
    glVertex2f(0.469,0.59);
    glEnd();
    glBegin(GL_POLYGON);//pupil
    glColor3f(0, 0, 0);
    glVertex2f(0.43, 0.59);
    glVertex2f(0.46, 0.59);
    glVertex2f(0.46, 0.65);
    glVertex2f(0.43, 0.65);
    glVertex2f(0.43, 0.59);
    glEnd();
    glBegin(GL_POLYGON);//mouth
    glColor3f(1, 0, 0);
    glVertex2f(0.45, 0.49);
    glVertex2f(0.45, 0.51);
    glVertex2f(0.51, 0.51);
    glVertex2f(0.49, 0.49);
    glVertex2f(0.45, 0.49);
    glEnd();
    glBegin(GL_POLYGON);//ear
    glColor3f(0.833,0.37,0.6);
    glVertex2f(0.35, 0.8);
    glVertex2f(0.42, 0.8);
    glVertex2f(0.42, 0.9);
    glVertex2f(0.35, 0.8);

    glEnd();
    glBegin(GL_TRIANGLE_FAN);//ear
    glColor3f(0.833,0.37,0.6);
    glVertex2f(0.25, 0.78);
    glVertex2f(0.19, 0.85);
    glVertex2f(0.1, 0.85);
   glVertex2f(0.03,0.8);
    glVertex2f(0.11, 0.8);
    glVertex2f(0.2, 0.69);
    glVertex2f(0.25, 0.78);
    glVertex2f(0.19, 0.85);
    glVertex2f(0.1, 0.85);
    glVertex2f(0.25, 0.78);

    glEnd();
    glBegin(GL_POLYGON);//ear
    glColor3f(0.763,0.844,0.48);
    glVertex2f(0.21, 0.69);
    glVertex2f(0.11, 0.8);
    glVertex2f(0.03, 0.8);
    glVertex2f(0,0.72);
   glVertex2f(0, 0.65);
    glVertex2f(0.03, 0.559);
    glVertex2f(0.11, 0.5);
    glVertex2f(0.21, 0.52);
    glVertex2f(0.21, 0.69);

    glEnd();
    glBegin(GL_POLYGON);//body
    glColor3f(0.833,0.37,0.6);
    glVertex2f(0.29, 0.492);
    glVertex2f(0.23, 0.45);
    glVertex2f(0.2, 0.4);
    glVertex2f(0.19,0.32);
   glVertex2f(0.21, 0.25);
   // glVertex2f(0.21, 0.17);
   glVertex2f(0.41, 0.17);
    glVertex2f(0.45, 0.24);
    glVertex2f(0.45, 0.4);
    glVertex2f(0.42, 0.441);

    glEnd();
    glBegin(GL_POLYGON);//body
    glColor3f(0.763,0.844,0.48);
    glVertex2f(0.41, 0.17);
    glVertex2f(0.45, 0.24);
    glVertex2f(0.45, 0.4);
    glVertex2f(0.42, 0.42);
    glVertex2f(0.39, 0.4);
    glVertex2f(0.39,0.24);
    glVertex2f(0.41, 0.17);
    glEnd();
    
   glBegin(GL_POLYGON);//leg
    glColor3f(0.833,0.37,0.6);
    glVertex2f(0.27, 0.1);
    glVertex2f(0.22, 0.05);
    glVertex2f(0.236, 0.01);
    glVertex2f(0.46, 0.01);
    glVertex2f(0.476,0.05);
    glVertex2f(0.41, 0.1);
    glVertex2f(0.41, 0.17);
    glVertex2f(0.21, 0.25);
    glVertex2f(0.25, 0.17);
    glEnd();
    glLineWidth(0.001);
    glBegin(GL_LINES);//leg
    glColor3f(0,0,0);
    glVertex2f(0.35, 0.01);
    glVertex2f(0.35, 0.17);
    glEnd();
    
    glBegin(GL_LINE_STRIP);//hand
    glColor3f(0, 0, 0);
    glVertex2f(0.29, 0.49);
    glVertex2f(0.23, 0.45);
    glVertex2f(0.2, 0.4);
    glVertex2f(0.19,0.32);
   glVertex2f(0.21, 0.25);
    glVertex2f(0.23, 0.23);

    glVertex2f(0.25, 0.25);
    
    glVertex2f(0.26, 0.32);


    glEnd();
    glLineWidth(5);

    glBegin(GL_LINE_STRIP);//body
    glColor3f(0.833,0.37,0.6);
    glVertex2f(0.21, 0.26);
    glVertex2f(0.14, 0.25);
    glVertex2f(0.11, 0.22);
    glVertex2f(0.06,0.23);
   glVertex2f(0.02, 0.25);
    glVertex2f(0.03, 0.3);

    glEnd();
    glLineWidth(1);

    glBegin(GL_LINE_STRIP);//m
    glColor3f(0, 0, 0);
    glVertex2f(0.51, 0.57);
    glVertex2f(0.6, 0.62);
    glEnd();
    glBegin(GL_LINE_STRIP);//m

    glVertex2f(0.51, 0.57);
    glVertex2f(0.4,0.57);
   
    glEnd();
    glBegin(GL_LINE_STRIP);//m

    glVertex2f(0.51, 0.57);
    glVertex2f(0.4,0.54);

    glEnd();
    glBegin(GL_LINE_STRIP);//m
    glVertex2f(0.51, 0.57);
    glVertex2f(0.6, 0.59);
    glEnd();

}

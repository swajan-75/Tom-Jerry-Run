//
//  Info_page.cpp
//  CG_project
//
//  Created by Swajan Baruah on 30/4/24.
//

#include "Info_page.hpp"

void drawText(string text,float x,float y)
{
    glRasterPos2f(x,y);
    for(int i=0;i<text.size();i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,text[i]);
    }
}


void drawText1(string text,float x,float y)
{
    glRasterPos2f(x,y);
    for(int i=0;i<text.size();i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,text[i]);
    }
}

void info()
{

    glClear (GL_COLOR_BUFFER_BIT);
    glClearColor (1.0f, 1.0f, 1.0f, 1.0f);

    glPushMatrix();
    glMatrixMode (GL_MODELVIEW);
    glLoadIdentity();

    glColor3f (0.2235f,.5176f,0.5686274509803922f);
    drawText("American International University, Bangladesh (AIUB)", -0.8f,0.8f);
    glColor3f (0.21568627450980395,0.403921568627451f, 0.5490196078431373f);
    drawText("FACULTY OF SCIENCE AND TECHNOLOGY",-0.8f,.65f);
    glColor3f (0.32156f,0.1333f, 0.1411764705882353f);
    drawText("PROJECT ON TOM & JERRY (GAME)",-0.8f,.5f);
    glColor3f (0.17641,0.17641,0.3803921568627451f);
    drawText("COURSE NAME COMPUTER GRAPHICS",-0.8f,.35f);
    drawText("COURSE SUPERVISOR: MAHFUJUR RAHMAN",-0.8f,.22f);
    glColor3f (0.76862745098039225,0.0784313725490196f,0.0784313725490196f);
    drawText("MEMBERS:",-0.2f,.05f);
    glColor3f (0.7686274509803922f,0.0784313725490196f,0.0784313725490196f);
    drawText1 ("1. SWAJAN BARUA ID:22-46838-1)",-0.75,-.21);
    drawText1 ("2. MD.RAFI UZ ZAMAN NAYEEM ID:22-46775-1)",-0.75,-.31);
    drawText1 ("3. ANKAN PAUL TURZA ID:22-46857-1)",-0.75,-.4f);
    drawText1 ("4. AINEA ESRAT ESIKA 22-46837-1)",-0.75,-.5f);
    glPopMatrix();

glPushMatrix();

int flash=glutGet(GLUT_ELAPSED_TIME)/500%2;

    if (flash) {
        glColor3f(0.0f, 1.0f, 1.0f);
        }

    else{
        glColor3f (1.0f, 0.0f, 0.0f);}
        drawText("Press 'N' to go Next",0.4f,-0.89f);
        glPopMatrix();
        glutSwapBuffers();
    }



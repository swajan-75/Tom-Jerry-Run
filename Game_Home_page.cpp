#include "Game_Home_page.h"
    string displayText = "";
    void drawButton(const char *label, float x, float y) {
        glPushMatrix();
        glTranslatef(x, y, 0.0f);
        glBegin(GL_QUADS);
        glColor3f(0.0f, 1.0f, 1.0f);
        glVertex2f(0.0f, 0.0f);
        glVertex2f(0.3f, 0.0f);
        glVertex2f(0.3f, 0.1f);
        glVertex2f(0.0f, 0.1f);
        glEnd();
        glColor3f(1.0f, 1.0f, 1.0f);
        glRasterPos2f(0.02f, 0.04f);
        for (const char *c = label; *c != '\0'; ++c) {
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *c);
        }
        glPopMatrix();
    }
    
    void Display_Game_Home_page(){
        glClear(GL_COLOR_BUFFER_BIT);
        glLoadIdentity();
        glTranslatef(0.4f, 0.1f, 0.0f);

      // Draw buttons
       
        drawButton("Play", -0.5f, 0.2f);
    
      drawButton("High Scores", -0.5f, 0.0f);
      drawButton("Instructions", -0.5f, -0.2f);

      // Display the text
      glColor3f(1.0f, 1.0f, 1.0f);
      glRasterPos2f(-0.5f, -0.5f);
        for (int i =0 ;i<displayText.size();i++) {
          glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, displayText[i]);
      }

      glFlush();
    }
    
void Display_Game_Home_page_resume(){
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(0.4f, 0.1f, 0.0f);

  // Draw buttons

  drawButton("Resume", -0.5f, 0.2f);
  drawButton("High Scores", -0.5f, 0.0f);
  drawButton("Instructions", -0.5f, -0.2f);

  // Display the text
  glColor3f(1.0f, 1.0f, 1.0f);
  glRasterPos2f(-0.5f, -0.5f);
    for (int i =0 ;i<displayText.size();i++) {
      glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, displayText[i]);
  }

  glFlush();
}

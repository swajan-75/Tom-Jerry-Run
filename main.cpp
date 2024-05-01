#include "MacOxide.h"
#include "Game_Home_page.h"
#include "Info_page.hpp"
#include "High_Score_page.h"
# define PI           3.14159265358979323846
// pages
bool showGame = false;
bool showInfo = true ;
bool showLanding = false ;

vector<GLfloat>col_X;
vector<GLfloat>col_Y;


GLfloat almira_position = 0.0f; // Initial position of almira door
GLfloat almira_speed = 1.0f; // Speed of almira door movement
GLfloat jerry_move =0.0f;
GLfloat jerry_jump =0.0f;
GLfloat  jerry_last_position =0.0f;
bool jerry_can_go_back = 0;
bool jerry_can_go_forward = true;
bool is_up =0;
GLfloat jerry_jump_position = 0;
GLfloat tom_last_position = -0.4 ;
bool game_over = 0;
bool paused = 0;




void pauseResumeGame() {
    paused = !paused;
}

long long score =0;


void renderBitmapString(float x, float y, float z, void *font, string str) {
    //char *c;
    glRasterPos3f(x, y,z);
    for (int i =0;i<str.size();i++)
    {
        glutBitmapCharacter(font, str[i]);
    }
}

void set_bg_color(int r, int g, int b){
    float a  = float(r)/255.0f , f = float(g)/255.0f , c = float(b)/255.0f ;
    glClearColor(a,f,c,1);
    
}

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

void almira_door(){
    glLineWidth(10.0);
    glBegin(GL_LINES);
    glColor3ub(122,95,34);
    glVertex2f(-1,-0.7);
    glVertex2f(-1,-1);
    glEnd();
    
    circle(-1.05,-0.8,0.03,174,137,45);
    circle(-0.95,-0.8,0.03,174,137,45);
    
}
GLfloat position = 0.0f;
GLfloat long_bar_position = 0.0f ;
GLfloat speed = 0.1f;
GLfloat long_bar  = 0.0f;
void update(int value)
{
    
    if(position <-5.5)
        position = 1.0f;
    position -= speed;
    glutPostRedisplay();
    glutTimerFunc(100, update, 0);
}

void update_for_long_bar(int value)
{
   
    if(long_bar_position <-7.2)
        long_bar_position = 3;
    long_bar_position -= speed;
    glutPostRedisplay();
    glutTimerFunc(100, update_for_long_bar, 0);
}


void update2(int value) {
  

        // If the door reaches the right side of the screen, reset its position
        if (almira_position < -1.0)
            almira_position = 1.0;
            almira_position -= almira_speed;

        glutPostRedisplay();
        glutTimerFunc(100, update2, 0);
}
void bar(double x1,double y1 , double x2 , double y2){
    //glLoadIdentity();
    glBegin(GL_POLYGON);
    glColor3ub(161,108,91);
    glVertex2f(x1,y1+0.1);
    glVertex2f(x1,y1);
    glVertex2f(x2,y2);
    glVertex2f(x2,y2+0.1);
    glEnd();
    
}



void add_bar_with_animation(double x1 , double y1 , double x2 , double y2 , double position_updater_x , double position_updater_y ,double position_updater_z){
    glPushMatrix();
    glTranslatef(position_updater_x,position_updater_y , position_updater_z);
    bar(x1,y1,x2,y2);
    glPopMatrix();
}

void tom(){
    
    glPushMatrix();
    glBegin(GL_POLYGON);
   
    glVertex2f(-0.6 , -0.45);
    glVertex2f(-0.4,-0.45);
    glVertex2f(-0.4,-0.6);
    glVertex2f(-0.6,-0.6);
    glEnd();
    glPopMatrix();
    
}


void jerry(){
    glBegin(GL_POLYGON);
    glVertex2f(0 , -0.5);
    glVertex2f(0.2,-0.5);
    glVertex2f(0.2,-0.6);
    glVertex2f(0,-0.6);
    glEnd();
    
}
void jerry_get_down(int x) {
    is_up = false ;
}
void jerry_jump_update(int x){
    if (is_up) {
        jerry_jump_position =0.3;
        glutTimerFunc(1000, jerry_get_down, 0);
    }else{
        jerry_jump_position = 0.0;
    }
}

void jerry_move_update(int x) {
 
    if (jerry_last_position > 0.7 ){
           jerry_can_go_back = 1;
        jerry_can_go_forward = 0;
       }
    if(jerry_last_position<tom_last_position){
        jerry_can_go_back =0;
     jerry_can_go_forward = 1;
    }

    if (jerry_can_go_forward && x==1) {
        jerry_move += 0.1;
        jerry_last_position += 0.1;
    }
    
    if (jerry_can_go_back && x==2) {
        jerry_move -= 0.1;
        jerry_last_position -= 0.1;
    }
}

void test(int x){
   // std::cout << jerry_move<<" "<<(jerry_last_position > 0.7)<<" "<<(jerry_last_position<tom_last_position)<< std::endl;
    glutTimerFunc(10, test, 0); // Call the test function again after 2 seconds
    
}
//************************* text read & write  **********************



void update_score(int x){
    if(jerry_last_position>tom_last_position){
        renderBitmapString(-0.98f, 0.9f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "Score : "+to_string(score));
        score++;
        //write_score(score);
    }else{
        game_over=1;
        renderBitmapString(0.0f, 0.0f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "Game Over ");

    }
    
}




void high_score(){
    set_bg_color(153,204,255 );    // Background color  ;
    glClear(GL_COLOR_BUFFER_BIT);
    
    
    glColor3f (0.2235f,.5176f,0.5686274509803922f);
    drawText("High Score ", -0.5f,0.8f);
    
    
    
    glFlush();
}


void display() {
    if(paused){
        return;
    }
    if(!game_over){
        
        set_bg_color(153,204,255 );    // Background color  ;
        glClear(GL_COLOR_BUFFER_BIT);
        // Clear the color buffer (background)

        
        // ground
        glBegin(GL_POLYGON);
        glColor3ub(184,170,112);
        glVertex2f(-1,-0.7);
        glVertex2f(-1,-1);
        glVertex2f(1,-1);
        glVertex2f(1,-0.7);
        glEnd();
        
        
        glPushMatrix();
                glTranslatef(almira_position, 0.0f, 0.0f); // Translate the almira door horizontally
                almira_door();
            for(int i =0 ;i<10;i++){
                glTranslatef(0.3, 0.0,0.0);
                almira_door();
                }
            glPopMatrix();
        
        glLoadIdentity();
        bar(-1,-0.7,1,-0.7);
        
        add_bar_with_animation(1.4,-0.4,1.8,-0.4,position,0,0);
        
        add_bar_with_animation(3,-0.4,3.4,-0.4,position,0,0);
        add_bar_with_animation(3.8,-0.2,4.2,-0.2,position,0,0);
        add_bar_with_animation(4.4,0,4.8,0,position,0,0);
        
        add_bar_with_animation(-0.2,-0.2,0.2,-0.2,position,0,0);
        add_bar_with_animation(5.2 ,-0.6 ,6.5,-0.6,long_bar_position,0,0);
        tom();
        
        glPushMatrix();
        jerry_jump_update(0);
        glTranslatef(jerry_move,jerry_jump_position,0 );
        jerry();
        //glutTimerFunc(3000,jerry_get_down,0);
        glPopMatrix();
        update_score(0);
       
        
        

        glFlush(); // Render now

    }else{
                set_bg_color(153, 204, 255); // Background color
                glClear(GL_COLOR_BUFFER_BIT);
                renderBitmapString(-0.2f, 0.0f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "Game Over");
                renderBitmapString(-0.2f, -0.1f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "Score: " + to_string(score));
                write_score(score);
                glFlush();
        
        }
    }

void specialKeys(int key , int x, int y){
    switch (key) {
    case GLUT_KEY_RIGHT:
        jerry_move_update(1);
        glutPostRedisplay();
        break;
    case GLUT_KEY_LEFT:
        jerry_move_update(2);
           // std::cout<<2<<std::endl;
        glutPostRedisplay();
        break;
            
    
    case GLUT_KEY_UP:
        //jerry_jump_update(0);
        is_up = true ;
        glutPostRedisplay();
        break;
        
        }
}

void keyboardFunc(unsigned char key, int x, int y) {
    switch (key) {
        case 'n':
        case 'N':
            //cout << "N" << endl;
            glutDisplayFunc(Display_Game_Home_page);
            glutPostRedisplay(); // Request a redraw to update the display
            break;
        case ' ':
            pauseResumeGame();
            break;
    }
}
void handleMouse(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        float mouseX = (2.0f * x) / glutGet(GLUT_WINDOW_WIDTH) - 1.0f;
        float mouseY = 1.0f - (2.0f * y) / glutGet(GLUT_WINDOW_HEIGHT);
        
        if (mouseX >= -0.5f && mouseX <= 0.5f && mouseY >= 0.3f && mouseY <= 0.4f) {
            
            glutDisplayFunc(display);
        } else if (mouseX >= -0.5f && mouseX <= 0.5f && mouseY >= 0.1f && mouseY <= 0.2f) {
           
            glutDisplayFunc(high_score);
        } else if (mouseX >= -0.5f && mouseX <= 0.5f && mouseY >= -0.1f && mouseY <= 0.1f) {
 
        }
    }
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(1200, 1200); // Set the window's initial width & height
    glutInitWindowPosition(250, 50);  // Set the window's initial position according to the monitor
    glutCreateWindow("OpenGL Setup"); // Create a window with the given title
    //read_from_file();
    glutKeyboardFunc(keyboardFunc);
    //write_score(score);
    glutTimerFunc(100, update, 0);
    glutTimerFunc(100, update2, 0);
   // glutTimerFunc(10,test,0);
    glutDisplayFunc(info);
   // glutTimerFunc(100,update_score,0);
   // glutIdleFunc(Idle);
    glutMouseFunc(handleMouse);
    glutTimerFunc(100,update_for_long_bar,0);
    glutSpecialFunc(specialKeys);
    // Register display callback handler for window re-paint
        glutMainLoop();
     // Enter the event-processing loop
    return 0;
}


#include "MacOxide.h"
#include "Game_Home_page.h"
#include "Info_page.hpp"
#include "High_Score_page.h"
#include "Basic_Element.hpp"
#include "Characters.h"
# define PI           3.14159265358979323846
// pages
bool showGame = false;
bool showInfo = true ;
bool showLanding = false ;
int kk =0;
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
bool is_down = 0;
bool is_collect_coin =false ;
GLfloat jerry_jump_position = 0;
GLfloat tom_last_position = -0.4 ;
bool game_over = 0;
bool paused = 0;
float angle = 0.0f;
class Jerry{
    public :
    double x_max  = -0.02;
    double x_min =0.02 ;
    double y_max =-0.5+0.02;
    double y_min =-0.6;
    double diff = 0.02;
    double x = 0.0 , y = -0.5;
    double width = abs(x_max - x_min);
    double height = abs(y_max - y_min);
    int life = 3;
    
    Jerry(){
      //  cout<<"faslkf"<<endl;
    }
    void reset(){
        this->x = 0.0 ;
        this->y = -0.5;
    }
    void set_bounds(double x_max ,double x_min , double y_max ,double y_min){
        this->x_max = x_max ;
        this->x_min = x_min ;
        this->y_max = y_max ;
        this->y_min = y_min ;
        
    }
    void bound_updater(double x_update , double y_update , double z_update){
        this->x_max +=x_update ;
        this->x_min +=x_update ;
        this->y_max +=y_update ;
        this->y_min +=y_update ;
        
        
        if(y_update==0){
            this->y =-0.5;
        }else{
            this->y += y_update-0.5 ;
        }
        
        if(y_update==0){
            this->x =0;
        }else{
            this->x +=x_update ;
        }
    }
    void draw(){
        /*
        glBegin(GL_POLYGON);
        glVertex2f(0 , -0.5);
        glVertex2f(0.2,-0.5);
        glVertex2f(0.2,-0.6);
        glVertex2f(0,-0.6);
        glEnd();
         */
        glScalef(0.3, 0.35, 0.0);
        glTranslatef(-0.6, -1.73, 0.0);
        jerry_test();
    }
};

class obstacle{
    public :
    double x,y;
    double width , height =0.1;
    int r=161,g=108,b=91;
    void set_color(int r, int g, int b){
        //glColor3ub(161,108,91);
        this->r = r;
        this->g = g;
        this->b = b;
    }
    void bar_draw(double x1 , double y1 , double x2 , double y2 , double position_updater_x , double position_updater_y ,double position_updater_z){
        glPushMatrix();
        glTranslatef(position_updater_x,position_updater_y , position_updater_z);
        bar(x1,y1,x2,y2,this->r,this->g,this->b);
        this->x =x1+position_updater_x +0.1;
        this->y = y1+position_updater_y+0.1 ;
        this->width = abs(x1-x2);
        bar(x1,y1,x2,y2,this->r,this->g,this->b);
        
        glPopMatrix();
    }
    void cup_draw(double x1 , double y1 , double x2 , double y2 , double position_updater_x , double position_updater_y ,double position_updater_z){
        this->x =x1+position_updater_x ;
        this->y = y1+position_updater_y ;
        this->width = 0.15;
        this->height=0.1;
        glPushMatrix();
        glTranslatef(position_updater_x, 0.0, 0.0);
        cup(x1,y1);
        glPopMatrix();
    }
};
class Coin{
    public :
    double x,y;
    bool visible = true;
    double width , height;
    void draw_coin(double x1 , double y1,double r , double position_updater_x , double position_updater_y ){
        if(visible){
            this->x = x1+r;
                        this->y = y1+r  ;
                        
                        this->width=this->height=r*2;
                        glPushMatrix();
                        glTranslatef(position_updater_x, position_updater_y, 0.0);
                        x=position_updater_x;
                        //y=position_updater_y;
                        glPushMatrix();
                        glPushAttrib(GL_CURRENT_BIT);
                        glRotatef(angle, 0.0, 0.1, 0.0);
                        
                        glTranslatef(x1 * 0.001, y1, 0.0); // Adjust the factor (0.5) to reduce the radius
                            // Draw the coin
                            circle(0.0,0.0, r, 255, 215, 0);
                        glPopAttrib();
                        glPopMatrix();
                        glPopMatrix();
        }
       
    }
    
};
Jerry jerry;


long long score =0;


void renderBitmapString(float x, float y, float z, void *font, string str) {
    //char *c;
    glRasterPos3f(x, y,z);
    for (int i =0;i<str.size();i++)
    {
        glutBitmapCharacter(font, str[i]);
    }
}
void pauseResumeGame() {
    paused = !paused;
}
void set_bg_color(int r, int g, int b){
    float a  = float(r)/255.0f , f = float(g)/255.0f , c = float(b)/255.0f ;
    glClearColor(a,f,c,1);
    
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
template <typename T1, typename T2>
bool collision(T1 obj , T2 obj2){
    bool overlapX = (obj.x+obj.width >=obj2.x) && (obj2.x+obj2.width>=obj.x);
    bool overlapY = (obj.y +obj.height >=obj2.y)&&(obj2.y +obj2.height >=obj.y);
    
    return  overlapX && overlapY;
}
template <typename T1, typename T2>
bool col2(T1 obj , T2 obj2){
        
}
GLfloat position = 0.0f;
GLfloat coin_position1 = 0.0f;
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
void coin_update(int value) {

    angle += 15.0f; // Increment angle for flipping
    if (angle > 360.0f) {
        angle -= 360.0f; // Ensure angle stays within 0 to 180 degrees
    }
    glutPostRedisplay(); // Request a redraw
    glutTimerFunc(16, coin_update, 0); // Update every 16 milliseconds (about 60 frames per second)
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

void coin_update1(int value){
    if(coin_position1 <-5.5)
        coin_position1 = 1.0f;
    coin_position1 -= 0.03;
    glutPostRedisplay();
    glutTimerFunc(100, coin_update1, 0);
}

void tom(){
    /*
    glPushMatrix();
    glBegin(GL_POLYGON);
   
    glVertex2f(-0.6 , -0.45);
    glVertex2f(-0.4,-0.45);
    glVertex2f(-0.4,-0.6);
    glVertex2f(-0.6,-0.6);
    glEnd();
    glPopMatrix();
    */
    glPushMatrix();
    glPushAttrib(GL_CURRENT_BIT);
    glTranslatef(-0.6,-0.45,0);
    glScaled(0.4, 0.5, 0.0);
    tom_test();
    glPopAttrib();
    glPopMatrix();
    
    
}
void jerry_get_down(int x) {
    is_up = false ;
}
int ff =0;
void jerry_jump_update(int x){
    double jerry_jump_speed_x = 0.0003;
    double jerry_jump_speed_y = 0.006;
    
    if(jerry_jump_position>=0.3){
        ff=1;
    }
    if (is_up) {
        if(ff==0){
            jerry.y+=jerry_jump_speed_y;
            jerry.x+=jerry_jump_speed_x;
            jerry_jump_position += jerry_jump_speed_y;
            jerry_move += jerry_jump_speed_x;
        }else{
            jerry_jump_position -= jerry_jump_speed_y;
            jerry_move += jerry_jump_speed_x;
            jerry.y-=jerry_jump_speed_y;
            jerry.x+=jerry_jump_speed_x;
            if(jerry_jump_position<=0){
                is_up=0;
            }
        }

    }else{
        jerry_jump_position = 0.0;
        ff=0;
        jerry.x-=0.0003;
       jerry_move -=0.0003;
       
    }
  
}


void jerry_move_update(int x) {
 
    if (jerry.x> 0.7 ){
        jerry_can_go_forward = 0;
    }else{
        jerry_can_go_forward = 1;
    }
    
    if (jerry_can_go_forward && x==1) {
        jerry_move += 0.1;
        jerry.x +=0.1;
        jerry_last_position += 0.1;
    }
    
    if ( x==2) {
        jerry_move -= 0.1;
        jerry.x -=0.1;
        jerry_last_position -= 0.1;
    }
    
}

void test(int x){
   // std::cout << jerry_move<<" "<<(jerry_last_position > 0.7)<<" "<<(jerry_last_position<tom_last_position)<< std::endl;
    glutTimerFunc(10, test, 0); // Call the test function again after 2 seconds
    
}
//************************* text read & write  **********************



void update_score(int x){
    if(jerry.x>tom_last_position && jerry.life>0){
        renderBitmapString(-0.98f, 0.9f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "Score : "+to_string(score));
        renderBitmapString(-0.98f, 0.8f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "Life : ");
        draw_love(jerry.life);
        if(is_collect_coin){
            score+=1000;
        }else{
            score++;
        }
        
        //write_score(score);
    }else{
        //jerry.life = 0 ;
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

void reset_game(){
    almira_position = 0.0f;
      almira_speed = 1.0f;
      jerry_move = 0.0f;
      jerry_jump = 0.0f;
      jerry_last_position = 0.0f;
      jerry_can_go_back = false;
      jerry_can_go_forward = true;
      is_up = false;
      is_down = false;
      jerry_jump_position = 0.0f;
      tom_last_position = -0.4f;
      game_over = false;
      paused = false;
    is_collect_coin = false ;

      // Reset Jerry's properties
      jerry.life = 3;
      jerry.reset();

      // Reset score
      score = 0;
}
bool call_display =0 ;

void display() {
    call_display = 1;
    if(paused){
        return;
    }
    if(!game_over && jerry.life>0){
        //Jerry jerry ;
        int number_of_bars = 5;
        int number_of_coins = 2;
        obstacle obs_bar[number_of_bars];
        Coin obj_C[number_of_coins];
        
        //obstacle_bar obs_long_bar1;
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
        bar(-1,-0.7,1,-0.7,161,108,91);
        
       // obs_bar[0].draw(1.4,-0.5,1.8,-0.5,position,0,0);
        
       // obs_bar[1].draw(3,-0.5,3.4,-0.5,position,0,0);
        
       // obs_bar[1].draw(3.8,-0.2,4.2,-0.2,position,0,0);
        
       // obs_bar[2].draw(4.4,0,4.8,0,position,0,0);
        
       // obs_bar[3].draw(-0.2,-0.2,0.2,-0.2,position,0,0);
        
        obs_bar[4].cup_draw(0.4,-0.6,0.7,-0.6,position,0,0);
        obs_bar[0].cup_draw(0.6,-0.6,0.7,-0.6,position,0,0);
        
        obj_C[0].draw_coin(0.8, -0.55, 0.03, coin_position1, 0.0);
        obj_C[1].draw_coin(0.6, -0.55, 0.03, coin_position1, 0.0);
       // add_coin_with_animation(0.6,-0.2,0.0,angle);
        
        //obs_bar[4].draw(5.2 ,-0.6 ,6.5,-0.6,long_bar_position,0,0);
       
        
        for(int i =0;i<number_of_bars;i++){
            if(collision(jerry,obs_bar[i])){
                cout<<"ok"<<endl;
                jerry.life--;
                if(jerry.life){
                    renderBitmapString(-0.2f, 0.0f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "Press Space to Resume ");
                    pauseResumeGame();
                }
                
               // cout<<"**************************************************************"<<endl;
                  
            }
            //cout<<endl;
        }
        
        for(int i =0;i<number_of_coins;i++){
            if(collision(jerry, obj_C[i])){
                is_collect_coin=true ;
                obj_C[i].visible=false;
               
            }else{
                is_collect_coin=false ;
                obj_C[i].visible=true;
            }
            
        }
        
        
        tom();
        
        glPushMatrix();
        jerry_jump_update(0);
        glTranslatef(jerry_move,jerry_jump_position,0 );
        jerry.draw();
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
        jerry_jump_update(0);
        is_up = true ;
            is_down =0;
            //jerry_super_jump();
        glutPostRedisplay();
        break;
        
        }
}

void keyboardFunc(unsigned char key, int x, int y) {
    switch (key) {
        case 27:
            //cout << "N" << endl;
            if(call_display && !game_over){
                glutDisplayFunc(Display_Game_Home_page_resume);
            }else{
                glutDisplayFunc(Display_Game_Home_page);
            }
            
           
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
            if(call_display && game_over){
                game_over=0;
                reset_game();
            }
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
    if(!game_over){
        glutTimerFunc(100, update, 0);
        glutTimerFunc(100, update2, 0);
        glutTimerFunc(100,update_for_long_bar,0);
        glutTimerFunc(0, coin_update, 0);
        glutTimerFunc(0, coin_update1, 0);
    }
    
   // glutTimerFunc(10,test,0);
    glutDisplayFunc(display);
   // glutTimerFunc(100,update_score,0);
   // glutIdleFunc(Idle);
    glutMouseFunc(handleMouse);
   
    glutSpecialFunc(specialKeys);
    // Register display callback handler for window re-paint
        glutMainLoop();
     // Enter the event-processing loop
    return 0;
}


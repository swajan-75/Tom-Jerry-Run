/*
 #define GL_SILENCE_DEPRECATION
 #include <GLUT/glut.h>
 #define db double
 double building_x = 0.0;
 bool is_up=false;
 void renderBitmapString(float x, float y, float z, void *font, char *string) {
 char *c;
 glRasterPos3f(x, y,z);
 for (c=string; *c != '\0'; c++)
 {
 glutBitmapCharacter(font, *c);
 }
 }
 void ver(double x , double y){
 x=x/10; y = y/10 ;
 glVertex2f(x, y);
 }
 
 
 void set_bg_color(int r, int g, int b){
 float a  = float(r)/255.0f , f = float(g)/255.0f , c = float(b)/255.0f ;
 glClearColor(a,f,c,1);
 
 }
 
 void building(double x1 ,double x2){
 glBegin(GL_POLYGON);
 glColor3ub(138,21,56);
 glVertex2f(x1,-0.5);
 glVertex2f(x1,-0.7);
 glVertex2f(x2,-0.7);
 glVertex2f(x2,-0.5);
 
 glEnd();
 }
 
 void building(double x1 ,double x2 , double y1, double y2){
 glBegin(GL_POLYGON);
 glColor3ub(138,21,56);
 glVertex2f(x1,y1);
 glVertex2f(x1,y2);
 glVertex2f(x2,y2);
 glVertex2f(x2,y1);
 
 glEnd();
 }
 
 void update(int value) {
 building_x -= 0.01;
 
 if (building_x <-1.5) {
 building_x = 0.5;
 }
 
 glutPostRedisplay();
 glutTimerFunc(16, update, 0);
 }
 void timer(int value) {
 is_up = false;  // Reset the flag after the delay
 }
 void display() {
 
 set_bg_color(153,204,255 );    // Set background color to black and opaque
 glClear(GL_COLOR_BUFFER_BIT);
 // Clear the color buffer (background)
 
 glBegin(GL_POLYGON);
 glColor3ub(255,255,255);
 glVertex2f(-1,-0.7);
 glVertex2f(-1,-1);
 glVertex2f(1,-1);
 glVertex2f(1,-0.7);
 
 glEnd();
 
 double building_x1 = building_x + 0.6;
 double building_x2 = building_x + 0.4;
 
 building(building_x1, building_x2);
 
 double x1 = -0.1 , x2 = 0.1 , y1 = -0.5 , y2 = -0.7 ;
 
 
 // building(building_x1+0.2, building_x2+0.1);
 if(is_up){
 y1= y1+0.5;
 y2=y2+0.5;
 glutTimerFunc(1000, timer, 0);
 }
 building(x1,x2,y1,y2);
 
 
 // building(0.3,0.2);
 //double x1 = 0.6, x2 = 0.4 ;
 
 
 glFlush(); // Render now
 }
 void specialKeys(int key,int x, int y){
 switch (key) {
 case GLUT_KEY_UP:
 is_up = true;
 break;
 // Add cases for other keys if needed
 }
 }
 int main(int argc, char** argv) {
 glutInit(&argc, argv);
 glutInitWindowSize(1200, 1200); // Set the window's initial width & height
 glutInitWindowPosition(250, 50);  // Set the window's initial position according to the monitor
 glutCreateWindow("OpenGL Setup"); // Create a window with the given title
 
 glutDisplayFunc(display);
 glutSpecialFunc(specialKeys);
 
 glutTimerFunc(0, update, 0);
 // Register display callback handler for window re-paint
 glutMainLoop(); // Enter the event-processing loop
 return 0;
 
 }
 
 
 
 
 
 void circle (GLfloat x, GLfloat y , GLfloat radius ){
     int i;
     int triangleAmount = 1000; //# of lines used to draw circle
     
     GLfloat twicePi = 2.0f * PI;

  //   glColor3ub(R,G,B);
     glBegin(GL_TRIANGLE_FAN);
         glVertex2f(x, y); // center of circle
         for(i = 0; i <= triangleAmount;i++) {
             glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                         y + (radius * sin(i * twicePi / triangleAmount)) );
         }
     glEnd();
 }
 */



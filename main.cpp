#include<windows.h>
#include <GL/glut.h>
#include <stdio.h>
#include <GL/gl.h>
#include<math.h>
int r;
void init(void)
{
  glClearColor(0.0,0.0,0.0,0.0); //GLfloat red,green,blue,alpha initial value 0 alpha values used by glclear to clear the color buffers
  glMatrixMode(GL_PROJECTION);  // To specify which matrix is the current matrix & projection applies subsequent matrix to projecton matrix stack
  glLoadIdentity();
  glOrtho(-50.0, 50.0, -50.0, 50.0, -1.0, 1.0);

}

void circle(int r) {
    int x = 0;
    int y = r;
    int Pk = 1 - r;
    glBegin(GL_POINTS);
    while(x<=y){

        if(Pk<0){
            x=x+1;
            y=y;
            Pk=Pk+(2*x)+1;
        }
        else
        {
            x=x+1;
            y=y-1;
            Pk=Pk+(2*x)+1-(2*y);
        }
    glVertex2i(x,y);
    glVertex2i(y,x);
    glVertex2i(-x,y);
    glVertex2i(-y,x);
    glVertex2i(-x,-y);
    glVertex2i(-y,-x);
    glVertex2i(x,-y);
    glVertex2i(y,-x);
    }
    glEnd();
}

void Draw()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1, 1, 0);
    circle(r);

    glutSwapBuffers();
}

int main(int argc, char **argv)
{
    printf("Enter the Radius: ");
    scanf("%d", &r);
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Lab Final");
    init();
    glutDisplayFunc(Draw);
    glutMainLoop();
    return 0;
}

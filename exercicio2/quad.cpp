/*
  Name:        quad.cpp
  Copyright:   Version 0.1
  Author:      Rodrigo Luis de Souza da Silva
  Last Update: 03/09/2014
  Release:     18/09/2004
  Description: Simple opengl program
*/

#include <stdio.h>
#include <GL/glut.h>
#include <math.h>

void display(void);
void init (void);
void keyboard(unsigned char key, int x, int y);
void desenhaEixo();
float converteGrausParaRadianos(float graus);
float pi = 3.1416;
int numeroDePartes = 6;

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize (250, 250);
    glutInitWindowPosition (100, 100);
    glutCreateWindow ("Quad Test");
    init ();
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);

    printf("Pressione ESC para fechar.\n");

    glutMainLoop();

    return 0;
}

void desenhaEixo()
{
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_LINES);
        glVertex3f(-1.0, 0.0, 0.0);
        glVertex3f(390.0, 0.0, 0.0);
    glEnd();
}

void display(void)
{
    // Limpar todos os pixels
    glClear (GL_COLOR_BUFFER_BIT);

    desenhaEixo();

    float AtualCoordenadaX = -10.0;
    glColor3f (0.0, 1.0, 0.0);
    glBegin(GL_LINE_STRIP);
        for(int i = 0; i < numeroDePartes+1; i++) {
            float argumento = converteGrausParaRadianos(0 + i*(360/numeroDePartes));
            glVertex3f(AtualCoordenadaX, sin(argumento), 0.0);
            AtualCoordenadaX += 400/numeroDePartes;
        }
    glEnd();

    glutSwapBuffers ();
}


void init (void)
{
    // selecionar cor de fundo (preto)
    glClearColor (0.0, 0.0, 0.0, 0.0);

    // inicializar sistema de viz.
    glMatrixMode(GL_PROJECTION);              // Seleciona Matriz de Projeção
    glLoadIdentity();
    glOrtho(-10.0, 390, -2, 2, -1.0, 1.0);

    glMatrixMode(GL_MODELVIEW); // Select The Modelview Matrix
    glLoadIdentity();           // Inicializa com matriz identidade
}

void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
        case 'a':
            numeroDePartes = 6;
            break;
        case 'b':
            numeroDePartes = 7;
            break;
        case 'c':
            numeroDePartes = 8;
            break;
        case 'd':
            numeroDePartes = 9;
            break;
        case 'e':
            numeroDePartes = 10;
            break;
        case 'f':
            numeroDePartes = 11;
            break;
        case 'g':
            numeroDePartes = 12;
            break;
        case 'h':
            numeroDePartes = 120;
            break;
    }
    glutPostRedisplay();
}

float converteGrausParaRadianos(float graus)
{
    return graus*pi/180;
}

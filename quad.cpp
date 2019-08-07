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

void display(void);
void init (void);
void keyboard(unsigned char key, int x, int y);

int desenho;

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

void desenhaEixos()
{
    glColor3f (1.0, 1.0, 1.0);
    glBegin(GL_LINES);
        glColor3f (0.0, 1.0, 0.0);
        glVertex3f (0.0, 0.5, 0.0);
        glVertex3f (1.0, 0.5, 0.0);
        glVertex3f (0.5, 1.0, 0.0);
        glVertex3f (0.5, 0.0, 0.0);
    glEnd();
}

void display(void)
{
    // Limpar todos os pixels
    glClear (GL_COLOR_BUFFER_BIT);

    desenhaEixos();
    if(desenho == 1)
    {
        glBegin(GL_TRIANGLES);
            glColor3f (1.0, 0.0, 0.0);
            glVertex3f (0.5, 0.5, 0.0);
            glVertex3f (0.75, 0.5, 0.0);
            glVertex3f (0.625, 0.75, 0.0);
        glEnd();
    }
    else if(desenho == 2)
    {
        glBegin(GL_LINE_LOOP);
            glColor3f (1.0, 0.0, 0.0);
            glVertex3f (0.5, 0.5, 0.0);
            glVertex3f (0.75, 0.5, 0.0);
            glVertex3f (0.625, 0.75, 0.0);
        glEnd();
    }
    else if(desenho == 3)
    {
        glBegin(GL_TRIANGLES);
            glColor3f (1.0, 0.0, 0.0);
            glVertex3f (0.5, 0.5, 0.0);
            glVertex3f (0.25, 0.5, 0.0);
            glVertex3f (0.375, 0.25, 0.0);
        glEnd();

        glBegin(GL_LINE_LOOP);
            glColor3f (1.0, 0.0, 0.0);
            glVertex3f (0.5, 0.5, 0.0);
            glVertex3f (0.75, 0.5, 0.0);
            glVertex3f (0.625, 0.75, 0.0);
        glEnd();
    }

    else if(desenho == 4)
    {
        glBegin(GL_LINE_STRIP);
            glColor3f(0.8, 0.8, 0.8);
            glVertex3f (0.625, 0.75, 0.0);
            glVertex3f (0.75, 0.5, 0.0);
            glVertex3f (0.625, 0.25, 0.0);
            glVertex3f (0.375, 0.25, 0.0);
            glVertex3f (0.25, 0.5, 0.0);
            glVertex3f (0.375, 0.75, 0.0);
        glEnd();
    }



    glutSwapBuffers ();
}


void init (void)
{
    // selecionar cor de fundo (preto)
    glClearColor (0.0, 0.0, 0.0, 0.0);

    // inicializar sistema de viz.
    glMatrixMode(GL_PROJECTION);              // Seleciona Matriz de Projeção
    glLoadIdentity();
    glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);

    glMatrixMode(GL_MODELVIEW); // Select The Modelview Matrix
    glLoadIdentity();           // Inicializa com matriz identidade
}

void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
        case 'a':
            desenho = 1;
            break;
        case 'b':
            desenho = 2;
            break;
        case 'c':
            desenho = 3;
            break;
        case 'd':
            desenho = 4;
            break;
    }
    glutPostRedisplay();
}

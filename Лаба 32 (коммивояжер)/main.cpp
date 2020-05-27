#include <iostream>
#include "Graph.h"
#include <string>
#include <Windows.h>
using namespace std;

int X, Y; //создание переменных для положения курсора
Graph graph; //создание графа
bool* mouse_vertex = new bool[AMOUNT]; //создание массива, который показывает пересекает ли курсор границы какой-либо вершины

//обработка положения мыши
int Circle_Check(int x, int y) //проверка, входит ли курсор в круг
{
    for (int i = 0; i < graph.get_size(); i++)
        if (pow(x - vrtC[i].x, 2) + pow(y - vrtC[i].y, 2) <= pow(R, 2))
            return i;
    return -1;
}
void mouseMove(int x, int y)
{
    y = WinH - y;
    X = x;
    Y = y;
    int i = Circle_Check(x, y);
    if (i != -1)
        mouse_vertex[i] = true;
    else
        for (int j = 0; j < graph.get_size(); j++)
            mouse_vertex[j] = false;
    glutPostRedisplay();
}
//отрисовка
void reshape(int w, int h)
{
    WinW = w;
    WinH = h;
    glViewport(0, 0, (GLsizei)WinW, (GLsizei)WinH);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, (GLdouble)WinW, 0, (GLdouble)WinH);
    glutPostRedisplay();
}
void display()
{
    glShadeModel(GL_SMOOTH);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, WinW, 0, WinH); //ставим начало координат в левый нижний угол
    glViewport(0, 0, WinW, WinH);
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    graph.draw_graph();
    glutSwapBuffers();
}

int main(int argc, char* argv[])
{
    setlocale(LC_ALL, "rus");
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(900, 720);
    glutCreateWindow("Задача коммивояжёра");
    WinW = glutGet(GLUT_WINDOW_WIDTH);
    WinH = glutGet(GLUT_WINDOW_HEIGHT);
    glutDisplayFunc(display);   
    glutPassiveMotionFunc(mouseMove);
    glutMainLoop();
    return 0;
}

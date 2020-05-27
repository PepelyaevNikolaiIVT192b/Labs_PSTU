#ifndef GLFUNC_H
#define GLFUNC_H
#include <string>
#include <GL/glut.h>
#include <cmath>
#include <vector>

int WinW, WinH, R; //объявление переменных для хранения выосты и ширины окна, а так же радиуса окружности
extern int AMOUNT; //оюъявлено в Graph.h

struct vertC { int x, y; }; //структура для хранения координат вершин
vertC* vrtC = new vertC[AMOUNT]; //вектор для хранения координат вершин

//вычисление координат для вершин
void set_coord(int i, int n) //установка координат
{
	int R_;
	int x0 = WinW / 2;
	int y0 = WinH / 2 - 60;
	if (WinW > WinH)
	{
		R = 5 * (WinH / 13) / n;
		R_ = WinH / 2 - R - 10;
	}
	else {
		R = 5 * (WinW / 13) / n;
		R_ = WinW / 2 - R - 10;
	}
	float theta = 2.0f * 3.1415926f * float(i) / float(n);
	float y1 = R_ * cos(theta) + y0;
	float x1 = R_ * sin(theta) + x0;

	vrtC[i].x = x1;
	vrtC[i].y = y1;
}
//отрисовка окружностей для вершин
void drawCircle(int x, int y, int R) //отрисовка круга
{
	glColor3f(0.0, 0.5, 0.5);
	float x1, y1;
	glBegin(GL_POLYGON);
	for (int i = 0; i < 360; i++)
	{
		float theta = 2.0f * 3.1415926f * float(i) / float(360);
		y1 = R * cos(theta) + y;
		x1 = R * sin(theta) + x;;
		glVertex2f(x1, y1);
	}
	glEnd();

	glColor3f(0.0f, 0.0f, 0.0f);
	float x2, y2;
	glBegin(GL_LINE_LOOP);
	for (int i = 0; i < 360; i++)
	{
		float theta = 2.0f * 3.1415926f * float(i) / float(360);
		y2 = R * cos(theta) + y;
		x2 = R * sin(theta) + x;
		glVertex2f(x2, y2);
	}
	glEnd();
}
void drawDedicCircle(int x, int y, int R)//отрисовка подсвеченного круга
{
	glColor3f(0.0, 1.0, 1.0);
	float x1, y1;
	glBegin(GL_POLYGON);
	for (int i = 0; i < 360; i++)
	{
		float theta = 2.0f * 3.1415926f * float(i) / float(360);
		y1 = R * cos(theta) + y;
		x1 = R * sin(theta) + x;;
		glVertex2f(x1, y1);
	}
	glEnd();

	glColor3f(0.0, 0.0, 0.0);
	float x2, y2;
	glBegin(GL_LINE_LOOP);
	for (int i = 0; i < 360; i++)
	{
		float theta = 2.0f * 3.1415926f * float(i) / float(360);
		y2 = R * cos(theta) + y;
		x2 = R * sin(theta) + x;
		glVertex2f(x2, y2);
	}
	glEnd();
}
//отрисовка текста
void drawText(std::string nom, int x1, int y1)//отрисовка текста
{
	GLvoid* font = GLUT_BITMAP_HELVETICA_18;
	glRasterPos2i(x1 - nom.size() * 5, y1 - 5);
	for (int j = 0; j < nom.length(); j++)
		glutBitmapCharacter(font, nom[j]);
}
void draw_rezult(int leng, std::string rezult) //вывод результата и пути
{
	GLvoid* font = GLUT_BITMAP_HELVETICA_18;
	std::string a = "Minimum length: ";
	glRasterPos2i(25, WinH - 25);
	for (int j = 0; j < a.length(); j++)
		glutBitmapCharacter(font, a[j]);
	//результат
	std::string r = std::to_string(leng);
	glRasterPos2i(170, WinH - 25);
	for (int j = 0; j < r.length(); j++)
		glutBitmapCharacter(font, r[j]);

	a = "Recommended way:";
	glRasterPos2i(25, WinH - 50);
	for (int j = 0; j < a.length(); j++)
		glutBitmapCharacter(font, a[j]);
	//путь
	glRasterPos2i(200, WinH - 50);
	for (int j = 0; j < rezult.length(); j++)
		glutBitmapCharacter(font, rezult[j]);
}
//отрисовка ребра
void drawLine(std::string a, int x0s, int y0s, int x1s, int y1s) //отрисовка ребер взвешенного графа
{
	int x0 = x0s, y0 = y0s, x1 = x1s, y1 = y1s;
	//отрисовка линии
	glColor3i(1, 0.0, 0.0);
	glBegin(GL_LINES);
	glVertex2i(x0, y0);
	glVertex2i(x1, y1);
	glEnd();
	//вывод веса графа
	drawText(a, (x0 + x1) / 2 + 10, (y0 + y1) / 2 + 10);

	//нахождение положения для стрелки
	float vx = x0 - x1;
	float vy = y0 - y1;
	float s = 1.0f / sqrt(vx * vx + vy * vy);
	vx *= s;
	vy *= s;
	x1 = x1 + R * vx;
	y1 = y1 + R * vy;
	//отрисовка стрелки
	glColor3i(1, 0.0, 0.0);
	glBegin(GL_TRIANGLES);
	glVertex2f(x1, y1);
	glVertex2f(x1 + 10 * (vx + vy), y1 + 10 * (vy - vx));
	glVertex2f(x1 + 10 * (vx - vy), y1 + 10 * (vy + vx));
	glEnd();

	//перерасчет положения для стрелки
	x0 = x0s, y0 = y0s, x1 = x1s, y1 = y1s;
	vx = x1 - x0;
	vy = y1 - y0;
	s = 1.0f / sqrt(vx * vx + vy * vy);
	vx *= s;
	vy *= s;
	x0 = x0 + R * vx;
	y0 = y0 + R * vy;
	//отрисовка стрелки
	glColor3i(1, 0.0, 0.0);
	glBegin(GL_TRIANGLES);
	glVertex2f(x0, y0);
	glVertex2f(x0 + 10 * (vx + vy), y0 + 10 * (vy - vx));
	glVertex2f(x0 + 10 * (vx - vy), y0 + 10 * (vy + vx));
	glEnd();
}
#endif
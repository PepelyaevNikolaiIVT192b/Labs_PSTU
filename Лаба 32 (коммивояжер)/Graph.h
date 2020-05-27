#define MAX_VALUE_OF_NODES 20
#ifndef GRAPH_T
#define GRAPH_T
#include "glfunc.h"
#include <vector>
#include <iomanip>
#include <iostream>
#include <ctime>

int AMOUNT; //количество вводимых вершин
int leng = -1; //длина кратчайшего пути
std::string rezult; //строка, в которую записывается кратчайший путь
extern bool *mouse_vertex; //находится в main.cpp 

class Graph; //прототип класса для прототипа функции чтобы использовать её в прототипе функции
void draw_vert(int n, Graph& graph); //прототип функции чтобы использовать её в классе
void drawDedicCircle(int x, int y, int R); //прототип функции чтобы использовать её в классе, объявлена в glfunc.h
struct Edge { int out; int inp; }; //структура, хранящая точки топравления и точка прибытия

class Graph
{
protected:
    std::vector<Edge> path; //вектор пути (хранятся точки топравления и точка прибытия)
    std::vector<std::string> verts; //вектор названий вершин
    int adjM[MAX_VALUE_OF_NODES][MAX_VALUE_OF_NODES]; //матрица смежности
public:
    Graph() //конструктор
    {
        this->insert();
    };
    std::string get_verts(int i) { return verts[i]; } //функция для возврата необходимого названия вершины
    int get_size() { return this->verts.size(); } //функция для возврата текущего количества вершин
    //ввод и вывод
    void insert()//ввод матрицы смежности
    {
        setlocale(LC_ALL, "rus"); srand(time(NULL));
        int temp, h = 1;
        //ввод вершин
        std::cout << "Введите количество вершин: "; std::cin >> AMOUNT;
        std::cout << "Введите вершины: ";
        for (int i = 0; i < AMOUNT; i++)
        {
            std::string temp;
            std::cin >> temp;
            verts.push_back(temp);
        }
        //ввод связей
        std::cout << "Для ручного ввода связей введите 1, иначе введите любой другой символ\nВаш выбор: "; std::cin >> h;
        if (h == 1)
        //для ручного ввода
        for (int i = 0; i < AMOUNT; i++) {
                for (int j = i; j < AMOUNT; j++)
                    if (i == j) adjM[i][j] = -1;
                    else
                    {
                        std::cout << "Введите вес ребра " << verts[i] << " => " << verts[j] << ": ";
                        std::cin >> adjM[i][j];
                        adjM[j][i] = adjM[i][j];
                    }
            }
        //для случайно генерируемых связей
        else for (int i = 0; i < AMOUNT; i++) {
            for (int j = i; j < AMOUNT; j++)
                if (i == j) adjM[i][j] = -1;
                else
                {
                    temp = rand() % 100 + 1;
                    adjM[i][j] = temp;
                    adjM[j][i] = temp;
                    std::cout << "Вес ребра " << verts[i] << " => " << verts[j] << " равен " << adjM[i][j] << std::endl;
                }
        }
    };
    void print(int** matrix) //вывод матрицы
    {
        for (int i = 0; i < AMOUNT; i++)
        {
            std::cout << std::setw(10) << verts[i]; //вывод названия вершины
            for (int j = 0; j < AMOUNT; j++) //вывод связей
            {
                if (matrix[i][j] == -1) std::cout << std::setw(4) << "[ ]";
                else std::cout << std::setw(4) << matrix[i][j];
            }
            std::cout << std::endl;
        }
    };
    //обработка матрицы
    void rows(int** map) //редукция строк
    {
        for (int j = 0; j < AMOUNT; j++) //проход по столбцам
        {
            int min = INT32_MAX; //минимум для каждого столбца вычисляется заново
            for (int i = 0; i < AMOUNT; i++) //проход по ячейкам столбца
                if ((map[j][i] < min) && (map[j][i] >= 0)) //если ячейка меньше минимума и не является путём в тот же город
                    min = map[j][i]; //обновляем минимум
            for (int i = 0; i < AMOUNT; i++) //редукция столбца
                if (map[j][i] != -1) //если не путь в тот же город
                    map[j][i] -= min; //вычитаем минимум
        }
    };
    void coll(int** map) //редукция столбцов
    {
        for (int j = 0; j < AMOUNT; j++) //проход по столбцам
        {
            int min = INT32_MAX; //минимум для каждого столбца вычисляется заново
            for (int i = 0; i < AMOUNT; i++) //проход по ячейкам столбца
                if ((map[i][j] < min) && (map[i][j] >= 0)) //если ячейка меньше минимума и не является путём в тот же город
                    min = map[i][j]; //обновляем минимум
            for (int i = 0; i < AMOUNT; i++) //редукция столбца
                if (map[i][j] != -1) //если не путь в тот же город
                    map[i][j] -= min; //вычитаем минимум
        }
    };
    int zero_rows(int** map, int row, int nCheck) //оценка нулей в строках
    {
        int min = INT32_MAX; //создаем переменную минимального элемента
        for (int j = 0; j < AMOUNT; j++) // Проходим каждый столбец в заданной строке
            if (j != nCheck) // Координаты столбца не совпали с заданными
                if ((min > map[row][j]) && (map[row][j] >= 0)) // Ищем минимум
                    min = map[row][j]; // Обновляем значение переменной
        return min; // Возвращаем минимальное значение
    };
    int zero_coll(int** map, int nCheck, int AMOUNT) //Оценка нулей в столбцах
    {
        int min = INT32_MAX; //минимум
        for (int i = 0; i < AMOUNT; i++) //проходим все строки в столбце
            if (i != nCheck) //строка не совпала с заданной
                if ((map[i][AMOUNT] < min) && (map[i][AMOUNT] >= 0)) //Поиск минимума
                    min = map[i][AMOUNT]; //обновляем значение переменной
        return min; //возвращаем минимум
    };
    Edge clear(int** map) //Удаление строки и столбца с наибольшим нулём
    {
        Edge temp;
        int max = -1, k = 0, l = 0; //Максимальный оцененный ноль, координаты его строки и столбца
        //поиск строки и столбца, которые нужно убрать из дальнейшего рассмотрения
        for (int i = 0; i < AMOUNT; i++)
            for (int j = 0; j < AMOUNT; j++)
                if (map[i][j] == 0)
                {
                    int tSum = this->zero_rows(map, i, j) + this->zero_coll(map, j, i);
                    if (tSum >= max)
                    {
                        max = tSum;
                        k = i;
                        l = j;
                    }
                }
        //стирание ненужных связей
        for (int i = 0; i < AMOUNT; i++)
            for (int j = 0; j < AMOUNT; j++)
            {
                if (i == k) map[i][j] = -1;
                if (j == l) map[i][j] = -1;
            }

        temp.out = k;
        temp.inp = l;
        return temp;
    };
    //обработка и отрисовка
    void alg() //нахождение кратчайшего пути
    {
        setlocale(LC_ALL, "rus");
        int** map = new int* [AMOUNT]; //создание вспомогательного массива
        for (int i = 0; i < AMOUNT; i++) map[i] = new int[AMOUNT];

        for (int i = 0; i < AMOUNT; i++) //заполнение вспомогательного массива
            for (int j = 0; j < AMOUNT; j++)
                map[i][j] = adjM[i][j];

        std::cout << "Матрица смежностей:\n";
        print(map);
        int i = 0;
        while (i != AMOUNT - 2) //Основной цикл
        {
            rows(map);
            std::cout << i + 1 << ". Редукция строк\n";
            print(map);

            coll(map);
            std::cout << i + 1 << ". Редукция столбцов\n";
            print(map);

            path.push_back(clear(map));

            std::cout << i + 1 << ". Новая матрица\n";
            print(map);
            i++;

        }
        //формирование пути
        for (int i = 1; i < path.size(); i++)
            for (int j = i; j < path.size(); j++)
                if (path[i].out == path[j].inp) std::swap(path[i], path[j]);
        //вывод пути
        rezult += verts[path[0].out] + " => " + verts[path[0].inp] + " => ";
        for (int i = 1; i < path.size(); i++)
        {
            if (path[i - 1].inp != path[i].out) rezult += verts[path[i].out] + " => " + verts[path[i].inp] + " => ";
            else rezult += verts[path[i].inp] + " => ";
        }
        rezult += verts[path[0].out];
        std::cout << std::endl << "Кратчайший путь: "<< rezult;

        int a = adjM[path[i - 1].inp][path[0].out]; //расстояние от последней вершины до первой
        a += adjM[path[0].out][path[0].inp]; //расстояние первого ребра

        for (int i = 1; i < path.size(); i++) //проходим по массиву структур
            a += adjM[path[i].out][path[i].inp]; //прибавим расстояние i-того ребра 

        for (int i = 0; i < path.size() - 1; i++) //проходим по массиву структур
            if (path[i].inp != path[i + 1].out) //если поля равны, то расстояние от вершины А до А считаем равным 0
                a += adjM[path[i].inp][path[i + 1].out]; //считаем расстояние между ребрами 

        std::cout << "\nРасстояние для прохождения всех вершин и возвращения в первую: " << a << '\n';
        leng = a;

        for (int i = 0; i < AMOUNT; i++) delete[] map[i];
        delete[] map;
    }
    void draw_graph()//отрисовка графа
    {
        if (leng == -1) alg();
        draw_rezult(leng, rezult);
        int n = verts.size();
        for (int i = 0; i < n; i++)//устанавливаются координаты для каждой вершины
            set_coord(i, n);
        for (int i = 0; i < n; i++) 
        {
            for (int j = i; j < n; j++)
            {
                int a = adjM[i][j];
                if (a > 0) //не рисуем ребро из А в А (оно равно -1)
                {
                    drawLine(std::to_string(a), vrtC[i].x, vrtC[i].y, vrtC[j].x, vrtC[j].y);
                }
            }
        }
        draw_vert(n, *this);
    }
};
void draw_vert(int n, Graph& graph) 
{
    for (int i = 0; i < n; i++) { //для каждой выршины рисуется круг
        if (mouse_vertex[i]) drawDedicCircle(vrtC[i].x, vrtC[i].y, R); //если мышь внутри окружности - рисуется выделенный круг
        else drawCircle(vrtC[i].x, vrtC[i].y, R);

        drawText(graph.get_verts(i), vrtC[i].x, vrtC[i].y);
    }
}
#endif
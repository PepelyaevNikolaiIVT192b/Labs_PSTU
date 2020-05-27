#define MAX_VALUE_OF_NODES 20
#ifndef GRAPH_T
#define GRAPH_T
#include "glfunc.h"
#include <vector>
#include <iomanip>
#include <iostream>
#include <ctime>

int AMOUNT; //���������� �������� ������
int leng = -1; //����� ����������� ����
std::string rezult; //������, � ������� ������������ ���������� ����
extern bool *mouse_vertex; //��������� � main.cpp 

class Graph; //�������� ������ ��� ��������� ������� ����� ������������ � � ��������� �������
void draw_vert(int n, Graph& graph); //�������� ������� ����� ������������ � � ������
void drawDedicCircle(int x, int y, int R); //�������� ������� ����� ������������ � � ������, ��������� � glfunc.h
struct Edge { int out; int inp; }; //���������, �������� ����� ����������� � ����� ��������

class Graph
{
protected:
    std::vector<Edge> path; //������ ���� (�������� ����� ����������� � ����� ��������)
    std::vector<std::string> verts; //������ �������� ������
    int adjM[MAX_VALUE_OF_NODES][MAX_VALUE_OF_NODES]; //������� ���������
public:
    Graph() //�����������
    {
        this->insert();
    };
    std::string get_verts(int i) { return verts[i]; } //������� ��� �������� ������������ �������� �������
    int get_size() { return this->verts.size(); } //������� ��� �������� �������� ���������� ������
    //���� � �����
    void insert()//���� ������� ���������
    {
        setlocale(LC_ALL, "rus"); srand(time(NULL));
        int temp, h = 1;
        //���� ������
        std::cout << "������� ���������� ������: "; std::cin >> AMOUNT;
        std::cout << "������� �������: ";
        for (int i = 0; i < AMOUNT; i++)
        {
            std::string temp;
            std::cin >> temp;
            verts.push_back(temp);
        }
        //���� ������
        std::cout << "��� ������� ����� ������ ������� 1, ����� ������� ����� ������ ������\n��� �����: "; std::cin >> h;
        if (h == 1)
        //��� ������� �����
        for (int i = 0; i < AMOUNT; i++) {
                for (int j = i; j < AMOUNT; j++)
                    if (i == j) adjM[i][j] = -1;
                    else
                    {
                        std::cout << "������� ��� ����� " << verts[i] << " => " << verts[j] << ": ";
                        std::cin >> adjM[i][j];
                        adjM[j][i] = adjM[i][j];
                    }
            }
        //��� �������� ������������ ������
        else for (int i = 0; i < AMOUNT; i++) {
            for (int j = i; j < AMOUNT; j++)
                if (i == j) adjM[i][j] = -1;
                else
                {
                    temp = rand() % 100 + 1;
                    adjM[i][j] = temp;
                    adjM[j][i] = temp;
                    std::cout << "��� ����� " << verts[i] << " => " << verts[j] << " ����� " << adjM[i][j] << std::endl;
                }
        }
    };
    void print(int** matrix) //����� �������
    {
        for (int i = 0; i < AMOUNT; i++)
        {
            std::cout << std::setw(10) << verts[i]; //����� �������� �������
            for (int j = 0; j < AMOUNT; j++) //����� ������
            {
                if (matrix[i][j] == -1) std::cout << std::setw(4) << "[ ]";
                else std::cout << std::setw(4) << matrix[i][j];
            }
            std::cout << std::endl;
        }
    };
    //��������� �������
    void rows(int** map) //�������� �����
    {
        for (int j = 0; j < AMOUNT; j++) //������ �� ��������
        {
            int min = INT32_MAX; //������� ��� ������� ������� ����������� ������
            for (int i = 0; i < AMOUNT; i++) //������ �� ������� �������
                if ((map[j][i] < min) && (map[j][i] >= 0)) //���� ������ ������ �������� � �� �������� ���� � ��� �� �����
                    min = map[j][i]; //��������� �������
            for (int i = 0; i < AMOUNT; i++) //�������� �������
                if (map[j][i] != -1) //���� �� ���� � ��� �� �����
                    map[j][i] -= min; //�������� �������
        }
    };
    void coll(int** map) //�������� ��������
    {
        for (int j = 0; j < AMOUNT; j++) //������ �� ��������
        {
            int min = INT32_MAX; //������� ��� ������� ������� ����������� ������
            for (int i = 0; i < AMOUNT; i++) //������ �� ������� �������
                if ((map[i][j] < min) && (map[i][j] >= 0)) //���� ������ ������ �������� � �� �������� ���� � ��� �� �����
                    min = map[i][j]; //��������� �������
            for (int i = 0; i < AMOUNT; i++) //�������� �������
                if (map[i][j] != -1) //���� �� ���� � ��� �� �����
                    map[i][j] -= min; //�������� �������
        }
    };
    int zero_rows(int** map, int row, int nCheck) //������ ����� � �������
    {
        int min = INT32_MAX; //������� ���������� ������������ ��������
        for (int j = 0; j < AMOUNT; j++) // �������� ������ ������� � �������� ������
            if (j != nCheck) // ���������� ������� �� ������� � ���������
                if ((min > map[row][j]) && (map[row][j] >= 0)) // ���� �������
                    min = map[row][j]; // ��������� �������� ����������
        return min; // ���������� ����������� ��������
    };
    int zero_coll(int** map, int nCheck, int AMOUNT) //������ ����� � ��������
    {
        int min = INT32_MAX; //�������
        for (int i = 0; i < AMOUNT; i++) //�������� ��� ������ � �������
            if (i != nCheck) //������ �� ������� � ��������
                if ((map[i][AMOUNT] < min) && (map[i][AMOUNT] >= 0)) //����� ��������
                    min = map[i][AMOUNT]; //��������� �������� ����������
        return min; //���������� �������
    };
    Edge clear(int** map) //�������� ������ � ������� � ���������� ����
    {
        Edge temp;
        int max = -1, k = 0, l = 0; //������������ ��������� ����, ���������� ��� ������ � �������
        //����� ������ � �������, ������� ����� ������ �� ����������� ������������
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
        //�������� �������� ������
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
    //��������� � ���������
    void alg() //���������� ����������� ����
    {
        setlocale(LC_ALL, "rus");
        int** map = new int* [AMOUNT]; //�������� ���������������� �������
        for (int i = 0; i < AMOUNT; i++) map[i] = new int[AMOUNT];

        for (int i = 0; i < AMOUNT; i++) //���������� ���������������� �������
            for (int j = 0; j < AMOUNT; j++)
                map[i][j] = adjM[i][j];

        std::cout << "������� ����������:\n";
        print(map);
        int i = 0;
        while (i != AMOUNT - 2) //�������� ����
        {
            rows(map);
            std::cout << i + 1 << ". �������� �����\n";
            print(map);

            coll(map);
            std::cout << i + 1 << ". �������� ��������\n";
            print(map);

            path.push_back(clear(map));

            std::cout << i + 1 << ". ����� �������\n";
            print(map);
            i++;

        }
        //������������ ����
        for (int i = 1; i < path.size(); i++)
            for (int j = i; j < path.size(); j++)
                if (path[i].out == path[j].inp) std::swap(path[i], path[j]);
        //����� ����
        rezult += verts[path[0].out] + " => " + verts[path[0].inp] + " => ";
        for (int i = 1; i < path.size(); i++)
        {
            if (path[i - 1].inp != path[i].out) rezult += verts[path[i].out] + " => " + verts[path[i].inp] + " => ";
            else rezult += verts[path[i].inp] + " => ";
        }
        rezult += verts[path[0].out];
        std::cout << std::endl << "���������� ����: "<< rezult;

        int a = adjM[path[i - 1].inp][path[0].out]; //���������� �� ��������� ������� �� ������
        a += adjM[path[0].out][path[0].inp]; //���������� ������� �����

        for (int i = 1; i < path.size(); i++) //�������� �� ������� ��������
            a += adjM[path[i].out][path[i].inp]; //�������� ���������� i-���� ����� 

        for (int i = 0; i < path.size() - 1; i++) //�������� �� ������� ��������
            if (path[i].inp != path[i + 1].out) //���� ���� �����, �� ���������� �� ������� � �� � ������� ������ 0
                a += adjM[path[i].inp][path[i + 1].out]; //������� ���������� ����� ������� 

        std::cout << "\n���������� ��� ����������� ���� ������ � ����������� � ������: " << a << '\n';
        leng = a;

        for (int i = 0; i < AMOUNT; i++) delete[] map[i];
        delete[] map;
    }
    void draw_graph()//��������� �����
    {
        if (leng == -1) alg();
        draw_rezult(leng, rezult);
        int n = verts.size();
        for (int i = 0; i < n; i++)//��������������� ���������� ��� ������ �������
            set_coord(i, n);
        for (int i = 0; i < n; i++) 
        {
            for (int j = i; j < n; j++)
            {
                int a = adjM[i][j];
                if (a > 0) //�� ������ ����� �� � � � (��� ����� -1)
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
    for (int i = 0; i < n; i++) { //��� ������ ������� �������� ����
        if (mouse_vertex[i]) drawDedicCircle(vrtC[i].x, vrtC[i].y, R); //���� ���� ������ ���������� - �������� ���������� ����
        else drawCircle(vrtC[i].x, vrtC[i].y, R);

        drawText(graph.get_verts(i), vrtC[i].x, vrtC[i].y);
    }
}
#endif
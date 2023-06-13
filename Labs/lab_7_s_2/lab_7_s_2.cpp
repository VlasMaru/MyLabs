/*Используя наследование и полиморфизм, напишите программу, которая работает с геометрическими фигурами:
1.	Треугольник
2.	Прямоугольник
3.	Круг

Программа должна хранить координаты и размеры фигуры, цвет, уметь вычислять площадь фигуры.

Продемонстрируйте, как ваша программа будет выводить на экран площади всех фигур
*/
//
#include <iostream>
#include <string>
#define _USE_MATH_DEFINES
#include <math.h>
#include <string>


enum class Colors
{
    WHITE,
    RED,
    BLU,
    BLACK,
    PINK,
    CIAN
};

enum class FigureType
{
    TRIANGLE, 
    RECTANGLE,
    CIRCLE

};

class Figure
{
private:
    Colors m_color = Colors::WHITE;
    int m_x = 0;
    int m_y = 0;
protected:
    long double  m_square = 1.1;
    FigureType m_type;
public:
    
    Figure(int start_x, int start_y): m_x(start_x), m_y(start_y)
    {
        std::cout << "Parent Const" << std::endl;
    }
    virtual ~Figure()
    {
        std::cout << "Parent Dest" << std::endl;
    }
    void SetColor(Colors col) { m_color = col; }
    void SetCurX(int x) { m_x = x; }
    void SetCurY(int y) { m_y = y; }
    int GetCurX() { return m_x; }
    int GetCurY() { return m_y; }
    long double GetSquare() { return m_square;}
    std::string GetColor()
    {
        switch (m_color)
        {
        case Colors::WHITE:
            return "White";
        case Colors::BLACK:
            return "Black";

        case Colors::BLU:
            return "Blu";
        case Colors::CIAN:
            return "Cian";
        case Colors::PINK:
            return "Pink";
        case Colors::RED:
            return "Red";
        }  
    }
    void Move(int ox, int oy)
    {
        m_x += ox;
        m_y += oy;
    }
    void ShowPos()
    {
        std::cout << "Obj position: x = " << m_x << " ; y = " << m_y << " ." << std::endl;
    }


    
};

class Triangle : public Figure
{
private:
    double  m_side_a;
    double  m_side_b;
    double  m_side_c;

public:
    Triangle(int a, int b, int c , int start_x, int start_y): Figure(start_x, start_y), m_side_a(a),m_side_b(b),m_side_c(c)
    {
        std::cout << "Triangle Const" << std::endl;
        m_type = FigureType::TRIANGLE;
        this->CounSq();
    }
    virtual ~Triangle()
    {
        std::cout << "Triangle Dest" << std::endl;
    }
    void CounSq()
    {
        float semi_peri = ((m_side_a + m_side_b + m_side_c) / 2.0) ;
        long double temp = semi_peri * (semi_peri - float(m_side_a))*(semi_peri - float(m_side_b))*(semi_peri - float(m_side_c));
        m_square =  sqrt(temp);
    }
};

class Rectangle : public Figure
{
private:
    double  m_side_a;
    double  m_side_b;

public:
    Rectangle(double a, double b, int start_x, int start_y) : Figure(start_x, start_y), m_side_a(a), m_side_b(b)
    {
        std::cout << "Rectangle Const" << std::endl;
        m_type = FigureType::RECTANGLE;
        this->CounSq();
    }
    virtual ~Rectangle()
    {
        std::cout << "Rectangle Dest" << std::endl;
    }
    void CounSq(){m_square = m_side_a*m_side_b;}
};


class Circle : public Figure
{
private:
    double  m_rad;

public:
    Circle(double rad, int start_x, int start_y) : Figure(start_x, start_y), m_rad(rad)
    {
        std::cout << "Circle Const" << std::endl;
        m_type = FigureType::CIRCLE;
        this->CounSq();
    }
    virtual ~Circle()
    {
        std::cout << "Circle Dest" << std::endl;
    }
    void CounSq() { m_square = pow(m_rad,2) * M_PI; }
};



int main()

{
    Triangle tr(6, 4, 7, 0, 0);
    tr.SetColor(Colors::RED);
    std::cout <<tr.GetSquare() <<std::endl;
    std::cout << tr.GetColor() << std::endl;

    Circle cr(13.2, 0, 0);
    std::cout << cr.GetSquare() << std::endl;

    Rectangle rc(1.1, 1.1, 0, 0);
    std::cout << rc.GetSquare() << std::endl;


    tr.Move(11, 2);
    tr.ShowPos();
    tr.Move(-3, 11);
    tr.ShowPos();

}


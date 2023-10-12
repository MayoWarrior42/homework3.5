#include <iostream>
#include <cmath>

class Figure {
public:
    virtual void printInfo() const = 0;
};

class Triangle : public Figure {
protected:
    double a, b, c;
    double A, B, C;
public:
    Triangle(double a, double b, double c, double A, double B, double C) : a(a), b(b), c(c), A(A), B(B), C(C) {}

    void printInfo() const override {
        std::cout << "Треугольник:\n";
        std::cout << "Стороны: a=" << a << ", b=" << b << ", c=" << c << "\n";
        std::cout << "Углы: A=" << A << ", B=" << B << ", C=" << C << "\n";
    }
};

class RightTriangle : public Triangle {
public:
    RightTriangle(double a, double b, double c, double A, double B, double C) : Triangle(a, b, c, A, B, C) {}
    void printInfo() const override {
        std::cout << "Прямоугольный треугольник:\n";
        std::cout << "Стороны: a=" << a << ", b=" << b << ", c=" << c << "\n";
        std::cout << "Углы: A=" << A << ", B=" << B << ", C=" << C << "\n";
    }
};

class IsoscelesTriangle : public Triangle {
public:
    IsoscelesTriangle(double a, double c, double A, double C) : Triangle(a, a, c, A, A, C) {}
    void printInfo() const override {
        std::cout << "Равнобедренный треугольник:\n";
        std::cout << "Стороны: a=" << a << ", b=" << b << ", c=" << c << "\n";
        std::cout << "Углы: A=" << A << ", B=" << B << ", C=" << C << "\n";
    }
};

class EquilateralTriangle : public Triangle {
public:
    EquilateralTriangle(double side) : Triangle(side, side, side, 60, 60, 60) {}
    void printInfo() const override {
        std::cout << "Равносторонний треугольник:\n";
        std::cout << "Стороны: a=" << a << ", b=" << b << ", c=" << c << "\n";
        std::cout << "Углы: A=" << A << ", B=" << B << ", C=" << C << "\n";
    }
};

class Quadrilateral : public Figure {
protected:
    double a, b, c, d;
    double A, B, C, D;
public:
    Quadrilateral(double a, double b, double c, double d, double A, double B, double C, double D) : a(a), b(b), c(c), d(d), A(A), B(B), C(C), D(D) {}
    void printInfo() const override {
        std::cout << "Четырехугольник:\n";
        std::cout << "Стороны: a=" << a << ", b=" << b << ", c=" << c << ", d=" << d << "\n";
        std::cout << "Углы: A=" << A << ", B=" << B << ", C=" << C << ", D=" << D << "\n";
    }
};

class Rectangle : public Quadrilateral {
public:
    Rectangle(double a, double b) : Quadrilateral(a, b, a, b, 90, 90, 90, 90) {}
    void printInfo() const override {
        std::cout << "Прямоугольник:\n";
        std::cout << "Стороны: a=" << a << ", b=" << b << ", c=" << c << ", d=" << d << "\n";
        std::cout << "Углы: A=" << A << ", B=" << B << ", C=" << C << ", D=" << D << "\n";
    }
};

class Square : public Rectangle {
public:
    Square(double side) : Rectangle(side, side) {}
    void printInfo() const override {
        std::cout << "Квадрат:\n";
        std::cout << "Стороны: a=" << a << ", b=" << b << ", c=" << c << ", d=" << d << "\n";
        std::cout << "Углы: A=" << A << ", B=" << B << ", C=" << C << ", D=" << D << "\n";
    }
};

class Parallelogram : public Quadrilateral {
public:
    Parallelogram(double a, double b, double A) : Quadrilateral(a, b, a, b, A, 180 - A, A, 180 - A) {}
    void printInfo() const override {
        std::cout << "Параллелограмм:\n";
        std::cout << "Стороны: a=" << a << ", b=" << b << ", c=" << c << ", d=" << d << "\n";
        std::cout << "Углы: A=" << A << ", B=" << B << ", C=" << C << ", D=" << D << "\n";
    }
};

class Rhombus : public Parallelogram {
public:
    Rhombus(double side, double A) : Parallelogram(side, side, A) {}
    void printInfo() const override {
        std::cout << "Ромб:\n";
        std::cout << "Стороны: a=" << a << ", b=" << b << ", c=" << c << ", d=" << d << "\n";
        std::cout << "Углы: A=" << A << ", B=" << B << ", C=" << C << ", D=" << D << "\n";
    }
};

void printInfo(const Figure* figure) {
    figure->printInfo();
    std::cout << "\n";
}

int main() {
    system("chcp 1251");
    Triangle triangle(10, 20, 30, 50, 60, 70);
    RightTriangle rightTriangle(10, 20, 30, 50, 60, 90);
    IsoscelesTriangle isoscelesTriangle(10, 20, 50, 60);
    Quadrilateral quadrilateral(10, 20, 30, 40, 50, 60, 70, 80);
    EquilateralTriangle equilateralTriangle(30);
    Rectangle rectangle(5, 7);
    Square square(5);
    Parallelogram parallelogram(3, 5, 60);
    Rhombus rhombus(4, 60);

    printInfo(&triangle);
    printInfo(&rightTriangle);
    printInfo(&isoscelesTriangle);
    printInfo(&equilateralTriangle);
    printInfo(&quadrilateral);
    printInfo(&rectangle);
    printInfo(&square);
    printInfo(&parallelogram);
    printInfo(&rhombus);

    return 0;
}
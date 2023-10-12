

#include <iostream>



class Figure {
protected:
    int sides_count;

public:
    Figure(int sides) : sides_count(sides) {}

    int get_sides_count() {
        return sides_count;
    }

    virtual std::string get_name() const {
        return "Фигура: ";
    }
};

class Triangle : public Figure {
public:
    Triangle() : Figure(3) {}

    std::string get_name() const override {
        return "Треугольник: ";
    }
};

class Quadrangle : public Figure {
public:
    Quadrangle() : Figure(4) {}

    std::string get_name() const override {
        return "Четырёхугольник: ";
    }
};

int main() {
    system("chcp 1251");
    int sides = 0;
    Figure figure(sides);
    Triangle triangle;
    Quadrangle quadrangle;


    std::cout << figure.get_name() << figure.get_sides_count() << std::endl;
    std::cout << triangle.get_name() << triangle.get_sides_count() << std::endl;
    std::cout << quadrangle.get_name() << quadrangle.get_sides_count() << std::endl;

    return 0;
}



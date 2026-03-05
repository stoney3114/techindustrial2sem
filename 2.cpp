#include <iostream>
#include <cmath>
#include <vector>

class Shape {
public:
    virtual double area() const = 0;
    virtual double perimeter() const = 0;
    virtual ~Shape() {}
};

class Circle : public Shape {
private:
    double r;
public:
    Circle(double r) : r(r) {}
    Circle(const Circle& other) : r(other.r) {}
    double area() const override { return M_PI * r * r; }
    double perimeter() const override { return 2 * M_PI * r; }
    double getR() const { return r; }
};

class Rectangle : public Shape {
private:
    double w, h;
public:
    Rectangle(double w, double h) : w(w), h(h) {}
    Rectangle(const Rectangle& other) : w(other.w), h(other.h) {}
    double area() const override { return w * h; }
    double perimeter() const override { return 2 * (w + h); }
    double getW() const { return w; }
    double getH() const { return h; }
};

class Triangle : public Shape {
private:
    double a, b, c;
public:
    Triangle(double a, double b, double c) : a(a), b(b), c(c) {}
    Triangle(const Triangle& other) : a(other.a), b(other.b), c(other.c) {}
    double area() const override { 
        double s = (a + b + c) / 2; 
        return std::sqrt(s * (s - a) * (s - b) * (s - c)); 
    }
    double perimeter() const override { return a + b + c; }
};

bool compareByArea(const Shape& s1, const Shape& s2) {
    return s1.area() < s2.area();
}

int main() {
    Circle c(5);
    Rectangle r(4, 6);
    Triangle t(3, 4, 5);
    
    std::cout << "Круг: S=" << c.area() << " P=" << c.perimeter() << "\n";
    std::cout << "Прямоугольник: S=" << r.area() << " P=" << r.perimeter() << "\n";
    std::cout << "Треугольник: S=" << t.area() << " P=" << t.perimeter() << "\n\n";
    
    Circle c2 = c;
    std::cout << "Копия круга: S=" << c2.area() << "\n\n";
    
    std::vector<const Shape*> shapes = {&c, &r, &t};
    std::vector<std::string> names = {"Круг", "Прямоугольник", "Треугольник"};
    
    for(int i = 0; i < 3; i++) {
        for(int j = i+1; j < 3; j++) {
            if(compareByArea(*shapes[i], *shapes[j]))
                std::cout << names[i] << " < " << names[j] << "\n";
            else if(shapes[i]->area() > shapes[j]->area())
                std::cout << names[i] << " > " << names[j] << "\n";
            else
                std::cout << names[i] << " = " << names[j] << "\n";
        }
    }
    
    return 0;
}

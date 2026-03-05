#include <iostream>
#include <vector>
#include <sstream>

class GraphicObject {
public:
    virtual void draw() = 0;
    virtual void scale(double) = 0;
    virtual std::string serialize() const = 0;
    virtual ~GraphicObject() {}
};

class Circle : public GraphicObject {
    double r, x, y;
public:
    Circle(double r, double x=0, double y=0) : r(r), x(x), y(y) {}
    void draw() override { std::cout << "Круг: r=" << r << " (" << x << "," << y << ")\n"; }
    void scale(double f) override { r *= f; }
    std::string serialize() const override {
        std::stringstream ss; ss << "Circle " << r << " " << x << " " << y; return ss.str();
    }
};

class Rectangle : public GraphicObject {
    double w, h, x, y;
public:
    Rectangle(double w, double h, double x=0, double y=0) : w(w), h(h), x(x), y(y) {}
    void draw() override { std::cout << "Прямоугольник: " << w << "x" << h << " (" << x << "," << y << ")\n"; }
    void scale(double f) override { w *= f; h *= f; }
    std::string serialize() const override {
        std::stringstream ss; ss << "Rectangle " << w << " " << h << " " << x << " " << y; return ss.str();
    }
};

int main() {
    std::vector<GraphicObject*> scene = {new Circle(5,10,10), new Rectangle(4,6,5,5)};
    
    std::cout << "До:\n"; for(auto o : scene) o->draw();
    std::cout << "\nПосле *2:\n"; for(auto o : scene) { o->scale(2); o->draw(); }
    std::cout << "\nСериализация:\n"; for(auto o : scene) std::cout << o->serialize() << "\n";
    
    for(auto o : scene) delete o;
}

#include <iostream>
#include <cmath>

/*
 SOLID:
 S - Zasada jednej odpowiedzialnosci (SRP)
 O - Zasada otwarte/zamkniete (OCP)
 L - Zasada podstawienia Liskov (LSP)
 I - Zasada segregacji interfejsow (ISP)
 D - Zasada odwrocenia zaleznosci (DIP)
 */

// Abstrakcyjna klasa bazowa dla wszystkich ksztaltow, demonstrujaca OCP i LSP
class Shape {
public:
    virtual double area() const = 0; // OCP
    virtual double perimeter() const = 0; // OCP
    virtual ~Shape() {}
};

// Interfejs do serializacji, demonstrujacy ISP
class Serializable {
public:
    virtual std::string serialize() const = 0;
    virtual ~Serializable() {}
};

// Interfejs do rysowania ksztaltow, demonstrujacy ISP
class Drawable {
public:
    virtual void draw() const = 0;
    virtual ~Drawable() {}
};

// Abstrakcja do zarzadzania roznymi ksztaltami, demonstrujaca DIP
class ShapeManager {
private:
    Shape* shape; // DIP: Wysoki poziom zalezy od abstrakcji, a nie od konkretow
public:
    ShapeManager(Shape* s) : shape(s) {}
    
    void printArea() const {
        std::cout << "Powierzchnia: " << shape->area() << std::endl;
    }

    void printPerimeter() const {
        std::cout << "Obwod: " << shape->perimeter() << std::endl;
    }
};

// Klasa okregu, spelniajaca ISP oraz OCP
class Circle : public Shape, public Serializable, public Drawable {
private:
    double radius;
    
public:
    Circle(double r) : radius(r) {}

    double area() const override { // OCP
        return 3.14 * radius * radius;
    }
    
    double perimeter() const override { // OCP
        return 2 * 3.14 * radius;
    }

    std::string serialize() const override { // ISP
        return "Okrag o promieniu: " + std::to_string(radius);
    }

    void draw() const override { // ISP
        const int size = 21;
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                double distance = std::sqrt(std::pow(i - size/2, 2) + std::pow(j - size/2, 2));
                if (std::abs(distance - radius) < 0.5) {
                    std::cout << "* ";
                } else {
                    std::cout << "  ";
                }
            }
            std::cout << std::endl;
        }
    }
};

// Klasa kwadratu, spelniajaca ISP oraz OCP
class Square : public Shape, public Serializable, public Drawable {
private:
    double side;
    
public:
    Square(double s) : side(s) {}

    double area() const override { // OCP
        return side * side;
    }
    
    double perimeter() const override { // OCP
        return 4 * side;
    }

    std::string serialize() const override { // ISP
        return "Kwadrat o boku: " + std::to_string(side);
    }

    void draw() const override { // ISP
        std::cout << std::endl;
        const int size = static_cast<int>(side);
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                std::cout << "* ";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }
};

// Klasa do rysowania ksztaltow, demonstrujaca DIP
class DrawingManager {
private:
    Drawable* drawable; // DIP: Wysoki poziom zalezy od abstrakcji, a nie od konkretow
public:
    DrawingManager(Drawable* d) : drawable(d) {}

    void render() const {
        drawable->draw();
    }
};

int main() {
    Circle circle(10);
    Square square(10);

    ShapeManager circleManager(&circle);
    ShapeManager squareManager(&square);

    DrawingManager drawingCircle(&circle);
    DrawingManager drawingSquare(&square);

    std::cout << "Informacje o okregu:" << std::endl;
    circleManager.printArea();
    circleManager.printPerimeter();
    std::cout << circle.serialize() << std::endl;
    drawingCircle.render();

    std::cout << "Informacje o kwadracie:" << std::endl;
    squareManager.printArea();
    squareManager.printPerimeter();
    std::cout << square.serialize() << std::endl;
    drawingSquare.render();
    
    return 0;
}

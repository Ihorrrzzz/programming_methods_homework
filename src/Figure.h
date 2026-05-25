#ifndef PROGRAMMING_METHODS_FIGURE_H
#define PROGRAMMING_METHODS_FIGURE_H

#include <string>

class Figure {
public:
    Figure();
    explicit Figure(const std::string& name);
    Figure(const std::string& name, int x, int y);
    virtual ~Figure() = default;

    void setName(const std::string& name);
    const std::string& getName() const;

    void setX(int x);
    void setY(int y);
    int getX() const;
    int getY() const;

    virtual double area() const = 0;
    virtual double perimeter() const = 0;
    virtual void print() const;

protected:
    std::string name;
    int x;
    int y;
};

#endif

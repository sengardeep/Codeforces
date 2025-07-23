#include <iostream>
#include <cmath> // For std::abs

struct Point {
    double x, y;
};

double triangleArea(Point A, Point B, Point C) {
    return  std::abs(A.x * (B.y - C.y) + B.x * (C.y - A.y) + C.x * (A.y - B.y));
}

int main() {
    Point A, B, C;

    std::cout << "Enter the coordinates of the first vertex (x1 y1): ";
    std::cin >> A.x >> A.y;
    std::cout << "Enter the coordinates of the second vertex (x2 y2): ";
    std::cin >> B.x >> B.y;
    std::cout << "Enter the coordinates of the third vertex (x3 y3): ";
    std::cin >> C.x >> C.y;

    double area = triangleArea(A, B, C);
    std::cout << "The area of the triangle is: " << area << std::endl;

    return 0;
}

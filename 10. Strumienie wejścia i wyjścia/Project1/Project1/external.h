#pragma once
#include <iostream>

// ex1
void ex1();
struct Point;
std::istream& operator>>(std::istream& is, Point& P);

// ex2
void ex2();

// ex3
struct Reading;
std::istream& operator>>(std::istream& is, Reading& R);
std::ostream& operator<<(std::ostream& os, Reading& R);
void ex3();


#pragma once
#include <iostream>
#include <list>
#include <vector>


using namespace std;
class Rect
{
    friend class R_Tree;
private:
    class Point {
        friend class R_Tree;
    public:
        double x;
        double y;
        Point(double x, double y);
        Point();
        bool operator==(const Point& rhs);

    };
public:
    Rect(Point lt, Point rb);
    Rect(double ltx, double lty, double rbx, double rby);
    Rect();
    bool operator==(const Rect& rhs);
    friend ostream& operator<<(ostream& os, const Rect& rct);
    Point get_lt();
    Point get_rb();
    string to_string();

private:


    Point lt;
    Point rb;
    static bool is_overlap(Rect E, Rect S);
    double area();
    static double area_to_increase(Rect E, Rect S);
    static Rect marged_rect(Rect E, Rect S);
    static double Area(vector<Rect> R);







};


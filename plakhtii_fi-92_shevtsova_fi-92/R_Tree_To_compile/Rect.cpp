#include "Rect.h"


Rect::Rect(Point lt, Point rb)
{
	this->lt = lt;
	this->rb = rb;
}

Rect::Rect(double ltx, double lty, double rbx, double rby)
{
	lt.x = ltx;
	lt.y = lty;
	rb.x = rbx;
	rb.y = rby;
}

Rect::Rect()
{
	lt = Point();
	rb = Point();
}

bool Rect::is_overlap(Rect E, Rect S)
{
	return (E.lt.x >= S.lt.x && E.lt.x <= S.rb.x && E.lt.y >= S.lt.y && E.lt.y <= S.rb.y) ||
		(E.rb.x >= S.lt.x && E.rb.x <= S.rb.x && E.rb.y >= S.lt.y && E.rb.y <= S.rb.y) ||
		(E.lt.x >= S.lt.x && E.lt.x <= S.rb.x && E.rb.y >= S.lt.y && E.rb.y <= S.rb.y) ||
		(E.rb.x >= S.lt.x && E.rb.x <= S.rb.x && E.lt.y >= S.lt.y && E.lt.y <= S.rb.y);
}

double Rect::area() {
	return abs((lt.x - rb.x) * (lt.y - rb.y));
}

double Rect::area_to_increase(Rect E, Rect S)
{
	double new_rect_area = Rect::marged_rect(E,S).area();
	return new_rect_area - E.area() - S.area();
}

Rect Rect::marged_rect(Rect E, Rect S)
{
	return Rect(Point((double)min(E.lt.x, S.lt.x), (double)min(E.lt.y, S.lt.y)), Point((double)max(E.rb.x, S.rb.x), (double)max(E.rb.y, S.rb.y)));
}

double Rect::Area(vector<Rect> R)
{

	double min_x = R[0].get_lt().x;
	double max_x = R[0].get_rb().x;
	double min_y = R[0].get_lt().y;
	double max_y = R[0].get_rb().y;
	for (int i = 1; i < R.size(); i++) {
		min_x = (double)min(R[i].get_lt().x, min_x);
		max_x = (double)max(R[i].get_rb().x, max_x);
		min_y = (double)min(R[i].get_lt().y, min_y);
		max_y = (double)max(R[i].get_rb().y, max_y);
	}
	return Rect(min_x, min_y, max_x, max_y).area();
}

bool Rect::operator==(const Rect& rhs)
{
	return (this->lt == rhs.lt) && (this->rb == rhs.rb);
}

Rect::Point Rect::get_lt()
{
	return this->lt;
}

Rect::Point Rect::get_rb()
{
	return this->rb;
}




Rect::Point::Point(double x, double y)
{

	this->x = x;
	this->y = y;

}

Rect::Point::Point()
{
	x = 0;
	y = 0;
}

bool Rect::Point::operator==(const Point& rhs)
{
	return (this->x == rhs.x) && (this->y == rhs.y);
}

ostream& operator<<(ostream& os, const Rect& rct)
{
	return os << "((" << rct.lt.x << ", " << rct.lt.y << "), (" << rct.rb.x << ", " << rct.rb.y << "))";
}
string Rect::to_string(){
    return "((" + std::to_string(lt.x) + ", " + std::to_string(lt.y)  + "), (" + std::to_string(rb.x)  + ", " + std::to_string(rb.y) + "))";
}

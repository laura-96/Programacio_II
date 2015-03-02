#include <math.h>
#include "Point2d.h"


bool Point2d::IsZero() const {

	return (x == 0.0f && y == 0.0f);
}

void Point2d::SetZero() {

	x = y = 0.0f;
}

Point2d& Point2d::Negate() {

	x = -x;
	y = -y;

	return(*this);
}

float Point2d::DistanceTo(const Point2d& a) const{

	float vx, vy;
	float distance;

	vx = x - a.x;
	vy = y - a.y;
	distance = sqrtf((vx*vx) + (vy*vy));
	//sqrtf() does the same as sqrt(). However, if we had used sqrt, there would have been a conversion from float to double

	return (distance);
}


//Operators:

Point2d Point2d::operator+ (const Point2d& a) const{

	Point2d b;
	b.x = x + a.x;
	b.y = y + a.y;

	return (b);
}

Point2d Point2d::operator- (const Point2d& a) const{

	Point2d b;
	b.x = x - a.x;
	b.y = y - a.y;

	return (b);
}

Point2d Point2d::operator+= (const Point2d& a) {

	x += a.x;
	y += a.y;

	return (*this);
}

Point2d Point2d::operator-= (const Point2d& a) {

	x -= a.x;
	y -= a.y;

	return (*this); //it returns itself
}


bool Point2d::operator== (const Point2d& a) const{

	return (x == a.x && y == a.y);
}

bool Point2d::operator!= (const Point2d& a) const{

	return (x != a.x || y != a.y);
}

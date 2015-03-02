#ifndef __POINT2D_H__
#define __POINT2D_H__

class Point2d{

public:

	//Attributes:
	float x, y;

public:

	void SetZero();
	bool IsZero() const; // Method to check whether the value of x and y is 0 or not
	Point2d& Negate(); // This method is not const, because it consists on changing the value of the variables (as it happens in setZero)
	float DistanceTo(const Point2d& a) const;

	//Operators:

	Point2d operator+ (const Point2d& a) const;
	Point2d operator- (const Point2d& a) const;
	Point2d operator+= (const Point2d& a);
	Point2d operator-= (const Point2d& a);
	//Comparison operators:
	bool operator== (const Point2d& a) const;
	bool operator!= (const Point2d& a) const;


};


#endif
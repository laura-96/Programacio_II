#ifndef __POINT2D_H__
#define __POINT2D_H__

class Point2d{

public:

	//Attributes:
	float x, y;

public:

	//Constructor:

	Point2d(); //This could have been omitted because an equal default constructor would have been created

	void setZero();
	bool isZero() const; // Method to check whether the value of x and y is 0 or not
	Point2d& negate(); // This method is not const, because it consists on changing the value of the variables (as it happens in setZero)
	float distanceTo(const Point2d& a) const;

	//Operators:

	Point2d operator+ (const Point2d& a) const;
	Point2d operator- (const Point2d& a) const;
	Point2d operator+= (const Point2d& a);
	Point2d operator-= (const Point2d& a);
	//Comparison operators:
	bool operator== (const Point2d& a) const;
	bool operator!= (const Point2d& a) const;


	//Destructor:

	virtual ~Point2d();
};


#endif
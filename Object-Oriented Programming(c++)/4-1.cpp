#include <iostream>
#include <cstdlib>
#define Pi 3.1415926

using namespace std;

class C_Shape
{
	public:
		C_Shape() { area=0; }
		C_Shape(double a) { area=a; cout<<"Here is shape constructor"<<endl; }
		double Get_Area() { return area; }
	private:
		double area;
};
class C_Rectangle: public C_Shape
{
	public:
		C_Rectangle() { width=length=0; }
		C_Rectangle(double,double);
	private:
		double width,length;
};
class C_Circle: public C_Shape
{
	public:
		C_Circle() { radius=0; cout<<"Here is derived constructor"<<endl;}
		C_Circle(double);
	private:
		double radius;
};
class C_Square: public C_Rectangle
{
	public:
		C_Square() { edge=0; };
		C_Square(double);
	private:
		double edge;
};
C_Rectangle::C_Rectangle(double a,double b): C_Shape(a*b)
{
	width=a;
	length=b;
	cout<<"Here is rectangle constructor"<<endl;
}
C_Circle::C_Circle(double r): C_Shape(Pi*r*r)
{
	radius=r;
	cout<<"Here is circle constructor"<<endl;
}
C_Square::C_Square(double a): C_Rectangle(a,a)
{
	edge=a;
	cout<<"Here is square constructor"<<endl;
}
int main(int argc, char const *argv[])
{
	double a,b,c;
	cout<<"input the square's length"<<endl;
	cin>>a;
	C_Square MySquare(a);
	cout<<"the area of this square is "<<MySquare.Get_Area()<<endl;
	cout<<"input the circle's radius"<<endl;
	cin>>b;
	C_Circle MyCircle(b);
	cout<<"the area of this circle is "<<MyCircle.Get_Area()<<endl;
	return 0;
}
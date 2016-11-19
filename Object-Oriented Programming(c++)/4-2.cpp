#include <iostream>
#include <cstdlib>
#define Pi 3.1415926

using namespace std;

class C_Shape
{
	public:
		virtual double Get_Area() const=0;
};
class C_Rectangle: public C_Shape
{
	public:
		C_Rectangle() { width=length=0; }
		C_Rectangle(double a,double b) { width=a; length=b; }
		virtual double Get_Area() const { return width*length; }
	private:
		double width,length;
};
class C_Circle: public C_Shape
{
	public:
		C_Circle() { radius=0; }
		C_Circle(double r) { radius=r; }
		virtual double Get_Area() const {return Pi*radius*radius; }
	private:
		double radius;
};
class C_Square: public C_Rectangle
{
	public:
		C_Square() { edge=0; };
		C_Square(double a) { edge=a; } 
		virtual double Get_Area() const {return edge*edge; }
	private:
		double edge;
};
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
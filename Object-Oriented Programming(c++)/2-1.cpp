#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

class Point
{
	public:
		Point(int xx=0,int yy=0) { x=xx; y=yy; };
		Point(Point &dot) { x=dot.x; y=dot.y; };
		double GetX() { return x; }
		double GetY() { return y; }
		void PrintPoint() { cout<<x<<" "<<y<<" "; }
		double CalculateDistance(Point,Point);
	private:
		double x,y;
};
class Rectangle
{
	public:
		Rectangle(Point,Point);
		double GetArea() { return Area; }
		void PrintVertex() { TopLeft.PrintPoint(); BottomRight.PrintPoint(); cout<<endl; }
	private:
		Point TopLeft,BottomRight;
		double Area;
};

inline double Point::CalculateDistance(Point a,Point b)
{
	return sqrt(pow((a.x-b.x),2)+pow((a.y-b.y),2));
}
inline Rectangle::Rectangle(Point a,Point b):TopLeft(a),BottomRight(b)    
{
	   		Area=abs((a.x-b.GetX())*(a.GetY()-b.GetY()));
}
int main(int argc, char const *argv[])
{
	double x1,x2,y1,y2;
	cout<<"Please input the top-left vertex and bottom-right vertex:\n";
	cin>>x1>>y1>>x2>>y2;
	Point a(x1,y1),b(x2,y2);
	Rectangle MyRect(a,b);
	cout<<"The Area of this rectangle is "<<MyRect.GetArea()<<endl;
	return 0;
} 
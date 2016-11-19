#include <iostream>
#include <cstdlib>

using namespace std;

class Point
{
	public:
		Point() { x=y=0; }
		Point(int xx,int yy) { x=xx; y=yy; }
		Point(const Point &p) { x=p.x; y=p.y; }
		Point& operator ++();
		Point& operator --();
		Point operator ++(int);
		Point operator --(int);
		Point& operator =(const Point&);
		friend ostream& operator <<(ostream&,const Point&);
	private:
		int x,y;
};

Point& Point::operator ++()
{
	x++;
	y++;
	return *this;
}

Point& Point::operator --()
{
	x--;
	y--;
	return *this;
}

Point Point::operator ++(int)
{
	Point temp(x,y);
	++(*this);
	return temp;
}

Point Point::operator --(int)
{
	Point temp(x,y);
	--(*this);
	return temp;
}

ostream& operator <<(ostream& out,const Point& a)
{
	out<<'('<<a.x<<','<<a.y<<')'<<endl;
	return out;
}

Point& Point::operator =(const Point &b)
{
	x=b.x;
	y=b.y;
	return (*this); 
}

int main(int argc, char const *argv[])
{
	Point a(2,3),b;
	b=(a++);            //b=(2,3) a=3,4
	cout<<b<<endl;
	b=(++a);			//b=(4,5) a=4,5
	cout<<b<<endl;
	b=(a--);			//b=(4,5) a=3,4
	cout<<b<<endl;
	b=(--a); 			//b=(2,3) a=2,3
	cout<<b<<endl;
	return 0;
}
#include <iostream>
#include <cstdlib>

using namespace std;

class Car;
class Boat
{
	public:
		Boat(int x) { weigh=x; };
		friend double TotalWeight(Boat& b, Car& c);
	private:
		int weigh;
};
class Car
{
	public:
		Car(int x) { weigh=x; };
		friend double TotalWeight(Boat& b, Car& c);
	private:
		int weigh;
};
double TotalWeight(Boat& b, Car& c)
{
	return b.weigh+c.weigh;
}
int main(int argc, char const *argv[])
{
	int a,b;
	cout<<"Please input the boat's weigh"<<endl;
	cin>>a;
	cout<<"Please input the car's weigh"<<endl;
	cin>>b;
	Boat MyBoat(a);
	Car MyCar(b);
	cout<<"The total weigh is "<<TotalWeight(MyBoat,MyCar)<<"."<<endl;
	return 0;
}
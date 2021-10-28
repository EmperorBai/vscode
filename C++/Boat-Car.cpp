#include <iostream>
#include<cmath>
using namespace std;
class Car;
class Boat
{
friend class Car;
public:
	friend int totalweight(Boat &b, Car &c);
	Boat(int a):weight(a){};
private:
	int weight;
};
class Car
{
public:
	friend int totalweight(Boat &b, Car &c);
	Car(int a):weight(a){}
private:
	int weight;
};

int totalweight(Boat &b, Car &c)
{
return b.weight + c.weight;
} 
int main()
{
Boat b(100);Car c(200);
cout<<"The weight is: ";
cout<<totalweight(b,c)<<endl;
}

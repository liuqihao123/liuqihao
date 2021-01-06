#include<iostream>
#include<stdio.h>
using namespace std;
class vehicle
{
public:
vehicle()
{
	cout<<"请输入车轮数和车重：";
	int a;double b;
	cin>>a>>b; 
	wheels=a;
	weight=b;
}
void display()
{
	cout<<"该车的车轮个数为："<<wheels<<endl;
	cout<<"该车的车重为："<<weight<<endl;

}
protected:
int wheels;
double weight;
};
class car:private vehicle 
{
public:
    car() 
	{
	    cout<<"请输入载人数：";
     	int c;
		cin>>c;
		passenger_load=c;
	}
void display1()
{
	cout<<"该车的载人数为："<<passenger_load<<endl;
	vehicle::display();
}
protected:
	int passenger_load;
};
class truck:private vehicle 
{
public:
    truck()
	{
		cout<<"请输入载人数和载重量：";
		int c;double d;
		cin>>c>>d;
		passenger_load=c;
		payload=d;
	}
void display2()
{
	cout<<"该车的载人数为："<<passenger_load<<endl;
	cout<<"该车的载重量为："<<payload<<endl;
	vehicle::display();
}
protected:
	int passenger_load;
	double payload;
};
main()
{
	car b1;
	b1.display1();
	truck c1;
	c1.display2();
}
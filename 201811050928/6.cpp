#include<iostream>
#include<stdio.h>
using namespace std;
class vehicle
{
public:
vehicle()
{
	cout<<"�����복�����ͳ��أ�";
	int a;double b;
	cin>>a>>b; 
	wheels=a;
	weight=b;
}
void display()
{
	cout<<"�ó��ĳ��ָ���Ϊ��"<<wheels<<endl;
	cout<<"�ó��ĳ���Ϊ��"<<weight<<endl;

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
	    cout<<"��������������";
     	int c;
		cin>>c;
		passenger_load=c;
	}
void display1()
{
	cout<<"�ó���������Ϊ��"<<passenger_load<<endl;
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
		cout<<"����������������������";
		int c;double d;
		cin>>c>>d;
		passenger_load=c;
		payload=d;
	}
void display2()
{
	cout<<"�ó���������Ϊ��"<<passenger_load<<endl;
	cout<<"�ó���������Ϊ��"<<payload<<endl;
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
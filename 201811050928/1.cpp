#include<stdio.h>
#include<iostream>
using namespace std;
int fun(int a,int b)
{
	int c;
	c=a/10*10+a%10*1000+b/10+b%10*100;
	return c;
}
main()
{
	int a,b;
	cin>>a>>b;
	int c=fun(a,b);
	cout<<c<<endl;
}
#include<stdio.h>
#include<iostream>
#include<string>
#define N 100
using namespace std;
main()
{
	char a[N][N];int i=0,j;int m,n;int b=0,b0[N],b1[N];
	cout<<"请输入疫情分布地图同时输入行数和列数："<<endl;
	cin>>m>>n;
	for(i=0;i<m;i++)
		for(j=0;j<n;j++)
	{
		cin>>a[i][j];
	}
	cout<<"请输入周期数"<<endl;
	int c;
	cin>>c;
	for(int i1=0;i1<c;i1++)
	{
		for(i=0;i<m;i++)
		for(j=0;j<n;j++)
	{
		if(a[i][j]=='X')
		{
			b0[b]=i;
			b1[b]=j;
			b++;
		}
	}
	for(b=b-1;b>=0;b--)
	{
		a[b0[b]+1][b1[b]]='X';
		a[b0[b]-1][b1[b]]='X';
		if(a[b0[b]][b1[b]+1]!='P')
	    a[b0[b]][b1[b]+1]='X';
		a[b0[b]][b1[b]-1]='X';
	}
	b=0;
	}
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
	{
		cout<<a[i][j];
	}
		cout<<endl;
	}
}
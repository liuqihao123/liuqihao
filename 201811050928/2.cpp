#include<iostream>
using namespace std;
	struct LNode
{
	int v;
	LNode *next;
};

	int fun(int m, int n)
{
	if (n==1) return m;
	LNode MKs[100];
	for (int i=0; i<m-1; ++i) 
{
	MKs[i].v=i+1;
	MKs[i].next=&MKs[i+1];
}
	MKs[m - 1].v=m;
	MKs[m - 1].next=&MKs[0];

	LNode* p=&MKs[0];
	while (p->next != p) 
{
	for (int i=0; i<n - 2; ++i) 
	{
	p=p->next;
}
	p->next=p->next->next;
	p=p->next;
}
	return p->v;
}
int fun2(int m, int n)
{
	int MK[100];int NUM=m;int k=0;
	for (int i=0; i<NUM; ++i) 
{
	MK[i]=1;
}
	while (NUM>1) 
{
	for (int i=0; i<m; ++i)
{
	if (MK[i]==1)
	++k;
	if (k==n)

{
	MK[i]=0;
	k=0;
	--NUM;
}
}
}
	for (int j=0; j<m; ++j) 
{
	if (MK[j]==1)
	return j+1;
}
}
main()
{
	int m, n;
	cout << "���������������Ҫ���ĸ���: "<<endl; cin>>m>>n;
	while (n >= m  && m<100) {
	cout << "Ҫ��n<m ����m<100, ����������" << endl;
	cin >> m >> n;
}
	int K1, K2;
	K2=fun(m, n); //����
	K1=fun2(m, n); //���鷨
	cout<< "��������ô����ǣ�" << K2<<endl
	<<"�����鷨��ô����ǣ�" << K1<<endl;
}
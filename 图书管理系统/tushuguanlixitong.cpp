#include <stdio.h>
#include<iostream.h>
#include <stdlib.h>
#include <winsock.h>
#include <mysql.h>
#pragma comment(lib,"libmysql.lib")
class inventory
{
public:
	MYSQL mysql,*sock;    // �������ݿ����ӵľ�����������ڼ������е� MySQL ����
    MYSQL_RES *res;       // ��ѯ��������ṹ����
    MYSQL_FIELD *fd ;     // �����ֶ���Ϣ�Ľṹ
    MYSQL_ROW row ;       // ���һ�в�ѯ������ַ�������
    char  qbuf[256];      // ��Ų�ѯ sql ����ַ���
	int bianhao;char shuming[20];char zuozhe[20];char chubanshe[20];
	char chubanriqi[20];int jine;char leibie[20];int zongrukushuliang;int dangqiankucunliang;
	int yijiechubenshu;//���ݳ�ԱΪ�˱���ֶ�
	void createinventorybook();//���Ӳ���
	void deleteinventorybook();//ɾ������
	void alterinventorybook();//�޸Ĳ���
	void selectinventorybook();//��ѯ����
};
class borrow:public inventory
{
public:
	int bianhao;char shuming[20];int jine;int jieshuzhenghao;int jieshuriqi;int daoqiriqi;
	int fakuanjine;
	void createborrowbook();//���ӽ���
	void returnborrowbook();//�������
	void renewbook();//�������
};
class person:public inventory
{
	public:
	int jieshuzhenghao;char xingming[20];char banji[20];char xuehao[20];
	//���ݳ�Ա
	void createperson();//���Ӷ�����Ϣ
	void deleteperson();//ɾ��������Ϣ
	void selectperson();//��ѯ������Ϣ
};
class tongji:public inventory
{
public:
	void jieyuepaihangbang();//�������а�
	void ziliaozhuangtai();//����״̬ͳ��
};
void inventory::createinventorybook()//�����Ϣ����
	{
	mysql_init(&mysql);
	if (!(sock = mysql_real_connect(&mysql,"localhost","root","12345678","liuqihao",0,NULL,0)))
	{
		fprintf(stderr,"Couldn't connect to engine!/n%s/n/n", mysql_error(&mysql));
		perror("");
		exit(1);
	}
    sprintf(qbuf, "create database liuqihao;");
	mysql_query(&mysql, qbuf);
	sprintf(qbuf, "use liuqihao;");
	mysql_query(&mysql, qbuf);
	sprintf(qbuf, "create table inventorybook(bianhao int,shuming varchar(10),zuozhe varchar(10),chubanshe varchar(10),chubanriqi varchar(10),jine int,leibie varchar(10),zongrukushuliang int,dangqiankucunliang int,yijiechubenshu int);");
	mysql_query(&mysql, qbuf);
	cout<<"������ͼ��Ŀ����Ϣ������š����������ߡ������硢�������ڡ�������������������ǰ��������ѽ������"<<endl;
	cin>>bianhao>>shuming>>zuozhe>>chubanshe>>chubanriqi>>jine>>leibie>>zongrukushuliang>>\
		dangqiankucunliang>>yijiechubenshu;
	sprintf(qbuf, "insert into inventorybook values ('%d', '%s', '%s', '%s', '%s', '%d', '%s', '%d', '%d', '%d');"\
		,bianhao,shuming,zuozhe,chubanshe,chubanriqi,jine,leibie,zongrukushuliang,\
		dangqiankucunliang,yijiechubenshu);
	mysql_query(&mysql, qbuf);
	cout<<endl;
	cout<<endl;
	cout<<"���   ����   ����  ������  ��������  ���  ���  ���������  ��ǰ�����  �ѽ������"<<endl;
	mysql_query(&mysql, "select * from inventorybook");//��������
    res=mysql_store_result(&mysql);
	int n;n=mysql_field_count(&mysql);//��ȡ�ֶ���
	while (row = mysql_fetch_row(res))
	{
		for(int i=0;i<n;i++)
			printf("%s   ",row[i]);
		cout<<endl;
	}
	cout<<endl;
	cout<<endl;
	}
void inventory::deleteinventorybook()//�����Ϣɾ��
{
	mysql_init(&mysql);
	if (!(sock = mysql_real_connect(&mysql,"localhost","root","12345678","liuqihao",0,NULL,0)))
	{
		fprintf(stderr,"Couldn't connect to engine!/n%s/n/n", mysql_error(&mysql));
		perror("");
		exit(1);
	}
    sprintf(qbuf, "create database liuqihao;");
	mysql_query(&mysql, qbuf);
	sprintf(qbuf, "use liuqihao;");
	mysql_query(&mysql, qbuf);
	cout<<"������Ҫɾ���鱾��Ϣ�ı��:"<<endl;
	int a;
	cin>>a;
	sprintf(qbuf,"delete from inventorybook where bianhao=%d;",a);
	mysql_query(&mysql, qbuf);
	cout<<endl;
	cout<<endl;
	cout<<"ɾ�������ݺ�ĵ��鱾��Ϣ"<<endl;
	cout<<"���   ����   ����  ������  �������� ��� ��� ��������� ��ǰ����� �ѽ������"<<endl;
	mysql_query(&mysql, "select * from inventorybook");//��������
    res=mysql_store_result(&mysql);
	int n;n=mysql_field_count(&mysql);//��ȡ�ֶ���
	while (row = mysql_fetch_row(res))
	{
		for(int i=0;i<n;i++)
			printf("%s   ",row[i]);
		cout<<endl;
	}
	cout<<endl;
	cout<<endl;
}
void inventory::alterinventorybook()//�����Ϣ�޸�
{
	mysql_init(&mysql);
	if (!(sock = mysql_real_connect(&mysql,"localhost","root","12345678","liuqihao",0,NULL,0)))
	{
		fprintf(stderr,"Couldn't connect to engine!/n%s/n/n", mysql_error(&mysql));
		perror("");
		exit(1);
	}
    sprintf(qbuf, "create database liuqihao;");
	mysql_query(&mysql, qbuf);
	sprintf(qbuf, "use liuqihao;");
	mysql_query(&mysql, qbuf);
	cout<<"������Ҫ�޸��鱾��Ϣ�ı��:"<<endl;
	int a;
	cin>>a;
	cout<<"������Ҫ�޸ĵ��ֶ�����Ҫ�޸ĵ�����"<<endl;
	char a1[20],char b1[20];
	cin>>a1>>b1;
	sprintf(qbuf,"update inventorybook set %s='%s' where bianhao=%d;",a1,b1,a);
	mysql_query(&mysql, qbuf);
	cout<<endl;
	cout<<endl;
	cout<<"�޸������ݺ�ĵ��鱾��Ϣ"<<endl;
	cout<<"���   ����   ����  ������  ��������  ���  ���  ���������  ��ǰ�����  �ѽ������"<<endl;
	mysql_query(&mysql, "select * from inventorybook");//��������
    res=mysql_store_result(&mysql);
	int n;n=mysql_field_count(&mysql);//��ȡ�ֶ���
	while (row = mysql_fetch_row(res))
	{
		for(int i=0;i<n;i++)
			printf("%s     ",row[i]);
		cout<<endl;
	}
	cout<<endl;
	cout<<endl;
}
void inventory::selectinventorybook()//�����Ϣ��ѯ
{
	mysql_init(&mysql);
	if (!(sock = mysql_real_connect(&mysql,"localhost","root","12345678","liuqihao",0,NULL,0)))
	{
		fprintf(stderr,"Couldn't connect to engine!/n%s/n/n", mysql_error(&mysql));
		perror("");
		exit(1);
	}
    sprintf(qbuf, "create database liuqihao;");
	mysql_query(&mysql, qbuf);
	sprintf(qbuf, "use liuqihao;");
	mysql_query(&mysql, qbuf);
	cout<<"������Ҫ��ѯ���ֶ�����Ҫ��ѯ������"<<endl;
	char a1[20],char b1[20];
	cin>>a1>>b1;
	sprintf(qbuf,"select * from inventorybook where %s='%s';",a1,b1);
	mysql_query(&mysql, qbuf);
	cout<<endl;
	cout<<endl;
	cout<<"��ѯ�����ݺ�ĵ��鱾��Ϣ"<<endl;
	cout<<"���   ����   ����  ������  ��������  ���  ���  ���������  ��ǰ�����  �ѽ������"<<endl;
	mysql_query(&mysql, "select * from inventorybook");//��������
    res=mysql_store_result(&mysql);
	int n;n=mysql_field_count(&mysql);//��ȡ�ֶ���
	while (row = mysql_fetch_row(res))
	{
		for(int i=0;i<n;i++)
			printf("%s     ",row[i]);
		cout<<endl;
	}
	cout<<endl;
	cout<<endl;
}
void borrow::createborrowbook()//����ͼ������
	{
	mysql_init(&mysql);
	if (!(sock = mysql_real_connect(&mysql,"localhost","root","12345678","liuqihao",0,NULL,0)))
	{
		fprintf(stderr,"Couldn't connect to engine!/n%s/n/n", mysql_error(&mysql));
		perror("");
		exit(1);
	}
    sprintf(qbuf, "create database liuqihao;");
	mysql_query(&mysql, qbuf);
	sprintf(qbuf, "use liuqihao;");
	mysql_query(&mysql, qbuf);
	sprintf(qbuf, "create table borrowbook(bianhao int,shuming varchar(10),jinge int,jieshuzhenghao int,jieshuriqi int,daoqiriqi int,fakuanjine int);");
	mysql_query(&mysql, qbuf);
	cout<<"�������ѽ��ͼ��Ŀ����Ϣ������š�������������֤�š��������ڡ��������ڡ�������"<<endl;
	int bianhao;char shuming[20];int jine;int jieshuzhenghao;int jieshuriqi;int daoqiriqi;
	int fakuanjine;
	cin>>bianhao>>shuming>>jine>>jieshuzhenghao>>jieshuriqi>>daoqiriqi>>fakuanjine;
	sprintf(qbuf, "insert into borrowbook values ('%d', '%s', '%d', '%d', '%d', '%d', '%d');",bianhao,shuming,jine,jieshuzhenghao,jieshuriqi,daoqiriqi,fakuanjine);
	mysql_query(&mysql, qbuf);
	sprintf(qbuf, "select * from borrowbook;");
	mysql_query(&mysql, qbuf);
	cout<<endl;
	cout<<endl;
	cout<<"���ͼ������Ϣ"<<endl;
	cout<<"���   ����   ���  ����֤��  ��������  ��������  ������ "<<endl;
	mysql_query(&mysql, "select * from borrowbook");//��������
    res=mysql_store_result(&mysql);
	int n;n=mysql_field_count(&mysql);//��ȡ�ֶ���
	while (row = mysql_fetch_row(res))
	{
		for(int i=0;i<n;i++)
			printf("%s     ",row[i]);
		cout<<endl;
	}
	cout<<endl;
	cout<<endl;
}
void borrow::returnborrowbook()//����ͼ��黹
{
	mysql_init(&mysql);
	if (!(sock = mysql_real_connect(&mysql,"localhost","root","12345678","liuqihao",0,NULL,0)))
	{
		fprintf(stderr,"Couldn't connect to engine!/n%s/n/n", mysql_error(&mysql));
		perror("");
		exit(1);
	}
    sprintf(qbuf, "create database liuqihao;");
	mysql_query(&mysql, qbuf);
	sprintf(qbuf, "use liuqihao;");
	mysql_query(&mysql, qbuf);
	cout<<"������Ҫ�����ѽ����鱾��Ϣ�ı��:"<<endl;
	int a;
	cin>>a;
	sprintf(qbuf,"update inventorybook set dangqiankucunliang=dangqiankucunliang+1 where bianhao=%d;",a);
	mysql_query(&mysql, qbuf);//��ǰ�������һ
	sprintf(qbuf,"update inventorybook set yijiechubenshu=yijiechubenshu-1 where bianhao=%d;",a);
	mysql_query(&mysql, qbuf);//�ѽ��������һ
	cout<<endl;
	cout<<endl;
	cout<<"���غ�ĵ��鱾�����Ϣ";
	cout<<"���   ����   ����  ������  ��������  ���  ���  ���������  ��ǰ�����  �ѽ������"<<endl;
	mysql_query(&mysql, "select * from inventorybook");//��������
    res=mysql_store_result(&mysql);
	int n;n=mysql_field_count(&mysql);//��ȡ�ֶ���
	while (row = mysql_fetch_row(res))
	{
		for(int i=0;i<n;i++)
			printf("%s     ",row[i]);
		cout<<endl;
	}
	cout<<endl;
	cout<<endl;
}
void borrow::renewbook()//����ͼ������
{
	mysql_init(&mysql);
	if (!(sock = mysql_real_connect(&mysql,"localhost","root","12345678","liuqihao",0,NULL,0)))
	{
		fprintf(stderr,"Couldn't connect to engine!/n%s/n/n", mysql_error(&mysql));
		perror("");
		exit(1);
	}
    sprintf(qbuf, "create database liuqihao;");
	mysql_query(&mysql, qbuf);
	sprintf(qbuf, "use liuqihao;");
	mysql_query(&mysql, qbuf);
	cout<<"������Ҫ�����ѽ����鱾��Ϣ�ı��:"<<endl;
	int a;
	cin>>a;
	cout<<"������Ҫ�����������"<<endl;
	int b;
	cin>>b;
	sprintf(qbuf,"update borrowbook set daoqiriqi=daoqiriqi+%d where bianhao=%d;",b,a);
	mysql_query(&mysql, qbuf);//������������
	cout<<endl;
	cout<<endl;
	cout<<"�����ĵ��鱾�����Ϣ"<<endl;
	cout<<"���   ����   ���  ����֤��  ��������  ��������  ������ "<<endl;
	mysql_query(&mysql, "select * from borrowbook");//��������
    res=mysql_store_result(&mysql);
	int n;n=mysql_field_count(&mysql);//��ȡ�ֶ���
	while (row = mysql_fetch_row(res))
	{
		for(int i=0;i<n;i++)
			printf("%s     ",row[i]);
		cout<<endl;
	}
	cout<<endl;
	cout<<endl;
}
void person::createperson()//������Ϣ����
{
	mysql_init(&mysql);
	if (!(sock = mysql_real_connect(&mysql,"localhost","root","12345678","liuqihao",0,NULL,0)))
	{
		fprintf(stderr,"Couldn't connect to engine!/n%s/n/n", mysql_error(&mysql));
		perror("");
		exit(1);
	}
    sprintf(qbuf, "create database liuqihao;");
	mysql_query(&mysql, qbuf);
	sprintf(qbuf, "use liuqihao;");
	mysql_query(&mysql, qbuf);
	sprintf(qbuf, "create table person(jieshuzhenghao int,xingming varchar(20),banji varchar(20),xuehao varchar(20));");
	mysql_query(&mysql, qbuf);
	cout<<"�������������Ϣ��������֤�š��������༶��ѧ��"<<endl;
	cin>>jieshuzhenghao>>xingming>>banji>>xuehao;
	sprintf(qbuf, "insert into person values ('%d', '%s', '%s', '%s');",jieshuzhenghao,xingming,banji,xuehao);
	mysql_query(&mysql, qbuf);
		cout<<endl;
	cout<<endl;
	cout<<"����֤��   ����   �༶  ѧ��"<<endl;
	mysql_query(&mysql, "select * from person");//��������
    res=mysql_store_result(&mysql);
	int n;n=mysql_field_count(&mysql);//��ȡ�ֶ���
	while (row = mysql_fetch_row(res))
	{
		for(int i=0;i<n;i++)
			printf("%s     ",row[i]);
		cout<<endl;
	}
		cout<<endl;
	cout<<endl;
}
void person::deleteperson()//������Ϣɾ��
{
	mysql_init(&mysql);
	if (!(sock = mysql_real_connect(&mysql,"localhost","root","12345678","liuqihao",0,NULL,0)))
	{
		fprintf(stderr,"Couldn't connect to engine!/n%s/n/n", mysql_error(&mysql));
		perror("");
		exit(1);
	}
    sprintf(qbuf, "create database liuqihao;");
	mysql_query(&mysql, qbuf);
	sprintf(qbuf, "use liuqihao;");
	mysql_query(&mysql, qbuf);
	cout<<"������Ҫɾ�����ߵ�ѧ��:"<<endl;
	int a;
	cin>>a;
	sprintf(qbuf,"delete from person where xuehao=%d;",a);
	mysql_query(&mysql, qbuf);
		cout<<endl;
	cout<<endl;
	cout<<"ɾ������ߺ�ĵĶ�����Ϣ"<<endl;
	cout<<"����֤��   ����   �༶  ѧ��"<<endl;
	mysql_query(&mysql, "select * from person");//��������
    res=mysql_store_result(&mysql);
	int n;n=mysql_field_count(&mysql);//��ȡ�ֶ���
	while (row = mysql_fetch_row(res))
	{
		for(int i=0;i<n;i++)
			printf("%s     ",row[i]);
		cout<<endl;
	}
		cout<<endl;
	cout<<endl;
}
void person::selectperson()//������Ϣ��ѯ
{
	mysql_init(&mysql);
	if (!(sock = mysql_real_connect(&mysql,"localhost","root","12345678","liuqihao",0,NULL,0)))
	{
		fprintf(stderr,"Couldn't connect to engine!/n%s/n/n", mysql_error(&mysql));
		perror("");
		exit(1);
	}
    sprintf(qbuf, "create database liuqihao;");
	mysql_query(&mysql, qbuf);
	sprintf(qbuf, "use liuqihao;");
	mysql_query(&mysql, qbuf);
	cout<<"������Ҫ��ѯ���ֶ�����Ҫ��ѯ������"<<endl;
	char a1[20],char b1[20];
	cin>>a1>>b1;
	sprintf(qbuf,"select * from person where %s='%s';",a1,b1);
	mysql_query(&mysql, qbuf);
		cout<<endl;
	cout<<endl;
	cout<<"��ѯ�����ݺ�ĵĶ�����Ϣ"<<endl;
	cout<<"����֤��   ����   �༶  ѧ��"<<endl;
	mysql_query(&mysql, "select * from person");//��������
    res=mysql_store_result(&mysql);
	int n;n=mysql_field_count(&mysql);//��ȡ�ֶ���
	while (row = mysql_fetch_row(res))
	{
		for(int i=0;i<n;i++)
			printf("%s     ",row[i]);
		cout<<endl;
	}
		cout<<endl;
	cout<<endl;
}
void tongji::jieyuepaihangbang()//��������
{
	mysql_init(&mysql);
	if (!(sock = mysql_real_connect(&mysql,"localhost","root","12345678","liuqihao",0,NULL,0)))
	{
		fprintf(stderr,"Couldn't connect to engine!/n%s/n/n", mysql_error(&mysql));
		perror("");
		exit(1);
	}
    sprintf(qbuf, "create database liuqihao;");
	mysql_query(&mysql, qbuf);
	sprintf(qbuf, "use liuqihao;");
	mysql_query(&mysql, qbuf);
	sprintf(qbuf,"select * from inventorybook order by yijiechubenshu desc;");
	mysql_query(&mysql, qbuf);
		cout<<endl;
	cout<<endl;
	cout<<"������Ŀ���"<<endl;
	cout<<"���   ����   ����  ������  �������� ��� ��� ��������� ��ǰ����� �ѽ������"<<endl;
	mysql_query(&mysql, "select * from inventorybook");//��������
    res=mysql_store_result(&mysql);
	int n;n=mysql_field_count(&mysql);//��ȡ�ֶ���
	while (row = mysql_fetch_row(res))
	{
		for(int i=0;i<n;i++)
			printf("%s     ",row[i]);
		cout<<endl;
	}
		cout<<endl;
	cout<<endl;
}
void tongji::ziliaozhuangtai()//����ͳ��
{
		
	mysql_init(&mysql);
	if (!(sock = mysql_real_connect(&mysql,"localhost","root","12345678","liuqihao",0,NULL,0)))
	{
		fprintf(stderr,"Couldn't connect to engine!/n%s/n/n", mysql_error(&mysql));
		perror("");
		exit(1);
	}
    sprintf(qbuf, "create database liuqihao;");
	mysql_query(&mysql, qbuf);
	sprintf(qbuf, "use liuqihao;");
	mysql_query(&mysql, qbuf);
	sprintf(qbuf,"select * from inventorybook where leibie='baokan';");
	mysql_query(&mysql, qbuf);
	cout<<"�����Ŀ���"<<endl;
	cout<<"���   ����   ����  ������  �������� ��� ��� ��������� ��ǰ����� �ѽ������"<<endl;
	mysql_query(&mysql, "select * from inventorybook");//��������
    res=mysql_store_result(&mysql);
	int n;n=mysql_field_count(&mysql);//��ȡ�ֶ���
	while (row = mysql_fetch_row(res))
	{
		for(int i=0;i<n;i++)
			printf("%s     ",row[i]);
		cout<<endl;
	}
	sprintf(qbuf,"select * from inventorybook where leibie='qikan';");
	mysql_query(&mysql, qbuf);
	cout<<"�ڿ��Ŀ���"<<endl;
	cout<<"���   ����   ����  ������  �������� ��� ��� ��������� ��ǰ����� �ѽ������"<<endl;
	mysql_query(&mysql, "select * from inventorybook");//��������
    res=mysql_store_result(&mysql);
	int n1;n1=mysql_field_count(&mysql);//��ȡ�ֶ���
	while (row = mysql_fetch_row(res))
	{
		for(int i=0;i<n1;i++)
			printf("%s     ",row[i]);
		cout<<endl;
	}	
	sprintf(qbuf,"select * from inventorybook where leibie='shuji';");
	mysql_query(&mysql, qbuf);
	cout<<"�鼮�Ŀ���"<<endl;
	cout<<"���   ����   ����  ������  �������� ��� ��� ��������� ��ǰ����� �ѽ������"<<endl;
	mysql_query(&mysql, "select * from inventorybook");//��������
    res=mysql_store_result(&mysql);
	int n2;n2=mysql_field_count(&mysql);//��ȡ�ֶ���
	while (row = mysql_fetch_row(res))
	{
		for(int i=0;i<n2;i++)
			printf("%s     ",row[i]);
		cout<<endl;
	}
}
void main()
{
		cout<<"                                 *************************************"<<endl;
		cout<<"                                 *            ͼ�����ϵͳ           *"<<endl;
		cout<<"                                 *                                   *"<<endl;
		cout<<"                                 * ϵͳ���ܣ�                        *"<<endl;
		cout<<"                                 *1.����ͼ���������ɾ���顢��     *"<<endl;
		cout<<"                                 *2.���Ĺ������顢���顢����       *"<<endl;
		cout<<"                                 *3.���߹�������ɾ����             *"<<endl;
		cout<<"                                 *4.ͳ�Ʒ����������С����ࡢͳ��     *"<<endl;
		cout<<"                                 *                                   *"<<endl;
		cout<<"                                 *                                   *"<<endl;
		cout<<"                                 *************************************"<<endl;
int f=10;
while(f)
{
	cout<<"��ѡ��Ҫ�����ģ�飺0����������1��ͼ����2���ѽ���ͼ��3��������Ϣ����4��ͳ��ģ��"<<endl;
	cin>>f;
	if(f==1)
	{
	int b=5;
while(b)
{
	inventory a1;//����һ��ͼ�����Ķ���
	cout<<"������Ҫ�Կ����Ϣ���еĲ�����0.��������1.��  2.ɾ  3.��  4.��."<<endl;
	cin>>b;
	if(b==1)
	a1.createinventorybook();//ͼ���������Ԫ�����
	else if(b==2)
	a1.deleteinventorybook();//ͼ�����ɾ��Ԫ�����
	else if(b==3)
	a1.selectinventorybook();//ͼ������ѯԪ�����
	else if(b==4)
	a1.alterinventorybook();//ͼ������޸�Ԫ�����
	else if(b==0)
		break;
}
}
if(f==2)
	{
int a;
while(a)
{
	borrow a2;//����һ���ѽ���ͼ���Ķ���
	cout<<"������Ҫ�Խ��ͼ����еĲ�����0.��������1.�����¼  2.����  3.����"<<endl;
	cin>>a;
	if(a==1)
	a2.createborrowbook();//���ļ�¼¼�����ݿ�
	else if(a==2)
	a2.returnborrowbook();//�������������ݿ�
	else if(a==3)
	a2.renewbook();//������Ϣ¼�����ݿ�
	else if(a==0)
		break;
}
}
if(f==3)
	{
int c;
while(c)
{
	person a3;//����һ�����Ķ��߱�Ķ���
	cout<<"������Ҫ�Զ�����Ϣ���еĲ�����0.��������1.����¼��  2.����ɾ��  3.���߲�ѯ"<<endl;
	cin>>c;
	if(c==1)
	a3.createperson();//������Ϣ¼��
	else if(c==2)
	a3.deleteperson();//ɾ��������Ϣ
	else if(c==3)
	a3.selectperson();//��ѯ������Ϣ
	else if(c==0)
		break;
}
}
if(f==4)
	{
int d=5;
while(d)
{
	tongji a4;//����һ��ͳ�Ʋ����Ķ���
	cout<<"������Ҫ���еĲ�����0.��������1.�������а�  2.����״̬ͳ��  3.����ͳ��"<<endl;
	cin>>d;
	if(d==1)
	a4.jieyuepaihangbang();//�������а�
	else if(d==2)
	a4.ziliaozhuangtai();//����ͳ��״̬
	else if(d==3)
	a4.jieyuepaihangbang();//����ͳ��
	else if(d==0)
		break;
}
}
else if(f==0)
break;
}
}
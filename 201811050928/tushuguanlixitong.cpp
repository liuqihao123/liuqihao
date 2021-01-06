#include <stdio.h>
#include<iostream.h>
#include <stdlib.h>
#include <winsock.h>
#include <mysql.h>
#pragma comment(lib,"libmysql.lib")
class inventory
{
public:
	MYSQL mysql,*sock;    // 定义数据库连接的句柄，它被用于几乎所有的 MySQL 函数
    MYSQL_RES *res;       // 查询结果集，结构类型
    MYSQL_FIELD *fd ;     // 包含字段信息的结构
    MYSQL_ROW row ;       // 存放一行查询结果的字符串数组
    char  qbuf[256];      // 存放查询 sql 语句字符串
	int bianhao;char shuming[20];char zuozhe[20];char chubanshe[20];
	char chubanriqi[20];int jine;char leibie[20];int zongrukushuliang;int dangqiankucunliang;
	int yijiechubenshu;//数据成员为此表的字段
	void createinventorybook();//增加操作
	void deleteinventorybook();//删除操作
	void alterinventorybook();//修改操作
	void selectinventorybook();//查询操作
};
class borrow:public inventory
{
public:
	int bianhao;char shuming[20];int jine;int jieshuzhenghao;int jieshuriqi;int daoqiriqi;
	int fakuanjine;
	void createborrowbook();//增加借书
	void returnborrowbook();//还书操作
	void renewbook();//续借操作
};
class person:public inventory
{
	public:
	int jieshuzhenghao;char xingming[20];char banji[20];char xuehao[20];
	//数据成员
	void createperson();//增加读者信息
	void deleteperson();//删除读者信息
	void selectperson();//查询读者信息
};
class tongji:public inventory
{
public:
	void jieyuepaihangbang();//借阅排行榜
	void ziliaozhuangtai();//资料状态统计
};
void inventory::createinventorybook()//库存信息增加
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
	cout<<"请输入图书的库存信息包括编号、书名、作者、出版社、出版日期、金额、类别、总入库数量、当前库存量、已借出本数"<<endl;
	cin>>bianhao>>shuming>>zuozhe>>chubanshe>>chubanriqi>>jine>>leibie>>zongrukushuliang>>\
		dangqiankucunliang>>yijiechubenshu;
	sprintf(qbuf, "insert into inventorybook values ('%d', '%s', '%s', '%s', '%s', '%d', '%s', '%d', '%d', '%d');"\
		,bianhao,shuming,zuozhe,chubanshe,chubanriqi,jine,leibie,zongrukushuliang,\
		dangqiankucunliang,yijiechubenshu);
	mysql_query(&mysql, qbuf);
	cout<<endl;
	cout<<endl;
	cout<<"编号   书名   作者  出版社  出版日期  金额  类别  总入库数量  当前库存量  已借出本数"<<endl;
	mysql_query(&mysql, "select * from inventorybook");//储存结果集
    res=mysql_store_result(&mysql);
	int n;n=mysql_field_count(&mysql);//获取字段数
	while (row = mysql_fetch_row(res))
	{
		for(int i=0;i<n;i++)
			printf("%s   ",row[i]);
		cout<<endl;
	}
	cout<<endl;
	cout<<endl;
	}
void inventory::deleteinventorybook()//库存信息删除
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
	cout<<"请输入要删除书本信息的编号:"<<endl;
	int a;
	cin>>a;
	sprintf(qbuf,"delete from inventorybook where bianhao=%d;",a);
	mysql_query(&mysql, qbuf);
	cout<<endl;
	cout<<endl;
	cout<<"删除完数据后的的书本信息"<<endl;
	cout<<"编号   书名   作者  出版社  出版日期 金额 类别 总入库数量 当前库存量 已借出本数"<<endl;
	mysql_query(&mysql, "select * from inventorybook");//储存结果集
    res=mysql_store_result(&mysql);
	int n;n=mysql_field_count(&mysql);//获取字段数
	while (row = mysql_fetch_row(res))
	{
		for(int i=0;i<n;i++)
			printf("%s   ",row[i]);
		cout<<endl;
	}
	cout<<endl;
	cout<<endl;
}
void inventory::alterinventorybook()//库存信息修改
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
	cout<<"请输入要修改书本信息的编号:"<<endl;
	int a;
	cin>>a;
	cout<<"请输入要修改的字段名及要修改的数据"<<endl;
	char a1[20],char b1[20];
	cin>>a1>>b1;
	sprintf(qbuf,"update inventorybook set %s='%s' where bianhao=%d;",a1,b1,a);
	mysql_query(&mysql, qbuf);
	cout<<endl;
	cout<<endl;
	cout<<"修改完数据后的的书本信息"<<endl;
	cout<<"编号   书名   作者  出版社  出版日期  金额  类别  总入库数量  当前库存量  已借出本数"<<endl;
	mysql_query(&mysql, "select * from inventorybook");//储存结果集
    res=mysql_store_result(&mysql);
	int n;n=mysql_field_count(&mysql);//获取字段数
	while (row = mysql_fetch_row(res))
	{
		for(int i=0;i<n;i++)
			printf("%s     ",row[i]);
		cout<<endl;
	}
	cout<<endl;
	cout<<endl;
}
void inventory::selectinventorybook()//库存信息查询
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
	cout<<"请输入要查询的字段名及要查询的数据"<<endl;
	char a1[20],char b1[20];
	cin>>a1>>b1;
	sprintf(qbuf,"select * from inventorybook where %s='%s';",a1,b1);
	mysql_query(&mysql, qbuf);
	cout<<endl;
	cout<<endl;
	cout<<"查询完数据后的的书本信息"<<endl;
	cout<<"编号   书名   作者  出版社  出版日期  金额  类别  总入库数量  当前库存量  已借出本数"<<endl;
	mysql_query(&mysql, "select * from inventorybook");//储存结果集
    res=mysql_store_result(&mysql);
	int n;n=mysql_field_count(&mysql);//获取字段数
	while (row = mysql_fetch_row(res))
	{
		for(int i=0;i<n;i++)
			printf("%s     ",row[i]);
		cout<<endl;
	}
	cout<<endl;
	cout<<endl;
}
void borrow::createborrowbook()//借阅图书增加
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
	cout<<"请输入已借出图书的库存信息包括编号、书名、金额、借书证号、借书日期、到期日期、罚款金额"<<endl;
	int bianhao;char shuming[20];int jine;int jieshuzhenghao;int jieshuriqi;int daoqiriqi;
	int fakuanjine;
	cin>>bianhao>>shuming>>jine>>jieshuzhenghao>>jieshuriqi>>daoqiriqi>>fakuanjine;
	sprintf(qbuf, "insert into borrowbook values ('%d', '%s', '%d', '%d', '%d', '%d', '%d');",bianhao,shuming,jine,jieshuzhenghao,jieshuriqi,daoqiriqi,fakuanjine);
	mysql_query(&mysql, qbuf);
	sprintf(qbuf, "select * from borrowbook;");
	mysql_query(&mysql, qbuf);
	cout<<endl;
	cout<<endl;
	cout<<"借出图书后的信息"<<endl;
	cout<<"编号   书名   金额  借书证号  借书日期  到期日期  罚款金额 "<<endl;
	mysql_query(&mysql, "select * from borrowbook");//储存结果集
    res=mysql_store_result(&mysql);
	int n;n=mysql_field_count(&mysql);//获取字段数
	while (row = mysql_fetch_row(res))
	{
		for(int i=0;i<n;i++)
			printf("%s     ",row[i]);
		cout<<endl;
	}
	cout<<endl;
	cout<<endl;
}
void borrow::returnborrowbook()//借阅图书归还
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
	cout<<"请输入要还回已借阅书本信息的编号:"<<endl;
	int a;
	cin>>a;
	sprintf(qbuf,"update inventorybook set dangqiankucunliang=dangqiankucunliang+1 where bianhao=%d;",a);
	mysql_query(&mysql, qbuf);//当前库存量加一
	sprintf(qbuf,"update inventorybook set yijiechubenshu=yijiechubenshu-1 where bianhao=%d;",a);
	mysql_query(&mysql, qbuf);//已借出数量减一
	cout<<endl;
	cout<<endl;
	cout<<"还回后的的书本库存信息";
	cout<<"编号   书名   作者  出版社  出版日期  金额  类别  总入库数量  当前库存量  已借出本数"<<endl;
	mysql_query(&mysql, "select * from inventorybook");//储存结果集
    res=mysql_store_result(&mysql);
	int n;n=mysql_field_count(&mysql);//获取字段数
	while (row = mysql_fetch_row(res))
	{
		for(int i=0;i<n;i++)
			printf("%s     ",row[i]);
		cout<<endl;
	}
	cout<<endl;
	cout<<endl;
}
void borrow::renewbook()//借阅图书续借
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
	cout<<"请输入要续借已借阅书本信息的编号:"<<endl;
	int a;
	cin>>a;
	cout<<"请输入要续借的天数："<<endl;
	int b;
	cin>>b;
	sprintf(qbuf,"update borrowbook set daoqiriqi=daoqiriqi+%d where bianhao=%d;",b,a);
	mysql_query(&mysql, qbuf);//到期日期增加
	cout<<endl;
	cout<<endl;
	cout<<"续借后的的书本借出信息"<<endl;
	cout<<"编号   书名   金额  借书证号  借书日期  到期日期  罚款金额 "<<endl;
	mysql_query(&mysql, "select * from borrowbook");//储存结果集
    res=mysql_store_result(&mysql);
	int n;n=mysql_field_count(&mysql);//获取字段数
	while (row = mysql_fetch_row(res))
	{
		for(int i=0;i<n;i++)
			printf("%s     ",row[i]);
		cout<<endl;
	}
	cout<<endl;
	cout<<endl;
}
void person::createperson()//读者信息增加
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
	cout<<"请输入借书人信息包括借书证号、姓名、班级、学号"<<endl;
	cin>>jieshuzhenghao>>xingming>>banji>>xuehao;
	sprintf(qbuf, "insert into person values ('%d', '%s', '%s', '%s');",jieshuzhenghao,xingming,banji,xuehao);
	mysql_query(&mysql, qbuf);
		cout<<endl;
	cout<<endl;
	cout<<"借书证号   姓名   班级  学号"<<endl;
	mysql_query(&mysql, "select * from person");//储存结果集
    res=mysql_store_result(&mysql);
	int n;n=mysql_field_count(&mysql);//获取字段数
	while (row = mysql_fetch_row(res))
	{
		for(int i=0;i<n;i++)
			printf("%s     ",row[i]);
		cout<<endl;
	}
		cout<<endl;
	cout<<endl;
}
void person::deleteperson()//读者信息删除
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
	cout<<"请输入要删除读者的学号:"<<endl;
	int a;
	cin>>a;
	sprintf(qbuf,"delete from person where xuehao=%d;",a);
	mysql_query(&mysql, qbuf);
		cout<<endl;
	cout<<endl;
	cout<<"删除完读者后的的读者信息"<<endl;
	cout<<"借书证号   姓名   班级  学号"<<endl;
	mysql_query(&mysql, "select * from person");//储存结果集
    res=mysql_store_result(&mysql);
	int n;n=mysql_field_count(&mysql);//获取字段数
	while (row = mysql_fetch_row(res))
	{
		for(int i=0;i<n;i++)
			printf("%s     ",row[i]);
		cout<<endl;
	}
		cout<<endl;
	cout<<endl;
}
void person::selectperson()//读者信息查询
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
	cout<<"请输入要查询的字段名及要查询的数据"<<endl;
	char a1[20],char b1[20];
	cin>>a1>>b1;
	sprintf(qbuf,"select * from person where %s='%s';",a1,b1);
	mysql_query(&mysql, qbuf);
		cout<<endl;
	cout<<endl;
	cout<<"查询完数据后的的读者信息"<<endl;
	cout<<"借书证号   姓名   班级  学号"<<endl;
	mysql_query(&mysql, "select * from person");//储存结果集
    res=mysql_store_result(&mysql);
	int n;n=mysql_field_count(&mysql);//获取字段数
	while (row = mysql_fetch_row(res))
	{
		for(int i=0;i<n;i++)
			printf("%s     ",row[i]);
		cout<<endl;
	}
		cout<<endl;
	cout<<endl;
}
void tongji::jieyuepaihangbang()//借阅排行
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
	cout<<"排序完的库存表"<<endl;
	cout<<"编号   书名   作者  出版社  出版日期 金额 类别 总入库数量 当前库存量 已借出本数"<<endl;
	mysql_query(&mysql, "select * from inventorybook");//储存结果集
    res=mysql_store_result(&mysql);
	int n;n=mysql_field_count(&mysql);//获取字段数
	while (row = mysql_fetch_row(res))
	{
		for(int i=0;i<n;i++)
			printf("%s     ",row[i]);
		cout<<endl;
	}
		cout<<endl;
	cout<<endl;
}
void tongji::ziliaozhuangtai()//资料统计
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
	cout<<"报刊的库存表"<<endl;
	cout<<"编号   书名   作者  出版社  出版日期 金额 类别 总入库数量 当前库存量 已借出本数"<<endl;
	mysql_query(&mysql, "select * from inventorybook");//储存结果集
    res=mysql_store_result(&mysql);
	int n;n=mysql_field_count(&mysql);//获取字段数
	while (row = mysql_fetch_row(res))
	{
		for(int i=0;i<n;i++)
			printf("%s     ",row[i]);
		cout<<endl;
	}
	sprintf(qbuf,"select * from inventorybook where leibie='qikan';");
	mysql_query(&mysql, qbuf);
	cout<<"期刊的库存表"<<endl;
	cout<<"编号   书名   作者  出版社  出版日期 金额 类别 总入库数量 当前库存量 已借出本数"<<endl;
	mysql_query(&mysql, "select * from inventorybook");//储存结果集
    res=mysql_store_result(&mysql);
	int n1;n1=mysql_field_count(&mysql);//获取字段数
	while (row = mysql_fetch_row(res))
	{
		for(int i=0;i<n1;i++)
			printf("%s     ",row[i]);
		cout<<endl;
	}	
	sprintf(qbuf,"select * from inventorybook where leibie='shuji';");
	mysql_query(&mysql, qbuf);
	cout<<"书籍的库存表"<<endl;
	cout<<"编号   书名   作者  出版社  出版日期 金额 类别 总入库数量 当前库存量 已借出本数"<<endl;
	mysql_query(&mysql, "select * from inventorybook");//储存结果集
    res=mysql_store_result(&mysql);
	int n2;n2=mysql_field_count(&mysql);//获取字段数
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
		cout<<"                                 *            图书管理系统           *"<<endl;
		cout<<"                                 *                                   *"<<endl;
		cout<<"                                 * 系统功能：                        *"<<endl;
		cout<<"                                 *1.借阅图书管理：增、删、查、改     *"<<endl;
		cout<<"                                 *2.借阅管理：借书、还书、续借       *"<<endl;
		cout<<"                                 *3.读者管理：增、删、查             *"<<endl;
		cout<<"                                 *4.统计分析：，排行、分类、统计     *"<<endl;
		cout<<"                                 *                                   *"<<endl;
		cout<<"                                 *                                   *"<<endl;
		cout<<"                                 *************************************"<<endl;
int f=10;
while(f)
{
	cout<<"请选择要进入的模块：0：不做操作1：图书库存2：已借阅图书3：读者信息管理4：统计模块"<<endl;
	cin>>f;
	if(f==1)
	{
	int b=5;
while(b)
{
	inventory a1;//定义一个图书库存表的对象
	cout<<"请输入要对库存信息进行的操作：0.不做操作1.增  2.删  3.查  4.改."<<endl;
	cin>>b;
	if(b==1)
	a1.createinventorybook();//图书库存表增加元组操作
	else if(b==2)
	a1.deleteinventorybook();//图书库存表删除元组操作
	else if(b==3)
	a1.selectinventorybook();//图书库存表查询元组操作
	else if(b==4)
	a1.alterinventorybook();//图书库存表修改元组操作
	else if(b==0)
		break;
}
}
if(f==2)
	{
int a;
while(a)
{
	borrow a2;//定义一个已借阅图书表的对象
	cout<<"请输入要对借出图书进行的操作：0.不做操作1.借书记录  2.还书  3.续借"<<endl;
	cin>>a;
	if(a==1)
	a2.createborrowbook();//借阅记录录入数据库
	else if(a==2)
	a2.returnborrowbook();//还回书增加数据库
	else if(a==3)
	a2.renewbook();//续借信息录入数据库
	else if(a==0)
		break;
}
}
if(f==3)
	{
int c;
while(c)
{
	person a3;//定义一个借阅读者表的对象
	cout<<"请输入要对读者信息进行的操作：0.不做操作1.读者录入  2.读者删除  3.读者查询"<<endl;
	cin>>c;
	if(c==1)
	a3.createperson();//读者信息录入
	else if(c==2)
	a3.deleteperson();//删除读者信息
	else if(c==3)
	a3.selectperson();//查询读者信息
	else if(c==0)
		break;
}
}
if(f==4)
	{
int d=5;
while(d)
{
	tongji a4;//定义一个统计操作的对象
	cout<<"请输入要进行的操作：0.不做操作1.借阅排行榜  2.资料状态统计  3.借阅统计"<<endl;
	cin>>d;
	if(d==1)
	a4.jieyuepaihangbang();//借阅排行榜
	else if(d==2)
	a4.ziliaozhuangtai();//资料统计状态
	else if(d==3)
	a4.jieyuepaihangbang();//借阅统计
	else if(d==0)
		break;
}
}
else if(f==0)
break;
}
}
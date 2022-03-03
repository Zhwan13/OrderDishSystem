#include"CGoods.h"

int CGoods::GoodsTypeCount=0;
CGoods::CGoods()
{
}


CGoods::CGoods(const CGoods &goods)//深拷贝
{
    this->GoodsType=new char[20];
    this->GoodsName=new char[10];
    this->Location=new char[15];
    this->No=goods.No;
    strcpy(this->GoodsName,goods.GoodsName);//！！！这里用strcpy();不能用=！！
    strcpy(this->GoodsType,goods.GoodsType);
    this->Price=goods.Price;
    this->GoodsCount=goods.GoodsCount;
    strcpy(this->Location,goods.Location);
}

CGoods::CGoods(char *GoodsName,char *GoodsType,int Price,char *Location)//例子初始化用 后面有时间可以考虑删掉
{
    this->No=1010+GoodsTypeCount;//商品编号
	this->GoodsName=new char[20];
	strcpy(this->GoodsName,GoodsName);
	this->Price=Price;
	this->GoodsType=new char[20];
	strcpy(this->GoodsType,GoodsType);
	this->Location=new char[15];
	strcpy(this->Location,Location);
}
/**
CGoods::CGoods(char *GoodsName,char *GoodsType,int Price,int Count)
{
    GoodsTypeCount++;//库存数量
    this->No=1010+GoodsTypeCount;//商品编号
	this->GoodsName=new char[20];
	strcpy(this->GoodsName,GoodsName);
	this->Price=Price;
	this->GoodsCount=Count;
	this->GoodsType=new char[20];
	strcpy(this->GoodsType,GoodsType);
	this->Location=this->No;
}
**/
CGoods::CGoods(int No,char *GoodsName,char *GoodsType,int Price,int Count)
{
    char *s="AX";//用于生成仓位编号
    this->No=No;//商品编号
	this->GoodsName=new char[20];
	strcpy(this->GoodsName,GoodsName);
	this->GoodsType=new char[20];
	strcpy(this->GoodsType,GoodsType);
	this->Price=Price;
	this->GoodsCount=Count;
	this->Location=new char[20];
	sprintf(this->Location,"%s%d",s,this->No);
}

CGoods::CGoods(int No,char *GoodsName,char *GoodsType,int Price,int Count,char *Location)
{
    GoodsTypeCount++;//库存数量
    this->No=No;//商品编号
	this->GoodsName=new char[20];
	strcpy(this->GoodsName,GoodsName);
	this->Price=Price;
	this->GoodsCount=Count;
	this->GoodsType=new char[20];
	strcpy(this->GoodsType,GoodsType);
	this->Location=new char[20];
	strcpy(this->Location,Location);
}
bool CGoods::operator=(const CGoods &goods)
{
    GoodsTypeCount++;//库存数量
    this->No=No;//商品编号
	this->GoodsName=new char[20];
	strcpy(this->GoodsName,goods.GoodsName);
	this->Price=goods.Price;
	this->GoodsCount=goods.GoodsCount;
	this->GoodsType=new char[20];
	strcpy(this->GoodsType,goods.GoodsType);
	this->Location=new char[20];
	strcpy(this->Location,goods.Location);
	return true;
}

CGoods::~CGoods()
{
}
int CGoods::getNo()
{
    return this->No;
}
char *CGoods::getName()
{
    return this->GoodsName;
}
char *CGoods::getType()
{
    return this->GoodsType;
}
int CGoods::getPrice()
{
    return this->Price;
}
int CGoods::getCount()
{
    return this->GoodsCount;
}
char *CGoods::getLocation()
{
    return this->Location;
}
void CGoods::setCount(int Count)
{
    this->GoodsCount=Count;
}

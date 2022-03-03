#ifndef _CGOODS_H_
#define _CGOODS_H_
#include<string.h>
#include<stdio.h>
//#include<stdlib.h>
#include<map>
#include"../core/CTool.h"
#include<iostream>
using namespace std;

//  #define TEXTNUM 20//text max long

class CGoods
{
public:
	CGoods();
	CGoods(const CGoods &goods);
	CGoods(char *GoodsName,char *GoodsType,int Price,char *Location);
	CGoods(int No,char *GoodsName,char *GoodsType,int Price,int Count);
	CGoods(int No,char *GoodsName,char *GoodsType,int Price,int Count,char *Location);
	bool operator =(const CGoods &goods);

	~CGoods();
	int getNo();
	char *getName();
	char *getType();
	int getPrice();
	int getCount();
	char *getLocation();

	void setCount(int Count);



private:
	int No;//商品编号--自动生成
	char *GoodsName;//商品名称
	char *GoodsType;//商品类型
	int Price;//商品价格
	int GoodsCount;//商品数量
	char *Location;//仓位编号--自动生成

	static int GoodsTypeCount;//商品种类数量


};


#endif

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
	int No;//��Ʒ���--�Զ�����
	char *GoodsName;//��Ʒ����
	char *GoodsType;//��Ʒ����
	int Price;//��Ʒ�۸�
	int GoodsCount;//��Ʒ����
	char *Location;//��λ���--�Զ�����

	static int GoodsTypeCount;//��Ʒ��������


};


#endif

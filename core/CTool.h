#ifndef _CTOOL_H_
#define _CTOOL_H_
#include<time.h>
#include<iostream>
#include <windows.h>
#include<windowsx.h>
#include <stdio.h>
using namespace std;
class CTool
{
public:
	static void gotoxy(int x,int y);

	static void getNowTime(char *Time);
	static void getDate(char *Date);

    static void setTemp(char *data);//设置类中静态变量temp的值，商品入库未查询到后新增界面用
    static char *temp;
    static char *role;
};


#endif

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

    static void setTemp(char *data);//�������о�̬����temp��ֵ����Ʒ���δ��ѯ��������������
    static char *temp;
    static char *role;
};


#endif

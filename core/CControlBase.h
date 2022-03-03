#ifndef _CCONTROLBASE_H_
#define _CCONTROLBASE_H_
#include <string.h>
#include"CTool.h"

#define LABEL 1
#define EDIT 2
#define PWDEDIT 3
#define ROLEEDIT 4
#define CHNEDIT 5
#define EMPTYEDIT 6//empty edit
#define BUTTON 7
#define GOODSTABLE 8//table replay goods
#define RECORDTABLE 9//table replay record
#define INFORMATION 10//´òÓ¡
#define CHECK_INFO 11

#define TEXTNUM 100//text max long

#define KEY_BACK 8
#define KEY_ESC 27
#define KEY_ENTER 13

#define KEY_LEFT 75
#define KEY_RIGHT 77

#define CHANGEFOCUS 1
#define DOACTION 2//返回button处的回车
#define CHANGEPAGE 3//翻页
/**
#define INPUT 5
#define FUNCTION 6
#define REGISTERWIN 7
#define EXIT 8
***/
class CControlBase
{
public:
    CControlBase(int x,int y,int height,int width,char text[TEXTNUM],int type);
	~CControlBase();
	virtual void show();
	friend class CWinBase;
	virtual int keyhandle(char ch)=0;

	char *getText();
	int getX();
	int getY();
	int getType();
	int getHeight();
protected:
    int x;
    int y;
    int height;
    int width;
    char text[TEXTNUM];
	int type;
};

#endif

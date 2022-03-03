#ifndef _CWINBASE_H_
#define _CWINBASE_H_
#include<string.h>
#include<stdio.h>
#include<conio.h>
#include"CControlBase.h"
#include"CButton.h"
#include"CEdit.h"
#include"CLabel.h"
#include<list>
#include<algorithm>

#include"CTable.h"

#define STARTWIN 0//开始
#define LOGINWIN 1//登录界面
#define REGISWIN 2//注册界面
#define ADMINWIN 3//仓管菜单界面
#define CHECKERWIN 4//盘点员菜单界面
#define SEARCHWIN 5//查找界面

#define INSTOCKMENUWIN 6  //入库菜单界面
#define INSTOCKWIN 7//入库界面
#define TIPSWIN 8//提示框界面
#define GOODSADDWIN 9//商品新增
#define INSTOCKRECORDWIN 10//入库记录界面

#define OUTSTOCKMENUWIN 11//出库菜单界面
#define OUTSTOCKWIN 12//出库界面
#define OUTSTOCKRECORDWIN 13//出库记录界面


#define CHECKMENUWIN 14 //盘点菜单界面
#define CHECKWINCREATE 15 //新建盘点界面
#define CHECKREPORTWIN 16 //盘点报表界面

#define CONTROLNUM 100


class CWinBase
{
public:
	CWinBase(int x,int y,int height,int width,char *text,int winNo);

	void outlinePrint();
    void show();
	void addControl(CControlBase *pctrl);

	int run(void *data);
	void changeFocus();
	virtual int doAction(void *data)=0;
	virtual void UpdateControls()=0;

	//static int role;

protected:
    int x;
    int y;
    int height;
    int width;
    char *text;
	CControlBase *controls[CONTROLNUM];
    int con_count;//控件个数
	int curControl;//当前是第几个控件

	int winNo;//用来存窗体编号

};

#endif

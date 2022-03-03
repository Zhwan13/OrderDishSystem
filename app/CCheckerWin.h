#ifndef _CCHECKERWIN_H_
#define _CCHECKERWIN_H_
#include "../core/CWinBase.h"
#include "../core/CButton.h"
#include<iostream>
using namespace std;

class CCheckerWin:public CWinBase
{
public:
    CCheckerWin(int x,int y,int height,int width,char *text,int winNo);
	~CCheckerWin();
	int doAction(void *data);
	void UpdateControls();
private:
    CLabel *WelcomeLab;
    CLabel *DateLab;
    CButton *GoodsSearch;//商品查询
	CButton *StockChecks;//仓库盘点
	CButton *exit;//退出按键

};


#endif

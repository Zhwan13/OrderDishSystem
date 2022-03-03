#ifndef _CAMDMINWIN_H_
#define _CAMDMINWIN_H_
#include "../core/CWinBase.h"
//#include"../core/CTool.h"
//#include "../core/CButton.h"

class CadminWin:public CWinBase
{
public:
	CadminWin(int x,int y,int height,int width,char *text,int winNo);
	~CadminWin();
	int doAction(void *data);
	void UpdateControls();
private:
    CLabel *WelcomeLab;
    CLabel *DateLab;
	CButton *GoodsSearch;//商品查询
	CButton *GoodsCheck;//盘点冲正
	CButton *InStock;//商品入库
	CButton *OutStock;//商品出库
	CButton *exit;//退出按键
};


#endif

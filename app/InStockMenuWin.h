#ifndef _INSTOCKMENUWIN_H_ //CGoodsInStackWin
#define _INSTOCKMENUWIN_H_
#include"../core/CButton.h"
#include"../core/CWinBase.h"
#include<iostream>
using namespace std;

class InStockMenuWin:public CWinBase
{
public:
    InStockMenuWin(int x,int y,int height,int width,char *text,int winNo);
    ~InStockMenuWin();
    int doAction(void *data);
    void UpdateControls();

private:
    CLabel *WelcomeLab;
    CLabel *DateLab;
    CButton *InStock;
	CButton *InStockRecord;
	CButton *exit;

};

#endif // _CGOODSPUTIN_H_

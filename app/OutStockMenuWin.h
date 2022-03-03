#ifndef _OUTSTOCKMENUWIN_H_
#define _OUTSTOCKMENUWIN_H_

#include"../core/CButton.h"
#include"../core/CWinBase.h"

#include<iostream>
using namespace std;

class OutStockMenuWin:public CWinBase
{
public:
    OutStockMenuWin(int x,int y,int height,int width,char *text,int winNo);
    ~OutStockMenuWin();
    int doAction(void *data);
    void UpdateControls();

private:
    CLabel *WelcomeLab;
    CLabel *DateLab;
    CButton *OutStock;
	CButton *OutStockRecord;
	CButton *exit;
};
#endif // _OUTSTOCKMENUWIN_H_

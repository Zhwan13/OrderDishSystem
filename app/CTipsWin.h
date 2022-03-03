#ifndef _CTIPSWIN_H_
#define _CTIPSWIN_H_
#include"../core/CWinBase.h"
#include"../core/CButton.h"
#include"../core/CLabel.h"
#include<iostream>
using namespace std;

class CTipsWin:public CWinBase
{
public:
    CTipsWin(int x,int y,int height,int width,char *text,int winNo);
    ~CTipsWin();
    int doAction(void *data);
    void UpdateControls();

private:
    CLabel *tips1Lab;//Ã· æ±Í«©
    CLabel *tips2Lab;
    CButton *reinputBtn;
    CButton *addBtn;
};
#endif // _CTIPSWIN_H_

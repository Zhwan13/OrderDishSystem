#ifndef _CCHECKMENUWIN_H_
#define _CCHECKMENUWIN_H_
#include"../core/CWinBase.h"
#include "../core/CLabel.h"
#include"../core/CButton.h"
#include<iostream>
using namespace std;

class CCheckMenuWin:public CWinBase
{
public:

    CCheckMenuWin(int x,int y,int height,int width,char *text,int winNo);
    ~CCheckMenuWin();
    int doAction(void *data);
    void UpdateControls();

private:
    CLabel *WelcomeLab;
    CLabel *DateLab;
    CButton *NewCheckBtn;
    CButton *CheckRecordBtn;
    CButton *ReturnBtn;

};

#endif // _CCHECKWIN_H_

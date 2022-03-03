#ifndef CLOGINWIN_H_
#define CLOGINWIN_H_

#include"../core/CButton.h"
#include"../core/CEdit.h"
#include"../core/CLabel.h"
#include"../core/CTool.h"
#include "CStaff.h"
#include"../core/CControlBase.h"
#include"../core/CWinBase.h"
#include"../core/CList.h"
#include"CadminWin.h"
#include"CCheckerWin.h"
#include<iostream>
using namespace std;

class CLoginWin:public CWinBase
{
public:
	CLoginWin(int x,int y,int height,int width,char *text,int winNo);
	~CLoginWin();
	int doAction(void *data);
	void UpdateControls();
private:
	CLabel *nameLabel;
    CLabel *pwdLabel;
    CEdit *nameEdit;
    CEdit *pwdEdit;
    CButton *LoginBtn;
    CButton *ExitBtn;
};

#endif // CLOGINWIN_H_INCLUDED

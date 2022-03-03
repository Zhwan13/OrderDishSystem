#ifndef _CREGISTERWIN_H_
#define _CREGISTERWIN_H_
#include"../core/CButton.h"
#include"../core/CEdit.h"
#include"../core/CLabel.h"
#include"../core/CTool.h"
#include"CFile.h"
#include "CStaff.h"
#include"../core/CControlBase.h"
#include"../core/CWinBase.h"
#include<list>
#include<algorithm>

class CRegisterWin:public CWinBase
{
public:
	CRegisterWin(int x,int y,int height,int width,char *text,int winNo);
	~CRegisterWin();
	int doAction(void *data);
	void UpdateControls();
private:
    CLabel *usernameLabel;
    CEdit *usernameEdit;
	CLabel *nameLabel;
    CEdit *nameEdit;
    CLabel *pwdLabel;//第一次密码
    CEdit *pwdEdit;//第一次密码
    CLabel *repwdLabel;//第二次密码标签
    CEdit *repwdEdit;//第二次密码编辑框
    CLabel *roleLabel;//注册角色标签
    CEdit *roleEdit;//注册角色编辑框
    CButton *RegisBtn;
    CButton *ExitBtn;
};


#endif

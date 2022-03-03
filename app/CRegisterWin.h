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
    CLabel *pwdLabel;//��һ������
    CEdit *pwdEdit;//��һ������
    CLabel *repwdLabel;//�ڶ��������ǩ
    CEdit *repwdEdit;//�ڶ�������༭��
    CLabel *roleLabel;//ע���ɫ��ǩ
    CEdit *roleEdit;//ע���ɫ�༭��
    CButton *RegisBtn;
    CButton *ExitBtn;
};


#endif

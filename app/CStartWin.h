#ifndef CSTARTWIN_H_
#define CSTARTWIN_H_
#include"../core/CButton.h"
#include"../core/CWinBase.h"
#include<iostream>
using namespace std;

class CStartWin:public CWinBase
{
public:
	CStartWin(int x,int y,int height,int width,char *text,int winNo);
	~CStartWin();
	int doAction(void *data);
	void UpdateControls();
private:
	CButton *Login;
	CButton *Register;
	CButton *exit;
};
#endif

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
	CButton *GoodsSearch;//��Ʒ��ѯ
	CButton *GoodsCheck;//�̵����
	CButton *InStock;//��Ʒ���
	CButton *OutStock;//��Ʒ����
	CButton *exit;//�˳�����
};


#endif

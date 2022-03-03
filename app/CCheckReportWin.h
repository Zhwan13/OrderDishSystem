#ifndef _CCHECKREPORTWIN_H_
#define _CCHECKREPORTWIN_H_
#include"../core/CWinBase.h"
#include<iostream>
using namespace std;

class CCheckReportWin:public CWinBase
{
public:
    CCheckReportWin(int x,int y,int height,int width,char *text,void *data,int winNo);
    ~CCheckReportWin();
    int doAction(void *data);
    void UpdateControls();

private:
    CLabel *WelcomeLab;
    CLabel *DateLab;
    CLabel *CheckNoLab;//�̵���
    CLabel *CheckStateLab;//�̵�״̬
    CTable *CheckReportTab;//�̵��¼���

    CLabel *GoodsNoLab;//��Ʒ���
    CLabel *GoodsNameLab;//��Ʒ����
    CLabel *StockCountLab;//�������
    CLabel *CheckCountLab;//�̵�����
    CLabel *DifferCount;//��������

    CButton *EndCheckBtn;//�����̵�
    CButton *ReturnBtn;//����

    void *data;//�洢�̵��¼������
};

#endif // _CCHECKREPORTWIN_H_

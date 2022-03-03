#ifndef _OUTSTOCKRECORDWIN_H
#define _OUTSTOCKRECORDWIN_H
#include<iostream>
#include"../core/CWinBase.h"
#include"CGoodsStockRecord.h"

using namespace std;
class OutStockRecordWin:public CWinBase
{
public:
    OutStockRecordWin(int x,int y,int height,int width,char *text,void *data,int winNo);//Ҫ�ټӸ� data-����¼�ļ�����
    ~OutStockRecordWin();
    int doAction(void *data);
    void UpdateControls();
private:
    CLabel *WelcomeLab;
    CLabel *DateLab;
    CLabel *Start;
    CLabel *End;

    CEdit *StartYear;
    CEdit *StartMon;
    CEdit *StartDay;
    CEdit *EndYear;
    CEdit *EndMon;
    CEdit *EndDay;

    CLabel *GoodsNoLab;//��Ʒ���
    CLabel *GoodsNameLab;//��Ʒ����
    CLabel *OutStockDateLab;//��������
    CLabel *OutStockNumLab;//��������
    CLabel *LocationNoLab;//��λ���
    CTable *OutStockRecTab;//�����¼��
    CButton *SearchbyDateBtn;//������ʱ���ѯ����
    CButton *returnBtn;//���ذ���

    void *data;//����ڱ��д�ӡ������
};
#endif

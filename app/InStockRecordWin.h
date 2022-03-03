#ifndef _INSTOCKRECORDWIN_H
#define _INSTOCKRECORDWIN_H
#include<iostream>
#include"../core/CWinBase.h"
#include"CGoodsStockRecord.h"

using namespace std;
class InStockRecordWin:public CWinBase
{
public:
    InStockRecordWin(int x,int y,int height,int width,char *text,void *data,int winNo);//Ҫ�ټӸ� data-����¼�ļ�����
    ~InStockRecordWin();
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
    CLabel *InStockDateLab;//�������
    CLabel *InStockNumLab;//�������
    CLabel *LocationNoLab;//��λ���
    CTable *InStockRecTab;//����¼��
    CButton *SearchbyDateBtn;//�����ʱ���ѯ
    CButton *returnBtn;//����

    void *data;//����ڱ��д�ӡ������
};
#endif

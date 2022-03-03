#ifndef _CCHECKCREATEWIN_H_
#define _CCHECKCREATEWIN_H_
#include<iostream>
#include"../core/CWinBase.h"
#include"../core/CGoodsFound.h"

using namespace std;

class CCheckCreateWin:public CWinBase
{
public:
    CCheckCreateWin(int x,int y,int height,int width,char *text,int winNo);
    ~CCheckCreateWin();
    int doAction(void *data);
    void UpdateControls();

    //char *setCheckNo();//�����̵���
private:
    CLabel *WelcomeLab;
    CLabel *DateLab;
    CLabel *CheckNoLab;//�̵���
    CLabel *NoLab;
    CEdit *NoEdt;
    CButton *SearchBtn;

    CLabel *GoodsName;//��Ʒ����
    CLabel *GoodsType;//��Ʒ����
    CLabel *GoodsPrice;//��Ʒ�۸�
    CLabel *LocationNum;//��λ���

    CLabel *CountLab;
    CEdit *CountEdt;
    CButton *EnterBtn;//ȷ����ť
    CButton *EscBtn;//ȡ����ť
    CButton *ReportBtn;//�����̵��

    CGoodsFound *Goods_Found;

    map<int,CGoods> *newGoods;//�洢��ѯ����һ��map
    int input;//��ѯ�������Ʒ���
};
#endif // _CCHECKCREATEWIN_H_

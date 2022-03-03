#ifndef _OUTSTOCKWIN_H_
#define _OUTSTOCKWIN_H_
#include"../core/CButton.h"
#include"../core/CWinBase.h"
#include"../core/CEdit.h"
#include"../core/CLabel.h"
#include"../core/CGoodsFound.h"
#include"CFile.h"
#include<conio.h>
#include<ctime>
#include<map>
#include<iostream>
using namespace std;

class OutStockWin:public CWinBase
{
public:
    OutStockWin(int x,int y,int height,int width,char *text,void *record,int winNo);
    ~OutStockWin();
    int doAction(void *data);
    void UpdateControls();

private:
    CLabel *WelcomeLab;
    CLabel *DateLab;
    CLabel *NoLab;
    CEdit *NoEdt;
    CButton *SearchBtn;

    CLabel *GoodsName;//��Ʒ����
    CLabel *GoodsType;//��Ʒ����
    CLabel *GoodsPrice;//��Ʒ�۸�
    CLabel *GoodsCount;//��Ʒ���
    CLabel *LocationNum;//��λ���

    CLabel *CountLab;
    CEdit *CountEdt;
    CButton *EnterBtn;//ȷ����ť
    CButton *EscBtn;//ȡ����ť
    CGoodsFound *Goods_Found;

    map<int,CGoods> *newGoods;//�洢��ѯ����һ��map
    int input;//����������Ʒ���

    vector<CGoodsStockRecord>*Record;//���մ�����������¼�ļ�

};
#endif // _INSTOCKWIN_H_

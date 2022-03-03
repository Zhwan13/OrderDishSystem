#ifndef _INSTOCKWIN_H_
#define _INSTOCKWIN_H_
#include"../core/CButton.h"
#include"../core/CWinBase.h"
#include"../core/CEdit.h"
#include"../core/CLabel.h"
#include"../core/CGoodsFound.h"
#include"InStockRecordWin.h"
#include"CGoodsAddWin.h"
#include"CFile.h"
#include<conio.h>
#include<vector>

#include<time.h>
#include<iostream>
using namespace std;

class InStockWin:public CWinBase
{
public:

    InStockWin(int x,int y,int height,int width,char *text,void *record,int winNo);
    ~InStockWin();
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

    CLabel *CountLab;//�������ݱ�ǩ
    CEdit *CountEdt;//
    CButton *EnterBtn;//ȷ����ť
    CButton *EscBtn;//ȡ����ť
    CGoodsFound *Goods_Found;

    map<int,CGoods> *newGoods;//�洢��ѯ����һ��map
    int input;//����ѯ�������Ʒ���

    vector<CGoodsStockRecord>*Record;//���մ�����������¼�ļ�

};
#endif // _INSTOCKWIN_H_

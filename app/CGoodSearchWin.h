#ifndef _CGOODSEARCH_H_
#define _CGOODSEARCH_H_
#include"../core/CButton.h"
#include"../core/CWinBase.h"
#include"../core/CTable.h"
#include"CGoods.h"
#include<map>
#include<algorithm>
#include<conio.h>
#include<iostream>
using namespace std;

class CGoodSearchWin:public CWinBase
{
public:
    CGoodSearchWin(int x,int y,int height,int width,char *text,void *data,int winNo);
    ~CGoodSearchWin();
    int doAction(void *data);
    void UpdateControls();

private:
    CLabel *WelcomeLab;
    CLabel *DateLab;
    CLabel *InputNum;//������
    CEdit *ComInput;//��ѯ�����
    CLabel *GoodsNum;//��Ʒ���
    CLabel *GoodsName;//��Ʒ����
    CLabel *GoodsType;//��Ʒ����
    CLabel *GoodsPrice;//��Ʒ�۸�
    CLabel *GoodsCount;//��Ʒ���
    CLabel *LocationNum;//��λ���
    CLabel *UpDownPage;

    CButton *SearchBtn;
    CButton *ExportBtn;
    CButton *ExitBtn;

    void *data;//������Ʒdata
    CTable *Table;//���Ǵ�ָ���Ƿ���Ҫ����
    int curPage;


};
#endif // _CGOODSEARCH_H_


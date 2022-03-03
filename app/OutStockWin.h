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

    CLabel *GoodsName;//商品名称
    CLabel *GoodsType;//商品类型
    CLabel *GoodsPrice;//商品价格
    CLabel *GoodsCount;//商品库存
    CLabel *LocationNum;//仓位编号

    CLabel *CountLab;
    CEdit *CountEdt;
    CButton *EnterBtn;//确定按钮
    CButton *EscBtn;//取消按钮
    CGoodsFound *Goods_Found;

    map<int,CGoods> *newGoods;//存储查询到的一个map
    int input;//入库输入的商品编号

    vector<CGoodsStockRecord>*Record;//接收传进来的入库记录文件

};
#endif // _INSTOCKWIN_H_

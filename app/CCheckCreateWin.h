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

    //char *setCheckNo();//生成盘点编号
private:
    CLabel *WelcomeLab;
    CLabel *DateLab;
    CLabel *CheckNoLab;//盘点编号
    CLabel *NoLab;
    CEdit *NoEdt;
    CButton *SearchBtn;

    CLabel *GoodsName;//商品名称
    CLabel *GoodsType;//商品类型
    CLabel *GoodsPrice;//商品价格
    CLabel *LocationNum;//仓位编号

    CLabel *CountLab;
    CEdit *CountEdt;
    CButton *EnterBtn;//确定按钮
    CButton *EscBtn;//取消按钮
    CButton *ReportBtn;//生成盘点表

    CGoodsFound *Goods_Found;

    map<int,CGoods> *newGoods;//存储查询到的一个map
    int input;//查询输入的商品编号
};
#endif // _CCHECKCREATEWIN_H_

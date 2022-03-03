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
    CLabel *CheckNoLab;//盘点编号
    CLabel *CheckStateLab;//盘点状态
    CTable *CheckReportTab;//盘点记录表格

    CLabel *GoodsNoLab;//商品编号
    CLabel *GoodsNameLab;//商品名称
    CLabel *StockCountLab;//库存数量
    CLabel *CheckCountLab;//盘点数量
    CLabel *DifferCount;//差异数量

    CButton *EndCheckBtn;//结束盘点
    CButton *ReturnBtn;//返回

    void *data;//存储盘点记录的容器
};

#endif // _CCHECKREPORTWIN_H_

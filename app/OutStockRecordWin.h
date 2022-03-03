#ifndef _OUTSTOCKRECORDWIN_H
#define _OUTSTOCKRECORDWIN_H
#include<iostream>
#include"../core/CWinBase.h"
#include"CGoodsStockRecord.h"

using namespace std;
class OutStockRecordWin:public CWinBase
{
public:
    OutStockRecordWin(int x,int y,int height,int width,char *text,void *data,int winNo);//要再加个 data-入库记录文件数据
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

    CLabel *GoodsNoLab;//商品编号
    CLabel *GoodsNameLab;//商品名称
    CLabel *OutStockDateLab;//出库日期
    CLabel *OutStockNumLab;//出库数量
    CLabel *LocationNoLab;//仓位编号
    CTable *OutStockRecTab;//出库记录表
    CButton *SearchbyDateBtn;//按出库时间查询按键
    CButton *returnBtn;//返回按键

    void *data;//存放在表中打印的数据
};
#endif

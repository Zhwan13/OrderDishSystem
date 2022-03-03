#ifndef _INSTOCKRECORDWIN_H
#define _INSTOCKRECORDWIN_H
#include<iostream>
#include"../core/CWinBase.h"
#include"CGoodsStockRecord.h"

using namespace std;
class InStockRecordWin:public CWinBase
{
public:
    InStockRecordWin(int x,int y,int height,int width,char *text,void *data,int winNo);//要再加个 data-入库记录文件数据
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

    CLabel *GoodsNoLab;//商品编号
    CLabel *GoodsNameLab;//商品名称
    CLabel *InStockDateLab;//入库日期
    CLabel *InStockNumLab;//入库数量
    CLabel *LocationNoLab;//仓位编号
    CTable *InStockRecTab;//入库记录表
    CButton *SearchbyDateBtn;//按入库时间查询
    CButton *returnBtn;//返回

    void *data;//存放在表中打印的数据
};
#endif

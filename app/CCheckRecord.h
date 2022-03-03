#ifndef _CCHECKRECORD_H_
#define _CCHECKRECORD_H_

class CCheckRecord
{
public:
    CCheckRecord();
    ~CCheckRecord();


private:
    CLabel *GoodsNoLab;//商品编号
    CLabel *GoodsNameLab;//商品名称
    CLabel *StockCountLab;//库存数量
    CLabel *CheckCountLab;//盘点数量
    CLabel *DifferCount;//差异数量
};

#endif // _CCHECKRECORD_H_


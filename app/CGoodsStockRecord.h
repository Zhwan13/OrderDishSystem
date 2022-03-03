#ifndef _INSTOCKRECORD_H_
#define _INSTOCKRECORD_H_
#include<iostream>
#include<string.h>

using namespace std;
class CGoodsStockRecord
{
public:
    CGoodsStockRecord();
    CGoodsStockRecord(int GoodsNo,char *GoodsName,int InStockDate,int InStockCount,char *GoodsLocation);
    CGoodsStockRecord(const CGoodsStockRecord &record);
    ~CGoodsStockRecord();

    int getNo();
    char *getName();
    int getDate();
    int getCount();
    char *getLocation();

private:
    int GoodsNo;
    char *GoodsName;
    int InStockDate;//�������
    int InStockCount;//�������
    char *GoodsLocation;//��λ���
};

#endif // _INSTOCKRECORD_H_

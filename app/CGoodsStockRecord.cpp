#include"CGoodsStockRecord.h"
CGoodsStockRecord::CGoodsStockRecord()
{
}

CGoodsStockRecord::CGoodsStockRecord(int GoodsNo,char *GoodsName,int InStockDate,int InStockCount,char *GoodsLocation)
{
    this->GoodsName=new char[20];
    this->GoodsLocation=new char[10];

    this->GoodsNo=GoodsNo;
    strcpy(this->GoodsName,GoodsName);
    this->InStockDate=InStockDate;
    this->InStockCount=InStockCount;
    strcpy(this->GoodsLocation,GoodsLocation);
}

CGoodsStockRecord::CGoodsStockRecord(const CGoodsStockRecord &record)
{
    this->GoodsName=new char[20];
    this->GoodsLocation=new char[10];
    this->GoodsNo=record.GoodsNo;
    strcpy(this->GoodsName,record.GoodsName);
    this->InStockDate=record.InStockDate;
    this->InStockCount=record.InStockCount;
    strcpy(this->GoodsLocation,record.GoodsLocation);
}
CGoodsStockRecord::~CGoodsStockRecord()
{
}
int CGoodsStockRecord::getNo()
{
    return this->GoodsNo;
}
char *CGoodsStockRecord::getName()
{
    return this->GoodsName;
}
int CGoodsStockRecord::getDate()
{
    return this->InStockDate;
}
int CGoodsStockRecord::getCount()
{
    return this->InStockCount;
}
char *CGoodsStockRecord::getLocation()
{
    return this->GoodsLocation;
}

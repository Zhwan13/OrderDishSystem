#ifndef _CTABLE_H_
#define _CTABLE_H_
#include"CTool.h"
#include"../app/CGoods.h"
#include"../app/InStockRecord.h"
#include"../app/CGoodsStockRecord.h"
#include"CControlBase.h"
#include"CWinBase.h"
#include<list>
#include<vector>
#include<map>
#include<algorithm>
#include<iostream>
using namespace std;

class CTable:public CControlBase
{
public:
    CTable(int x,int y,int height,int width,void *data,int type);
    void setData(void *data);
    void show();
    void show_tabledata(void *data);
    void show_recordtabledata(void *data);
    int keyhandle(char ch);
private:
    int x;
    int y;
    int height;
    int width;

    //int showcount;//一页打印的数据条数
    int index;//打印索引
    int curPage;//当前打印数据页面
    int pageNum;//商品类的页数
    int NumPerPage;//每页打印数据条数=3

    void *data;//用来存储商品数据
};

#endif // _CTABLE_H_

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

    //int showcount;//һҳ��ӡ����������
    int index;//��ӡ����
    int curPage;//��ǰ��ӡ����ҳ��
    int pageNum;//��Ʒ���ҳ��
    int NumPerPage;//ÿҳ��ӡ��������=3

    void *data;//�����洢��Ʒ����
};

#endif // _CTABLE_H_

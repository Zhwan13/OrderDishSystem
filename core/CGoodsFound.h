#ifndef _CGOODSFOUND_H_
#define _CGOODSFOUND_H_
#include<iostream>
#include"CControlBase.h"
#include"../app/CGoods.h"
#include<map>
#include<algorithm>


using namespace std;

class CGoodsFound:public CControlBase//用来打印商品信息的控件
{
public:
    CGoodsFound(int x,int y,int height,int width,void *data,int type=INFORMATION);
    ~CGoodsFound();
    void setnewGoods(map<int,CGoods> *data);
    void show();
    int keyhandle(char ch);
    void showdata(map<int,CGoods> *data);
private:
    map<int,CGoods> *newGoods;//用来存除查询功能外外查询到的要打印的信息

};
#endif // GOODS_FOUND

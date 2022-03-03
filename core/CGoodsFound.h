#ifndef _CGOODSFOUND_H_
#define _CGOODSFOUND_H_
#include<iostream>
#include"CControlBase.h"
#include"../app/CGoods.h"
#include<map>
#include<algorithm>


using namespace std;

class CGoodsFound:public CControlBase//������ӡ��Ʒ��Ϣ�Ŀؼ�
{
public:
    CGoodsFound(int x,int y,int height,int width,void *data,int type=INFORMATION);
    ~CGoodsFound();
    void setnewGoods(map<int,CGoods> *data);
    void show();
    int keyhandle(char ch);
    void showdata(map<int,CGoods> *data);
private:
    map<int,CGoods> *newGoods;//���������ѯ���������ѯ����Ҫ��ӡ����Ϣ

};
#endif // GOODS_FOUND

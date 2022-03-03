#ifndef _CGOODSEARCH_H_
#define _CGOODSEARCH_H_
#include"../core/CButton.h"
#include"../core/CWinBase.h"
#include"../core/CTable.h"
#include"CGoods.h"
#include<map>
#include<algorithm>
#include<conio.h>
#include<iostream>
using namespace std;

class CGoodSearchWin:public CWinBase
{
public:
    CGoodSearchWin(int x,int y,int height,int width,char *text,void *data,int winNo);
    ~CGoodSearchWin();
    int doAction(void *data);
    void UpdateControls();

private:
    CLabel *WelcomeLab;
    CLabel *DateLab;
    CLabel *InputNum;//输入编号
    CEdit *ComInput;//查询输入框
    CLabel *GoodsNum;//商品编号
    CLabel *GoodsName;//商品名称
    CLabel *GoodsType;//商品类型
    CLabel *GoodsPrice;//商品价格
    CLabel *GoodsCount;//商品库存
    CLabel *LocationNum;//仓位编号
    CLabel *UpDownPage;

    CButton *SearchBtn;
    CButton *ExportBtn;
    CButton *ExitBtn;

    void *data;//接收商品data
    CTable *Table;//考虑此指针是否需要定义
    int curPage;


};
#endif // _CGOODSEARCH_H_


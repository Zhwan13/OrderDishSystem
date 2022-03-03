#ifndef _GOODSADDWIN_H_
#define _GOODSADDWIN_H_
#include <iostream>
#include<map>
//#include<algorithm>
#include "../core/CWinBase.h"
#include"../core/CLabel.h"
#include"../core/CEdit.h"
#include"CFile.h"

using namespace std;
class CGoodsAddWin:public CWinBase
{
public:
    CGoodsAddWin(int x,int y,int height,int width,char *text,int winNo);
    ~CGoodsAddWin();
    int doAction(void *data);
    void UpdateControls();

private:

    CLabel *WelcomeLab;
    CLabel *DateLab;
    CLabel *GoodsNoLab;//��Ʒ��ű�ǩ
    CLabel *GoodsNo;
    CLabel *GoodsNameLab;
    CEdit *GoodsNameEdt;
    CLabel *GoodsTypeLab;
    CEdit *GoodsTypeEdt;
    CLabel *GoodsPriceLab;
    CEdit *GoodsPriceEdt;
    CLabel *GoodsPositionLab;//��λ��ű�ǩ
    CEdit *GoodsPositionEdt;
    CButton *Enter;
    CButton *Esc;
};

#endif // _GOODSADDWIN_H_

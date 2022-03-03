#include"CTipsWin.h"

/******************************
*函数名 CTipsWin()
*函数功能：窗体界面构造函数，对窗体的控件进行初始化
*输入 窗体的坐标和宽度、高度、窗体名字
*输出 无
************************************/
CTipsWin::CTipsWin(int x,int y,int height,int width,char *text,int winNo)
:CWinBase(x,y,height,width,text,winNo)
{
    this->tips1Lab=new CLabel(this->x+3,this->y+1,2,16,"提示:");
    this->tips2Lab=new CLabel(this->x+2,this->y+3,2,16,"未找到对应的商品");
    this->reinputBtn=new CButton(this->x+6,this->y+6,2,10,"重新输入");
    this->addBtn=new CButton(this->x+6,this->y+10,2,10,"新增商品");

    this->addControl(this->tips1Lab);
    this->addControl(this->tips2Lab);
    this->addControl(this->reinputBtn);
    this->addControl(this->addBtn);
}

CTipsWin::~CTipsWin()
{
   // delete

}

/******************************
*函数名 doAction()
*函数功能：对按键处理结果进行响应
*输入 所需数据，如商品信息，员工信息，出入库信息
*返回 界面号
************************************/
int CTipsWin::doAction(void *data)
{
    if(strcmp(this->controls[this->curControl]->getText(),"重新输入")==0)
    {
        return INSTOCKWIN;
    }
    else if(strcmp(this->controls[this->curControl]->getText(),"新增商品")==0)
        return GOODSADDWIN;
}

/******************************
*函数名 UpdateControls()
*函数功能：提示界面不需要，只是为了实现基类的纯虚函数才写的
*输入 无
*输出 无
************************************/
void CTipsWin::UpdateControls()
{

}

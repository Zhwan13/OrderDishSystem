#include"CadminWin.h"
#include<iostream>
using namespace std;


/******************************
*函数名 CadminWin()
*函数功能：登录窗体界面构造函数，对窗体界面的控件进行初始化
*输入 窗体界面的坐标和宽度、高度、窗体名字
*输出 无
************************************/

CadminWin::CadminWin(int x,int y,int height,int width,char *text,int winNo)
:CWinBase(x,y,height,width,text,winNo)
{
    this->WelcomeLab=new CLabel(this->x+6,this->y+3,2,6,"欢迎:");
    this->DateLab=new CLabel(this->x+this->width-16,this->y+3,2,6,"日期:");
	this->GoodsSearch=new CButton((this->width)/4+this->x,this->y+5,2,8,"商品查询");
	this->GoodsCheck=new CButton((this->width)*3/4+this->x,this->y+5,2,8,"盘点冲正");
	this->InStock=new CButton((this->width)/4+this->x,this->y+9,2,8,"商品入库");
	this->OutStock=new CButton((this->width)*3/4+this->x,this->y+9,2,8,"商品出库");
	this->exit=new CButton((this->width)/4+this->x,this->y+13,2,8,"退出程序");

	this->addControl(this->WelcomeLab);
	this->addControl(this->DateLab);
	this->addControl(this->GoodsSearch);
	this->addControl(this->GoodsCheck);
	this->addControl(this->InStock);
	this->addControl(this->OutStock);
	this->addControl(this->exit);
}
CadminWin::~CadminWin()
{

}

/******************************
*函数名 doAction
*函数功能：在仓库管理员的窗体界面对相应按键进行响应
*输入 void *data
*输出 对应的窗体界面宏定义的号数 0~16
************************************/

int CadminWin::doAction(void *data)
{
    if(strcmp(this->controls[this->curControl]->getText(),"商品查询")==0)
    {
        return SEARCHWIN;
    }
    else if(strcmp(this->controls[this->curControl]->getText(),"盘点冲正")==0)
    {
        return CHECKMENUWIN;
    }
    else if(strcmp(this->controls[this->curControl]->getText(),"商品入库")==0)
    {
        return INSTOCKMENUWIN;//INSTOCKMENUWIN 入库菜单界面
    }
    else if(strcmp(this->controls[this->curControl]->getText(),"商品出库")==0)
    {
        return OUTSTOCKMENUWIN;
    }
    else if(strcmp(this->controls[this->curControl]->getText(),"退出程序")==0)
    {
        return STARTWIN;//开始界面
    }
    return STARTWIN;
}

/******************************
*函数名 UpdateControls()
*函数功能：更新窗体控件，主要是登录者的身份和当前日期
*输入 无
*输出 无
************************************/
void CadminWin::UpdateControls()
{
    char *Date=new char[20];
    CTool::getDate(Date);
    char newLab[25]={0};
    sprintf(newLab,"日期:%s",Date);
    this->DateLab->setLab(newLab);
    if (strcmp(CTool::role,"1")==0)
    {
        this->WelcomeLab->setLab("欢迎:仓库管理员");
    }
    else
    {
        this->WelcomeLab->setLab("欢迎:盘点员");
    }
    delete Date;
    return ;
}

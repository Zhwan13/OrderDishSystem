#include"InStockMenuWin.h"


/******************************
*函数名 InStockMenuWin()
*函数功能：窗体界面构造函数，对窗体的控件进行初始化
*输入 窗体的坐标和宽度、高度、窗体名字
*输出 无
************************************/
InStockMenuWin::InStockMenuWin(int x,int y,int height,int width,char *text,int winNo)
:CWinBase(x,y,height,width,text,winNo)
{
    this->WelcomeLab=new CLabel(this->x+6,this->y+3,2,6,"欢迎:");
    this->DateLab=new CLabel(this->x+this->width-16,this->y+3,2,6,"日期:");
    this->InStock=new CButton((this->width)/2+this->x-1,this->y+4,2,6,"入库");
    this->InStockRecord=new CButton((this->width)/2+this->x-1,this->y+8,2,8,"入库记录");
    this->exit=new CButton((this->width)/2+this->x-1,this->y+12,2,6,"返回");

    this->addControl(this->WelcomeLab);
	this->addControl(this->DateLab);
    this->addControl(this->InStock);
    this->addControl(this->InStockRecord);
    this->addControl(this->exit);
}

InStockMenuWin::~InStockMenuWin()
{
    delete this->InStock;
    delete this->InStockRecord;
    delete this->exit;
}

/******************************
*函数名 doAction()
*函数功能：对按键处理结果进行响应
*输入 所需数据，如商品信息，员工信息，出入库信息
*返回 界面号
************************************/
int InStockMenuWin::doAction(void *daata)
{
    if(strcmp(this->controls[this->curControl]->getText(),"入库")==0)
    {
        return INSTOCKWIN;//入库界面
    }
    else if(strcmp(this->controls[this->curControl]->getText(),"入库记录")==0)
    {
        return INSTOCKRECORDWIN;//入库记录界面
    }
    else if(strcmp(this->controls[this->curControl]->getText(),"返回")==0)
    {
        return ADMINWIN;
    }
}

/******************************
*函数名 UpdateControls()
*函数功能：更新窗体控件，主要是登录者的身份和当前日期
*输入 无
*输出 无
************************************/
void InStockMenuWin::UpdateControls()
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

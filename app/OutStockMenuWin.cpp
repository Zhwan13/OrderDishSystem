#include"OutStockMenuWin.h"


/******************************
*函数名 OutStockMenuWin()
*函数功能：窗体界面构造函数，对窗体的控件进行初始化
*输入 窗体的坐标和宽度、高度、窗体名字
*输出 无
************************************/
OutStockMenuWin::OutStockMenuWin(int x,int y,int height,int width,char *text,int winNo)
:CWinBase(x,y,height,width,text,winNo)
{
    this->WelcomeLab=new CLabel(this->x+6,this->y+3,2,6,"欢迎:");
    this->DateLab=new CLabel(this->x+this->width-20,this->y+3,2,6,"日期:");
    this->OutStock=new CButton((this->width)/2+this->x-1,this->y+4,2,4,"出库");
    this->OutStockRecord=new CButton((this->width)/2+this->x-1,this->y+8,2,8,"出库记录");
    this->exit=new CButton((this->width)/2+this->x-1,this->y+12,2,4,"返回");

    this->addControl(this->WelcomeLab);
    this->addControl(this->DateLab);
    this->addControl(this->OutStock);
    this->addControl(this->OutStockRecord);
    this->addControl(this->exit);
}

OutStockMenuWin::~OutStockMenuWin()
{
    delete this->OutStock;
    delete this->OutStockRecord;
    delete this->exit;
}

/******************************
*函数名 doAction()
*函数功能：对按键处理结果进行响应
*输入 所需数据，如商品信息，员工信息，出入库信息
*返回 界面号
************************************/
int OutStockMenuWin::doAction(void *daata)
{
    if(strcmp(this->controls[this->curControl]->getText(),"出库")==0)
    {
        return OUTSTOCKWIN;//入库界面INSTOCKWIN
    }
    else if(strcmp(this->controls[this->curControl]->getText(),"出库记录")==0)
    {
        return OUTSTOCKRECORDWIN;//入库记录界面
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
void OutStockMenuWin::UpdateControls()
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



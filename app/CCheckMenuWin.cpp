#include"CCheckMenuWin.h"


/******************************
*函数名 CCheckMenuWin()
*函数功能：窗体界面构造函数，对窗体的控件进行初始化
*输入 窗体的坐标和宽度、高度、窗体名字
*输出 无
************************************/
CCheckMenuWin::CCheckMenuWin(int x,int y,int height,int width,char *text,int winNo)
:CWinBase(x,y,height,width,text,winNo)
{
    this->WelcomeLab=new CLabel(this->x+6,this->y+3,2,6,"欢迎:");
    this->DateLab=new CLabel(this->x+this->width-20,this->y+3,2,6,"日期:");
    this->NewCheckBtn=new CButton(this->x+8,this->y+6,2,8,"新建盘点");
    this->CheckRecordBtn=new CButton(this->x+this->width-18,this->y+6,2,8,"盘点记录");
    this->ReturnBtn=new CButton(this->x+8,this->y+10,2,4,"返回");

    this->addControl(this->WelcomeLab);
    this->addControl(this->DateLab);
    this->addControl(this->NewCheckBtn);
    this->addControl(this->CheckRecordBtn);
    this->addControl(this->ReturnBtn);
}
/******************************
*函数名 doAction()
*函数功能：对按键处理结果进行响应
*输入 所需数据，如商品信息，员工信息，出入库信息
*返回 界面号
************************************/
int CCheckMenuWin::doAction(void *data)
{
    if(strcmp(this->controls[this->curControl]->getText(),"新建盘点")==0)
    {
        return CHECKWINCREATE;
    }
    else if(strcmp(this->controls[this->curControl]->getText(),"盘点记录")==0)
    {
        return CHECKREPORTWIN;
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
void CCheckMenuWin::UpdateControls()
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



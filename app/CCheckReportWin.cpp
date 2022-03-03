#include "CCheckReportWin.h"


/******************************
*函数名 CCheckReportWin()
*函数功能：窗体界面构造函数，对窗体的控件进行初始化
*输入 窗体的坐标和宽度、高度、窗体名字
*输出 无
************************************/
CCheckReportWin::CCheckReportWin(int x,int y,int height,int width,char *text,void *data,int winNo)
:CWinBase(x,y,height,width,text,winNo)
{
    this->data=data;
    this->WelcomeLab=new CLabel(this->x+6,this->y+4,2,6,"欢迎:");
    this->DateLab=new CLabel(this->x+this->width-20,this->y+4,2,6,"日期:");
    this->CheckNoLab=new CLabel(this->x+5,this->y+6,2,6,"盘点编号:");
    this->CheckStateLab=new CLabel(this->x+this->width-15,this->y+6,2,6,"盘点状态:");
    this->CheckReportTab=new CTable(this->x+2,this->y+8,8,58,this->data,RECORDTABLE);//盘点记录表格

    this->GoodsNoLab=new CLabel(this->x+3,this->y+9,2,6,"商品编号");
    this->GoodsNameLab=new CLabel(this->x+15,this->y+9,2,6,"商品名称");
    this->StockCountLab=new CLabel(this->x+27,this->y+9,2,6,"库存数量");
    this->CheckCountLab=new CLabel(this->x+49,this->y+9,2,6,"盘点数量");
    this->DifferCount=new CLabel(this->x+51,this->y+9,2,6,"差异数量");

    this->EndCheckBtn=new CButton(this->x+4,this->y+18,2,8,"结束盘点");
    this->ReturnBtn=new CButton(this->x+16,this->y+18,2,4,"返回");

    this->addControl(this->WelcomeLab);
    this->addControl(this->DateLab);
    this->addControl(this->CheckNoLab);
    this->addControl(this->CheckStateLab);
    this->addControl(this->CheckReportTab);
    this->addControl(this->GoodsNoLab);
    this->addControl(this->GoodsNameLab);
    this->addControl(this->StockCountLab);
    this->addControl(this->CheckCountLab);
    this->addControl(this->DifferCount);
    this->addControl(this->EndCheckBtn);
    this->addControl(this->ReturnBtn);
}
CCheckReportWin::~CCheckReportWin()
{
    delete this->WelcomeLab;
    delete this->DateLab;
    delete this->CheckNoLab;
    delete this->CheckStateLab;
    delete this->CheckReportTab;
    delete this->GoodsNoLab;
    delete this->GoodsNameLab;
    delete this->StockCountLab;
    delete this->CheckCountLab;
    delete this->DifferCount;
    delete this->EndCheckBtn;
    delete this->ReturnBtn;
}

/******************************
*函数名 doAction()
*函数功能：对按键处理结果进行响应
*输入 所需数据，如商品信息，员工信息，出入库信息
*返回 界面号
************************************/
int CCheckReportWin::doAction(void *data)
{
    if(strcmp(this->controls[this->curControl]->getText(),"结束盘点")==0)//返回盘点菜单界面，盘点记录不能再新增商品盘点记录
    {
        return CHECKMENUWIN;
    }

    else if(strcmp(this->controls[this->curControl]->getText(),"返回")==0)//返回盘点界面
    {
        return CHECKREPORTWIN;
    }
}

/******************************
*函数名 UpdateControls()
*函数功能：更新窗体控件，主要是登录者的身份和当前日期
*输入 无
*输出 无
************************************/
void CCheckReportWin::UpdateControls()
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

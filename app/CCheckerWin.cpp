#include"CCheckerWin.h"


/******************************
*函数名 CCheckerWin()
*函数功能：窗体界面构造函数，对窗体的控件进行初始化
*输入 窗体的坐标和宽度、高度、窗体名字
*输出 无
************************************/
CCheckerWin::CCheckerWin(int x,int y,int height,int width,char *text,int winNo)
:CWinBase(x,y,height,width,text,winNo)
{
     this->WelcomeLab=new CLabel(this->x+6,this->y+3,2,6,"欢迎:");
    this->DateLab=new CLabel(this->x+this->width-16,this->y+3,2,6,"日期:");
    this->GoodsSearch=new CButton((this->width)/5+this->x,this->y+4,2,8,"商品查询");
	this->StockChecks=new CButton((this->width)*3/5+this->x,this->y+4,2,8,"仓库盘点");
	this->exit=new CButton((this->width)/5+this->x,this->y+8,2,8,"退出程序");

	this->addControl(this->WelcomeLab);
	this->addControl(this->DateLab);
	this->addControl(this->GoodsSearch);
	this->addControl(this->StockChecks);
	this->addControl(this->exit);
}

CCheckerWin::~CCheckerWin()
{

}

/******************************
*函数名 doAction()
*函数功能：对按键处理结果进行响应
*输入 所需数据，如商品信息，员工信息，出入库信息
*返回 界面号
************************************/
int CCheckerWin::doAction(void *data)
{
    if(strcmp(this->controls[this->curControl]->getText(),"商品查询")==0)
        return SEARCHWIN;
    if(strcmp(this->controls[this->curControl]->getText(),"仓库盘点")==0)
        return CHECKMENUWIN;//盘点菜单界面
    else if(strcmp(this->controls[this->curControl]->getText(),"退出程序")==0)
        return 0;//返回开始界面
}

/******************************
*函数名 UpdateControls()
*函数功能：更新窗体控件，主要是登录者的身份和当前日期
*输入 无
*输出 无
************************************/
void CCheckerWin::UpdateControls()
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

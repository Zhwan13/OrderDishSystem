#include"CStartWin.h"



/******************************
*函数名 CStartWin()
*函数功能：窗体界面构造函数，对窗体的控件进行初始化
*输入 窗体的坐标和宽度、高度、窗体名字
*输出 无
************************************/
CStartWin::CStartWin(int x,int y,int height,int width,char *text,int winNo)
:CWinBase(x,y,height,width,text,winNo)
{
    this->Login=new CButton((this->width)/2+this->x-1,this->y+4,2,4,"登录");
    this->Register=new CButton((this->width)/2+this->x-1,this->y+8,2,4,"注册");
    this->exit=new CButton((this->width)/2+this->x-1,this->y+12,2,4,"退出");

    this->addControl(this->Login);
    this->addControl(this->Register);
    this->addControl(this->exit);
}

CStartWin::~CStartWin()
{
    delete this->Login;
    delete this->Register;
    delete this->exit;
}
/******************************
*函数名 doAction()
*函数功能：对按键处理结果进行响应
*输入 所需数据，如商品信息，员工信息，出入库信息
*返回 界面号
************************************/
int CStartWin::doAction(void *data)
{
    //接受flag 返回界面
    if(strcmp(this->controls[this->curControl]->getText(),"登录")==0)
    {
        return LOGINWIN;
    }
    else if (strcmp(this->controls[this->curControl]->getText(),"注册")==0)
    {
        return REGISWIN;
    }
    else if (strcmp(this->controls[this->curControl]->getText(),"退出")==0)
    {
        return -1;
    }
    return STARTWIN;
}
/******************************
*函数名 UpdateControls()
*函数功能：开始界面不需要，只是为了实现基类的纯虚函数才写的
*输入 无
*输出 无
************************************/
void CStartWin::UpdateControls()
{

}

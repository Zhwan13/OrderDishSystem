#include"CLoginWin.h"
#include<stdio.h>


/******************************
*函数名 CLoginWin()
*函数功能：窗体界面构造函数，对窗体的控件进行初始化
*输入 窗体的坐标和宽度、高度、窗体名字
*输出 无
************************************/
CLoginWin::CLoginWin(int x,int y,int height,int width,char *text,int winNo)
:CWinBase(x,y,height,width,text,winNo)
{
    this->nameLabel=new CLabel((this->width)/5+this->x,this->y+4,2,4,"ID:");//(12,6,2,5,"name:");
    this->nameEdit=new CEdit((this->width)/5+this->x+8,this->y+4,2,10,"",EDIT);
    this->pwdLabel=new CLabel((this->width)/5+this->x,this->y+8,2,5,"密码:");
    this->pwdEdit=new CEdit((this->width)/5+this->x+8,this->y+8,2,10,"",PWDEDIT);
    this->LoginBtn=new CButton((this->width)/5+this->x+2,this->y+12,2,4,"登录");
    this->ExitBtn=new CButton((this->width)/5+this->x+16,this->y+12,2,4,"退出");

	this->addControl(this->nameLabel);
	this->addControl(this->nameEdit);
	this->addControl(this->pwdLabel);
	this->addControl(this->pwdEdit);
	this->addControl(this->LoginBtn);
	this->addControl(this->ExitBtn);
}

CLoginWin::~CLoginWin()
{
    delete this->pwdEdit;
    delete this->pwdLabel;
    delete this->nameEdit;
    delete this->nameLabel;
    delete this->LoginBtn;
    delete this->ExitBtn;
}

/******************************
*函数名 doAction()
*函数功能：对按键处理结果进行响应
*输入 所需数据，如商品信息，员工信息，出入库信息
*返回 界面号
************************************/
int CLoginWin::doAction(void *data)
{
    int ch;
    if(strcmp(this->controls[this->curControl]->getText(),"登录")==0)
    {
        if(strlen(this->controls[1]->getText())<=0)//判断用户名框是否为空
        {
            CTool::gotoxy(12,17);
            cout<<"用户名不能为空！请重新输入";
            system("pause");
        }
        else if(strlen(this->controls[3]->getText())<=0)//判断密码框是否为空
        {
            CTool::gotoxy(12,17);
            cout<<"密码不能为空！请重新输入";
            system("pause");
        }

        ch=CStaff::loginCheck(this->controls[1]->getText(),this->controls[3]->getText(),data);//链表中核对账号和密码
        if(ch==1)//管理员
        {
            CTool::gotoxy(20,20);
            cout<<"管理员登录成功";
            system("pause");
            strcpy(CTool::role,"1");//角色为仓库管理员
            return ADMINWIN;

        }
        else if(ch==2)//盘点员
        {
            CTool::gotoxy(20,20);
            cout<<"盘点员登录成功!";
            system("pause");
            strcpy(CTool::role,"2");//角色为仓库管理员
            return CHECKERWIN;
        }
        CTool::gotoxy(20,20);
        cout<<"密码错误";
        system("pause");

    }
    else if(strcmp(this->controls[this->curControl]->getText(),"退出")==0)
        return STARTWIN;//返回开始界面

    return LOGINWIN;//登录失败、信息没输入好都返回登录界面
}

/******************************
*函数名 UpdateControls()
*函数功能：登录界面不需要，只是为了实现基类的纯虚函数才写的
*输入 无
*输出 无
************************************/
void CLoginWin::UpdateControls()
{

}

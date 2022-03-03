#include "CRegisterWin.h"
#include<iostream>
using namespace std;



/******************************
*函数名 CRegisterWin()
*函数功能：窗体界面构造函数，对窗体的控件进行初始化
*输入 窗体的坐标和宽度、高度、窗体名字
*输出 无
************************************/
CRegisterWin::CRegisterWin(int x,int y,int height,int width,char *text,int winNo)
:CWinBase(x,y,height,width,text,winNo)
{
    this->usernameLabel=new CLabel((this->width)/4+this->x,this->y+4,2,5,"用户名:");//(12,6,2,5,"name:")
    this->usernameEdit=new CEdit((this->width)/4+this->x+8,this->y+4,2,10,"",EDIT);
    this->nameLabel=new CLabel((this->width)/4+this->x,this->y+7,2,5,"姓名:");//
    this->nameEdit=new CEdit((this->width)/4+this->x+8,this->y+7,2,10,"",CHNEDIT);
    this->pwdLabel=new CLabel((this->width)/4+this->x,this->y+10,2,5,"密码:");//第一次密码
    this->pwdEdit=new CEdit((this->width)/4+this->x+8,this->y+10,2,10,"",PWDEDIT);
    this->repwdLabel=new CLabel((this->width)/4+this->x,this->y+13,2,5,"新密码:");//第二次密码
    this->repwdEdit=new CEdit((this->width)/4+this->x+8,this->y+13,2,10,"",PWDEDIT);
    this->roleLabel=new CLabel((this->width)/4+this->x,this->y+16,2,5,"角色:");//角色
    this->roleEdit=new CEdit((this->width)/4+this->x+8,this->y+16,2,10,"",ROLEEDIT);
    this->RegisBtn=new CButton((this->width)/5+this->x+2,this->y+20,2,4,"注册");//注册按键
    this->ExitBtn=new CButton((this->width)/5+this->x+18,this->y+20,2,4,"退出");

    this->addControl(this->usernameLabel);
    this->addControl(this->usernameEdit);//用户名编辑框
	this->addControl(this->nameLabel);
	this->addControl(this->nameEdit);//姓名编辑框
	this->addControl(this->pwdLabel);
	this->addControl(this->pwdEdit);//密码编辑框
	this->addControl(this->repwdLabel);
	this->addControl(this->repwdEdit);//再次输入密码编辑框
	this->addControl(this->roleLabel);
	this->addControl(this->roleEdit);//角色编辑框
	this->addControl(this->RegisBtn);
	this->addControl(this->ExitBtn);
}

CRegisterWin::~CRegisterWin()
{
    delete this->nameEdit;
    delete this->nameLabel;
    delete this->pwdEdit;
    delete this->pwdLabel;
    delete this->repwdLabel;
    delete this->repwdEdit;
    delete this->roleLabel;
    delete this->roleEdit;
    delete this->RegisBtn;
    delete this->ExitBtn;
}

/******************************
*函数名 doAction()
*函数功能：对按键处理结果进行响应
*输入 所需数据，如商品信息，员工信息，出入库信息
*返回 界面号
************************************/
int CRegisterWin::doAction(void *data)//注册函数
{
    int i=0;
    if(strcmp(this->controls[this->curControl]->getText(),"注册")==0)
    {
        if(strlen(this->controls[1]->getText())<=0)
        {
            CTool::gotoxy(20,27);
            cout<<"用户名不能为空!请重新输入";
            system("pause");
        }
        else if(strlen(this->controls[3]->getText())<=0)
        {
            CTool::gotoxy(20,27);
            cout<<"名字不能为空!请重新输入";
            system("pause");
        }
        else if(strlen(this->controls[7]->getText())<=0||strlen(this->controls[5]->getText())<=0)
        {
            CTool::gotoxy(20,27);
            cout<<"密码不能为空！请重新输入";
            system("pause");
        }
        else if(strlen(this->controls[9]->getText())<=0)
        {
            CTool::gotoxy(20,27);
            cout<<"角色不能为空！请重新输入";
            system("pause");
        }
        else if(strcmp(this->controls[7]->getText(),this->controls[5]->getText())!=0)//判断密码是否一致
        {
            CTool::gotoxy(20,27);
            cout<<"两次密码不一致！请重新输入";
            system("pause");
        }
        else if(CStaff::registerCheck(this->controls[1]->getText(),data))//判断用户名是否已经存在
        {
            CTool::gotoxy(20,27);
            cout<<"用户名已存在！请重新输入";
            system("pause");
        }
        else
        {
            ((list <CStaff>*)data)->push_back(CStaff(this->controls[1]->getText(),this->controls[3]->getText(),this->controls[7]->getText(),this->controls[9]->getText()));
            CTool::gotoxy(20,27);
            cout<<"注册成功";
            getch();
            CFile::Staff_Filewrite("data/Staff.txt",(list <CStaff>*)data);
            return STARTWIN;
        }
        return REGISWIN;
    }

    else if(strcmp(this->controls[this->curControl]->getText(),"退出")==0)
    {
    }
    return STARTWIN;
}

/******************************
*函数名 UpdateControls()
*函数功能：注册界面不需要，只是为了实现基类的纯虚函数才写的
*输入 无
*输出 无
************************************/
void CRegisterWin::UpdateControls()
{

}


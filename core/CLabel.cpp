#include"CLabel.h"
#include<iostream>

using namespace std;

CLabel::CLabel(int x,int y,int height,int width,char text[TEXTNUM],int type)
:CControlBase(x,y,height,width,text,type)
{
}
void CLabel::show()
{
    CTool::gotoxy(this->x,this->y);
    cout<<this->text<<endl;
}
void CLabel::setLab(char *text)
{
    strcpy(this->text,text);
    return ;
}


/******************************
*函数名 keyhandle()
*函数功能：对键盘输入的键值进行判断是否要做出响应
*输入 键盘输入的键值 char ch
*输出 响应值
************************************/
int CLabel::keyhandle(char ch)
{
	return 0;
}



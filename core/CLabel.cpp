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
*������ keyhandle()
*�������ܣ��Լ�������ļ�ֵ�����ж��Ƿ�Ҫ������Ӧ
*���� ��������ļ�ֵ char ch
*��� ��Ӧֵ
************************************/
int CLabel::keyhandle(char ch)
{
	return 0;
}



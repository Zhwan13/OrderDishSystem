#include "CButton.h"
#include<iostream>
#include<stdio.h>
using namespace std;

CButton::CButton(int x,int y,int height,int width,char text[TEXTNUM],int type)
:CControlBase(x,y,height,width,text,type)
{

}

void CButton::show()
{
    int i=0,j=0;
	CTool::gotoxy(this->x-2,this->y-1);
    for(i=0;i<3;i++)
	{
		if(i==0)
		{
			printf("┌");
			for(j=0;j<this->width/2;j++)
			{
				printf("─");
			}
			printf("┐");
			CTool::gotoxy(this->x-2,this->y);
		}
		else if(i==2)
		{
			CTool::gotoxy(this->x-2,(this->y)+(this->height)-1);
			printf("└");
			for(j=0;j<this->width/2;j++)
			{
				printf("─");
			}
			printf("┘");
		}
		else if(i==1)
		{
			printf("│");
			for(j=0;j<this->width;j++)//此处用this->width会出现死循环，上面两处也是，所以换成了具体数据6
			{
				printf(" ");
			}
			printf("│");
			CTool::gotoxy((this->x)-2,this->y+1);
		}
	}
    CTool::gotoxy(this->x,this->y);
    cout<<this->text<<endl;
}

/******************************
*函数名 keyhandle()
*函数功能：对键盘输入的键值进行判断是否要做出响应
*输入 键盘输入的键值 char ch
*输出 响应值
************************************/
int CButton::keyhandle(char ch)
{
    if(ch=='\t')//table键
	{
		return CHANGEFOCUS;//转到下一个控件
	}
	else if(ch==KEY_ESC)
    {
        return 0;//退出
    }
	else if(ch=='\r')//回车键
	{
	    return DOACTION;//响应
	}
	return 0;

}

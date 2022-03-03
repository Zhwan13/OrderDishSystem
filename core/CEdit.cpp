#include "CEdit.h"
#include<iostream>
#include<stdio.h>
#include<conio.h>
using namespace std;

CEdit::CEdit(int x,int y,int height,int width,char text[TEXTNUM],int type)
:CControlBase(x,y,height,width,text,type)
{
}
void CEdit::show()
{
    int i=0,j=0;
    CTool::gotoxy(this->x-2,this->y-1);
    for(i=0;i<2;i++)
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
		if(i==2-1)
		{
			CTool::gotoxy(this->x-2,(this->y)+2-1);
			printf("└");
			for(j=0;j<this->width/2;j++)
			{
				printf("─");
			}
			printf("┘");
		}
		else
		{
			printf("│");
			for(j=0;j<this->width;j++)
			{
				printf(" ");
			}
			printf("│");
		}
	}
}


/******************************
*函数名 keyhandle()
*函数功能：对键盘输入的键值进行判断是否要做出响应：输入数据、跳转
*输入 键盘输入的键值 char ch
*输出 响应值
************************************/
int CEdit::keyhandle(char ch)
{
	int length=0;//text数组内数据长度
	char ch2;
	length=strlen(this->text);
	if(length==0&&this->getType()==ROLEEDIT&&(ch=='0'||ch=='1'))//类型是ROLEEDIT，则只输入一位数字
    {
        *(this->text+length)=ch;
        putchar(ch);
    }
	else if((ch>='A'&&ch<='Z')||(ch>='a'&&ch<='z')||(ch>='0'&&ch<='9')||ch=='-')//编辑框最多8位
	{
		if((length<=7&&this->getType()==EDIT)||(length<=20&&this->getType()==CHNEDIT))	//输入用户名
		{
			*(this->text+length)=ch;
			putchar(ch);
		}
		else if(this->getType()==PWDEDIT)	//输入密码
		{
			*(this->text+length)=ch;
			putchar('*');
		}
	}
	else if((ch=='\b')&&(length>0))//退格
    {
        printf("\b \b");
        *(this->text+length-1)='\0';
    }
    else if(ch=='\t'||ch=='\r')//编辑框中回车或者table时跳转光标
    {
        return CHANGEFOCUS;
    }
    else if((unsigned char)ch>=0XA1&&(unsigned char)ch<=0xFE&&length<=20)
    {
        if(this->getType()==CHNEDIT)
        {
            *(this->text+length)=ch;
            ch2=getch();
            if((unsigned char)ch2>=0XA1&&(unsigned char)ch2<=0xFE)
            {
                putchar(ch);
                length=strlen(this->text);
                *(this->text+length)=ch2;
                putchar(ch2);
            }
        }
    }
	return 0;
}

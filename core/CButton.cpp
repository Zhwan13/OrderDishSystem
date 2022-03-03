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
			printf("��");
			for(j=0;j<this->width/2;j++)
			{
				printf("��");
			}
			printf("��");
			CTool::gotoxy(this->x-2,this->y);
		}
		else if(i==2)
		{
			CTool::gotoxy(this->x-2,(this->y)+(this->height)-1);
			printf("��");
			for(j=0;j<this->width/2;j++)
			{
				printf("��");
			}
			printf("��");
		}
		else if(i==1)
		{
			printf("��");
			for(j=0;j<this->width;j++)//�˴���this->width�������ѭ������������Ҳ�ǣ����Ի����˾�������6
			{
				printf(" ");
			}
			printf("��");
			CTool::gotoxy((this->x)-2,this->y+1);
		}
	}
    CTool::gotoxy(this->x,this->y);
    cout<<this->text<<endl;
}

/******************************
*������ keyhandle()
*�������ܣ��Լ�������ļ�ֵ�����ж��Ƿ�Ҫ������Ӧ
*���� ��������ļ�ֵ char ch
*��� ��Ӧֵ
************************************/
int CButton::keyhandle(char ch)
{
    if(ch=='\t')//table��
	{
		return CHANGEFOCUS;//ת����һ���ؼ�
	}
	else if(ch==KEY_ESC)
    {
        return 0;//�˳�
    }
	else if(ch=='\r')//�س���
	{
	    return DOACTION;//��Ӧ
	}
	return 0;

}

#include"CWinBase.h"
#include<stdio.h>
#include<conio.h>
#include<iostream>
using namespace std;

CWinBase::CWinBase(int x,int y,int height,int width,char *text,int winNo)
{
    this->x=x;
    this->y=y;
    this->width=width;
    this->height=height;
    this->text=new char[30];
    strcpy(this->text,text);
    this->con_count=0;//控件个数
    this->curControl=0;//当前控件
    this->winNo=winNo;
}

void CWinBase::addControl(CControlBase *pctrl)	//添加控件
{
	this->controls[con_count]=pctrl;
	CWinBase::con_count++;
}

void CWinBase::outlinePrint()//窗口外框和标题打印
{
    int i=0,j=0;
    CTool::gotoxy(this->x,this->y);
    for(i=0;i<(this->height);i++)
	{
		if(i==0)
		{
			printf("┌");
			for(j=0;j<this->width/2;j++)
			{
				printf("─");
			}
			printf("┐");
			CTool::gotoxy(this->x,this->y+1);
			continue;
		}
		if(i==3)
		{
			printf("├");
			for(j=0;j<this->width/2;j++)
			{
				printf("─");
			}
			printf("┤");
			CTool::gotoxy(this->x,this->y+i);
			continue;
		}

		if(i==(this->height)-1)
		{
			printf("└");
			for(j=0;j<this->width/2;j++)
			{
				printf("─");
			}
			printf("┘");
			continue;
		}
		if(i>0&&i<(this->height)-1)
		{
			printf("│");
			for(j=0;j<this->width;j++)
			{
				printf(" ");
			}
			printf("│");
			CTool::gotoxy(this->x,this->y+i);
			continue;
		}
	}
	CTool::gotoxy(this->x+(this->width)/2-(strlen(this->text))/2+1,this->y+1);//显示标题
    cout<<this->text<<endl;
}

void CWinBase::show()	//打印界面
{
	int i=0;
	if(strlen(this->text)!=0)
	{
	    system("CLS");
	}

	this->UpdateControls();//更新控件内容、获取时间、角色

    this->outlinePrint();
	for(i=0;i<this->con_count;i++)    //count是控件数量——控件数量最大20
	{
        this->controls[i]->show();
	}
	if(strcmp(this->text,"商品新增界面")==0)
    {
        CTool::gotoxy(29,10);
        cout<<CTool::temp;
    }
	return ;
}


//窗体管理器的run函数
int CWinBase::run(void *data)
{
	int i=0;
	char ch;//输入
	int flag;
	int rs=0;
	this->show();
	for(i=0;i<this->con_count;i++)
    {
        if(this->controls[i]->getType()==EDIT||this->controls[i]->getType()==PWDEDIT||this->controls[i]->getType()==ROLEEDIT||this->controls[i]->getType()==CHNEDIT)
        {
            //if(this->winNo!=INSTOCKWIN)//如果不是入库界面就清空编辑框内容
            memset(this->controls[i]->text,0,TEXTNUM);
        }
    }
    i=0;
	while(this->controls[i]->getType()==LABEL||this->controls[i]->getType()==INFORMATION||this->controls[i]->getType()==EMPTYEDIT)//注意此处不要死循环
    {
        i++;
    }
    this->curControl=i;
	CTool::gotoxy(this->controls[this->curControl]->getX(),this->controls[this->curControl]->getY());//找到第一个编辑框

	while(1)
	{
		ch=getch();
		if(ch==224)
        {
            ch=getch();
        }
		flag=this->controls[this->curControl]->keyhandle(ch);
		if(flag==CHANGEFOCUS)
        {
            this->changeFocus();//移动光标
        }
        else if(flag==DOACTION)//BUTTON处回车对应的响应
        {
            rs=this->doAction(data);//响应 虚函数
            return rs;
        }
        else if(flag==CHANGEPAGE)//如果是table返回的翻页
        {
            return this->winNo;
        }
	}
}

/***
实现table之后转到编辑框和按键
***/
void CWinBase::changeFocus()
{
	int length=0;//编辑框内容长度
	int i=this->curControl;
	while(1)
    {
        if(i==this->con_count-1)//当移动到最后一个可停留控件时跳转到第一个不为LABEL的控件
        {
            i=-1;
             /**i=0;
			while(this->controls[i]->getType()==LABEL||this->controls[i]->getType()==INFORMATION||this->controls[i]->getType()==EMPTYEDIT)
            {
                i++;
            }
            this->curControl=i;
            break;
            ***/
        }
        if(this->controls[i+1]->getType()!=LABEL&&this->controls[i+1]->getType()!=EMPTYEDIT&&this->controls[i+1]->getType()!=INFORMATION&&this->controls[i+1]->getType()!=CHECK_INFO)//下一个控件不是xxxx就可跳转
        {
            this->curControl=i+1;
            break;
        }
		i++;
    }
    length=strlen(this->controls[this->curControl]->getText());//编辑框内的长度
	if(this->controls[this->curControl]->getType()==PWDEDIT||this->controls[this->curControl]->getType()==EDIT||this->controls[this->curControl]->getType()==ROLEEDIT||this->controls[this->curControl]->getType()==CHNEDIT)
    {
        CTool::gotoxy(this->controls[this->curControl]->getX()+length,this->controls[this->curControl]->getY());
    }//如果是跳转到编辑框还要加上编辑框内容长度
    else if(this->controls[this->curControl]->getType()==BUTTON||this->controls[this->curControl]->getType()==GOODSTABLE||this->controls[this->curControl]->getType()==RECORDTABLE)
    {
        CTool::gotoxy(this->controls[this->curControl]->getX(),this->controls[this->curControl]->getY());
    }//按键

}

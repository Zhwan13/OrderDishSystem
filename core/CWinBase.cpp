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
    this->con_count=0;//�ؼ�����
    this->curControl=0;//��ǰ�ؼ�
    this->winNo=winNo;
}

void CWinBase::addControl(CControlBase *pctrl)	//��ӿؼ�
{
	this->controls[con_count]=pctrl;
	CWinBase::con_count++;
}

void CWinBase::outlinePrint()//�������ͱ����ӡ
{
    int i=0,j=0;
    CTool::gotoxy(this->x,this->y);
    for(i=0;i<(this->height);i++)
	{
		if(i==0)
		{
			printf("��");
			for(j=0;j<this->width/2;j++)
			{
				printf("��");
			}
			printf("��");
			CTool::gotoxy(this->x,this->y+1);
			continue;
		}
		if(i==3)
		{
			printf("��");
			for(j=0;j<this->width/2;j++)
			{
				printf("��");
			}
			printf("��");
			CTool::gotoxy(this->x,this->y+i);
			continue;
		}

		if(i==(this->height)-1)
		{
			printf("��");
			for(j=0;j<this->width/2;j++)
			{
				printf("��");
			}
			printf("��");
			continue;
		}
		if(i>0&&i<(this->height)-1)
		{
			printf("��");
			for(j=0;j<this->width;j++)
			{
				printf(" ");
			}
			printf("��");
			CTool::gotoxy(this->x,this->y+i);
			continue;
		}
	}
	CTool::gotoxy(this->x+(this->width)/2-(strlen(this->text))/2+1,this->y+1);//��ʾ����
    cout<<this->text<<endl;
}

void CWinBase::show()	//��ӡ����
{
	int i=0;
	if(strlen(this->text)!=0)
	{
	    system("CLS");
	}

	this->UpdateControls();//���¿ؼ����ݡ���ȡʱ�䡢��ɫ

    this->outlinePrint();
	for(i=0;i<this->con_count;i++)    //count�ǿؼ����������ؼ��������20
	{
        this->controls[i]->show();
	}
	if(strcmp(this->text,"��Ʒ��������")==0)
    {
        CTool::gotoxy(29,10);
        cout<<CTool::temp;
    }
	return ;
}


//�����������run����
int CWinBase::run(void *data)
{
	int i=0;
	char ch;//����
	int flag;
	int rs=0;
	this->show();
	for(i=0;i<this->con_count;i++)
    {
        if(this->controls[i]->getType()==EDIT||this->controls[i]->getType()==PWDEDIT||this->controls[i]->getType()==ROLEEDIT||this->controls[i]->getType()==CHNEDIT)
        {
            //if(this->winNo!=INSTOCKWIN)//����������������ձ༭������
            memset(this->controls[i]->text,0,TEXTNUM);
        }
    }
    i=0;
	while(this->controls[i]->getType()==LABEL||this->controls[i]->getType()==INFORMATION||this->controls[i]->getType()==EMPTYEDIT)//ע��˴���Ҫ��ѭ��
    {
        i++;
    }
    this->curControl=i;
	CTool::gotoxy(this->controls[this->curControl]->getX(),this->controls[this->curControl]->getY());//�ҵ���һ���༭��

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
            this->changeFocus();//�ƶ����
        }
        else if(flag==DOACTION)//BUTTON���س���Ӧ����Ӧ
        {
            rs=this->doAction(data);//��Ӧ �麯��
            return rs;
        }
        else if(flag==CHANGEPAGE)//�����table���صķ�ҳ
        {
            return this->winNo;
        }
	}
}

/***
ʵ��table֮��ת���༭��Ͱ���
***/
void CWinBase::changeFocus()
{
	int length=0;//�༭�����ݳ���
	int i=this->curControl;
	while(1)
    {
        if(i==this->con_count-1)//���ƶ������һ����ͣ���ؼ�ʱ��ת����һ����ΪLABEL�Ŀؼ�
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
        if(this->controls[i+1]->getType()!=LABEL&&this->controls[i+1]->getType()!=EMPTYEDIT&&this->controls[i+1]->getType()!=INFORMATION&&this->controls[i+1]->getType()!=CHECK_INFO)//��һ���ؼ�����xxxx�Ϳ���ת
        {
            this->curControl=i+1;
            break;
        }
		i++;
    }
    length=strlen(this->controls[this->curControl]->getText());//�༭���ڵĳ���
	if(this->controls[this->curControl]->getType()==PWDEDIT||this->controls[this->curControl]->getType()==EDIT||this->controls[this->curControl]->getType()==ROLEEDIT||this->controls[this->curControl]->getType()==CHNEDIT)
    {
        CTool::gotoxy(this->controls[this->curControl]->getX()+length,this->controls[this->curControl]->getY());
    }//�������ת���༭��Ҫ���ϱ༭�����ݳ���
    else if(this->controls[this->curControl]->getType()==BUTTON||this->controls[this->curControl]->getType()==GOODSTABLE||this->controls[this->curControl]->getType()==RECORDTABLE)
    {
        CTool::gotoxy(this->controls[this->curControl]->getX(),this->controls[this->curControl]->getY());
    }//����

}

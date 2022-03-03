#include"CadminWin.h"
#include<iostream>
using namespace std;


/******************************
*������ CadminWin()
*�������ܣ���¼������湹�캯�����Դ������Ŀؼ����г�ʼ��
*���� ������������Ϳ�ȡ��߶ȡ���������
*��� ��
************************************/

CadminWin::CadminWin(int x,int y,int height,int width,char *text,int winNo)
:CWinBase(x,y,height,width,text,winNo)
{
    this->WelcomeLab=new CLabel(this->x+6,this->y+3,2,6,"��ӭ:");
    this->DateLab=new CLabel(this->x+this->width-16,this->y+3,2,6,"����:");
	this->GoodsSearch=new CButton((this->width)/4+this->x,this->y+5,2,8,"��Ʒ��ѯ");
	this->GoodsCheck=new CButton((this->width)*3/4+this->x,this->y+5,2,8,"�̵����");
	this->InStock=new CButton((this->width)/4+this->x,this->y+9,2,8,"��Ʒ���");
	this->OutStock=new CButton((this->width)*3/4+this->x,this->y+9,2,8,"��Ʒ����");
	this->exit=new CButton((this->width)/4+this->x,this->y+13,2,8,"�˳�����");

	this->addControl(this->WelcomeLab);
	this->addControl(this->DateLab);
	this->addControl(this->GoodsSearch);
	this->addControl(this->GoodsCheck);
	this->addControl(this->InStock);
	this->addControl(this->OutStock);
	this->addControl(this->exit);
}
CadminWin::~CadminWin()
{

}

/******************************
*������ doAction
*�������ܣ��ڲֿ����Ա�Ĵ���������Ӧ����������Ӧ
*���� void *data
*��� ��Ӧ�Ĵ������궨��ĺ��� 0~16
************************************/

int CadminWin::doAction(void *data)
{
    if(strcmp(this->controls[this->curControl]->getText(),"��Ʒ��ѯ")==0)
    {
        return SEARCHWIN;
    }
    else if(strcmp(this->controls[this->curControl]->getText(),"�̵����")==0)
    {
        return CHECKMENUWIN;
    }
    else if(strcmp(this->controls[this->curControl]->getText(),"��Ʒ���")==0)
    {
        return INSTOCKMENUWIN;//INSTOCKMENUWIN ���˵�����
    }
    else if(strcmp(this->controls[this->curControl]->getText(),"��Ʒ����")==0)
    {
        return OUTSTOCKMENUWIN;
    }
    else if(strcmp(this->controls[this->curControl]->getText(),"�˳�����")==0)
    {
        return STARTWIN;//��ʼ����
    }
    return STARTWIN;
}

/******************************
*������ UpdateControls()
*�������ܣ����´���ؼ�����Ҫ�ǵ�¼�ߵ���ݺ͵�ǰ����
*���� ��
*��� ��
************************************/
void CadminWin::UpdateControls()
{
    char *Date=new char[20];
    CTool::getDate(Date);
    char newLab[25]={0};
    sprintf(newLab,"����:%s",Date);
    this->DateLab->setLab(newLab);
    if (strcmp(CTool::role,"1")==0)
    {
        this->WelcomeLab->setLab("��ӭ:�ֿ����Ա");
    }
    else
    {
        this->WelcomeLab->setLab("��ӭ:�̵�Ա");
    }
    delete Date;
    return ;
}

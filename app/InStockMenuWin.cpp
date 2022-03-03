#include"InStockMenuWin.h"


/******************************
*������ InStockMenuWin()
*�������ܣ�������湹�캯�����Դ���Ŀؼ����г�ʼ��
*���� ���������Ϳ�ȡ��߶ȡ���������
*��� ��
************************************/
InStockMenuWin::InStockMenuWin(int x,int y,int height,int width,char *text,int winNo)
:CWinBase(x,y,height,width,text,winNo)
{
    this->WelcomeLab=new CLabel(this->x+6,this->y+3,2,6,"��ӭ:");
    this->DateLab=new CLabel(this->x+this->width-16,this->y+3,2,6,"����:");
    this->InStock=new CButton((this->width)/2+this->x-1,this->y+4,2,6,"���");
    this->InStockRecord=new CButton((this->width)/2+this->x-1,this->y+8,2,8,"����¼");
    this->exit=new CButton((this->width)/2+this->x-1,this->y+12,2,6,"����");

    this->addControl(this->WelcomeLab);
	this->addControl(this->DateLab);
    this->addControl(this->InStock);
    this->addControl(this->InStockRecord);
    this->addControl(this->exit);
}

InStockMenuWin::~InStockMenuWin()
{
    delete this->InStock;
    delete this->InStockRecord;
    delete this->exit;
}

/******************************
*������ doAction()
*�������ܣ��԰���������������Ӧ
*���� �������ݣ�����Ʒ��Ϣ��Ա����Ϣ���������Ϣ
*���� �����
************************************/
int InStockMenuWin::doAction(void *daata)
{
    if(strcmp(this->controls[this->curControl]->getText(),"���")==0)
    {
        return INSTOCKWIN;//������
    }
    else if(strcmp(this->controls[this->curControl]->getText(),"����¼")==0)
    {
        return INSTOCKRECORDWIN;//����¼����
    }
    else if(strcmp(this->controls[this->curControl]->getText(),"����")==0)
    {
        return ADMINWIN;
    }
}

/******************************
*������ UpdateControls()
*�������ܣ����´���ؼ�����Ҫ�ǵ�¼�ߵ���ݺ͵�ǰ����
*���� ��
*��� ��
************************************/
void InStockMenuWin::UpdateControls()
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

#include"OutStockMenuWin.h"


/******************************
*������ OutStockMenuWin()
*�������ܣ�������湹�캯�����Դ���Ŀؼ����г�ʼ��
*���� ���������Ϳ�ȡ��߶ȡ���������
*��� ��
************************************/
OutStockMenuWin::OutStockMenuWin(int x,int y,int height,int width,char *text,int winNo)
:CWinBase(x,y,height,width,text,winNo)
{
    this->WelcomeLab=new CLabel(this->x+6,this->y+3,2,6,"��ӭ:");
    this->DateLab=new CLabel(this->x+this->width-20,this->y+3,2,6,"����:");
    this->OutStock=new CButton((this->width)/2+this->x-1,this->y+4,2,4,"����");
    this->OutStockRecord=new CButton((this->width)/2+this->x-1,this->y+8,2,8,"�����¼");
    this->exit=new CButton((this->width)/2+this->x-1,this->y+12,2,4,"����");

    this->addControl(this->WelcomeLab);
    this->addControl(this->DateLab);
    this->addControl(this->OutStock);
    this->addControl(this->OutStockRecord);
    this->addControl(this->exit);
}

OutStockMenuWin::~OutStockMenuWin()
{
    delete this->OutStock;
    delete this->OutStockRecord;
    delete this->exit;
}

/******************************
*������ doAction()
*�������ܣ��԰���������������Ӧ
*���� �������ݣ�����Ʒ��Ϣ��Ա����Ϣ���������Ϣ
*���� �����
************************************/
int OutStockMenuWin::doAction(void *daata)
{
    if(strcmp(this->controls[this->curControl]->getText(),"����")==0)
    {
        return OUTSTOCKWIN;//������INSTOCKWIN
    }
    else if(strcmp(this->controls[this->curControl]->getText(),"�����¼")==0)
    {
        return OUTSTOCKRECORDWIN;//����¼����
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
void OutStockMenuWin::UpdateControls()
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



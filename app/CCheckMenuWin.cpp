#include"CCheckMenuWin.h"


/******************************
*������ CCheckMenuWin()
*�������ܣ�������湹�캯�����Դ���Ŀؼ����г�ʼ��
*���� ���������Ϳ�ȡ��߶ȡ���������
*��� ��
************************************/
CCheckMenuWin::CCheckMenuWin(int x,int y,int height,int width,char *text,int winNo)
:CWinBase(x,y,height,width,text,winNo)
{
    this->WelcomeLab=new CLabel(this->x+6,this->y+3,2,6,"��ӭ:");
    this->DateLab=new CLabel(this->x+this->width-20,this->y+3,2,6,"����:");
    this->NewCheckBtn=new CButton(this->x+8,this->y+6,2,8,"�½��̵�");
    this->CheckRecordBtn=new CButton(this->x+this->width-18,this->y+6,2,8,"�̵��¼");
    this->ReturnBtn=new CButton(this->x+8,this->y+10,2,4,"����");

    this->addControl(this->WelcomeLab);
    this->addControl(this->DateLab);
    this->addControl(this->NewCheckBtn);
    this->addControl(this->CheckRecordBtn);
    this->addControl(this->ReturnBtn);
}
/******************************
*������ doAction()
*�������ܣ��԰���������������Ӧ
*���� �������ݣ�����Ʒ��Ϣ��Ա����Ϣ���������Ϣ
*���� �����
************************************/
int CCheckMenuWin::doAction(void *data)
{
    if(strcmp(this->controls[this->curControl]->getText(),"�½��̵�")==0)
    {
        return CHECKWINCREATE;
    }
    else if(strcmp(this->controls[this->curControl]->getText(),"�̵��¼")==0)
    {
        return CHECKREPORTWIN;
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
void CCheckMenuWin::UpdateControls()
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



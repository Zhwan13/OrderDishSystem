#include "CCheckReportWin.h"


/******************************
*������ CCheckReportWin()
*�������ܣ�������湹�캯�����Դ���Ŀؼ����г�ʼ��
*���� ���������Ϳ�ȡ��߶ȡ���������
*��� ��
************************************/
CCheckReportWin::CCheckReportWin(int x,int y,int height,int width,char *text,void *data,int winNo)
:CWinBase(x,y,height,width,text,winNo)
{
    this->data=data;
    this->WelcomeLab=new CLabel(this->x+6,this->y+4,2,6,"��ӭ:");
    this->DateLab=new CLabel(this->x+this->width-20,this->y+4,2,6,"����:");
    this->CheckNoLab=new CLabel(this->x+5,this->y+6,2,6,"�̵���:");
    this->CheckStateLab=new CLabel(this->x+this->width-15,this->y+6,2,6,"�̵�״̬:");
    this->CheckReportTab=new CTable(this->x+2,this->y+8,8,58,this->data,RECORDTABLE);//�̵��¼���

    this->GoodsNoLab=new CLabel(this->x+3,this->y+9,2,6,"��Ʒ���");
    this->GoodsNameLab=new CLabel(this->x+15,this->y+9,2,6,"��Ʒ����");
    this->StockCountLab=new CLabel(this->x+27,this->y+9,2,6,"�������");
    this->CheckCountLab=new CLabel(this->x+49,this->y+9,2,6,"�̵�����");
    this->DifferCount=new CLabel(this->x+51,this->y+9,2,6,"��������");

    this->EndCheckBtn=new CButton(this->x+4,this->y+18,2,8,"�����̵�");
    this->ReturnBtn=new CButton(this->x+16,this->y+18,2,4,"����");

    this->addControl(this->WelcomeLab);
    this->addControl(this->DateLab);
    this->addControl(this->CheckNoLab);
    this->addControl(this->CheckStateLab);
    this->addControl(this->CheckReportTab);
    this->addControl(this->GoodsNoLab);
    this->addControl(this->GoodsNameLab);
    this->addControl(this->StockCountLab);
    this->addControl(this->CheckCountLab);
    this->addControl(this->DifferCount);
    this->addControl(this->EndCheckBtn);
    this->addControl(this->ReturnBtn);
}
CCheckReportWin::~CCheckReportWin()
{
    delete this->WelcomeLab;
    delete this->DateLab;
    delete this->CheckNoLab;
    delete this->CheckStateLab;
    delete this->CheckReportTab;
    delete this->GoodsNoLab;
    delete this->GoodsNameLab;
    delete this->StockCountLab;
    delete this->CheckCountLab;
    delete this->DifferCount;
    delete this->EndCheckBtn;
    delete this->ReturnBtn;
}

/******************************
*������ doAction()
*�������ܣ��԰���������������Ӧ
*���� �������ݣ�����Ʒ��Ϣ��Ա����Ϣ���������Ϣ
*���� �����
************************************/
int CCheckReportWin::doAction(void *data)
{
    if(strcmp(this->controls[this->curControl]->getText(),"�����̵�")==0)//�����̵�˵����棬�̵��¼������������Ʒ�̵��¼
    {
        return CHECKMENUWIN;
    }

    else if(strcmp(this->controls[this->curControl]->getText(),"����")==0)//�����̵����
    {
        return CHECKREPORTWIN;
    }
}

/******************************
*������ UpdateControls()
*�������ܣ����´���ؼ�����Ҫ�ǵ�¼�ߵ���ݺ͵�ǰ����
*���� ��
*��� ��
************************************/
void CCheckReportWin::UpdateControls()
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

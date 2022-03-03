#include"CCheckerWin.h"


/******************************
*������ CCheckerWin()
*�������ܣ�������湹�캯�����Դ���Ŀؼ����г�ʼ��
*���� ���������Ϳ�ȡ��߶ȡ���������
*��� ��
************************************/
CCheckerWin::CCheckerWin(int x,int y,int height,int width,char *text,int winNo)
:CWinBase(x,y,height,width,text,winNo)
{
     this->WelcomeLab=new CLabel(this->x+6,this->y+3,2,6,"��ӭ:");
    this->DateLab=new CLabel(this->x+this->width-16,this->y+3,2,6,"����:");
    this->GoodsSearch=new CButton((this->width)/5+this->x,this->y+4,2,8,"��Ʒ��ѯ");
	this->StockChecks=new CButton((this->width)*3/5+this->x,this->y+4,2,8,"�ֿ��̵�");
	this->exit=new CButton((this->width)/5+this->x,this->y+8,2,8,"�˳�����");

	this->addControl(this->WelcomeLab);
	this->addControl(this->DateLab);
	this->addControl(this->GoodsSearch);
	this->addControl(this->StockChecks);
	this->addControl(this->exit);
}

CCheckerWin::~CCheckerWin()
{

}

/******************************
*������ doAction()
*�������ܣ��԰���������������Ӧ
*���� �������ݣ�����Ʒ��Ϣ��Ա����Ϣ���������Ϣ
*���� �����
************************************/
int CCheckerWin::doAction(void *data)
{
    if(strcmp(this->controls[this->curControl]->getText(),"��Ʒ��ѯ")==0)
        return SEARCHWIN;
    if(strcmp(this->controls[this->curControl]->getText(),"�ֿ��̵�")==0)
        return CHECKMENUWIN;//�̵�˵�����
    else if(strcmp(this->controls[this->curControl]->getText(),"�˳�����")==0)
        return 0;//���ؿ�ʼ����
}

/******************************
*������ UpdateControls()
*�������ܣ����´���ؼ�����Ҫ�ǵ�¼�ߵ���ݺ͵�ǰ����
*���� ��
*��� ��
************************************/
void CCheckerWin::UpdateControls()
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

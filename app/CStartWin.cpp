#include"CStartWin.h"



/******************************
*������ CStartWin()
*�������ܣ�������湹�캯�����Դ���Ŀؼ����г�ʼ��
*���� ���������Ϳ�ȡ��߶ȡ���������
*��� ��
************************************/
CStartWin::CStartWin(int x,int y,int height,int width,char *text,int winNo)
:CWinBase(x,y,height,width,text,winNo)
{
    this->Login=new CButton((this->width)/2+this->x-1,this->y+4,2,4,"��¼");
    this->Register=new CButton((this->width)/2+this->x-1,this->y+8,2,4,"ע��");
    this->exit=new CButton((this->width)/2+this->x-1,this->y+12,2,4,"�˳�");

    this->addControl(this->Login);
    this->addControl(this->Register);
    this->addControl(this->exit);
}

CStartWin::~CStartWin()
{
    delete this->Login;
    delete this->Register;
    delete this->exit;
}
/******************************
*������ doAction()
*�������ܣ��԰���������������Ӧ
*���� �������ݣ�����Ʒ��Ϣ��Ա����Ϣ���������Ϣ
*���� �����
************************************/
int CStartWin::doAction(void *data)
{
    //����flag ���ؽ���
    if(strcmp(this->controls[this->curControl]->getText(),"��¼")==0)
    {
        return LOGINWIN;
    }
    else if (strcmp(this->controls[this->curControl]->getText(),"ע��")==0)
    {
        return REGISWIN;
    }
    else if (strcmp(this->controls[this->curControl]->getText(),"�˳�")==0)
    {
        return -1;
    }
    return STARTWIN;
}
/******************************
*������ UpdateControls()
*�������ܣ���ʼ���治��Ҫ��ֻ��Ϊ��ʵ�ֻ���Ĵ��麯����д��
*���� ��
*��� ��
************************************/
void CStartWin::UpdateControls()
{

}

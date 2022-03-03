#include"CTipsWin.h"

/******************************
*������ CTipsWin()
*�������ܣ�������湹�캯�����Դ���Ŀؼ����г�ʼ��
*���� ���������Ϳ�ȡ��߶ȡ���������
*��� ��
************************************/
CTipsWin::CTipsWin(int x,int y,int height,int width,char *text,int winNo)
:CWinBase(x,y,height,width,text,winNo)
{
    this->tips1Lab=new CLabel(this->x+3,this->y+1,2,16,"��ʾ:");
    this->tips2Lab=new CLabel(this->x+2,this->y+3,2,16,"δ�ҵ���Ӧ����Ʒ");
    this->reinputBtn=new CButton(this->x+6,this->y+6,2,10,"��������");
    this->addBtn=new CButton(this->x+6,this->y+10,2,10,"������Ʒ");

    this->addControl(this->tips1Lab);
    this->addControl(this->tips2Lab);
    this->addControl(this->reinputBtn);
    this->addControl(this->addBtn);
}

CTipsWin::~CTipsWin()
{
   // delete

}

/******************************
*������ doAction()
*�������ܣ��԰���������������Ӧ
*���� �������ݣ�����Ʒ��Ϣ��Ա����Ϣ���������Ϣ
*���� �����
************************************/
int CTipsWin::doAction(void *data)
{
    if(strcmp(this->controls[this->curControl]->getText(),"��������")==0)
    {
        return INSTOCKWIN;
    }
    else if(strcmp(this->controls[this->curControl]->getText(),"������Ʒ")==0)
        return GOODSADDWIN;
}

/******************************
*������ UpdateControls()
*�������ܣ���ʾ���治��Ҫ��ֻ��Ϊ��ʵ�ֻ���Ĵ��麯����д��
*���� ��
*��� ��
************************************/
void CTipsWin::UpdateControls()
{

}

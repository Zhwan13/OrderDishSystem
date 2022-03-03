#include"CLoginWin.h"
#include<stdio.h>


/******************************
*������ CLoginWin()
*�������ܣ�������湹�캯�����Դ���Ŀؼ����г�ʼ��
*���� ���������Ϳ�ȡ��߶ȡ���������
*��� ��
************************************/
CLoginWin::CLoginWin(int x,int y,int height,int width,char *text,int winNo)
:CWinBase(x,y,height,width,text,winNo)
{
    this->nameLabel=new CLabel((this->width)/5+this->x,this->y+4,2,4,"ID:");//(12,6,2,5,"name:");
    this->nameEdit=new CEdit((this->width)/5+this->x+8,this->y+4,2,10,"",EDIT);
    this->pwdLabel=new CLabel((this->width)/5+this->x,this->y+8,2,5,"����:");
    this->pwdEdit=new CEdit((this->width)/5+this->x+8,this->y+8,2,10,"",PWDEDIT);
    this->LoginBtn=new CButton((this->width)/5+this->x+2,this->y+12,2,4,"��¼");
    this->ExitBtn=new CButton((this->width)/5+this->x+16,this->y+12,2,4,"�˳�");

	this->addControl(this->nameLabel);
	this->addControl(this->nameEdit);
	this->addControl(this->pwdLabel);
	this->addControl(this->pwdEdit);
	this->addControl(this->LoginBtn);
	this->addControl(this->ExitBtn);
}

CLoginWin::~CLoginWin()
{
    delete this->pwdEdit;
    delete this->pwdLabel;
    delete this->nameEdit;
    delete this->nameLabel;
    delete this->LoginBtn;
    delete this->ExitBtn;
}

/******************************
*������ doAction()
*�������ܣ��԰���������������Ӧ
*���� �������ݣ�����Ʒ��Ϣ��Ա����Ϣ���������Ϣ
*���� �����
************************************/
int CLoginWin::doAction(void *data)
{
    int ch;
    if(strcmp(this->controls[this->curControl]->getText(),"��¼")==0)
    {
        if(strlen(this->controls[1]->getText())<=0)//�ж��û������Ƿ�Ϊ��
        {
            CTool::gotoxy(12,17);
            cout<<"�û�������Ϊ�գ�����������";
            system("pause");
        }
        else if(strlen(this->controls[3]->getText())<=0)//�ж�������Ƿ�Ϊ��
        {
            CTool::gotoxy(12,17);
            cout<<"���벻��Ϊ�գ�����������";
            system("pause");
        }

        ch=CStaff::loginCheck(this->controls[1]->getText(),this->controls[3]->getText(),data);//�����к˶��˺ź�����
        if(ch==1)//����Ա
        {
            CTool::gotoxy(20,20);
            cout<<"����Ա��¼�ɹ�";
            system("pause");
            strcpy(CTool::role,"1");//��ɫΪ�ֿ����Ա
            return ADMINWIN;

        }
        else if(ch==2)//�̵�Ա
        {
            CTool::gotoxy(20,20);
            cout<<"�̵�Ա��¼�ɹ�!";
            system("pause");
            strcpy(CTool::role,"2");//��ɫΪ�ֿ����Ա
            return CHECKERWIN;
        }
        CTool::gotoxy(20,20);
        cout<<"�������";
        system("pause");

    }
    else if(strcmp(this->controls[this->curControl]->getText(),"�˳�")==0)
        return STARTWIN;//���ؿ�ʼ����

    return LOGINWIN;//��¼ʧ�ܡ���Ϣû����ö����ص�¼����
}

/******************************
*������ UpdateControls()
*�������ܣ���¼���治��Ҫ��ֻ��Ϊ��ʵ�ֻ���Ĵ��麯����д��
*���� ��
*��� ��
************************************/
void CLoginWin::UpdateControls()
{

}

#include "CRegisterWin.h"
#include<iostream>
using namespace std;



/******************************
*������ CRegisterWin()
*�������ܣ�������湹�캯�����Դ���Ŀؼ����г�ʼ��
*���� ���������Ϳ�ȡ��߶ȡ���������
*��� ��
************************************/
CRegisterWin::CRegisterWin(int x,int y,int height,int width,char *text,int winNo)
:CWinBase(x,y,height,width,text,winNo)
{
    this->usernameLabel=new CLabel((this->width)/4+this->x,this->y+4,2,5,"�û���:");//(12,6,2,5,"name:")
    this->usernameEdit=new CEdit((this->width)/4+this->x+8,this->y+4,2,10,"",EDIT);
    this->nameLabel=new CLabel((this->width)/4+this->x,this->y+7,2,5,"����:");//
    this->nameEdit=new CEdit((this->width)/4+this->x+8,this->y+7,2,10,"",CHNEDIT);
    this->pwdLabel=new CLabel((this->width)/4+this->x,this->y+10,2,5,"����:");//��һ������
    this->pwdEdit=new CEdit((this->width)/4+this->x+8,this->y+10,2,10,"",PWDEDIT);
    this->repwdLabel=new CLabel((this->width)/4+this->x,this->y+13,2,5,"������:");//�ڶ�������
    this->repwdEdit=new CEdit((this->width)/4+this->x+8,this->y+13,2,10,"",PWDEDIT);
    this->roleLabel=new CLabel((this->width)/4+this->x,this->y+16,2,5,"��ɫ:");//��ɫ
    this->roleEdit=new CEdit((this->width)/4+this->x+8,this->y+16,2,10,"",ROLEEDIT);
    this->RegisBtn=new CButton((this->width)/5+this->x+2,this->y+20,2,4,"ע��");//ע�ᰴ��
    this->ExitBtn=new CButton((this->width)/5+this->x+18,this->y+20,2,4,"�˳�");

    this->addControl(this->usernameLabel);
    this->addControl(this->usernameEdit);//�û����༭��
	this->addControl(this->nameLabel);
	this->addControl(this->nameEdit);//�����༭��
	this->addControl(this->pwdLabel);
	this->addControl(this->pwdEdit);//����༭��
	this->addControl(this->repwdLabel);
	this->addControl(this->repwdEdit);//�ٴ���������༭��
	this->addControl(this->roleLabel);
	this->addControl(this->roleEdit);//��ɫ�༭��
	this->addControl(this->RegisBtn);
	this->addControl(this->ExitBtn);
}

CRegisterWin::~CRegisterWin()
{
    delete this->nameEdit;
    delete this->nameLabel;
    delete this->pwdEdit;
    delete this->pwdLabel;
    delete this->repwdLabel;
    delete this->repwdEdit;
    delete this->roleLabel;
    delete this->roleEdit;
    delete this->RegisBtn;
    delete this->ExitBtn;
}

/******************************
*������ doAction()
*�������ܣ��԰���������������Ӧ
*���� �������ݣ�����Ʒ��Ϣ��Ա����Ϣ���������Ϣ
*���� �����
************************************/
int CRegisterWin::doAction(void *data)//ע�ắ��
{
    int i=0;
    if(strcmp(this->controls[this->curControl]->getText(),"ע��")==0)
    {
        if(strlen(this->controls[1]->getText())<=0)
        {
            CTool::gotoxy(20,27);
            cout<<"�û�������Ϊ��!����������";
            system("pause");
        }
        else if(strlen(this->controls[3]->getText())<=0)
        {
            CTool::gotoxy(20,27);
            cout<<"���ֲ���Ϊ��!����������";
            system("pause");
        }
        else if(strlen(this->controls[7]->getText())<=0||strlen(this->controls[5]->getText())<=0)
        {
            CTool::gotoxy(20,27);
            cout<<"���벻��Ϊ�գ�����������";
            system("pause");
        }
        else if(strlen(this->controls[9]->getText())<=0)
        {
            CTool::gotoxy(20,27);
            cout<<"��ɫ����Ϊ�գ�����������";
            system("pause");
        }
        else if(strcmp(this->controls[7]->getText(),this->controls[5]->getText())!=0)//�ж������Ƿ�һ��
        {
            CTool::gotoxy(20,27);
            cout<<"�������벻һ�£�����������";
            system("pause");
        }
        else if(CStaff::registerCheck(this->controls[1]->getText(),data))//�ж��û����Ƿ��Ѿ�����
        {
            CTool::gotoxy(20,27);
            cout<<"�û����Ѵ��ڣ�����������";
            system("pause");
        }
        else
        {
            ((list <CStaff>*)data)->push_back(CStaff(this->controls[1]->getText(),this->controls[3]->getText(),this->controls[7]->getText(),this->controls[9]->getText()));
            CTool::gotoxy(20,27);
            cout<<"ע��ɹ�";
            getch();
            CFile::Staff_Filewrite("data/Staff.txt",(list <CStaff>*)data);
            return STARTWIN;
        }
        return REGISWIN;
    }

    else if(strcmp(this->controls[this->curControl]->getText(),"�˳�")==0)
    {
    }
    return STARTWIN;
}

/******************************
*������ UpdateControls()
*�������ܣ�ע����治��Ҫ��ֻ��Ϊ��ʵ�ֻ���Ĵ��麯����д��
*���� ��
*��� ��
************************************/
void CRegisterWin::UpdateControls()
{

}


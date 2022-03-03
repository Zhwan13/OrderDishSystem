#ifndef _CWINBASE_H_
#define _CWINBASE_H_
#include<string.h>
#include<stdio.h>
#include<conio.h>
#include"CControlBase.h"
#include"CButton.h"
#include"CEdit.h"
#include"CLabel.h"
#include<list>
#include<algorithm>

#include"CTable.h"

#define STARTWIN 0//��ʼ
#define LOGINWIN 1//��¼����
#define REGISWIN 2//ע�����
#define ADMINWIN 3//�ֹܲ˵�����
#define CHECKERWIN 4//�̵�Ա�˵�����
#define SEARCHWIN 5//���ҽ���

#define INSTOCKMENUWIN 6  //���˵�����
#define INSTOCKWIN 7//������
#define TIPSWIN 8//��ʾ�����
#define GOODSADDWIN 9//��Ʒ����
#define INSTOCKRECORDWIN 10//����¼����

#define OUTSTOCKMENUWIN 11//����˵�����
#define OUTSTOCKWIN 12//�������
#define OUTSTOCKRECORDWIN 13//�����¼����


#define CHECKMENUWIN 14 //�̵�˵�����
#define CHECKWINCREATE 15 //�½��̵����
#define CHECKREPORTWIN 16 //�̵㱨�����

#define CONTROLNUM 100


class CWinBase
{
public:
	CWinBase(int x,int y,int height,int width,char *text,int winNo);

	void outlinePrint();
    void show();
	void addControl(CControlBase *pctrl);

	int run(void *data);
	void changeFocus();
	virtual int doAction(void *data)=0;
	virtual void UpdateControls()=0;

	//static int role;

protected:
    int x;
    int y;
    int height;
    int width;
    char *text;
	CControlBase *controls[CONTROLNUM];
    int con_count;//�ؼ�����
	int curControl;//��ǰ�ǵڼ����ؼ�

	int winNo;//�����洰����

};

#endif

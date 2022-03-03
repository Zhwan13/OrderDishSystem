#include"OutStockRecordWin.h"

/******************************
*������ OutStockRecordWin()
*�������ܣ�������湹�캯�����Դ���Ŀؼ����г�ʼ��
*���� ���������Ϳ�ȡ��߶ȡ���������
*��� ��
************************************/
OutStockRecordWin::OutStockRecordWin(int x,int y,int height,int width,char *text,void *data,int winNo)
:CWinBase(x,y,height,width,text,winNo)
{
    this->data=data;
    this->WelcomeLab=new CLabel(this->x+6,this->y+3,2,6,"��ӭ:");
    this->DateLab=new CLabel(this->x+this->width-20,this->y+3,2,6,"����:");
    this->Start=new CLabel(this->x+2,this->y+6,2,6,"��ʼ����:");
    this->End=new CLabel(this->x+2,this->y+9,2,6,"��������:");

    this->OutStockRecTab=new CTable(this->x+6,this->y+11,8,60,this->data,RECORDTABLE);
    this->StartYear=new CEdit(this->x+13,this->y+6,2,10,"",EDIT);
    this->StartMon=new CEdit(this->x+28,this->y+6,2,8,"",EDIT);
    this->StartDay=new CEdit(this->x+43,this->y+6,2,8,"",EDIT);
    this->EndYear=new CEdit(this->x+13,this->y+9,2,10,"",EDIT);
    this->EndMon=new CEdit(this->x+28,this->y+9,2,8,"",EDIT);
    this->EndDay=new CEdit(this->x+43,this->y+9,2,8,"",EDIT);

    this->SearchbyDateBtn=new CButton(this->x+(this->width)-16,this->y+6,2,14,"������ʱ���ѯ");
    this->returnBtn=new CButton(this->x+(this->width)-16,this->y+9,2,4,"����");
    this->GoodsNoLab=new CLabel(this->x+7,this->y+12,2,6,"��Ʒ���");
    this->GoodsNameLab=new CLabel(this->x+19,this->y+12,2,6,"��Ʒ����");
    this->OutStockDateLab=new CLabel(this->x+31,this->y+12,2,6,"��������");
    this->OutStockNumLab=new CLabel(this->x+43,this->y+12,2,6,"��������");
    this->LocationNoLab=new CLabel(this->x+55,this->y+12,2,6,"��λ���");



    this->addControl(this->WelcomeLab);
    this->addControl(this->DateLab);
    this->addControl(this->Start);

    this->addControl(this->OutStockRecTab);
    this->addControl(this->StartYear);//4
    this->addControl(this->StartMon);//5
    this->addControl(this->StartDay);//6
    this->addControl(this->EndYear);//7
    this->addControl(this->EndMon);//8
    this->addControl(this->EndDay);//9
    this->addControl(this->SearchbyDateBtn);
    this->addControl(this->returnBtn);
    this->addControl(this->End);

    this->addControl(this->GoodsNoLab);
    this->addControl(this->GoodsNameLab);
    this->addControl(this->OutStockDateLab);
    this->addControl(this->OutStockNumLab);
    this->addControl(this->LocationNoLab);

}

OutStockRecordWin::~OutStockRecordWin()
{

}

/******************************
*������ doAction()
*�������ܣ��԰���������������Ӧ
*���� �������ݣ�����Ʒ��Ϣ��Ա����Ϣ���������Ϣ
*���� �����
************************************/
int OutStockRecordWin::doAction(void *data)
{
    int flag=0;//�ж��Ƿ���ҵ�
    int startDate=0;//���ͱ�ʾ����Ĳ�ѯ����
    int endDate=0;
    int startYear=0,startMon=0,startDay=0,endYear=0,endMon=0,endDay=0;
    vector<CGoodsStockRecord> *Record=(vector<CGoodsStockRecord>*)data;
    vector<CGoodsStockRecord> *Recordfind=new vector<CGoodsStockRecord>;

    this->OutStockRecTab->setData(data);//��ˢһ�±������ݣ�������û���ҵ����ӡ����
    if(strcmp(this->controls[this->curControl]->getText(),"������ʱ���ѯ")==0)
    {
        if(strlen(this->controls[4]->getText())!=0&&strlen(this->controls[5]->getText())!=0&&strlen(this->controls[6]->getText())!=0&&strlen(this->controls[7]->getText())!=0&&strlen(this->controls[8]->getText())!=0&&strlen(this->controls[9]->getText())!=0)
        {//�ж�������Ƿ���������
            //����������ݶ�ת������
            sscanf(this->controls[4]->getText(),"%d",&startYear);
            sscanf(this->controls[5]->getText(),"%d",&startMon);
            sscanf(this->controls[6]->getText(),"%d",&startDay);
            sscanf(this->controls[7]->getText(),"%d",&endYear);
            sscanf(this->controls[8]->getText(),"%d",&endMon);
            sscanf(this->controls[9]->getText(),"%d",&endDay);
            startDate=startYear*10000+startMon*100+startDay;
            endDate=endYear*10000+endMon*100+endDay;
            vector<CGoodsStockRecord>::iterator it=Record->begin();
            for(it=Record->begin();it!=Record->end();++it)//�˴�֮ǰ��ѭ���ˣ���Ϊ��main�а����ݴ����ˡ�������
            {
                if(it->getDate()>=startDate&&it->getDate()<=endDate)
                {//���ҵ������ݴ��������ٴ�ӡ����
                    flag=1;//�Ѿ����ҵ�
                    //���¶���һ����������ҵ�������
                    Recordfind->push_back(CGoodsStockRecord(it->getNo(),it->getName(),it->getDate(),it->getCount(),it->getLocation()));
                }
            }
            if(flag==1)
                this->OutStockRecTab->setData(Recordfind);
            else if(flag==0)
            {
                CTool::gotoxy(20,30);
                cout<<"no find";
                getch();
            }
            //return INSTOCKRECORDWIN;
        }
        else
        {
            CTool::gotoxy(20,30);
            cout<<"input correct date";
            getch();
        }
        //this->data=Recordfind;
        return OUTSTOCKRECORDWIN;//��������¼����
    }
    else if(strcmp(this->controls[this->curControl]->getText(),"����")==0)
    {
        return OUTSTOCKMENUWIN;
    }
    return OUTSTOCKRECORDWIN;//��ֹ�������
}

/******************************
*������ UpdateControls()
*�������ܣ����´���ؼ�����Ҫ�ǵ�¼�ߵ���ݺ͵�ǰ����
*���� ��
*��� ��
************************************/
void OutStockRecordWin::UpdateControls()
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

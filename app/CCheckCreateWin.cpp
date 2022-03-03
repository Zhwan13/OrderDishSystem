#include"CCheckCreateWin.h"

/******************************
*������ CCheckCreateWin()
*�������ܣ�������湹�캯�����Դ���Ŀؼ����г�ʼ��
*���� ���������Ϳ�ȡ��߶ȡ���������
*��� ��
************************************/
CCheckCreateWin::CCheckCreateWin(int x,int y,int height,int width,char *text,int winNo)
:CWinBase(x,y,height,width,text,winNo)
{
    this->WelcomeLab=new CLabel(this->x+6,this->y+3,2,6,"��ӭ:");
    this->DateLab=new CLabel(this->x+this->width-20,this->y+3,2,6,"����:");
    this->NoLab=new CLabel(this->x+2,this->y+6,2,8,"��������Ʒ���:");
    this->NoEdt=new CEdit(this->x+22,this->y+6,2,18,"",EDIT);
    this->SearchBtn=new CButton(this->x+this->width-8,this->y+6,2,4,"��ѯ");
    //this->InformLab=new CLabel(this->x+6,this->y+9,6,30,"��Ʒ����:\n\n\t\t��Ʒ����:\n\n\t\t��Ʒ�۸�:\n\n\t\t�������:\n\n\t\tλ�ñ��:");

    this->GoodsName=new CLabel(this->x+6,this->y+9,2,10,"��Ʒ����:");
    this->GoodsType=new CLabel(this->x+6,this->y+11,2,10,"��Ʒ����:");
    this->GoodsPrice=new CLabel(this->x+6,this->y+13,2,10,"��Ʒ�۸�:");
    this->LocationNum=new CLabel(this->x+6,this->y+15,2,10,"λ�ñ��:");

    this->CountLab=new CLabel(this->x+this->width-24,this->y+9,2,25,"�������̵�������1-10000��");
    this->CountEdt=new CEdit(this->x+this->width-20,this->y+11,2,18,"",EDIT);
    this->EnterBtn=new CButton(this->x+this->width-20,this->y+14,2,4,"ȷ��");
    this->EscBtn=new CButton(this->x+this->width-12,this->y+14,2,4,"ȡ��");
    this->ReportBtn=new CButton(this->x+this->width-20,this->y+17,2,10,"�����̵��");
    this->Goods_Found=new CGoodsFound(this->x+3,this->y+8,10,24,this->newGoods,CHECK_INFO);

    this->addControl(this->WelcomeLab);
    this->addControl(this->DateLab);
    this->addControl(this->NoLab);
    this->addControl(this->NoEdt);
    this->addControl(this->SearchBtn);
    this->addControl(this->Goods_Found);

    this->addControl(this->GoodsName);
    this->addControl(this->GoodsType);
    this->addControl(this->GoodsPrice);
    this->addControl(this->LocationNum);


    this->addControl(this->CountLab);
    this->addControl(this->CountEdt);
    this->addControl(this->EnterBtn);
    this->addControl(this->EscBtn);
    this->addControl(this->ReportBtn);
    this->newGoods=new map<int,CGoods>;
    this->input=0;
}

CCheckCreateWin::~CCheckCreateWin()
{
    delete this->WelcomeLab;
    delete this->DateLab;
    delete this->NoLab;
    delete this->NoEdt;
    delete this->SearchBtn;
    delete this->GoodsName;
    delete this->GoodsType;
    delete this->GoodsPrice;
    delete this->LocationNum;
    delete this->CountLab;
    delete this->CountEdt;
    delete this->EnterBtn;
    delete this->EscBtn;
    delete this->ReportBtn;
    delete this->Goods_Found;

}

/******************************
*������ doAction()
*�������ܣ��԰���������������Ӧ
*���� �������ݣ�����Ʒ��Ϣ��Ա����Ϣ���������Ϣ
*���� �����
************************************/
int CCheckCreateWin::doAction(void *data)
{

    int nowcount=0;//�̵������
    int date1=0,date2=0;//��Ż�ȡ������
    map<int,CGoods>*Goods=(map<int,CGoods> *)data;
    sscanf(this->controls[3]->getText(),"%d",&input);//����Ĳ�ѯ��Ʒ�ı��ת��int�ͣ���input���
    map<int,CGoods>::iterator it;//�˾�֮ǰ������--ԭ����Goods����������--��������ʱ������
    it=Goods->find(input);
    if(strcmp(this->controls[this->curControl]->getText(),"��ѯ")==0)
    {
        if(it!=Goods->end())//��it������������д�뵽�µ�map��,��map ��ֻ����һ��key_value ��
        {
            //���ҵ������ݴ�������
            this->newGoods->insert(map<int,CGoods>::value_type(999,CGoods("��ʼ��","����",1205,"AX0999")));//�ȳ�ʼ��һ����ֵ����ɾ��
            this->newGoods->insert(map<int,CGoods>::value_type(1000,CGoods("��ʼ��","����",1205,"AX1000")));
            this->newGoods->erase(this->newGoods->begin(),this->newGoods->end());//�ȳ�ʼ�����������²���
            this->newGoods->insert(map<int,CGoods>::value_type(it->first,CGoods(it->first,it->second.getName(),it->second.getType(),it->second.getPrice(),it->second.getCount(),it->second.getLocation())));
            this->Goods_Found->setnewGoods(this->newGoods);
        }
        else
        {
            cout<<"δ�ҵ�no find";
            //CTool::setTemp(this->controls[3]->getText());
            //return TIPSWIN;//��ʾ����
        }
        return CHECKWINCREATE;
    }
    if(strcmp(this->controls[this->curControl]->getText(),"ȷ��")==0&&strlen(this->controls[8]->getText())!=0)//ȷ��ʱ�в�ѯ����Ʒ��Ϣ������������ݲŽ��в���
    {

        sscanf(this->controls[11]->getText(),"%d",&nowcount);
        if(nowcount<0||nowcount>10000)
        {
            cout<<"����������������������";
        }
        else
        {
            it->second.setCount(nowcount);//it��ָ����ҵ�����Ʒ�ĵ�����,��Ʒ�����������޸�
            if(this->newGoods!=NULL)//���¼�����������ʾ����Ʒ��Ϣ����
            {
                this->newGoods->erase(this->newGoods->begin());
            }
            this->newGoods->insert(map<int,CGoods>::value_type(it->first,CGoods(it->first,it->second.getName(),it->second.getType(),it->second.getPrice(),nowcount,it->second.getLocation())));
            //CFile::Goods_Filewrite("data/Goods.txt",Goods);
            CTool::gotoxy(this->x+this->width-17,this->y+18);
            cout<<"�̵�ɹ�!";

            //�����̵���Ϣ
            char *Date;
            Date=new char[20];
            CTool::getNowTime(Date);//��ȡ��ǰ����

        }
        getch();
        return CHECKWINCREATE;
    }
    else if(strcmp(this->controls[this->curControl]->getText(),"ȡ��")==0)
    {
        this->Goods_Found->setnewGoods(NULL);
        return CHECKMENUWIN;// �����̵�˵�����
    }
    else if(strcmp(this->controls[this->curControl]->getText(),"�����̵��")==0)
    {
        return CHECKREPORTWIN;//�̵�����
    }

    return CHECKWINCREATE;
}

/******************************
*������ UpdateControls()
*�������ܣ����´���ؼ�����Ҫ�ǵ�¼�ߵ���ݺ͵�ǰ����
*���� ��
*��� ��
************************************/
void CCheckCreateWin::UpdateControls()
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
